#include "wifimanager.h"
#include "ui_wifimanager.h"
#include <QKeyEvent>
#include <QString>
#include <QProcess>
#include <QDebug>
#include <QModelIndexList>
#include <QTimer>
#include <QMap>
struct WifiNetwork{
    QString ssid;
    int signal;
    QString Bars;
    QString secuirity;
};
wifimanager::wifimanager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wifimanager)
{
    ui->setupUi(this);

    //ui->listView->setEnabled(true);
    model = new QStringListModel(this);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    scanTimer = new QTimer(this);
    connect(scanTimer, &QTimer::timeout, this, &wifimanager::on_refrech_clicked);
    //connect(ui->hidden, &QCheckBox::toggled,this,&wifimanager::on_addnet_clicked);
    ui->pass->setPlaceholderText("enter password");
    ui->pass->setVisible(false);
    ui->pass->setFocusPolicy(Qt::StrongFocus);
    ui->pass->setEchoMode(QLineEdit::Password);
    ui->showpass->setVisible(false);
    ui->showpass->setChecked(false);
    //ui->disconnect->setVisible(false);
    connect(ui->showpass, &QCheckBox::toggled, this, [this](bool checked) {
        ui->pass->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
    });
    //add network config
    connect(ui->pass, &QLineEdit::returnPressed,this,&wifimanager::on_connect_clicked);

    ui->pass2Line->setEchoMode(QLineEdit::Password);
     all = {ui->pass2,ui->pass2Line,ui->check2,ui->Eap,ui->Eaplabel,ui->idenityLine,ui->idenity};
    for(QWidget* w : all){
        w->setEnabled(false);
        w->setVisible(false);
    }
    connect(ui->check2, &QCheckBox::toggled, this, [this](bool checked) {
        ui->pass2Line->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
    });
    scaning = false;
    //addnet Enable status
    ui->addnet->setEnabled(false);
    connect(ui->ssid2,&QLineEdit::textChanged,this,[this](const QString &text){
         ui->addnet->setEnabled(!text.isEmpty());
    });
   //end addnet Enable status

    connect(ui->listSecurity, &QListWidget::itemSelectionChanged,this,[this](){
        QListWidgetItem* current = ui->listSecurity->currentItem();
        QList<QWidget*> widgets = {ui->pass2,ui->pass2Line,ui->check2};
        QList<QWidget*> notw = {ui->Eap,ui->Eaplabel,ui->idenityLine,ui->idenity};
        if(current->text() != "none" ){
            if(current->text() == "WPA/WPA2-Personal" || current->text() == "WPA3-Personal"){
                for( QWidget* w : widgets){
                    w->setVisible(true);
                     w->setEnabled(true);
                }
                for(QWidget* nw : notw){
                    nw->setVisible(false);
                    nw->setEnabled(false);
                }
            }else if(current->text() == "WPA/WPA2-Enterprise" || current->text() == "WPA3-Enterprise"){
                for(QWidget* tw : all){
                    tw->setVisible(true);
                    tw->setEnabled(true);

                }
            }
        }else{
            for(QWidget* tw : all){
                tw->setVisible(false);
                tw->setEnabled(false);
            }
        }


    });
    //end add network config
    }
wifimanager::~wifimanager()
{
    if(scanTimer) {scanTimer->stop();
    delete scanTimer;
    }
    delete ui;
}

QString signalToBars(int signalStrength) {
    if (signalStrength >= 75)
        return "▂▄▆█";  // full
    else if (signalStrength >= 50)
        return "▂▄▆";   // 3 bars
    else if (signalStrength >= 25)
        return "▂▄";    // 2 bars
    else if (signalStrength > 0)
        return "▂";     // 1 bar
    else
        return "";      // no signal
}
QList<WifiNetwork> getUniqueWifiNetworks()
{
    QProcess process;
    process.start("bash", QStringList() << "-c" << R"(
        nmcli -f SSID,SIGNAL,SECURITY device wifi list | awk 'NF && $1 != "--"' | sort -k2 -nr
    )");
    process.waitForFinished();

    QString output = process.readAllStandardOutput();
    QStringList something = output.split('\n', Qt::SkipEmptyParts);

    QMap<QString, WifiNetwork> uniqueNetworks;

    for (const QString& line : something) {
        QStringList parts = line.simplified().split(' ');
        if (parts.size() >= 3) {
            QString ssid = parts[0].trimmed();
            if (ssid.isEmpty() || ssid == "SSID" || ssid == "--")
                continue;
            bool ok;
            int signal = parts[1].toInt(&ok);
            if(!ok){
                continue;
            }
            QString Bars= signalToBars(signal);
            QString security = parts[2].trimmed();

            if (!uniqueNetworks.contains(ssid)) {
                uniqueNetworks[ssid] = { ssid, signal ,Bars, security };
            }
        }
    }

    return uniqueNetworks.values();
}
QStringList converter(QList<WifiNetwork>& ssids){
    QStringList ssidList;
    for (const WifiNetwork& net:ssids) {
        ssidList<<QString("%1 %2 - %3").arg(net.ssid.leftJustified(25)).arg(net.Bars.leftJustified(5)).arg(net.secuirity);
        //ssidList<<net.ssid;
    }
    return ssidList;
}
void wifimanager::on_refrech_clicked()
{
    // 🔸 Save current selected SSID before refreshing
    QString currentSsid;
    QModelIndex currentIndex = ui->listView->currentIndex();
    if (currentIndex.isValid()) {
        currentSsid = currentIndex.data().toString().split(' ').first().trimmed();
    }
    // 🔄 Refresh list
    QList<WifiNetwork> uniqueSSid = getUniqueWifiNetworks();
    QStringList newList = converter(uniqueSSid);
    model->setStringList(newList);
    ui->listView->setModel(model);
    // 🔁 Reselect previously selected SSID
    if (!currentSsid.isEmpty()) {
        for (int row = 0; row < model->rowCount(); ++row) {
            QString itemSsid = model->data(model->index(row)).toString().split(' ').first().trimmed();
            if (itemSsid == currentSsid) {
                ui->listView->setCurrentIndex(model->index(row));
                break;
            }
        }
    }
    // 📌 Keep selection listener connected
    connect(ui->listView->selectionModel(), &QItemSelectionModel::currentChanged,
            this, [this](const QModelIndex &current, const QModelIndex &) {
                qDebug() << "selected index changed to:" << current.data().toString();
                isforgetable();
            });

    if (!scanTimer->isActive()) {
        scanTimer->start(5000);
        scaning = true;
    }
}
bool wifimanager::checkIfSaved(const QString &ssid){
    QProcess process;
    process.start("nmcli", QStringList() << "connection" << "show");

    if (!process.waitForFinished()) {    //if(checkIfSaved(ssid)){
        //  process.start("nmcli",QStringList()<<"device"<<"wifi"<<"connect"<<ssid);
        //}
        qDebug() << "❌ nmcli process failed";
        return false;
    }
    QString output = process.readAllStandardOutput();
    // Each line in nmcli output
    QStringList lines = output.split('\n', Qt::SkipEmptyParts);

    // Skip the first line (it's a header)
    lines.removeFirst();

    // Check each line's first column (SSID)
    for (const QString &line : lines) {
        QString name = line.section(' ', 0, 0).trimmed(); // first word is SSID
        if (name == ssid.trimmed()) {
            return true; // found saved network
        }
    }
    return false;
}
void wifimanager::isforgetable(){
    QModelIndex index = ui->listView->currentIndex();
    if(!index.isValid()) {
        ui->forgot->setEnabled(false);
        return;
    }
    QString ssid = index.data().toString().split(' ').first().trimmed();
    ui->forgot->setEnabled(checkIfSaved(ssid));
}
void wifimanager::on_connect_clicked()
{
   // ui->pass->setVisible(true);
    //ui->statuslabel->setText("🔓 Password field should now be visible.");
    QModelIndex index = ui->listView->currentIndex();
    if(!index.isValid()) return;

    QModelIndex const last = index;
    //QString ssid=model->data(index,Qt::DisplayRole).toString().split(' ').first().;
    QString ssid = last.data().toString().split(' ').first().trimmed();
    if (awaitingPassword) {
        // This is the second click: user already saw the password field and typed it
        QString password = ui->pass->text().trimmed();
        if (password.isEmpty()) {
            ui->statuslabel->setText("🔐 Please enter password for " + ssid);
            return;
        }
        QProcess process;
        process.start("nmcli", QStringList() << "device" << "wifi" << "connect" << ssid << "password" << password);
        process.waitForFinished();

        QString error = process.readAllStandardError();
        if (process.exitCode() != 0) {
            ui->statuslabel->setText("❌ Failed to connect: " + error);
        } else {
            ui->statuslabel->setText("✅ Connected to " + ssid);
            QTimer::singleShot(5000, ui->statuslabel,[=](){
                ui->statuslabel->clear();
                ui->statuslabel->hide();
            });
            ui->pass->setVisible(false);
            ui->showpass->setVisible(false);
            awaitingPassword = false;
        }
        return;
    }
    // First click — check if it's saed
    bool ifsaved = checkIfSaved(ssid);
    if (ifsaved) {
        ui->pass->setVisible(false);
        QProcess process;
        process.start("nmcli", QStringList() << "device" << "wifi" << "connect" << ssid);
        process.waitForFinished();

        QString error = process.readAllStandardError();
        if (process.exitCode() != 0) {
            ui->statuslabel->setText("❌ Failed to connect: " + error);
        } else {
            ui->statuslabel->setText("✅ Connected to " + ssid);
            ui->showpass->setVisible(false);
            ui->showpass->setChecked(false);
        }
    } else {
        // First click on unsaved network → show pass field and wait
        ui->pass->clear();
        ui->pass->setVisible(true);
        ui->showpass->setVisible(true);
        ui->pass->setFocus();
        ui->statuslabel->setText("🔐 Enter password for " + ssid + " and click Connect again");
        awaitingPassword = true;
    }
}
void wifimanager::on_forgot_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    if(!index.isValid()) return;
    QString ssid = index.data().toString().split(' ').first().trimmed();
    QProcess process;
    process.start("nmcli",QStringList() << "connection" << "delete" << "id" << ssid);
    process.waitForFinished();

    QProcess *rescan = new QProcess(this);
    rescan->start("nmcli",{"device" , "wifi" ,"rescan" ,"hidden", "yes"} );
    rescan->waitForFinished();

    on_refrech_clicked();
}
void wifimanager::on_disconnect_clicked()
{
        QProcess process;
        process.start("nmcli", QStringList() << "device" << "disconnect"<<"wlan0");
        process.waitForFinished();
}
void wifimanager::on_addnet_clicked()
{   if(!ui->listSecurity->currentItem()){
        qDebug() << "No security method selected";
        return;
    }
    bool ishidden = ui->hiddenbox->checkState();
    QString ssid = ui->ssid2->text().trimmed();
    QString security = ui->listSecurity->currentItem()->text().trimmed();
    QString Eap ;
    if(ui->Eap->currentItem()){
        Eap = ui->Eap->currentItem()->text().trimmed();
    }
    QString password2 = ui->pass2Line->text().trimmed();
    QString idf = ui->idenityLine->text().trimmed();
    QProcess process;

    if(security == "none"){
        process.start("nmcli",QStringList() << "dev" << "wifi" << "connect" << ssid);
        process.waitForFinished();
        if(process.exitCode() != 0){
            qDebug() << "failed to connection !!" ;
        }
    }else if(security == "WPA/WPA2-Personal" || security == "WPA3-Personal"){
        QStringList cmd = {
            "connection" , "add" ,
            "type" , "wifi" ,
            "ifname" , "wlan0",
            "con-name" , ssid,
            "ssid" , ssid ,
            "wifi.mode","infrastructure",
            "wifi-sec.key-mgmt" , (security == "WPA3-Personal" ? "sae" : "wpa-psk"),
            "wifi-sec.psk" , password2
    };
        if(ishidden){
            cmd <<"wifi.hidden" << "yes";
        }
        process.start("nmcli",cmd);
        process.waitForFinished();
        if(process.exitCode() != 0){
            qDebug() << "failed to add to personal secured  Network !! ";
        }else{
            ui->addstatus->setText("the Network had been succesfully added to the list");
           if (!ui->addstatus) {
                qDebug() << "addstatus is nullptr!";
            }
            qDebug() << "trying to set message on label" << ui->addstatus ;

            QTimer::singleShot(5000, ui->addstatus,[=](){
                ui->addstatus->clear();
                ui->addstatus->hide();
                for (QWidget *x : all) {
                    if(auto lineedit = qobject_cast<QLineEdit *>(x)){lineedit->clear(); }
                    else if (auto checkbox = qobject_cast<QCheckBox *>(x)){checkbox->setChecked(false);}
                    else if(auto list = qobject_cast<QListWidget *>(x)){list->clearSelection();}
                }
                ui->ssid2->clear();
            });
        }
    }
    else{
        if(Eap.isEmpty() || idf.isEmpty() || password2.isEmpty() ){
            qDebug() << "Missing EAP credentials.";
        }
     QStringList args = {
            "connection", "add",
            "type", "wifi",
            "ifname" , "wlan0",
            "con-name my_wifi",
            "ssid", ssid,
            "wifi.mode","infrastructure",
            "wifi-sec.key-mgmt", "wpa-eap",
            "802-1x.eap", Eap ,
            "802-1x.identity", idf ,
            "802-1x.password", password2
        };
        process.start("nmcli", args );
        process.waitForFinished();
     }
}
