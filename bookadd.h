/**
 * \class BookAdd
 *
 *
 * \brief BookAdd ba;
 *
 * This class can be accessible through the BookAdd window. The logged in
 * user can add new book through the window. Also,
 * it can return the login screen by clicking action menu.
 *
 * \author Ali Emre Çakmakoğlu - Ayberk Zeray
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2015/05/20 22:31:19 $
 *
 * Contact: bilgi@aliemre.co
 *
 * Created on: Wednesday May 22:31:19 2015
 *
 *
 */
#ifndef BOOKADD_H
#define BOOKADD_H

#include <QMainWindow>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class BookAdd;
}

class BookAdd : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookAdd(QWidget *parent = 0);
    ~BookAdd();

private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void on_actionLogout_triggered();
    void on_returnButton_clicked();

private:
    Ui::BookAdd *ui;
    QString databaseFile;
    QSqlDatabase *bookManagerDb;
    QSqlQuery *bookManagerQuery;
};

#endif // BOOKADD_H
