/**
 * \class BookList
 *
 *
 * \brief BookList bl;
 *
 * This class can be accessible through the BookList window. All data
 * which have been added to Books database, listed in TableView widget.
 * Also, it can return the login screen by clicking action menu.
 *
 * \author Ali Emre Çakmakoğlu - Ayberk Zeray
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2015/05/20 22:27:19 $
 *
 * Contact: bilgi@aliemre.co
 *
 * Created on: Wednesday May 22:27:19 2015
 *
 *
 */
#ifndef BOOKLIST_H
#define BOOKLIST_H

#include <QMainWindow>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QModelIndex>

namespace Ui {
class BookList;
}

class BookList : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookList(QWidget *parent = 0);
    ~BookList();

private slots:
    void on_actionLogout_triggered();
    void on_addBookButton_clicked();
    void on_bookListTableView_activated(const QModelIndex &index);

private:
    Ui::BookList *ui;
    QString databaseFile;
    QSqlDatabase *bookManagerDb;
    QSqlQuery *bookManagerQuery;
};

#endif // BOOKLIST_H
