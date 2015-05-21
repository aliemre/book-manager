/**
 * \class MainWindow
 *
 *
 * \brief MainWindow w;
 *
 * This class can be accessible through the LoginWindow. If the
 * username and password fields are correct then the user can
 * add, remove and update data using the proper ui fields.
 *
 * Also, main tables Users and Books created in that window.
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include "booklist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonLogin_clicked();
    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    QString databaseFile;
    QSqlDatabase *bookManagerDb;
    QSqlQuery *bookManagerQuery;
    QCryptographicHash *hash;
};

#endif // MAINWINDOW_H
