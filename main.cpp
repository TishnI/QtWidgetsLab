#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "win.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "QtWidgetsLab_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    Win win(0);
    win.show();
    return a.exec();
}
