#include <QApplication>
#include <QTabWidget>

#include "cesarCipher.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CesarCipher wdg_cesar_cipher;

    wdg_cesar_cipher.setWindowTitle("Ciphers");

    wdg_cesar_cipher.resize(1024, 480);
    wdg_cesar_cipher.show();
    return a.exec();
}
