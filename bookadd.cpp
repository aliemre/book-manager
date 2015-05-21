#include "bookadd.h"
#include "ui_bookadd.h"
#include "mainwindow.h"
#include "booklist.h"
#include "database.h"
#include <QDir>
#include <QMessageBox>
#include <QLabel>
#include <QDebug>
#include <QByteArray>
#include <QTextCodec>
#include <QPixmap>
#include <QObject>

BookAdd::BookAdd(QWidget *parent) : QMainWindow(parent), ui(new Ui::BookAdd)
{
    ui->setupUi(this);
    this->setWindowTitle("Add | Book Manager");

    // INIT DATABASE
    bookManagerDb = Database::connection();
    bookManagerQuery = new QSqlQuery(*bookManagerDb);
}

BookAdd::~BookAdd()
{
    delete ui;
}

void BookAdd::on_saveButton_clicked()
{
    QString name, author, pageNumber, description, language, isbnNumber, sizes, publishedAt, publishedOn;

    name = ui->fieldName->text();
    author = ui->fieldAuthor->text();
    pageNumber = ui->fieldPagesNumber->text();
    description = ui->fieldDescription->toPlainText();
    language = ui->fieldLanguage->text();
    isbnNumber = ui->fieldISBN->text();
    sizes = ui->fieldSize->text();
    publishedAt = ui->fieldPublishedAt->text();
    publishedOn = ui->fieldPublishedOn->text();

    bookManagerQuery->prepare("INSERT INTO Books VALUES(NULL, '"+name+"', '"+author+"', '"+pageNumber+"', '"+description+"', '"+language+"', '"+isbnNumber+"', '"+sizes+"', '"+publishedAt+"', '"+publishedOn+"');");
    bookManagerQuery->exec();

    ui->labelActionStatus->setText("The book successfully added!");
    ui->labelActionStatus->setStyleSheet("color: green;");
}

void BookAdd::on_cancelButton_clicked()
{
    this->hide();

    BookList *bookList = new BookList;
    bookList->show();
}

void BookAdd::on_actionLogout_triggered()
{
    this->hide();

    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
}

void BookAdd::on_returnButton_clicked()
{
    this->hide();

    BookList *bookList = new BookList;
    bookList->show();
}
