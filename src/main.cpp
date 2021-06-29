#include <QApplication>
#include <QTabWidget>

#include "cesarCipher.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTabWidget main_tab;
    CesarCipher* wdg_cesar_cipher = new CesarCipher;

    main_tab.addTab(wdg_cesar_cipher, "Cesar Cipher");

    main_tab.setWindowTitle("Ciphers");

    main_tab.resize(1024, 480);
    main_tab.show();
    return app.exec();
}
