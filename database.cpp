#include "database.h"
#include <QMessageBox>
#include <QDebug>

QString Database::_dbFile;
Database *Database::_instance = 0;

void Database::init(const QString &dbFile) {
    _instance = new Database(dbFile);
}

Database::Database(const QString &dbFile) {

    qDebug() << dbFile;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFile);

    if (!db.open()) {
        QMessageBox msg;
        msg.setText(tr("Could not connect the database."));
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
    }

}

void Database::close() {
    if (!_instance) {
        return;
    }

    _instance->db.close();
    delete _instance;
    _instance = 0;
}
