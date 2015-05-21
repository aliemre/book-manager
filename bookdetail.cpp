#include "bookdetail.h"
#include "ui_bookdetail.h"
#include "mainwindow.h"
#include "booklist.h"
#include "database.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>

BookDetail::BookDetail(QWidget *parent, QString bookId) : QMainWindow(parent), ui(new Ui::BookDetail)
{
    this->bookId = bookId;

    ui->setupUi(this);
    this->setWindowTitle("Detail | Book Manager");

    // INIT DATABASE
    bookManagerDb = Database::connection();
    bookManagerQuery = new QSqlQuery(*bookManagerDb);

    // FIND A BOOK
    QSqlQuery find("SELECT * FROM Books WHERE id = '"+bookId+"'");

    while(find.next()) {
        ui->fieldName->setText(find.value(1).toString());
        ui->fieldAuthor->setText(find.value(2).toString());
        ui->fieldPagesNumber->setText(find.value(3).toString());
        ui->fieldDescription->setText(find.value(4).toString());
        ui->fieldLanguage->setText(find.value(5).toString());
        ui->fieldISBN->setText(find.value(6).toString());
        ui->fieldSize->setText(find.value(7).toString());
        ui->fieldPublishedAt->setText(find.value(8).toString());
        ui->fieldPublishedOn->setText(find.value(9).toString());
    }
}

BookDetail::~BookDetail()
{
    delete ui;
}

void BookDetail::on_actionLogout_triggered()
{
    this->hide();

    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
}

void BookDetail::on_cancelButton_clicked()
{
    this->hide();

    BookList *bookList = new BookList;
    bookList->show();
}

void BookDetail::on_deleteButton_clicked()
{
    QMessageBox msgBox;

    QPushButton *abortButton = msgBox.addButton(QMessageBox::Abort);
    QPushButton *connectButton = msgBox.addButton(tr("Delete"), QMessageBox::ActionRole);

    msgBox.setText("Are you sure?");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.exec();

    if (msgBox.clickedButton() == connectButton) {
        bookManagerQuery->prepare("DELETE FROM Books WHERE id = '"+this->bookId+"'");
        bookManagerQuery->exec();

        this->hide();
        BookList *bookList = new BookList;
        bookList->show();
    }
}

void BookDetail::on_saveButton_clicked()
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

    bookManagerQuery->prepare("UPDATE Books SET "
                              "name = '"+name+"', author = '"+author+"', pageNumber = '"+pageNumber+"', description = '"+description+"', "
                              "language = '"+language+"', isbnNumber = '"+isbnNumber+"', sizes = '"+sizes+"', publishedAt = '"+publishedAt+"', publishedOn = '"+publishedOn+"' "
                              "WHERE id = '"+this->bookId+"'");
    bookManagerQuery->exec();

    ui->labelActionStatus->setText("The book successfully updated!");
    ui->labelActionStatus->setStyleSheet("color: green;");
}
