#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'generalSettings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALSETTINGS_H
#define UI_GENERALSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>
#include "kcolorbutton.h"
#include "kfontrequester.h"

QT_BEGIN_NAMESPACE

class Ui_generalSettings
{
public:
    QGroupBox *appearanceGroup;
    QComboBox *gaugeTheme;
    QLabel *label;
    QLineEdit *gaugeLabel;
    QLabel *label_7;
    QComboBox *gaugeType;
    QLabel *label_6;
    QCheckBox *showPlasmaBg;
    QCheckBox *showRaw;
    QCheckBox *showIcon;
    QComboBox *gaugeIcon;
    QCheckBox *showAnimations;
    QLabel *label_9;
    KFontRequester *fontChooser;
    KColorButton *fontColor;
    QGroupBox *rangeGroup;
    QLineEdit *rangeMin;
    QLabel *label_5;
    QLabel *label_8;
    QLineEdit *rangeMax;
    QCheckBox *autoRange;

    void setupUi(QWidget *generalSettings)
    {
        if (generalSettings->objectName().isEmpty())
            generalSettings->setObjectName(QString::fromUtf8("generalSettings"));
        generalSettings->resize(450, 450);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(generalSettings->sizePolicy().hasHeightForWidth());
        generalSettings->setSizePolicy(sizePolicy);
        generalSettings->setMinimumSize(QSize(450, 450));
        generalSettings->setMaximumSize(QSize(123456, 123456));
        generalSettings->setInputMethodHints(Qt::ImhDigitsOnly);
        appearanceGroup = new QGroupBox(generalSettings);
        appearanceGroup->setObjectName(QString::fromUtf8("appearanceGroup"));
        appearanceGroup->setGeometry(QRect(0, 0, 451, 301));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(appearanceGroup->sizePolicy().hasHeightForWidth());
        appearanceGroup->setSizePolicy(sizePolicy1);
        appearanceGroup->setMinimumSize(QSize(330, 189));
        gaugeTheme = new QComboBox(appearanceGroup);
        gaugeTheme->setObjectName(QString::fromUtf8("gaugeTheme"));
        gaugeTheme->setGeometry(QRect(90, 90, 351, 24));
        label = new QLabel(appearanceGroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 90, 81, 21));
        gaugeLabel = new QLineEdit(appearanceGroup);
        gaugeLabel->setObjectName(QString::fromUtf8("gaugeLabel"));
        gaugeLabel->setGeometry(QRect(90, 30, 351, 23));
        label_7 = new QLabel(appearanceGroup);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 30, 81, 21));
        gaugeType = new QComboBox(appearanceGroup);
        gaugeType->setObjectName(QString::fromUtf8("gaugeType"));
        gaugeType->setGeometry(QRect(90, 120, 351, 24));
        label_6 = new QLabel(appearanceGroup);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 120, 81, 21));
        showPlasmaBg = new QCheckBox(appearanceGroup);
        showPlasmaBg->setObjectName(QString::fromUtf8("showPlasmaBg"));
        showPlasmaBg->setGeometry(QRect(90, 240, 211, 21));
        showRaw = new QCheckBox(appearanceGroup);
        showRaw->setObjectName(QString::fromUtf8("showRaw"));
        showRaw->setGeometry(QRect(90, 150, 161, 21));
        showIcon = new QCheckBox(appearanceGroup);
        showIcon->setObjectName(QString::fromUtf8("showIcon"));
        showIcon->setGeometry(QRect(90, 180, 101, 21));
        gaugeIcon = new QComboBox(appearanceGroup);
        gaugeIcon->setObjectName(QString::fromUtf8("gaugeIcon"));
        gaugeIcon->setGeometry(QRect(200, 180, 241, 24));
        showAnimations = new QCheckBox(appearanceGroup);
        showAnimations->setObjectName(QString::fromUtf8("showAnimations"));
        showAnimations->setGeometry(QRect(90, 210, 171, 21));
        label_9 = new QLabel(appearanceGroup);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 60, 71, 21));
        fontChooser = new KFontRequester(appearanceGroup);
        fontChooser->setObjectName(QString::fromUtf8("fontChooser"));
        fontChooser->setGeometry(QRect(90, 60, 301, 24));
        fontColor = new KColorButton(appearanceGroup);
        fontColor->setObjectName(QString::fromUtf8("fontColor"));
        fontColor->setGeometry(QRect(395, 60, 41, 24));
        rangeGroup = new QGroupBox(generalSettings);
        rangeGroup->setObjectName(QString::fromUtf8("rangeGroup"));
        rangeGroup->setGeometry(QRect(0, 330, 451, 101));
        rangeMin = new QLineEdit(rangeGroup);
        rangeMin->setObjectName(QString::fromUtf8("rangeMin"));
        rangeMin->setEnabled(true);
        rangeMin->setGeometry(QRect(90, 70, 121, 23));
        rangeMin->setAutoFillBackground(false);
        rangeMin->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
        label_5 = new QLabel(rangeGroup);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 70, 61, 21));
        label_8 = new QLabel(rangeGroup);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(250, 70, 71, 21));
        rangeMax = new QLineEdit(rangeGroup);
        rangeMax->setObjectName(QString::fromUtf8("rangeMax"));
        rangeMax->setGeometry(QRect(320, 70, 121, 23));
        rangeMax->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
        autoRange = new QCheckBox(rangeGroup);
        autoRange->setObjectName(QString::fromUtf8("autoRange"));
        autoRange->setGeometry(QRect(20, 30, 281, 21));
        QWidget::setTabOrder(gaugeLabel, gaugeTheme);
        QWidget::setTabOrder(gaugeTheme, gaugeType);
        QWidget::setTabOrder(gaugeType, showRaw);
        QWidget::setTabOrder(showRaw, showIcon);
        QWidget::setTabOrder(showIcon, gaugeIcon);
        QWidget::setTabOrder(gaugeIcon, showAnimations);
        QWidget::setTabOrder(showAnimations, showPlasmaBg);
        QWidget::setTabOrder(showPlasmaBg, autoRange);
        QWidget::setTabOrder(autoRange, rangeMin);
        QWidget::setTabOrder(rangeMin, rangeMax);

        retranslateUi(generalSettings);

        QMetaObject::connectSlotsByName(generalSettings);
    } // setupUi

    void retranslateUi(QWidget *generalSettings)
    {
        generalSettings->setWindowTitle(tr2i18n("Dialog", 0));
        appearanceGroup->setTitle(tr2i18n("Appearance", 0));
#ifndef UI_QT_NO_TOOLTIP
        gaugeTheme->setToolTip(tr2i18n("Type of gauge", 0));
#endif // QT_NO_TOOLTIP
        label->setText(tr2i18n("Theme", 0));
#ifndef UI_QT_NO_TOOLTIP
        gaugeLabel->setToolTip(tr2i18n("A label for the gauge (optional)", 0));
#endif // QT_NO_TOOLTIP
        label_7->setText(tr2i18n("Label", 0));
#ifndef UI_QT_NO_TOOLTIP
        gaugeType->setToolTip(tr2i18n("Type of gauge", 0));
#endif // QT_NO_TOOLTIP
        label_6->setText(tr2i18n("Gauge Type", 0));
        showPlasmaBg->setText(tr2i18n("Show Plasmoid Background", 0));
        showRaw->setText(tr2i18n("Display Raw Value", 0));
        showIcon->setText(tr2i18n("Display Icon", 0));
        showAnimations->setText(tr2i18n("Show Animations", 0));
        label_9->setText(tr2i18n("Font", 0));
        rangeGroup->setTitle(tr2i18n("Gauge Range", 0));
#ifndef UI_QT_NO_TOOLTIP
        rangeMin->setToolTip(tr2i18n("The value at which the gauge reads the lowest", 0));
#endif // QT_NO_TOOLTIP
        rangeMin->setPlaceholderText(QString());
        label_5->setText(tr2i18n("Minimum", 0));
        label_8->setText(tr2i18n("Maximum", 0));
#ifndef UI_QT_NO_TOOLTIP
        rangeMax->setToolTip(tr2i18n("<html><head/><body><p>The value at which the gauge reads the highest</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        rangeMax->setPlaceholderText(QString());
        autoRange->setText(tr2i18n("Automatically Determine Range", 0));
    } // retranslateUi

};

namespace Ui {
    class generalSettings: public Ui_generalSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // GENERALSETTINGS_H

