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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTabWidget *mainTabWidget;
    QWidget *tab;
    QPushButton *buttonTest;
    QPushButton *buttonUpdateLists;
    QListWidget *listLocations;
    QPushButton *buttonLocationInfo;
    QListWidget *listActions;
    QPushButton *buttonItemInfo;
    QListWidget *listPeople;
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
    QPushButton *buttonAddRelationship;
    QPushButton *buttonRemoveRelationship;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer;
    QSpinBox *policeRep;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *mobRep;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *policeWanted;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *mobWanted;
    QLabel *label_16;
    QSpinBox *storyRank;
    QLabel *rankLabel;
    QCheckBox *citizenCheckBox;
    QLabel *label_17;
    QLabel *roleLabel;
    QSpinBox *storyRole;
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
    QListWidget *listLocationsGoTo;
    QLabel *labelLocationCurrent;
    QLabel *label_9;
    QListWidget *listLocationsComeFrom;
    QLabel *label_10;
    QListWidget *listLocationsPeople;
    QLabel *label_11;
    QWidget *tabAction;
    QPushButton *buttonPersonInfo;
    QListWidget *listWorldObjects;
    QPushButton *buttonActionInfo;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QLabel *numAttempts;
    QListWidget *listGoals;
    QLabel *maxAttempts;
    QLabel *label_19;
    QTextBrowser *goalTextBrowser;
    QPushButton *refreshGoals;
    QLabel *label_18;
    QGroupBox *groupBox_3;
    QListWidget *listStories;
    QPushButton *refreshStories;
    QTextBrowser *stortTextBrowser;
    QPushButton *loadGoals;
    QPushButton *loadStories;
    QLabel *label_20;
    QWidget *tab_3;
    QGroupBox *groupBox_4;
    QListWidget *currentGoalsList;
    QPushButton *updateCurrentGoalsButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(664, 713);
        mainTabWidget = new QTabWidget(Form);
        mainTabWidget->setObjectName(QStringLiteral("mainTabWidget"));
        mainTabWidget->setGeometry(QRect(0, 0, 671, 711));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        buttonTest = new QPushButton(tab);
        buttonTest->setObjectName(QStringLiteral("buttonTest"));
        buttonTest->setGeometry(QRect(400, 10, 75, 23));
        buttonUpdateLists = new QPushButton(tab);
        buttonUpdateLists->setObjectName(QStringLiteral("buttonUpdateLists"));
        buttonUpdateLists->setGeometry(QRect(20, 10, 75, 23));
        listLocations = new QListWidget(tab);
        listLocations->setObjectName(QStringLiteral("listLocations"));
        listLocations->setGeometry(QRect(330, 40, 151, 161));
        buttonLocationInfo = new QPushButton(tab);
        buttonLocationInfo->setObjectName(QStringLiteral("buttonLocationInfo"));
        buttonLocationInfo->setGeometry(QRect(370, 210, 75, 23));
        listActions = new QListWidget(tab);
        listActions->setObjectName(QStringLiteral("listActions"));
        listActions->setGeometry(QRect(490, 40, 151, 161));
        buttonItemInfo = new QPushButton(tab);
        buttonItemInfo->setObjectName(QStringLiteral("buttonItemInfo"));
        buttonItemInfo->setGeometry(QRect(200, 210, 75, 23));
        listPeople = new QListWidget(tab);
        listPeople->setObjectName(QStringLiteral("listPeople"));
        listPeople->setGeometry(QRect(10, 40, 151, 161));
        infoTabWidget = new QTabWidget(tab);
        infoTabWidget->setObjectName(QStringLiteral("infoTabWidget"));
        infoTabWidget->setGeometry(QRect(10, 250, 631, 421));
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
        personRelStrengthInput->setGeometry(QRect(390, 100, 42, 22));
        personRelStrengthInput->setMaximum(2);
        personRelTypeInput = new QSpinBox(tabPerson);
        personRelTypeInput->setObjectName(QStringLiteral("personRelTypeInput"));
        personRelTypeInput->setGeometry(QRect(390, 60, 42, 22));
        personRelTypeInput->setMaximum(12);
        personRelType = new QLabel(tabPerson);
        personRelType->setObjectName(QStringLiteral("personRelType"));
        personRelType->setGeometry(QRect(390, 80, 71, 16));
        personRelStrength = new QLabel(tabPerson);
        personRelStrength->setObjectName(QStringLiteral("personRelStrength"));
        personRelStrength->setGeometry(QRect(390, 120, 71, 16));
        personRelPrintout = new QLabel(tabPerson);
        personRelPrintout->setObjectName(QStringLiteral("personRelPrintout"));
        personRelPrintout->setGeometry(QRect(250, 190, 291, 16));
        listPersonLocations = new QListWidget(tabPerson);
        listPersonLocations->setObjectName(QStringLiteral("listPersonLocations"));
        listPersonLocations->setGeometry(QRect(480, 60, 131, 131));
        label_5 = new QLabel(tabPerson);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(490, 40, 101, 16));
        personCurrentLocation = new QLabel(tabPerson);
        personCurrentLocation->setObjectName(QStringLiteral("personCurrentLocation"));
        personCurrentLocation->setGeometry(QRect(480, 20, 191, 20));
        personMoodInput = new QSpinBox(tabPerson);
        personMoodInput->setObjectName(QStringLiteral("personMoodInput"));
        personMoodInput->setGeometry(QRect(370, 10, 42, 22));
        personMoodInput->setMaximum(10);
        label_6 = new QLabel(tabPerson);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(340, 10, 46, 20));
        buttonAddRelationship = new QPushButton(tabPerson);
        buttonAddRelationship->setObjectName(QStringLiteral("buttonAddRelationship"));
        buttonAddRelationship->setGeometry(QRect(390, 140, 75, 23));
        buttonRemoveRelationship = new QPushButton(tabPerson);
        buttonRemoveRelationship->setObjectName(QStringLiteral("buttonRemoveRelationship"));
        buttonRemoveRelationship->setGeometry(QRect(390, 170, 75, 23));
        groupBox = new QGroupBox(tabPerson);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 210, 391, 141));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 141, 116));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout->addWidget(label_12);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        policeRep = new QSpinBox(layoutWidget);
        policeRep->setObjectName(QStringLiteral("policeRep"));
        policeRep->setMaximum(10);

        horizontalLayout->addWidget(policeRep);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_2->addWidget(label_13);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        mobRep = new QSpinBox(layoutWidget);
        mobRep->setObjectName(QStringLiteral("mobRep"));
        mobRep->setMaximum(10);

        horizontalLayout_2->addWidget(mobRep);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_3->addWidget(label_14);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        policeWanted = new QSpinBox(layoutWidget);
        policeWanted->setObjectName(QStringLiteral("policeWanted"));
        policeWanted->setMaximum(10);

        horizontalLayout_3->addWidget(policeWanted);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_4->addWidget(label_15);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        mobWanted = new QSpinBox(layoutWidget);
        mobWanted->setObjectName(QStringLiteral("mobWanted"));
        mobWanted->setMaximum(10);

        horizontalLayout_4->addWidget(mobWanted);


        verticalLayout->addLayout(horizontalLayout_4);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(200, 30, 61, 16));
        storyRank = new QSpinBox(groupBox);
        storyRank->setObjectName(QStringLiteral("storyRank"));
        storyRank->setGeometry(QRect(260, 30, 42, 22));
        storyRank->setMaximum(3);
        rankLabel = new QLabel(groupBox);
        rankLabel->setObjectName(QStringLiteral("rankLabel"));
        rankLabel->setGeometry(QRect(310, 30, 61, 16));
        citizenCheckBox = new QCheckBox(groupBox);
        citizenCheckBox->setObjectName(QStringLiteral("citizenCheckBox"));
        citizenCheckBox->setGeometry(QRect(200, 60, 70, 17));
        citizenCheckBox->setChecked(true);
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(200, 90, 61, 16));
        roleLabel = new QLabel(groupBox);
        roleLabel->setObjectName(QStringLiteral("roleLabel"));
        roleLabel->setGeometry(QRect(310, 90, 71, 16));
        storyRole = new QSpinBox(groupBox);
        storyRole->setObjectName(QStringLiteral("storyRole"));
        storyRole->setGeometry(QRect(260, 90, 42, 22));
        storyRole->setMaximum(8);
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
        listLocationsGoTo = new QListWidget(tabLocation);
        listLocationsGoTo->setObjectName(QStringLiteral("listLocationsGoTo"));
        listLocationsGoTo->setGeometry(QRect(40, 50, 131, 131));
        labelLocationCurrent = new QLabel(tabLocation);
        labelLocationCurrent->setObjectName(QStringLiteral("labelLocationCurrent"));
        labelLocationCurrent->setGeometry(QRect(20, 10, 191, 20));
        label_9 = new QLabel(tabLocation);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 30, 101, 16));
        listLocationsComeFrom = new QListWidget(tabLocation);
        listLocationsComeFrom->setObjectName(QStringLiteral("listLocationsComeFrom"));
        listLocationsComeFrom->setGeometry(QRect(210, 50, 131, 131));
        label_10 = new QLabel(tabLocation);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(210, 30, 101, 16));
        listLocationsPeople = new QListWidget(tabLocation);
        listLocationsPeople->setObjectName(QStringLiteral("listLocationsPeople"));
        listLocationsPeople->setGeometry(QRect(400, 50, 131, 131));
        label_11 = new QLabel(tabLocation);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(400, 30, 111, 16));
        infoTabWidget->addTab(tabLocation, QString());
        tabAction = new QWidget();
        tabAction->setObjectName(QStringLiteral("tabAction"));
        infoTabWidget->addTab(tabAction, QString());
        buttonPersonInfo = new QPushButton(tab);
        buttonPersonInfo->setObjectName(QStringLiteral("buttonPersonInfo"));
        buttonPersonInfo->setGeometry(QRect(50, 210, 75, 23));
        listWorldObjects = new QListWidget(tab);
        listWorldObjects->setObjectName(QStringLiteral("listWorldObjects"));
        listWorldObjects->setGeometry(QRect(170, 40, 151, 161));
        buttonActionInfo = new QPushButton(tab);
        buttonActionInfo->setObjectName(QStringLiteral("buttonActionInfo"));
        buttonActionInfo->setGeometry(QRect(520, 210, 75, 23));
        mainTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 10, 601, 251));
        numAttempts = new QLabel(groupBox_2);
        numAttempts->setObjectName(QStringLiteral("numAttempts"));
        numAttempts->setGeometry(QRect(290, 60, 21, 16));
        listGoals = new QListWidget(groupBox_2);
        listGoals->setObjectName(QStringLiteral("listGoals"));
        listGoals->setGeometry(QRect(10, 60, 151, 161));
        maxAttempts = new QLabel(groupBox_2);
        maxAttempts->setObjectName(QStringLiteral("maxAttempts"));
        maxAttempts->setGeometry(QRect(290, 90, 21, 16));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(180, 90, 101, 16));
        goalTextBrowser = new QTextBrowser(groupBox_2);
        goalTextBrowser->setObjectName(QStringLiteral("goalTextBrowser"));
        goalTextBrowser->setGeometry(QRect(310, 20, 281, 221));
        refreshGoals = new QPushButton(groupBox_2);
        refreshGoals->setObjectName(QStringLiteral("refreshGoals"));
        refreshGoals->setGeometry(QRect(20, 30, 81, 23));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(180, 60, 101, 16));
        numAttempts->raise();
        listGoals->raise();
        label_18->raise();
        maxAttempts->raise();
        label_19->raise();
        goalTextBrowser->raise();
        refreshGoals->raise();
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 270, 601, 251));
        listStories = new QListWidget(groupBox_3);
        listStories->setObjectName(QStringLiteral("listStories"));
        listStories->setGeometry(QRect(20, 70, 151, 161));
        refreshStories = new QPushButton(groupBox_3);
        refreshStories->setObjectName(QStringLiteral("refreshStories"));
        refreshStories->setGeometry(QRect(30, 40, 91, 23));
        stortTextBrowser = new QTextBrowser(groupBox_3);
        stortTextBrowser->setObjectName(QStringLiteral("stortTextBrowser"));
        stortTextBrowser->setGeometry(QRect(310, 20, 281, 221));
        loadGoals = new QPushButton(tab_2);
        loadGoals->setObjectName(QStringLiteral("loadGoals"));
        loadGoals->setGeometry(QRect(40, 640, 75, 23));
        loadStories = new QPushButton(tab_2);
        loadStories->setObjectName(QStringLiteral("loadStories"));
        loadStories->setGeometry(QRect(130, 640, 75, 23));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(60, 600, 131, 31));
        label_20->setWordWrap(true);
        mainTabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 30, 581, 241));
        currentGoalsList = new QListWidget(groupBox_4);
        currentGoalsList->setObjectName(QStringLiteral("currentGoalsList"));
        currentGoalsList->setGeometry(QRect(20, 30, 391, 191));
        updateCurrentGoalsButton = new QPushButton(groupBox_4);
        updateCurrentGoalsButton->setObjectName(QStringLiteral("updateCurrentGoalsButton"));
        updateCurrentGoalsButton->setGeometry(QRect(440, 30, 75, 23));
        mainTabWidget->addTab(tab_3, QString());

        retranslateUi(Form);

        mainTabWidget->setCurrentIndex(2);
        infoTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        buttonTest->setText(QApplication::translate("Form", "Test", 0));
        buttonUpdateLists->setText(QApplication::translate("Form", "Update Lists", 0));
        buttonLocationInfo->setText(QApplication::translate("Form", "Location Info", 0));
        buttonItemInfo->setText(QApplication::translate("Form", "Item Info", 0));
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
        buttonAddRelationship->setText(QApplication::translate("Form", "Add Rel", 0));
        buttonRemoveRelationship->setText(QApplication::translate("Form", "Remove Rel", 0));
        groupBox->setTitle(QApplication::translate("Form", "Cops and Robbers", 0));
        label_12->setText(QApplication::translate("Form", "Police Reputation", 0));
        label_13->setText(QApplication::translate("Form", "Mob Reputation", 0));
        label_14->setText(QApplication::translate("Form", "Police Wanted", 0));
        label_15->setText(QApplication::translate("Form", "Mob Wanted", 0));
        label_16->setText(QApplication::translate("Form", "Story Rank", 0));
        rankLabel->setText(QApplication::translate("Form", "Rank", 0));
        citizenCheckBox->setText(QApplication::translate("Form", "Citizen", 0));
        label_17->setText(QApplication::translate("Form", "Story Role", 0));
        roleLabel->setText(QApplication::translate("Form", "Role", 0));
        infoTabWidget->setTabText(infoTabWidget->indexOf(tabPerson), QApplication::translate("Form", "Person", 0));
        labelCurrentItem->setText(QApplication::translate("Form", "Current Item", 0));
        label_7->setText(QApplication::translate("Form", "Actions Do", 0));
        label_8->setText(QApplication::translate("Form", "Actions Get", 0));
        buttonItemAddDo->setText(QApplication::translate("Form", "Add Do", 0));
        buttonItemRemoveDo->setText(QApplication::translate("Form", "Remove Do", 0));
        buttonItemAddGet->setText(QApplication::translate("Form", "Add Get", 0));
        buttonItemRemoveGet->setText(QApplication::translate("Form", "Remove Get", 0));
        infoTabWidget->setTabText(infoTabWidget->indexOf(tabItem), QApplication::translate("Form", "Item", 0));
        labelLocationCurrent->setText(QApplication::translate("Form", "Current Location:", 0));
        label_9->setText(QApplication::translate("Form", "Possible Locations", 0));
        label_10->setText(QApplication::translate("Form", "Come From", 0));
        label_11->setText(QApplication::translate("Form", "Current People Here", 0));
        infoTabWidget->setTabText(infoTabWidget->indexOf(tabLocation), QApplication::translate("Form", "Location", 0));
        infoTabWidget->setTabText(infoTabWidget->indexOf(tabAction), QApplication::translate("Form", "Action", 0));
        buttonPersonInfo->setText(QApplication::translate("Form", "Person Info", 0));
        buttonActionInfo->setText(QApplication::translate("Form", "Action Info", 0));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab), QApplication::translate("Form", "World", 0));
        groupBox_2->setTitle(QApplication::translate("Form", "Goals", 0));
        numAttempts->setText(QApplication::translate("Form", "0", 0));
        maxAttempts->setText(QApplication::translate("Form", "0", 0));
        label_19->setText(QApplication::translate("Form", "Max Attempts", 0));
        refreshGoals->setText(QApplication::translate("Form", "Refresh Goals", 0));
        label_18->setText(QApplication::translate("Form", "Number of Attempts", 0));
        groupBox_3->setTitle(QApplication::translate("Form", "Stories", 0));
        refreshStories->setText(QApplication::translate("Form", "Refresh Stories", 0));
        loadGoals->setText(QApplication::translate("Form", "Load Goals", 0));
        loadStories->setText(QApplication::translate("Form", "Load Stories", 0));
        label_20->setText(QApplication::translate("Form", "These buttons reset the current stories and goals!", 0));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab_2), QApplication::translate("Form", "Stories and Goals", 0));
        groupBox_4->setTitle(QApplication::translate("Form", "Current Goals", 0));
        updateCurrentGoalsButton->setText(QApplication::translate("Form", "Update", 0));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab_3), QApplication::translate("Form", "Director", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
