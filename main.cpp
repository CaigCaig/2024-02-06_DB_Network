#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>

#include <QtNetwork>
#include <QUdpSocket>>
#include <QTcpServer>
#include <QtSql>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "2024-02-06_DB_Network_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QTcpServer tcpServer;
    QUdpSocket sock;

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("my_db.sqlite");
    if (!dbase.open()) {
        qDebug() << "Что-то пошло не так!";
        return -1;
    }

    return a.exec();
}

/*
Инструкция к заданию

Создать новый проект. Консольное приложение.
В файле CMakeList.txt добавить модули для работы с БД и сетью.
В main создать экземпляры любых классов из этого модуля.

Задание 1

Подключить к проекту модули для работы с сетью и с БД.
Создать два экземпляра классов из этих модулей в функции main.
*/
