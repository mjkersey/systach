/***************************************************************************
 *   Copyright 2013 by Michael Kersey <michael.kersey@gmail.com>	   *
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

#ifndef SYSTACHAPPLET_H
#define SYSTACHAPPLET_H

#include <Plasma/Applet>

#include "ui_generalSettings.h"
#include "ui_datasourceSettings.h"

namespace Plasma {
    class DeclarativeWidget;
}

class QGraphicsLinearLayout;

class SysTach : public Plasma::Applet
{
  Q_OBJECT
  public:
      SysTach(QObject *parent, const QVariantList &args);
      ~SysTach();

      void init();

  public Q_SLOTS:
      void setAuto(double rLow, double rHigh);

  Q_SIGNALS:
      void reloadConfig();
      void forceUpdate();

  protected:
      void createConfigurationInterface(KConfigDialog *parent);
      void connectQML(QString qmlFile);

  protected Q_SLOTS:
      void configSaved();
      void toggleRange(bool range);
      void addThemes();
      void parseIni();
      void enumThemefiles();
      void loadTheme();
      void configChanged();
      void loadSources(QString engine);
      void engineChanged();
      void connectEngine(QString engine);
      void sourceLoaded();
      void sourceChanged();

  private:
      void setConfig(QString key, QVariant value);
      QVariant getConfig(QString key);
      QGraphicsLinearLayout *m_plasmoidLayout;
      Plasma::DeclarativeWidget *m_declarativeWidget;
      Plasma::DataEngine *m_dataengine;
      Ui::generalSettings m_generalSettings;
      Ui::datasourceSettings m_datasourceSettings;
      
      QString m_gaugeLabel;
      bool m_showRaw;
      QString m_gaugeTheme;
      QString m_gaugeType;
      QStringList m_enginemanager;
      QString m_gaugeDatasource;
      QString m_gaugeDataengine;
      double m_updateInterval;
      bool m_autoRange;
      double m_rangeMin;
      double m_rangeMax;
      QString m_packagePath;
      QString m_themeFile;
      QString m_gaugeField;
      QString m_themePath;
      QList<QString> m_datakeys;
      QMap<QString, QString> m_themeFileList;
      QVariantMap cfgSettings;
      QVariantMap iniSettings;
      QMap<QString, QString> configEntries;
};

#endif