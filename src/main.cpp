#include <QApplication>
#include <QTabWidget>
#include <windows.h>

#include "cesarCipher.h"

int main(int argc, char *argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    QApplication a(argc, argv);

    QTabWidget main_tab;
    CesarCipher* wdg_cesar_cipher = new CesarCipher;

    main_tab.addTab(wdg_cesar_cipher, "Cesar Cipher");

    main_tab.setWindowTitle("Ciphers");

    main_tab.resize(1024, 480);
    main_tab.show();
    return a.exec();
}
