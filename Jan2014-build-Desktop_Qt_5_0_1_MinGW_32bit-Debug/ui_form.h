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
    QGroupBox *groupBox_3;
    QListWidget *listStories;
    QPushButton *refreshStories;
    QTextBrowser *stortTextBrowser;
    QPushButton *loadStories;
    QLabel *label_25;
    QLabel *label_26;
    QTextBrowser *textBrowser_2;
    QWidget *tab_3;
    QGroupBox *groupBox_4;
    QListWidget *currentGoalsList;
    QPushButton *updateCurrentGoalsButton;
    QGroupBox *groupBox_5;
    QListWidget *currentStoriesList;
    QPushButton *updateCurrentStoriesButton;
    QListWidget *currentTriggerStoriesList;
    QLabel *label_21;
    QLabel *label_22;
    QListWidget *currentActiveStory;
    QLabel *label_24;
    QTextBrowser *textBrowser;
    QPushButton *completeStory;
    QPushButton *runDirectorLoop;
    QListWidget *currentStoryInfo;
    QLabel *label_23;
    QWidget *tab_4;
    QListWidget *outputText;

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
        groupBox->setGeometry(QRect(10, 240, 391, 141));
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
        label_17 = new QLabel(tabPerson);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 200, 61, 16));
        roleLabel = new QLabel(tabPerson);
        roleLabel->setObjectName(QStringLiteral("roleLabel"));
        roleLabel->setGeometry(QRect(130, 200, 71, 16));
        storyRole = new QSpinBox(tabPerson);
        storyRole->setObjectName(QStringLiteral("storyRole"));
        storyRole->setGeometry(QRect(80, 200, 42, 22));
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
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 30, 601, 251));
        listStories = new QListWidget(groupBox_3);
        listStories->setObjectName(QStringLiteral("listStories"));
        listStories->setGeometry(QRect(20, 70, 151, 161));
        refreshStories = new QPushButton(groupBox_3);
        refreshStories->setObjectName(QStringLiteral("refreshStories"));
        refreshStories->setGeometry(QRect(120, 20, 101, 23));
        stortTextBrowser = new QTextBrowser(groupBox_3);
        stortTextBrowser->setObjectName(QStringLiteral("stortTextBrowser"));
        stortTextBrowser->setGeometry(QRect(310, 40, 281, 201));
        loadStories = new QPushButton(groupBox_3);
        loadStories->setObjectName(QStringLiteral("loadStories"));
        loadStories->setGeometry(QRect(20, 20, 91, 23));
        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(320, 20, 111, 16));
        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(40, 50, 121, 16));
        textBrowser_2 = new QTextBrowser(tab_2);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setEnabled(false);
        textBrowser_2->setGeometry(QRect(40, 310, 271, 81));
        mainTabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 30, 581, 171));
        currentGoalsList = new QListWidget(groupBox_4);
        currentGoalsList->setObjectName(QStringLiteral("currentGoalsList"));
        currentGoalsList->setGeometry(QRect(20, 30, 391, 121));
        updateCurrentGoalsButton = new QPushButton(groupBox_4);
        updateCurrentGoalsButton->setObjectName(QStringLiteral("updateCurrentGoalsButton"));
        updateCurrentGoalsButton->setGeometry(QRect(440, 30, 75, 23));
        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(30, 220, 581, 241));
        currentStoriesList = new QListWidget(groupBox_5);
        currentStoriesList->setObjectName(QStringLiteral("currentStoriesList"));
        currentStoriesList->setGeometry(QRect(20, 40, 151, 161));
        updateCurrentStoriesButton = new QPushButton(groupBox_5);
        updateCurrentStoriesButton->setObjectName(QStringLiteral("updateCurrentStoriesButton"));
        updateCurrentStoriesButton->setGeometry(QRect(50, 210, 75, 23));
        currentTriggerStoriesList = new QListWidget(groupBox_5);
        currentTriggerStoriesList->setObjectName(QStringLiteral("currentTriggerStoriesList"));
        currentTriggerStoriesList->setGeometry(QRect(210, 40, 151, 161));
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(60, 20, 71, 16));
        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(250, 20, 81, 16));
        currentActiveStory = new QListWidget(groupBox_5);
        currentActiveStory->setObjectName(QStringLiteral("currentActiveStory"));
        currentActiveStory->setGeometry(QRect(390, 40, 151, 31));
        label_24 = new QLabel(groupBox_5);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(410, 20, 111, 16));
        textBrowser = new QTextBrowser(groupBox_5);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setEnabled(false);
        textBrowser->setGeometry(QRect(390, 80, 151, 101));
        completeStory = new QPushButton(groupBox_5);
        completeStory->setObjectName(QStringLiteral("completeStory"));
        completeStory->setGeometry(QRect(420, 190, 91, 23));
        runDirectorLoop = new QPushButton(tab_3);
        runDirectorLoop->setObjectName(QStringLiteral("runDirectorLoop"));
        runDirectorLoop->setGeometry(QRect(530, 510, 101, 23));
        currentStoryInfo = new QListWidget(tab_3);
        currentStoryInfo->setObjectName(QStringLiteral("currentStoryInfo"));
        currentStoryInfo->setGeometry(QRect(50, 490, 431, 171));
        currentStoryInfo->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        label_23 = new QLabel(tab_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(70, 470, 111, 16));
        mainTabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        outputText = new QListWidget(tab_4);
        outputText->setObjectName(QStringLiteral("outputText"));
        outputText->setGeometry(QRect(50, 50, 571, 311));
        mainTabWidget->addTab(tab_4, QString());

        retranslateUi(Form);

        mainTabWidget->setCurrentIndex(0);
        infoTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
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
        groupBox_3->setTitle(QApplication::translate("Form", "Plot Fragments", 0));
        refreshStories->setText(QApplication::translate("Form", "Refresh Fragments", 0));
        loadStories->setText(QApplication::translate("Form", "Load Fragments", 0));
        label_25->setText(QApplication::translate("Form", "Selected Plot Info", 0));
        label_26->setText(QApplication::translate("Form", "Loaded Plot Fragments", 0));
        textBrowser_2->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">This tab is used to load all plot fragments from file using the &quot;Load Fragments&quot; button. They will be displayed in the left list. From there, double clicking a fragments will add it as an Author level plot fragment. The right list will display the plot fragment information.</span></p></body></html>", 0));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab_2), QApplication::translate("Form", "Plot Fragments", 0));
        groupBox_4->setTitle(QApplication::translate("Form", "Current Goals List", 0));
        updateCurrentGoalsButton->setText(QApplication::translate("Form", "Update", 0));
        groupBox_5->setTitle(QApplication::translate("Form", "Current Plot Lists", 0));
        updateCurrentStoriesButton->setText(QApplication::translate("Form", "Update", 0));
        label_21->setText(QApplication::translate("Form", "Active Plot List", 0));
        label_22->setText(QApplication::translate("Form", "Trigger Plot List", 0));
        label_24->setText(QApplication::translate("Form", "Current Active Plot", 0));
        textBrowser->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">If a plot is currently active then go to the world tab and act out the plot fragment. Once all changes have been made click &quot;Complete Plot&quot; button.</span></p></body></html>", 0));
        completeStory->setText(QApplication::translate("Form", "Complete Plot", 0));
        runDirectorLoop->setText(QApplication::translate("Form", "Run Director Loop", 0));
        label_23->setText(QApplication::translate("Form", "Selected Plot Info", 0));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab_3), QApplication::translate("Form", "Director", 0));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tab_4), QApplication::translate("Form", "Output", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
