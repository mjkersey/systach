#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'datasourceSettings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASOURCESETTINGS_H
#define UI_DATASOURCESETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_datasourceSettings
{
public:
    QGroupBox *groupBox;
    QLabel *label_8;
    QComboBox *gaugeDataengine;
    QLabel *label_2;
    QComboBox *gaugeDatasource;
    QComboBox *gaugeField;
    QLabel *label_3;
    QLineEdit *gaugeUnits;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *gaugeDivisor;
    QCheckBox *gaugeShowUnits;
    QLabel *label_4;
    QDoubleSpinBox *updateInterval;
    QDoubleSpinBox *gaugePrecision;
    QLabel *label_7;
    QLabel *label;

    void setupUi(QWidget *datasourceSettings)
    {
        if (datasourceSettings->objectName().isEmpty())
            datasourceSettings->setObjectName(QString::fromUtf8("datasourceSettings"));
        datasourceSettings->resize(450, 475);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(datasourceSettings->sizePolicy().hasHeightForWidth());
        datasourceSettings->setSizePolicy(sizePolicy);
        datasourceSettings->setMinimumSize(QSize(450, 450));
        groupBox = new QGroupBox(datasourceSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 451, 461));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 30, 81, 21));
        gaugeDataengine = new QComboBox(groupBox);
        gaugeDataengine->setObjectName(QString::fromUtf8("gaugeDataengine"));
        gaugeDataengine->setGeometry(QRect(90, 30, 351, 24));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gaugeDataengine->sizePolicy().hasHeightForWidth());
        gaugeDataengine->setSizePolicy(sizePolicy2);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 81, 21));
        gaugeDatasource = new QComboBox(groupBox);
        gaugeDatasource->setObjectName(QString::fromUtf8("gaugeDatasource"));
        gaugeDatasource->setEnabled(true);
        gaugeDatasource->setGeometry(QRect(90, 60, 351, 23));
        sizePolicy2.setHeightForWidth(gaugeDatasource->sizePolicy().hasHeightForWidth());
        gaugeDatasource->setSizePolicy(sizePolicy2);
        gaugeDatasource->setEditable(true);
        gaugeField = new QComboBox(groupBox);
        gaugeField->setObjectName(QString::fromUtf8("gaugeField"));
        gaugeField->setGeometry(QRect(90, 90, 351, 24));
        gaugeField->setEditable(false);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 81, 21));
        gaugeUnits = new QLineEdit(groupBox);
        gaugeUnits->setObjectName(QString::fromUtf8("gaugeUnits"));
        gaugeUnits->setGeometry(QRect(90, 150, 141, 23));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 150, 81, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 180, 61, 21));
        gaugeDivisor = new QLineEdit(groupBox);
        gaugeDivisor->setObjectName(QString::fromUtf8("gaugeDivisor"));
        gaugeDivisor->setGeometry(QRect(90, 180, 141, 23));
        gaugeShowUnits = new QCheckBox(groupBox);
        gaugeShowUnits->setObjectName(QString::fromUtf8("gaugeShowUnits"));
        gaugeShowUnits->setGeometry(QRect(260, 150, 141, 21));
        gaugeShowUnits->setChecked(true);
        gaugeShowUnits->setTristate(false);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 120, 71, 21));
        updateInterval = new QDoubleSpinBox(groupBox);
        updateInterval->setObjectName(QString::fromUtf8("updateInterval"));
        updateInterval->setGeometry(QRect(90, 120, 91, 23));
        updateInterval->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        updateInterval->setDecimals(1);
        updateInterval->setMinimum(0.1);
        updateInterval->setSingleStep(0.5);
        updateInterval->setValue(2);
        gaugePrecision = new QDoubleSpinBox(groupBox);
        gaugePrecision->setObjectName(QString::fromUtf8("gaugePrecision"));
        gaugePrecision->setGeometry(QRect(90, 210, 91, 23));
        gaugePrecision->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gaugePrecision->setDecimals(0);
        gaugePrecision->setMinimum(0);
        gaugePrecision->setSingleStep(1);
        gaugePrecision->setValue(0);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 210, 71, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 120, 54, 21));
        QWidget::setTabOrder(gaugeDataengine, gaugeDatasource);
        QWidget::setTabOrder(gaugeDatasource, gaugeField);
        QWidget::setTabOrder(gaugeField, updateInterval);
        QWidget::setTabOrder(updateInterval, gaugeUnits);
        QWidget::setTabOrder(gaugeUnits, gaugeShowUnits);
        QWidget::setTabOrder(gaugeShowUnits, gaugeDivisor);
        QWidget::setTabOrder(gaugeDivisor, gaugePrecision);

        retranslateUi(datasourceSettings);

        QMetaObject::connectSlotsByName(datasourceSettings);
    } // setupUi

    void retranslateUi(QWidget *datasourceSettings)
    {
        datasourceSettings->setWindowTitle(tr2i18n("Dialog", 0));
        groupBox->setTitle(tr2i18n("Data Engine", 0));
        label_8->setText(tr2i18n("Engine", 0));
#ifndef UI_QT_NO_TOOLTIP
        gaugeDataengine->setToolTip(tr2i18n("Engine to connect to for sources", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(tr2i18n("Datasource", 0));
#ifndef UI_QT_NO_TOOLTIP
        gaugeDatasource->setToolTip(tr2i18n("Source to poll for data", 0));
#endif // QT_NO_TOOLTIP
#ifndef UI_QT_NO_TOOLTIP
        gaugeField->setToolTip(tr2i18n("Select the field containing the data for the gauge", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(tr2i18n("Data Field", 0));
#ifndef UI_QT_NO_TOOLTIP
        gaugeUnits->setToolTip(tr2i18n("Units to display (if shown)", 0));
#endif // QT_NO_TOOLTIP
        label_5->setText(tr2i18n("Units", 0));
        label_6->setText(tr2i18n("Divisor", 0));
#ifndef UI_QT_NO_TOOLTIP
        gaugeDivisor->setToolTip(tr2i18n("A number by which to divide the output.  Useful for converting to a different base unit.", 0));
#endif // QT_NO_TOOLTIP
        gaugeDivisor->setText(tr2i18n("1", 0));
#ifndef UI_QT_NO_TOOLTIP
        gaugeShowUnits->setToolTip(tr2i18n("Show the raw value units on the gauge when raw values are shown", 0));
#endif // QT_NO_TOOLTIP
        gaugeShowUnits->setText(tr2i18n("Display Units", 0));
        label_4->setText(tr2i18n("Poll Interval", 0));
#ifndef UI_QT_NO_TOOLTIP
        updateInterval->setToolTip(tr2i18n("Polling interval in seconds", 0));
#endif // QT_NO_TOOLTIP
#ifndef UI_QT_NO_TOOLTIP
        gaugePrecision->setToolTip(tr2i18n("# of digits after decimal point", 0));
#endif // QT_NO_TOOLTIP
        label_7->setText(tr2i18n("Precision", 0));
        label->setText(tr2i18n("seconds", 0));
    } // retranslateUi

};

namespace Ui {
    class datasourceSettings: public Ui_datasourceSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DATASOURCESETTINGS_H

