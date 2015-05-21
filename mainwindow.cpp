#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QDir>
#include <QMessageBox>
#include <QLabel>
#include <QDebug>
#include <QByteArray>
#include <QTextCodec>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Login | Book Manager");

    // INIT DATABASE
    databaseFile = QDir::currentPath() + QDir::separator() + "bookmanager.db";
    Database::init(databaseFile);

    bookManagerDb = Database::connection();
    bookManagerQuery = new QSqlQuery(*bookManagerDb);

    QString dbStatus;

    if (bookManagerDb->open()) {
        dbStatus = "DB connection established.";
    } else {
        dbStatus = "DB connection error!";
    }

    ui->statusBar->showMessage(dbStatus);

    // TRUNCATE TABLE
    //bookManagerQuery->exec("DROP TABLE Users");

    // CREATE TABLES
    bookManagerQuery->exec("CREATE TABLE IF NOT EXISTS Users "
                           "(id INTEGER PRIMARY KEY, "
                           "username VARCHAR(100), "
                           "password VARCHAR(100), "
                           "firstName VARCHAR(100), "
                           "lastName VARCHAR(100))");

    bookManagerQuery->exec("CREATE TABLE IF NOT EXISTS Books "
                           "(id INTEGER PRIMARY KEY, "
                           "name VARCHAR(200), "
                           "author VARCHAR(200), "
                           "pageNumber VARCHAR(100), "
                           "description TEXT ,"
                           "language VARCHAR(50) ,"
                           "isbnNumber VARCHAR(100) ,"
                           "sizes VARCHAR(100),"
                           "publishedAt VARCHAR(100),"
                           "publishedOn DATETIME)");

    // INSERT ADMIN
    QString adminPassword = "12345";
    QByteArray hashedAdminPassword = hash->hash(adminPassword.toAscii(), QCryptographicHash::Md5);

    bookManagerQuery->prepare(QObject::trUtf8("INSERT OR IGNORE INTO Users VALUES(1, 'admin', '" + hashedAdminPassword.toHex() + "', 'Ali Emre', 'Çakmakoğlu')"));
    bookManagerQuery->exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLogin_clicked()
{
    QByteArray result = hash->hash(ui->lineEditPassword->text().toAscii(), QCryptographicHash::Md5);

    QString hashedPassword = result.toHex();
    QString username = ui->lineEditUsername->text();

    int count = 0;

    QSqlQuery find("SELECT * FROM users WHERE username = '" + username + "' AND password = '"+ hashedPassword + "'");

    while (find.next()) {
        ++count;
    }

    if (count) {
        ui->labelLoginMessage->setText("You have been logged in.");
        ui->labelLoginMessage->setStyleSheet("color: green;");

        this->hide();

        BookList *booklist = new BookList;
        booklist->show();

    } else {
        ui->labelLoginMessage->setText("Check your credentials!");
        ui->labelLoginMessage->setStyleSheet("color: red");
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, QString::fromUtf8("About"), QString::fromUtf8("Ali Emre Çakmakoğlu & Ayberk Zeray \nQT Project 2015"));
}
