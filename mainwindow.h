#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<usrinfo.h>
#include<chatwindow.h>
#include<QString>
#include<QAction>
#include<QVBoxLayout>
#include<QToolBox>
#include<QLinkedList>
#include<QMap>
#include<udpserver.h>
#include<QPushButton>
#include<changeinfo.h>

class UsrInfo;
class UdpServer;
class ChatWindow;
class ChangeInfo;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    friend class UsrInfo;
    friend class ChatWindow;
    //explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(unsigned int id,QWidget *parent = 0);
    ~MainWindow();
    unsigned int getId();
    UdpServer*getUdpServer();
    UsrInfo*getUsrInfo();

private slots:
    void on_changeInfoButton_clicked();

private:
    Ui::MainWindow *ui;
    unsigned int id;
    UsrInfo*myInfo;
    QToolBox*friendsBox;
    void addFirends(unsigned int id);
    QMap<QString,QLinkedList<int>* >friends;//first:分组名,second:朋友id
    void initFriendsList();
    QMap<unsigned int,ChatWindow*>chatWindows;
    UdpServer*udpServer;
    QMap<unsigned int,UsrInfo*>infoMap;
    QPushButton*changeInfoButton;
};

#endif // MAINWINDOW_H
