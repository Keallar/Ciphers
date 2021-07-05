#include <QApplication>
#include <QTabWidget>

#include "cesarCipher.h"
#include "algorithmlhuna.h"

//make message boxes for all tabs

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTabWidget main_tab;
    CesarCipher* wdg_cesar_cipher = new CesarCipher;
    AlgorithmLhuna* wdg_alg_lhuna = new AlgorithmLhuna;

    main_tab.addTab(wdg_cesar_cipher, "Cesar Cipher");
    main_tab.addTab(wdg_alg_lhuna, "Algorithm Lhuna");

    main_tab.setWindowTitle("Ciphers");

    main_tab.resize(1024, 480);
    main_tab.show();
    return app.exec();
}
