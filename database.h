/**
 * \class Database
 *
 *
 * \brief Database db;
 *
 * This class can be accessible through the each window.
 * It enables to application to create database connection.
 * Also, main feature of the class is that the main database file
 * will be created automatically.
 *
 * \author Ali Emre Çakmakoğlu - Ayberk Zeray
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2015/05/20 22:23:19 $
 *
 * Contact: bilgi@aliemre.co
 *
 * Created on: Wednesday May 22:23:19 2015
 *
 *
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlError>
#include <QString>
#include <QSqlDatabase>
#include <QCoreApplication>

class Database
{
    Q_DECLARE_TR_FUNCTIONS(Database)
private:
    static QString _dbFile;
    static Database *_instance;
    Database(const QString &dbFile = QString());
    QSqlDatabase db;

public:
    static void init(const QString &dbFile);
    static void close();
    static Database *instance() { return _instance; }
    static const QString &dbFile() { return _dbFile; }
    static QSqlDatabase *connection() { return &_instance->db; }
    //static const QSqlError &lastError() { return _instance->_connection.lastError(); }
};

#endif // DATABASE_H
