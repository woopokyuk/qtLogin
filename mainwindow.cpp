#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Login Test");
    qDebug() << QSqlDatabase::drivers();
    ui->passwdLineEdit->setEchoMode(QLineEdit::Password);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("0000");
    db.setDatabaseName("neuralinfo");
    db.open();
    if (!db.open()) {
        qDebug() << "db not open";
        return;
    }
    QSqlQuery query = (QSqlQuery) db;
    QString userName = ui->userLineEdit->text();
    QString sqlLine = "SELECT " + userName + " FROM users";
    qDebug() << query.exec(sqlLine);
}

MainWindow::~MainWindow()
{
    delete ui;
}

