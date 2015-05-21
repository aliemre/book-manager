/**
 * \class BookDetail
 *
 *
 * \brief BookDetail bd;
 *
 * This class can be accessible through the BookDetail window. The logged in
 * user can show, update and remove the book through the window. Also,
 * it can return the login screen by clicking action menu.
 *
 * \author Ali Emre Çakmakoğlu - Ayberk Zeray
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2015/05/20 22:22:19 $
 *
 * Contact: bilgi@aliemre.co
 *
 * Created on: Wednesday May 22:22:19 2015
 *
 *
 */
#ifndef BOOKDETAIL_H
#define BOOKDETAIL_H

#include <QMainWindow>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class BookDetail;
}

class BookDetail : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookDetail(QWidget *parent = 0);
    explicit BookDetail(QWidget *parent = 0, QString bookId = 0);
    ~BookDetail();

private slots:
    void on_actionLogout_triggered();
    void on_cancelButton_clicked();
    void on_deleteButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::BookDetail *ui;
    QString databaseFile;
    QSqlDatabase *bookManagerDb;
    QSqlQuery *bookManagerQuery;
    QString bookId;
};

#endif // BOOKDETAIL_H
