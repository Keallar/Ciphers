#pragma once
#include <string>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QTextDocument>
#include <QLabel>
#include <QPlainTextEdit>
#include <QStringListModel>
#include <QListView>

#include "historymodel.h"

class CesarCipher : public QWidget
{
    Q_OBJECT
public:
    CesarCipher(QWidget* mwdg = 0);
    virtual ~CesarCipher();
    void chooseLanguage();
    void encryption();
    void unEncryption();
    void addHistory(const QString &str_history_input, const QString &str_history_output);
private:
    unsigned int n_shift;
    unsigned int index_letter;
    QString str_lang_up;
    QString str_lang_down;
    QString str_input;
    QString str_output;

    HistoryModel* m_history;

    const QString STR_ALPHABET_RUS_UP = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
    const QString STR_ALPHABET_RUS_DOWN = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";
    const QString STR_ALPHABET_ENG_UP = "ABCDEFGHIKLMNOPQRSTVXYZ";
    const QString STR_ALPHABET_ENG_DOWN = "abcdefghiklmnopqrstvxyz";
private:
    QTextEdit* ted_input;
    QTextEdit* ted_output;
    QPushButton* bt_switch;
    QComboBox* cmb_lang;
    QComboBox* cmb_shift;
    QComboBox* cmb_state_of_cipher;
    QPushButton* bt_run;

protected:
    enum {NormalState = -1, Encryption, Unencryption};
    enum {None = -1, English, Russian};

    int state_cipher;
    int state_language;
private slots:
    void SlotButtonRun();
    void SlotButtonSwitch();
    void SlotCmbChangeShift(int);
    void SlotCmbChooseLang(int);
    void SlotCmbEncrOrUnencr(int);
};

