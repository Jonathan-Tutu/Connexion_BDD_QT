//--------------------------------
// Programme de test
// Accès à une base via ODBC sur QT
// (jP) version 1.0 - 04/06/2020
//--------------------------------
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

// Point d'entrée de l'application
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Chaîne de connexion
    // Serveur OVH (situé à Strasbourg) : xx.xxx.xxx.xx // localhost
    // Port : xxx
    // UID : User
    // PWD : xxxxx
    // Nom de la base de données : ESA_Lorawan
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QODBC");
    QString QStrCnxDatabase = QString("DRIVER={MongoDB ODBC 1.0 ANSI Driver};Server Name=")+QString("127.0.0.1")+QString(";Server Port=xxx;Database=xxx;UID=xxx;PWD=xxx"); //Il nous faut un connector ODBC
	//Il faut regarder pour se connecter directement avec une base SQL

    // Préparation de la connexion via ODBC sur la base de données HFSQL ESA_Lorawan
    dbase.setDatabaseName(QStrCnxDatabase);

    // Connexion à la base de données HFSQL Esa_Lorawan
    if (dbase.open())
        qDebug() << "Connecté à la base de donnée";
    else
        qDebug() << "Non connecté à la base de donnée";

    qDebug() << dbase.isValid();
}
