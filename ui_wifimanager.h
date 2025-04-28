/********************************************************************************
** Form generated from reading UI file 'wifimanager.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIFIMANAGER_H
#define UI_WIFIMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wifimanager
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListView *listView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *refrech;
    QPushButton *connect;
    QPushButton *disconnect;
    QPushButton *forgot;
    QLineEdit *pass;
    QLabel *statuslabel;
    QCheckBox *showpass;
    QWidget *tab_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ssid2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Security;
    QListWidget *listSecurity;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *pass2;
    QLineEdit *pass2Line;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Eaplabel;
    QListWidget *Eap;
    QCheckBox *check2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *idenity;
    QLineEdit *idenityLine;
    QPushButton *addnet;
    QLabel *addstatus;
    QCheckBox *hiddenbox;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLabel *label_6;
    QToolBar *toolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *wifimanager)
    {
        if (wifimanager->objectName().isEmpty())
            wifimanager->setObjectName(QString::fromUtf8("wifimanager"));
        wifimanager->setWindowModality(Qt::WindowModality::NonModal);
        wifimanager->setEnabled(true);
        wifimanager->resize(1293, 614);
        wifimanager->setTabletTracking(false);
        wifimanager->setDocumentMode(false);
        wifimanager->setDockNestingEnabled(false);
        centralwidget = new QWidget(wifimanager);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(50, 20, 1171, 561));
        QFont font;
        font.setPointSize(12);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        listView = new QListView(tab);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(27, 30, 491, 200));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(580, 20, 160, 195));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        refrech = new QPushButton(verticalLayoutWidget);
        refrech->setObjectName(QString::fromUtf8("refrech"));
        refrech->setEnabled(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Downloads/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        refrech->setIcon(icon);

        verticalLayout->addWidget(refrech);

        connect = new QPushButton(verticalLayoutWidget);
        connect->setObjectName(QString::fromUtf8("connect"));

        verticalLayout->addWidget(connect);

        disconnect = new QPushButton(verticalLayoutWidget);
        disconnect->setObjectName(QString::fromUtf8("disconnect"));

        verticalLayout->addWidget(disconnect);

        forgot = new QPushButton(verticalLayoutWidget);
        forgot->setObjectName(QString::fromUtf8("forgot"));

        verticalLayout->addWidget(forgot);

        pass = new QLineEdit(tab);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(580, 220, 251, 25));
        pass->setEchoMode(QLineEdit::EchoMode::Password);
        statuslabel = new QLabel(tab);
        statuslabel->setObjectName(QString::fromUtf8("statuslabel"));
        statuslabel->setGeometry(QRect(20, 340, 991, 61));
        QFont font1;
        font1.setPointSize(20);
        statuslabel->setFont(font1);
        showpass = new QCheckBox(tab);
        showpass->setObjectName(QString::fromUtf8("showpass"));
        showpass->setEnabled(true);
        showpass->setGeometry(QRect(840, 220, 281, 23));
        showpass->setChecked(false);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayoutWidget = new QWidget(tab_2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 20, 391, 35));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        ssid2 = new QLineEdit(horizontalLayoutWidget);
        ssid2->setObjectName(QString::fromUtf8("ssid2"));
        ssid2->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(ssid2);

        horizontalLayoutWidget_2 = new QWidget(tab_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(60, 50, 391, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Security = new QLabel(horizontalLayoutWidget_2);
        Security->setObjectName(QString::fromUtf8("Security"));

        horizontalLayout_2->addWidget(Security);

        listSecurity = new QListWidget(horizontalLayoutWidget_2);
        new QListWidgetItem(listSecurity);
        new QListWidgetItem(listSecurity);
        new QListWidgetItem(listSecurity);
        new QListWidgetItem(listSecurity);
        new QListWidgetItem(listSecurity);
        listSecurity->setObjectName(QString::fromUtf8("listSecurity"));
        listSecurity->setEnabled(true);
        listSecurity->setMaximumSize(QSize(16777215, 23));
        listSecurity->setMovement(QListView::Movement::Static);
        listSecurity->setProperty("isWrapping", QVariant(false));
        listSecurity->setResizeMode(QListView::ResizeMode::Fixed);
        listSecurity->setLayoutMode(QListView::LayoutMode::SinglePass);
        listSecurity->setViewMode(QListView::ViewMode::ListMode);
        listSecurity->setSelectionRectVisible(true);
        listSecurity->setSortingEnabled(false);

        horizontalLayout_2->addWidget(listSecurity);

        horizontalLayoutWidget_3 = new QWidget(tab_2);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(59, 90, 391, 35));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pass2 = new QLabel(horizontalLayoutWidget_3);
        pass2->setObjectName(QString::fromUtf8("pass2"));

        horizontalLayout_3->addWidget(pass2);

        pass2Line = new QLineEdit(horizontalLayoutWidget_3);
        pass2Line->setObjectName(QString::fromUtf8("pass2Line"));
        pass2Line->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_3->addWidget(pass2Line);

        horizontalLayoutWidget_4 = new QWidget(tab_2);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(60, 120, 391, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Eaplabel = new QLabel(horizontalLayoutWidget_4);
        Eaplabel->setObjectName(QString::fromUtf8("Eaplabel"));

        horizontalLayout_4->addWidget(Eaplabel);

        Eap = new QListWidget(horizontalLayoutWidget_4);
        new QListWidgetItem(Eap);
        new QListWidgetItem(Eap);
        new QListWidgetItem(Eap);
        Eap->setObjectName(QString::fromUtf8("Eap"));
        Eap->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_4->addWidget(Eap);

        check2 = new QCheckBox(tab_2);
        check2->setObjectName(QString::fromUtf8("check2"));
        check2->setGeometry(QRect(470, 100, 241, 16));
        horizontalLayoutWidget_5 = new QWidget(tab_2);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(60, 160, 391, 43));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        idenity = new QLabel(horizontalLayoutWidget_5);
        idenity->setObjectName(QString::fromUtf8("idenity"));

        horizontalLayout_5->addWidget(idenity);

        idenityLine = new QLineEdit(horizontalLayoutWidget_5);
        idenityLine->setObjectName(QString::fromUtf8("idenityLine"));

        horizontalLayout_5->addWidget(idenityLine);

        addnet = new QPushButton(tab_2);
        addnet->setObjectName(QString::fromUtf8("addnet"));
        addnet->setGeometry(QRect(710, 390, 171, 25));
        addstatus = new QLabel(tab_2);
        addstatus->setObjectName(QString::fromUtf8("addstatus"));
        addstatus->setGeometry(QRect(70, 270, 621, 161));
        hiddenbox = new QCheckBox(tab_2);
        hiddenbox->setObjectName(QString::fromUtf8("hiddenbox"));
        hiddenbox->setGeometry(QRect(480, 30, 82, 21));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayoutWidget_2 = new QWidget(tab_3);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(40, 80, 1001, 191));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        horizontalLayoutWidget_6 = new QWidget(tab_3);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(39, 0, 1001, 80));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Source Code Pro Medium"));
        font2.setPointSize(20);
        font2.setBold(true);
        label_2->setFont(font2);

        horizontalLayout_6->addWidget(label_2);

        label_6 = new QLabel(horizontalLayoutWidget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        tabWidget->addTab(tab_3, QString());
        wifimanager->setCentralWidget(centralwidget);
        toolBar = new QToolBar(wifimanager);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        wifimanager->addToolBar(Qt::LeftToolBarArea, toolBar);
        statusbar = new QStatusBar(wifimanager);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        wifimanager->setStatusBar(statusbar);

        retranslateUi(wifimanager);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(wifimanager);
    } // setupUi

    void retranslateUi(QMainWindow *wifimanager)
    {
        wifimanager->setWindowTitle(QCoreApplication::translate("wifimanager", "wifimanager", nullptr));
        refrech->setText(QCoreApplication::translate("wifimanager", "scan", nullptr));
        connect->setText(QCoreApplication::translate("wifimanager", "connect", nullptr));
        disconnect->setText(QCoreApplication::translate("wifimanager", "Disconnect", nullptr));
        forgot->setText(QCoreApplication::translate("wifimanager", "forget", nullptr));
        pass->setPlaceholderText(QCoreApplication::translate("wifimanager", "Enter password", nullptr));
        statuslabel->setText(QString());
        showpass->setText(QCoreApplication::translate("wifimanager", "show password", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("wifimanager", "WIFI menu", nullptr));
        label->setText(QCoreApplication::translate("wifimanager", "SSID:", nullptr));
        ssid2->setPlaceholderText(QCoreApplication::translate("wifimanager", "Enter Network name", nullptr));
        Security->setText(QCoreApplication::translate("wifimanager", "Security:", nullptr));

        const bool __sortingEnabled = listSecurity->isSortingEnabled();
        listSecurity->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listSecurity->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("wifimanager", "none", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listSecurity->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("wifimanager", "WPA/WPA2-Personal", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listSecurity->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("wifimanager", "WPA3-Personal", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listSecurity->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("wifimanager", "WPA/WPA2-Enterprise", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listSecurity->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("wifimanager", "WPA3-Enterprise", nullptr));
        listSecurity->setSortingEnabled(__sortingEnabled);

        pass2->setText(QCoreApplication::translate("wifimanager", "password", nullptr));
        pass2Line->setPlaceholderText(QCoreApplication::translate("wifimanager", "Enter password", nullptr));
        Eaplabel->setText(QCoreApplication::translate("wifimanager", "EAP method:", nullptr));

        const bool __sortingEnabled1 = Eap->isSortingEnabled();
        Eap->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem5 = Eap->item(0);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("wifimanager", "PEAP", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = Eap->item(1);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("wifimanager", "TTLS", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = Eap->item(2);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("wifimanager", "TLS", nullptr));
        Eap->setSortingEnabled(__sortingEnabled1);

        check2->setText(QCoreApplication::translate("wifimanager", "show password", nullptr));
        idenity->setText(QCoreApplication::translate("wifimanager", "identity:", nullptr));
        addnet->setText(QCoreApplication::translate("wifimanager", "Add Network", nullptr));
        addstatus->setText(QString());
        hiddenbox->setText(QCoreApplication::translate("wifimanager", "hidden", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("wifimanager", "add Wifi", nullptr));
        label_3->setText(QCoreApplication::translate("wifimanager", "Designed by : Zaid benkhaira    ", nullptr));
        label_4->setText(QCoreApplication::translate("wifimanager", "Coded By Oualid & Zaid Benkhaira", nullptr));
        label_5->setText(QCoreApplication::translate("wifimanager", "Optimized By : Marouane Drioueche", nullptr));
        label_2->setText(QCoreApplication::translate("wifimanager", "WifiManager version : 1.0 (BETA)!!", nullptr));
        label_6->setText(QCoreApplication::translate("wifimanager", "               Welcome to Wifi_Manger nmcli based", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("wifimanager", "About us", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("wifimanager", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wifimanager: public Ui_wifimanager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIFIMANAGER_H
