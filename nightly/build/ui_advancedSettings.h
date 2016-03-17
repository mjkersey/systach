#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'advancedSettings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCEDSETTINGS_H
#define UI_ADVANCEDSETTINGS_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_advancedSettings
{
public:
    QGroupBox *groupBox;
    QPushButton *alertAdd;
    QComboBox *alertValue;
    QLabel *label;
    QLabel *label_2;
    QComboBox *alertCondition;
    QLabel *label_3;
    QSpinBox *alertInterval;
    QLabel *label_4;
    QComboBox *alertAction;
    QLabel *label_5;
    QPushButton *alertRemove;
    QLineEdit *alertCommand;
    QLabel *label_6;
    QPushButton *alertModify;
    QTableWidget *alertList;
    QComboBox *alertParameter;
    QGroupBox *groupBox_2;
    QCheckBox *logCheckbox;
    QLabel *label_7;
    QLabel *logFilename;
    QPushButton *logChoose;

    void setupUi(QWidget *advancedSettings)
    {
        if (advancedSettings->objectName().isEmpty())
            advancedSettings->setObjectName(QString::fromUtf8("advancedSettings"));
        advancedSettings->resize(450, 450);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(advancedSettings->sizePolicy().hasHeightForWidth());
        advancedSettings->setSizePolicy(sizePolicy);
        advancedSettings->setMinimumSize(QSize(450, 450));
        groupBox = new QGroupBox(advancedSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 451, 281));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        alertAdd = new QPushButton(groupBox);
        alertAdd->setObjectName(QString::fromUtf8("alertAdd"));
        alertAdd->setGeometry(QRect(380, 170, 61, 24));
        alertValue = new QComboBox(groupBox);
        alertValue->setObjectName(QString::fromUtf8("alertValue"));
        alertValue->setGeometry(QRect(60, 30, 381, 24));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(15, 30, 51, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 60, 21, 21));
        alertCondition = new QComboBox(groupBox);
        alertCondition->setObjectName(QString::fromUtf8("alertCondition"));
        alertCondition->setGeometry(QRect(60, 60, 121, 24));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 90, 31, 21));
        alertInterval = new QSpinBox(groupBox);
        alertInterval->setObjectName(QString::fromUtf8("alertInterval"));
        alertInterval->setGeometry(QRect(60, 90, 91, 23));
        alertInterval->setMinimum(1);
        alertInterval->setMaximum(999999999);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 90, 71, 21));
        alertAction = new QComboBox(groupBox);
        alertAction->setObjectName(QString::fromUtf8("alertAction"));
        alertAction->setGeometry(QRect(240, 90, 201, 24));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 120, 61, 21));
        alertRemove = new QPushButton(groupBox);
        alertRemove->setObjectName(QString::fromUtf8("alertRemove"));
        alertRemove->setGeometry(QRect(380, 230, 61, 24));
        alertCommand = new QLineEdit(groupBox);
        alertCommand->setObjectName(QString::fromUtf8("alertCommand"));
        alertCommand->setGeometry(QRect(80, 120, 361, 23));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 140, 301, 21));
        alertModify = new QPushButton(groupBox);
        alertModify->setObjectName(QString::fromUtf8("alertModify"));
        alertModify->setGeometry(QRect(380, 200, 61, 24));
        alertList = new QTableWidget(groupBox);
        alertList->setObjectName(QString::fromUtf8("alertList"));
        alertList->setGeometry(QRect(10, 170, 361, 81));
        alertParameter = new QComboBox(groupBox);
        alertParameter->setObjectName(QString::fromUtf8("alertParameter"));
        alertParameter->setGeometry(QRect(190, 60, 251, 24));
        alertParameter->setEditable(true);
        groupBox_2 = new QGroupBox(advancedSettings);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 280, 451, 111));
        logCheckbox = new QCheckBox(groupBox_2);
        logCheckbox->setObjectName(QString::fromUtf8("logCheckbox"));
        logCheckbox->setGeometry(QRect(10, 20, 171, 21));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 50, 61, 16));
        logFilename = new QLabel(groupBox_2);
        logFilename->setObjectName(QString::fromUtf8("logFilename"));
        logFilename->setGeometry(QRect(80, 50, 331, 16));
        logChoose = new QPushButton(groupBox_2);
        logChoose->setObjectName(QString::fromUtf8("logChoose"));
        logChoose->setGeometry(QRect(300, 70, 121, 24));

        retranslateUi(advancedSettings);

        QMetaObject::connectSlotsByName(advancedSettings);
    } // setupUi

    void retranslateUi(QWidget *advancedSettings)
    {
        advancedSettings->setWindowTitle(tr2i18n("Dialog", 0));
        groupBox->setTitle(tr2i18n("Alerts", 0));
        alertAdd->setText(tr2i18n("Add", 0));
        label->setText(tr2i18n("If value", 0));
        label_2->setText(tr2i18n("is", 0));
        label_3->setText(tr2i18n("for", 0));
        label_4->setText(tr2i18n("intervals, do", 0));
        label_5->setText(tr2i18n("Command:", 0));
        alertRemove->setText(tr2i18n("Remove", 0));
        label_6->setText(tr2i18n("Tip: Use $v for value, $c for condition, $i for intervals", 0));
        alertModify->setText(tr2i18n("Modify", 0));
        groupBox_2->setTitle(tr2i18n("Log", 0));
        logCheckbox->setText(tr2i18n("Log to file", 0));
        label_7->setText(tr2i18n("Filename:", 0));
        logFilename->setText(tr2i18n("(none selected)", 0));
        logChoose->setText(tr2i18n("Choose File...", 0));
    } // retranslateUi

};

namespace Ui {
    class advancedSettings: public Ui_advancedSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADVANCEDSETTINGS_H

