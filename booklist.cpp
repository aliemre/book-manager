#include "booklist.h"
#include "ui_booklist.h"
#include "mainwindow.h"
#include "bookadd.h"
#include "bookdetail.h"
#include "database.h"

#include <QSqlQueryModel>
#include <QDir>
#include <QMessageBox>
#include <QLabel>
#include <QDebug>
#include <QWidget>

BookList::BookList(QWidget *parent) : QMainWindow(parent), ui(new Ui::BookList)
{
    ui->setupUi(this);
    this->setWindowTitle("List | Book Manager");

    // INIT DATABASE
    bookManagerDb = Database::connection();
    bookManagerQuery = new QSqlQuery(*bookManagerDb);

    // LOAD BOOKS
    QSqlQueryModel *queryModel = new QSqlQueryModel;

    bookManagerQuery->prepare("SELECT * FROM Books");
    bookManagerQuery->exec();

    queryModel->setQuery(*bookManagerQuery);

    ui->bookListTableView->setModel(queryModel);

}

BookList::~BookList()
{
    delete ui;
}

void BookList::on_actionLogout_triggered()
{
    this->hide();

    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
}

void BookList::on_addBookButton_clicked()
{
    this->hide();

    BookAdd *bookAdd = new BookAdd;
    bookAdd->show();
}

void BookList::on_bookListTableView_activated(const QModelIndex &index)
{
    QString tableValue = ui->bookListTableView->model()->data(index).toString();

    this->hide();

    QWidget *parent = 0;

    BookDetail *bookDetail = new BookDetail(parent, tableValue);
    bookDetail->show();
}
