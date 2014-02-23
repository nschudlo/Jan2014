/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *buttonUpdateLists;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser;
    QListWidget *listPeople;
    QListWidget *listWorldObjects;
    QListWidget *listLocations;
    QListWidget *listActions;
    QPushButton *buttonPersonInfo;
    QPushButton *buttonItemInfo;
    QPushButton *buttonLocationInfo;
    QPushButton *buttonActionInfo;
    QTabWidget *infoTabWidget;
    QWidget *tabPerson;
    QLabel *label;
    QListWidget *listPersonItems;
    QPushButton *buttonAddItem;
    QPushButton *buttonRemoveItem;
    QLabel *labelCurrentPerson;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *personMoneyInput;
    QSpinBox *personHealthInput;
    QListWidget *listPersonRelationship;
    QLabel *label_4;
    QSpinBox *personRelStrengthInput;
    QSpinBox *personRelTypeInput;
    QLabel *personRelType;
    QLabel *personRelStrength;
    QLabel *personRelPrintout;
    QListWidget *listPersonLocations;
    QLabel *label_5;
    QLabel *personCurrentLocation;
    QSpinBox *personMoodInput;
    QLabel *label_6;
    QWidget *tabItem;
    QLabel *labelCurrentItem;
    QListWidget *listItemActionDo;
    QListWidget *listItemActionGet;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *buttonItemAddDo;
    QPushButton *buttonItemRemoveDo;
    QPushButton *buttonItemAddGet;
    QPushButton *buttonItemRemoveGet;
    QWidget *tabLocation;
    QWidget *tabAction;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(664, 713);
        buttonUpdateLists = new QPushButton(Form);
        buttonUpdateLists->setObjectName(QStringLiteral("buttonUpdateLists"));
        buttonUpdateLists->setGeometry(QRect(300, 230, 75, 23));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 220, 75, 23));
        textBrowser = new QTextBrowser(Form);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 10, 361, 201));
        listPeople = new QListWidget(Form);
        listPeople->setObjectName(QStringLiteral("listPeople"));
        listPeople->setGeometry(QRect(20, 260, 151, 161));
        listWorldObjects = new QListWidget(Form);
        listWorldObjects->setObjectName(QStringLiteral("listWorldObjects"));
        listWorldObjects->setGeometry(QRect(180, 260, 151, 161));
        listLocations = new QListWidget(Form);
        listLocations->setObjectName(QStringLiteral("listLocations"));
        listLocations->setGeometry(QRect(340, 260, 151, 161));
        listActions = new QListWidget(Form);
        listActions->setObjectName(QStringLiteral("listActions"));
        listActions->setGeometry(QRect(500, 260, 151, 161));
        buttonPersonInfo = new QPushButton(Form);
        buttonPersonInfo->setObjectName(QStringLiteral("buttonPersonInfo"));
        buttonPersonInfo->setGeometry(QRect(60, 430, 75, 23));
        buttonItemInfo = new QPushButton(Form);
        buttonItemInfo->setObjectName(QStringLiteral("buttonItemInfo"));
        buttonItemInfo->setGeometry(QRect(210, 430, 75, 23));
        buttonLocationInfo = new QPushButton(Form);
        buttonLocationInfo->setObjectName(QStringLiteral("buttonLocationInfo"));
        buttonLocationInfo->setGeometry(QRect(380, 430, 75, 23));
        buttonActionInfo = new QPushButton(Form);
        buttonActionInfo->setObjectName(QStringLiteral("buttonActionInfo"));
        buttonActionInfo->setGeometry(QRect(530, 430, 75, 23));
        infoTabWidget = new QTabWidget(Form);
        infoTabWidget->setObjectName(QStringLiteral("infoTabWidget"));
        infoTabWidget->setGeometry(QRect(20, 470, 631, 231));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(infoTabWidget->sizePolicy().hasHeightForWidth());
        infoTabWidget->setSizePolicy(sizePolicy);
        tabPerson = new QWidget();
        tabPerson->setObjectName(QStringLiteral("tabPerson"));
        label = new QLabel(tabPerson);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 46, 13));
        listPersonItems = new QListWidget(tabPerson);
        listPersonItems->setObjectName(QStringLiteral("listPersonItems"));
        listPersonItems->setGeometry(QRect(10, 60, 131, 131));
        buttonAddItem = new QPushButton(tabPerson);
        buttonAddItem->setObjectName(QStringLiteral("buttonAddItem"));
        buttonAddItem->setGeometry(QRect(150, 60, 75, 23));
        buttonRemoveItem = new QPushButton(tabPerson);
        buttonRemoveItem->setObjectName(QStringLiteral("buttonRemoveItem"));
        buttonRemoveItem->setGeometry(QRect(150, 90, 75, 23));
        labelCurrentPerson = new QLabel(tabPerson);
        labelCurrentPerson->setObjectName(QStringLiteral("labelCurrentPerson"));
        labelCurrentPerson->setGeometry(QRect(20, 10, 181, 16));
        label_2 = new QLabel(tabPerson);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 10, 46, 20));
        label_3 = new QLabel(tabPerson);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 10, 31, 20));
        personMoneyInput = new QSpinBox(tabPerson);
        personMoneyInput->setObjectName(QStringLiteral("personMoneyInput"));
        personMoneyInput->setGeometry(QRect(260, 10, 61, 22));
        personMoneyInput->setMaximum(1000);
        personHealthInput = new QSpinBox(tabPerson);
        personHealthInput->setObjectName(QStringLiteral("personHealthInput"));
        personHealthInput->setGeometry(QRect(170, 10, 42, 22));
        personHealthInput->setMaximum(100);
        listPersonRelationship = new QListWidget(tabPerson);
        listPersonRelationship->setObjectName(QStringLiteral("listPersonRelationship"));
        listPersonRelationship->setGeometry(QRect(250, 60, 131, 131));
        label_4 = new QLabel(tabPerson);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 40, 71, 16));
        personRelStrengthInput = new QSpinBox(tabPerson);
        personRelStrengthInput->setObjectName(QStringLiteral("personRelStrengthInput"));
        personRelStrengthInput->setGeometry(QRect(390, 120, 42, 22));
        personRelStrengthInput->setMaximum(2);
        personRelTypeInput = new QSpinBox(tabPerson);
        personRelTypeInput->setObjectName(QStringLiteral("personRelTypeInput"));
        personRelTypeInput->setGeometry(QRect(390, 70, 42, 22));
        personRelTypeInput->setMaximum(12);
        personRelType = new QLabel(tabPerson);
        personRelType->setObjectName(QStringLiteral("personRelType"));
        personRelType->setGeometry(QRect(390, 90, 71, 16));
        personRelStrength = new QLabel(tabPerson);
        personRelStrength->setObjectName(QStringLiteral("personRelStrength"));
        personRelStrength->setGeometry(QRect(390, 140, 71, 16));
        personRelPrintout = new QLabel(tabPerson);
        personRelPrintout->setObjectName(QStringLiteral("personRelPrintout"));
        personRelPrintout->setGeometry(QRect(250, 190, 291, 16));
        listPersonLocations = new QListWidget(tabPerson);
        listPersonLocations->setObjectName(QStringLiteral("listPersonLocations"));
        listPersonLocations->setGeometry(QRect(460, 60, 131, 131));
        label_5 = new QLabel(tabPerson);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(470, 40, 101, 16));
        personCurrentLocation = new QLabel(tabPerson);
        personCurrentLocation->setObjectName(QStringLiteral("personCurrentLocation"));
        personCurrentLocation->setGeometry(QRect(460, 20, 191, 20));
        personMoodInput = new QSpinBox(tabPerson);
        personMoodInput->setObjectName(QStringLiteral("personMoodInput"));
        personMoodInput->setGeometry(QRect(370, 10, 42, 22));
        personMoodInput->setMaximum(10);
        label_6 = new QLabel(tabPerson);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(340, 10, 46, 20));
        infoTabWidget->addTab(tabPerson, QString());
        tabItem = new QWidget();
        tabItem->setObjectName(QStringLiteral("tabItem"));
        labelCurrentItem = new QLabel(tabItem);
        labelCurrentItem->setObjectName(QStringLiteral("labelCurrentItem"));
        labelCurrentItem->setGeometry(QRect(20, 10, 71, 16));
        listItemActionDo = new QListWidget(tabItem);
        listItemActionDo->setObjectName(QStringLiteral("listItemActionDo"));
        listItemActionDo->setGeometry(QRect(10, 60, 131, 131));
        listItemActionGet = new QListWidget(tabItem);
        listItemActionGet->setObjectName(QStringLiteral("listItemActionGet"));
        listItemActionGet->setGeometry(QRect(280, 60, 130, 131));
        label_7 = new QLabel(tabItem);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 40, 61, 16));
        label_8 = new QLabel(tabItem);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(290, 40, 60, 16));
        buttonItemAddDo = new QPushButton(tabItem);
        buttonItemAddDo->setObjectName(QStringLiteral("buttonItemAddDo"));
        buttonItemAddDo->setGeometry(QRect(150, 80, 75, 23));
        buttonItemRemoveDo = new QPushButton(tabItem);
        buttonItemRemoveDo->setObjectName(QStringLiteral("buttonItemRemoveDo"));
        buttonItemRemoveDo->setGeometry(QRect(150, 120, 75, 23));
        buttonItemAddGet = new QPushButton(tabItem);
        buttonItemAddGet->setObjectName(QStringLiteral("buttonItemAddGet"));
        buttonItemAddGet->setGeometry(QRect(420, 80, 75, 23));
        buttonItemRemoveGet = new QPushButton(tabItem);
        buttonItemRemoveGet->setObjectName(QStringLiteral("buttonItemRemoveGet"));
        buttonItemRemoveGet->setGeometry(QRect(420, 120, 75, 23));
        infoTabWidget->addTab(tabItem, QString());
        tabLocation = new QWidget();
        tabLocation->setObjectName(QStringLiteral("tabLocation"));
        infoTabWidget->addTab(tabLocation, QString());
        tabAction = new QWidget();
        tabAction->setObjectName(QStringLiteral("tabAction"));
        infoTabWidget->addTab(tabAction, QString());

        retranslateUi(Form);

        infoTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        buttonUpdateLists->setText(QApplication::translate("Form", "Update Lists", 0));
        pushButton_2->setText(QApplication::translate("Form", "Cancel", 0));
        buttonPersonInfo->setText(QApplication::translate("Form", "Person Info", 0));
        buttonItemInfo->setText(QApplication::translate("Form", "Item Info", 0));
        buttonLocationInfo->setText(QApplication::translate("Form", "Location Info", 0));
        buttonActionInfo->setText(QApplication::translate("Form", "Action Info", 0));
        label->setText(QApplication::translate("Form", "Items", 0));
        buttonAddItem->setText(QApplication::translate("Form", "Add Item", 0));
        buttonRemoveItem->setText(QApplication::translate("Form", "Remove Item", 0));
        labelCurrentPerson->setText(QApplication::translate("Form", "Current Person", 0));
        label_2->setText(QApplication::translate("Form", "Health", 0));
        label_3->setText(QApplication::translate("Form", "Money", 0));
        label_4->setText(QApplication::translate("Form", "Relationships", 0));
        personRelType->setText(QApplication::translate("Form", "Type", 0));
        personRelStrength->setText(QApplication::translate("Form", "Status", 0));
        personRelPrintout->setText(QString());
        label_5->setText(QApplication::translate("Form", "Possible Locations", 0));
        personCurrentLocation->setText(QApplication::translate("Form", "Current Location:", 0));
        label_6->setText(QApplication::translate("Form", "Mood", 0));
        infoTabWidget->setTabText(infoTabWidget->indexOf(tabPerson), QApplication::translate("Form", "Person", 0));
        labelCurrentItem->setText(QApplication::translate("Form", "Current Item", 0));
        label_7->setText(QApplication::translate("Form", "Actions Do", 0));
        label_8->setText(QApplication::translate("Form", "Actions Get", 0));
        buttonItemAddDo->setText(QApplication::translate("Form", "Add Do", 0));
        buttonItemRemoveDo->setText(QApplication::translate("Form", "Remove Do", 0));
        buttonItemAddGet->setText(QApplication::translate("Form", "Add Get", 0));
        buttonItemRemoveGet->setText(QApplication::translate("Form", "Remove Get", 0));
        infoTabWidget->setTabText(infoTabWidget->indexOf(tabItem), QApplication::translate("Form", "Item", 0));
        infoTabWidget->setTabText(infoTabWidget->indexOf(tabLocation), QApplication::translate("Form", "Location", 0));
        infoTabWidget->setTabText(infoTabWidget->indexOf(tabAction), QApplication::translate("Form", "Action", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
