/***************************************************************************
 *   Copyright 2013 by Michael Kersey <michael.kersey@gmail.com>           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "systach.h"

#include <KConfigDialog>

#include <Plasma/DeclarativeWidget>
#include <Plasma/Package>
#include <Plasma/DataEngine>
#include <Plasma/DataEngineManager>

#include <QDeclarativeContext>
#include <QDeclarativeEngine>
#include <QDeclarativePropertyMap>
#include <QGraphicsLinearLayout>
#include <QDirIterator>
#include <QSettings>

SysTach::SysTach(QObject* parent, const QVariantList& args) 
    : Plasma::Applet(parent, args),
    m_plasmoidLayout(0),
    m_declarativeWidget(0)
{

    setAspectRatioMode(Plasma::KeepAspectRatio);
  
}

SysTach::~SysTach()
{
}

void SysTach::init()
{

    Plasma::PackageStructure::Ptr structure = Plasma::PackageStructure::load("Plasma/Generic");
    Plasma::Package *package = new Plasma::Package(QString(), "systach", structure);
    const QString qmlFile = package->filePath("mainscript");
    
    m_packagePath = package->path();
    
    delete package;

    m_declarativeWidget = new Plasma::DeclarativeWidget(this);
    
    configChanged();
    connectEngine(m_gaugeDataengine);
    connectQML(qmlFile);    
    
    m_plasmoidLayout = new QGraphicsLinearLayout(this);
    m_plasmoidLayout->addItem(m_declarativeWidget);

    setLayout(m_plasmoidLayout);

}

void SysTach::createConfigurationInterface(KConfigDialog* parent)
{
  
    QWidget *generalWidget = new QWidget();
    QWidget *datasourceWidget = new QWidget();
    //QWidget *advancedWidget = new QWidget();
    
    m_generalSettings.setupUi(generalWidget);
    m_datasourceSettings.setupUi(datasourceWidget);
    //m_advancedSettings.setupUi(advancedWidget);

    connectEngine(m_gaugeDataengine);
    
    enumThemefiles();
    
    KConfigGroup kcfg = config();
    
    m_generalSettings.gaugeLabel->setText(getConfig("gLabel").toString());
    m_generalSettings.fontChooser->setFont(getConfig("gFont").value<QFont>());
    m_generalSettings.fontColor->setColor(getConfig("gFontColor").value<QColor>());
    m_generalSettings.showRaw->setChecked(getConfig("gRaw").toBool());
    m_generalSettings.showPlasmaBg->setChecked(getConfig("gPlasmaBg").toBool());
    m_datasourceSettings.updateInterval->setValue(m_updateInterval);
    m_datasourceSettings.gaugeDatasource->addItem("");
    m_generalSettings.gaugeTheme->addItem("");
    m_generalSettings.gaugeType->addItem("");
    m_datasourceSettings.gaugeUnits->setText(getConfig("gUnits").toString());
    m_datasourceSettings.gaugeDivisor->setText(getConfig("gDivisor").toString());
    m_datasourceSettings.gaugePrecision->setValue(getConfig("gPrecision").toDouble());
    
    QStringList m_enginemanager = Plasma::DataEngineManager::listAllEngines();
    
    m_enginemanager.removeAt(m_enginemanager.indexOf("potd"));  // Remove POTD datasource, it's problematic
    m_enginemanager.sort();
    m_datasourceSettings.gaugeDataengine->addItems(m_enginemanager);
        
    int findDataengine = m_datasourceSettings.gaugeDataengine->findText(m_gaugeDataengine);
    
    if (findDataengine != -1) { m_datasourceSettings.gaugeDataengine->setCurrentIndex(findDataengine); }
    
    loadSources(m_datasourceSettings.gaugeDataengine->itemText(m_datasourceSettings.gaugeDataengine->currentIndex()));
    sourceLoaded();
    
//     m_datasourceSettings.gaugeSampleData->insertColumn(0);
//     m_datasourceSettings.gaugeSampleData->insertColumn(1);
//     m_datasourceSettings.gaugeSampleData->setHorizontalHeaderItem(0, new QTableWidgetItem("Field"));
//     m_datasourceSettings.gaugeSampleData->setHorizontalHeaderItem(1, new QTableWidgetItem("Current Value"));
//     m_datasourceSettings.gaugeSampleData->horizontalHeader()->setStretchLastSection(true);
//     
    m_generalSettings.autoRange->setChecked(m_autoRange);
    
    // Test range. If both = 0, then QML datasource min/max need to be used.
    if ( !(m_rangeMin == 0 && m_rangeMax == 0) ) {
      m_generalSettings.rangeMin->setText(QString::number(m_rangeMin, 'f', 2));
      m_generalSettings.rangeMax->setText(QString::number(m_rangeMax, 'f', 2));
    }
    
    if (m_generalSettings.autoRange->isChecked()) {
        m_generalSettings.rangeMin->setDisabled(true);
	m_generalSettings.rangeMax->setDisabled(true);
    }

    parent->addPage(generalWidget, i18n("General"), "preferences-system");
    parent->addPage(datasourceWidget, i18n("Datasource"), "server-database");
    //parent->addPage(advancedWidget, i18n("Advanced"), "applications-system");
   
    connect(parent, 					SIGNAL(applyClicked()),			this, 		SLOT(configSaved()));
    connect(parent, 					SIGNAL(okClicked()), 			this, 		SLOT(configSaved()));
    
    connect(m_generalSettings.gaugeLabel, 		SIGNAL(textChanged(QString)), 		parent, 	SLOT(settingsModified()));
    connect(m_generalSettings.fontChooser, 		SIGNAL(fontSelected(QFont)), 		parent, 	SLOT(settingsModified()));
    connect(m_generalSettings.fontColor, 		SIGNAL(changed(QColor)), 		parent, 	SLOT(settingsModified()));
    connect(m_generalSettings.gaugeTheme, 		SIGNAL(currentIndexChanged(int)), 	parent, 	SLOT(settingsModified()));
    connect(m_generalSettings.gaugeTheme, 		SIGNAL(currentIndexChanged(QString)), 	this,	 	SLOT(loadTheme()));
    connect(m_generalSettings.gaugeType, 		SIGNAL(currentIndexChanged(int)), 	parent, 	SLOT(settingsModified()));
    connect(m_generalSettings.showRaw, 			SIGNAL(toggled(bool)), 			parent, 	SLOT(settingsModified()));
    connect(m_generalSettings.showIcon,			SIGNAL(toggled(bool)), 			parent, 	SLOT(settingsModified()));
    connect(m_generalSettings.gaugeIcon, 		SIGNAL(currentIndexChanged(int)), 	parent, 	SLOT(settingsModified()));
    connect(m_generalSettings.showAnimations,		SIGNAL(toggled(bool)), 			parent, 	SLOT(settingsModified()));
    connect(m_generalSettings.showPlasmaBg,		SIGNAL(toggled(bool)), 			parent, 	SLOT(settingsModified()));
    connect(m_generalSettings.autoRange, 		SIGNAL(toggled(bool)),			parent,		SLOT(settingsModified()));
    connect(m_generalSettings.autoRange, 		SIGNAL(toggled(bool)),			this, 		SLOT(toggleRange(bool)));
    connect(m_generalSettings.rangeMin, 		SIGNAL(textChanged(QString)), 		parent, 	SLOT(settingsModified()));
    connect(m_generalSettings.rangeMax, 		SIGNAL(textChanged(QString)), 		parent, 	SLOT(settingsModified()));

    connect(m_datasourceSettings.gaugeDataengine,	SIGNAL(currentIndexChanged(int)), 	parent, 	SLOT(settingsModified()));
    connect(m_datasourceSettings.gaugeDataengine,	SIGNAL(currentIndexChanged(int)), 	this, 		SLOT(engineChanged()));
    connect(m_datasourceSettings.gaugeDatasource,	SIGNAL(currentIndexChanged(int)), 	parent, 	SLOT(settingsModified()));
    connect(m_datasourceSettings.gaugeDatasource,	SIGNAL(currentIndexChanged(int)), 	this, 		SLOT(sourceChanged()));
    connect(m_datasourceSettings.updateInterval,	SIGNAL(valueChanged(double)), 		parent, 	SLOT(settingsModified()));
    connect(m_datasourceSettings.gaugeUnits, 		SIGNAL(textChanged(QString)), 		parent, 	SLOT(settingsModified()));
    connect(m_datasourceSettings.gaugeDivisor, 		SIGNAL(textChanged(QString)), 		parent, 	SLOT(settingsModified()));
    connect(m_datasourceSettings.gaugeField,		SIGNAL(currentIndexChanged(int)), 	parent, 	SLOT(settingsModified()));
    connect(m_datasourceSettings.gaugePrecision,	SIGNAL(valueChanged(double)), 		parent, 	SLOT(settingsModified()));
    
    connect(m_datasourceSettings.sensorTree,		SIGNAL(itemClicked(QTreeWidgetItem*, int)), this,		SLOT(expandTree(QTreeWidgetItem*)));
    
    addThemes();
    
}

void SysTach::expandTree(QTreeWidgetItem* item)
{
  
  qDebug() << item->text(0);
  
}

void SysTach::setConfig(QString key, QVariant value) 
{

  cfgSettings.insert(key, value);
  
}

QVariant SysTach::getConfig(QString key)
{
  
  return cfgSettings.value(key);
  
}

void SysTach::loadSources(QString engine) 
{
  
    if ( !m_dataengine-> isValid() ) {
      connectEngine(engine);
    }
    
    m_datasourceSettings.gaugeDatasource->clear();
    m_datasourceSettings.gaugeDatasource->addItem("");
    
    QStringList m_availableSources = m_dataengine->sources();
    
    m_datasourceSettings.sensorTree->clear();

    foreach (QString source, m_availableSources) {
      QHash<QString, QVariant> m_datakeys = m_dataengine->query(source);
      QString friendlyName = m_datakeys.value("name").toString() + " (" + source + ")";
      
      QStringList treeItems = source.split("/");
      
      QTreeWidgetItem *item = new QTreeWidgetItem();
      item->setText(0,treeItems.value(0));
      
      m_datasourceSettings.sensorTree->addTopLevelItem(item);

      if (friendlyName.isEmpty()) {
	friendlyName = source;
      }
      
      foreach (QString treeItem, treeItems) {
 	QTreeWidgetItem *child = new QTreeWidgetItem();
	child->setText(0,treeItem);
//	parent->addChild(child);
      }
      
            
      m_datasourceSettings.gaugeDatasource->addItem(friendlyName, source);
    }
    
    int findDatasource = m_datasourceSettings.gaugeDatasource->findData(m_gaugeDatasource);
    
    if (findDatasource != -1) {
      m_datasourceSettings.gaugeDatasource->setCurrentIndex(findDatasource);
    }
}

void SysTach::engineChanged() 
{

  connectEngine(m_datasourceSettings.gaugeDataengine->itemText(m_datasourceSettings.gaugeDataengine->currentIndex()));
  loadSources(m_datasourceSettings.gaugeDataengine->itemText(m_datasourceSettings.gaugeDataengine->currentIndex()));
  
}

void SysTach::enumThemefiles()
{
 
  QDirIterator *directoryIterator = new QDirIterator(m_packagePath, QDirIterator::Subdirectories);
      while (directoryIterator->hasNext()) {
	directoryIterator->next();
	
	if (QFileInfo(directoryIterator->filePath()).isFile()) {
	  if (QFileInfo(directoryIterator->filePath()).suffix() == "cfg") {
	    QStringList themePath = directoryIterator->filePath().split("/");
	    QString themeFolder = themePath.value(themePath.length() - 2);
	    m_themeFileList.insert(themeFolder, directoryIterator->filePath());
	  }
	}
      }
}

void SysTach::sourceLoaded() 
{
    
    // Some datasources will not give us data unless we force an update.  The signal is connected below to updateAllSources()
    emit forceUpdate();
  
//     m_datasourceSettings.gaugeSampleData->setRowCount(0);
    m_datasourceSettings.gaugeField->clear();

    QString source = m_datasourceSettings.gaugeDatasource->itemData(m_datasourceSettings.gaugeDatasource->currentIndex()).toString();
    QHash<QString, QVariant> m_datakeys = m_dataengine->query(source);
    
    // If min and max are in the datasource, set the min and max in the config dialog on source changed.  
    int rLow = m_datakeys.value("min").toInt();
    int rHigh = m_datakeys.value("max").toInt();
    m_generalSettings.rangeMin->setText(QString::number(rLow, 'f', 2));
    m_generalSettings.rangeMax->setText(QString::number(rHigh, 'f', 2));
    
    foreach (QString key, m_datakeys.keys()) {
       m_datasourceSettings.gaugeField->addItem(key + " [=" + m_datakeys.value(key).toString() + "]", key);
    }
     
     int findField = m_datasourceSettings.gaugeField->findData(m_gaugeField);
    
     if (findField!= -1) {
	m_datasourceSettings.gaugeField->setCurrentIndex(findField);
     }

}

void SysTach::sourceChanged() 
{

  sourceLoaded();
  
  QString source = m_datasourceSettings.gaugeDatasource->itemData(m_datasourceSettings.gaugeDatasource->currentIndex()).toString();
  QHash<QString, QVariant> m_datakeys = m_dataengine->query(source);
  
  m_datasourceSettings.gaugeUnits->setText(m_datakeys.value("units").toString());

}

void SysTach::connectEngine(QString engine) {
    m_dataengine = this->dataEngine(engine);
    if ( !m_dataengine-> isValid() ) {
      qDebug() << "Something bad happened, I can't connect to Plasma data engine" << engine << "!  Send me an email about it?";
    } else {
      connect(
	this, 
	SIGNAL(forceUpdate()), 
	m_dataengine, 
	SLOT(updateAllSources())
      );
    }
}

void SysTach::addThemes()
{
  
    m_generalSettings.gaugeTheme->clear();
    m_generalSettings.gaugeTheme->addItem("");
 
    foreach (QString themeFile, m_themeFileList) {
      QSettings *themeSettings = new QSettings(themeFile, QSettings::IniFormat);
      const QString displayName = themeSettings->value("Global/displayName").toString();

      if (!displayName.isEmpty()) {
	QStringList themePath = themeFile.split("/");
	QString themeFolder = themePath.value(themePath.length() - 2);
	m_generalSettings.gaugeTheme->addItem(displayName, themeFolder);
	int selectedItem = m_generalSettings.gaugeTheme->findData(getConfig("gTheme"), Qt::UserRole);

	if (selectedItem != -1) {
	  m_generalSettings.gaugeTheme->setCurrentIndex(selectedItem);
	  loadTheme();
	}
      }
    }
}

void SysTach::loadTheme() {
    m_generalSettings.gaugeType->clear();
    m_generalSettings.gaugeType->addItem("");
    
    QString themeFile = m_themeFileList[m_generalSettings.gaugeTheme->itemData(m_generalSettings.gaugeTheme->currentIndex()).toString()];
    QSettings *themeSettings = new QSettings(themeFile, QSettings::IniFormat);
    const QStringList icons = themeSettings->value("Global/icons").toStringList();
    
    foreach (QString icon, icons) {
      m_generalSettings.gaugeIcon->addItem(icon);      
    }
    
    QStringList gaugeTypes = themeSettings->childGroups();
    
    foreach (const QString& gaugeType, gaugeTypes) {
      if (gaugeType != "Global") {
	themeSettings->beginGroup(gaugeType);
	QString displayName = themeSettings->value("gaugeName").toString();
	m_generalSettings.gaugeType->addItem(displayName, gaugeType);
	int selectedItem = m_generalSettings.gaugeType->findData(m_gaugeType, Qt::UserRole);

	if (selectedItem != -1) {
	  m_generalSettings.gaugeType->setCurrentIndex(selectedItem);
	}
	themeSettings->endGroup();
      }
    }
}

void SysTach::parseIni() {
    //make sure we have the theme and proper values loaded
    if (m_themeFile.isEmpty() || getConfig("gTheme") == "" || m_gaugeType.isEmpty() || !m_updateInterval) {  
      return;
    }
    
    QDeclarativeContext *rootCtxt = m_declarativeWidget->engine()->rootContext();
    QSettings *themeSettings = new QSettings(m_themeFile, QSettings::IniFormat);
    themeSettings->beginGroup(m_gaugeType);
    
    foreach (QString iniKey, themeSettings->childKeys()) {
      QStringList iniVal = themeSettings->value(iniKey).toStringList();

      // Check to see if we're inserting a value or a set of values
      // If a single value, insert
      if ( iniVal.size() == 1 ) {
	iniSettings.insert(iniKey, iniVal);
	
      // If a set of values delimited by a `:`, split it, and insert key:val pairs
      // This allows QML to access it in a key.subkey fashion
      // Note that a `:` in the value will muck everything up, so this supports two-level arrays only.
      // A recursive function would fix this
      } else {
	QVariantMap subPropList;
	foreach (QString subMap, iniVal) {
	  QString subKey = subMap.split(":")[0].trimmed();
	  QString subVal = subMap.split(":")[1].trimmed();
	  subPropList.insert(subKey, subVal);
	}
	iniSettings.insert(iniKey, subPropList);
      }
    }
    rootCtxt->setContextProperty("iniSettings", iniSettings);
    themeSettings->endGroup();
    
}

void SysTach::toggleRange(bool range)
{

    if (range) {
        m_generalSettings.rangeMin->setDisabled(true);
	m_generalSettings.rangeMax->setDisabled(true);
    } else {
        m_generalSettings.rangeMin->setDisabled(false);
	m_generalSettings.rangeMax->setDisabled(false);
    }

}

void SysTach::setAuto(double rLow, double rHigh) {
  
    KConfigGroup cfg = config();
    
    // Make sure the combo boxes actually exist
    if ( this->isUserConfiguring() ) {
      if ( m_generalSettings.autoRange->isChecked() ) {  // Otherwise, if the user unchecks it and is entering values, they will change
	m_generalSettings.rangeMin->setText(QString::number(rLow, 'f', 2));
	m_generalSettings.rangeMax->setText(QString::number(rHigh, 'f', 2));
      }
    }
    
    cfg.writeEntry("rangeMin",		QString::number(rLow, 'f', 2));
    cfg.writeEntry("rangeMax", 		QString::number(rHigh, 'f', 2));
   
}

void SysTach::configSaved()
{
  
    KConfigGroup cfg = config();
    
    cfg.writeEntry("gaugeLabel", 	m_generalSettings.gaugeLabel->text());
    cfg.writeEntry("gaugeFont", 	m_generalSettings.fontChooser->font());
    cfg.writeEntry("fontColor", 	m_generalSettings.fontColor->color().name());
    cfg.writeEntry("showRaw", 		m_generalSettings.showRaw->isChecked());
    cfg.writeEntry("showPlasmaBg", 	m_generalSettings.showPlasmaBg->isChecked());
    cfg.writeEntry("gaugeTheme", 	m_generalSettings.gaugeTheme->itemData(m_generalSettings.gaugeTheme->currentIndex()).toString());
    cfg.writeEntry("gaugeType", 	m_generalSettings.gaugeType->itemData(m_generalSettings.gaugeType->currentIndex()).toString());
    cfg.writeEntry("showIcon", 		m_generalSettings.showIcon->isChecked());
    cfg.writeEntry("gaugeIcon", 	m_generalSettings.gaugeIcon->currentIndex());
    cfg.writeEntry("showAnimations", 	m_generalSettings.showAnimations->isChecked());
    cfg.writeEntry("gaugeDatasource", 	m_datasourceSettings.gaugeDatasource->itemData(m_datasourceSettings.gaugeDatasource->currentIndex()));
    cfg.writeEntry("updateInterval",	m_datasourceSettings.updateInterval->value());
    cfg.writeEntry("gaugeDataengine", 	m_datasourceSettings.gaugeDataengine->itemText(m_datasourceSettings.gaugeDataengine->currentIndex()));
    cfg.writeEntry("autoRange", 	m_generalSettings.autoRange->isChecked());
    cfg.writeEntry("rangeMin",		m_generalSettings.rangeMin->text());
    cfg.writeEntry("rangeMax", 		m_generalSettings.rangeMax->text());
    cfg.writeEntry("themeFile", 	m_themeFileList[m_generalSettings.gaugeTheme->itemData(m_generalSettings.gaugeTheme->currentIndex()).toString()]);
    cfg.writeEntry("gaugeField",	m_datasourceSettings.gaugeField->itemData(m_datasourceSettings.gaugeField->currentIndex()));
    cfg.writeEntry("gaugeUnits",	m_datasourceSettings.gaugeUnits->text());
    cfg.writeEntry("gaugeDivisor",	m_datasourceSettings.gaugeDivisor->text());
    cfg.writeEntry("gaugePrecision",	m_datasourceSettings.gaugePrecision->value());

}

void SysTach::configChanged()
{
  
    // Get data from config, feed it to plasmoid
    KConfigGroup cfg = config();
    configEntries = cfg.entryMap();
    
    setConfig("gLabel", cfg.readEntry("gaugeLabel"));
    setConfig("gFont", cfg.readEntry("gaugeFont"));
    setConfig("gFontColor", cfg.readEntry("fontColor"));
    setConfig("gRaw", cfg.readEntry("showRaw", false));
    setConfig("gPlasmaBg", cfg.readEntry("showPlasmaBg", true));
    setConfig("gTheme", cfg.readEntry("gaugeTheme"));
    setConfig("gShowIcon", cfg.readEntry("showIcon"));
    setConfig("gIcon", cfg.readEntry("gaugeIcon"));
    setConfig("gShowAnimations", cfg.readEntry("showAnimations"));
        
    setConfig("gUnits", cfg.readEntry("gaugeUnits"));
    setConfig("gPrecision", cfg.readEntry("gaugePrecision"));
    setConfig("gDivisor", cfg.readEntry("gaugeDivisor", 1));
    
    m_gaugeType 	= cfg.readEntry("gaugeType");
    m_gaugeDatasource 	= cfg.readEntry("gaugeDatasource");
    m_gaugeDataengine 	= cfg.readEntry("gaugeDataengine", "systemmonitor");
    m_updateInterval 	= cfg.readEntry("updateInterval", 4.0);
    m_autoRange 	= cfg.readEntry("autoRange", false);
    m_rangeMin		= cfg.readEntry("rangeMin").toDouble();
    m_rangeMax		= cfg.readEntry("rangeMax").toDouble();
    m_themeFile		= cfg.readEntry("themeFile");
    m_gaugeField	= cfg.readEntry("gaugeField", "value");
    
    // Needs to be done here
    if (cfg.readEntry("showPlasmaBg", true)) {
      setBackgroundHints(DefaultBackground);
    } else {
      setBackgroundHints(0);
    }
    
    parseIni();
    
    QDeclarativeContext *rootCtxt = m_declarativeWidget->engine()->rootContext();
    
    rootCtxt->setContextProperty("gType", 		m_gaugeType);
    rootCtxt->setContextProperty("gDatasource", 	m_gaugeDatasource);
    rootCtxt->setContextProperty("gDataengine", 	m_gaugeDataengine);
    rootCtxt->setContextProperty("gField", 		m_gaugeField);
    rootCtxt->setContextProperty("gInterval", 		m_updateInterval);
    rootCtxt->setContextProperty("gAuto", 		m_autoRange);
    rootCtxt->setContextProperty("gMinRange", 		m_rangeMin);
    rootCtxt->setContextProperty("gMaxRange", 		m_rangeMax);
    
    foreach (QString cfgKey, cfgSettings.keys()) {
      rootCtxt->setContextProperty(cfgKey, getConfig(cfgKey));
    }
    
    // tell QML to reassign vars
    emit reloadConfig();

}

void SysTach::connectQML(QString qmlFile)
{

    configChanged();
  
    m_declarativeWidget->setQmlPath(qmlFile);
    
    connect(
      this,
      SIGNAL(reloadConfig()),
      m_declarativeWidget->rootObject(),
      SIGNAL(reloadConfig())
    );
    
    connect(
      m_declarativeWidget->rootObject(),
      SIGNAL(setAuto(double, double)),
      this,
      SLOT(setAuto(double, double))
    );
 
}

K_EXPORT_PLASMA_APPLET(systach, SysTach)

#include "systach.moc"