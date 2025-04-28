#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <QMainWindow>
#include <QStringListModel>
#include <QListView>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class wifimanager;
}
QT_END_NAMESPACE

class wifimanager : public QMainWindow
{
    Q_OBJECT

public:
    wifimanager(QWidget *parent = nullptr);
    ~wifimanager();

private slots:
    void on_refrech_clicked();

   void on_connect_clicked();
    void on_forgot_clicked();
   void on_disconnect_clicked();
   //void on_add_clicked();

   void on_addnet_clicked();

   private:
  bool checkIfSaved(const QString &ssid);
  void isforgetable();
private:
    Ui::wifimanager *ui;
    QStringListModel *model;
    QTimer *scanTimer;
    QList<QWidget*> all;
    bool scaning = false;
    bool awaitingPassword = false;
    //QListView *listview;
};
#endif // WIFIMANAGER_H
