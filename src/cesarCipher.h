#pragma once
#include <string>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QTextDocument>
#include <QLabel>
#include <QTextEdit>

class CesarCipher : public QWidget
{
    Q_OBJECT
private:
	unsigned int n_shift = 0;
	unsigned int index_letter = 0;
    QString str_lang_up;
    QString str_lang_down;
    QString str_input;
    QString str_output;

    const QString STR_ALPHABET_RUS_UP = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
    const QString STR_ALPHABET_RUS_DOWN = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";
    const QString STR_ALPHABET_ENG_UP = "ABCDEFGHIKLMNOPQRSTVXYZ";
    const QString STR_ALPHABET_ENG_DOWN = "abcdefghiklmnopqrstvxyz";
private:
    QTextEdit* ted_input;
    QTextEdit* ted_output;
    QLabel* lbl_lang;
    QComboBox* cmb_lang;
    QLabel* lbl_shift;
    QLineEdit* led_shift;
    QLabel* lbl_cipher;
    QComboBox* cmb_state_of_cipher;
    QPushButton* bt_run;
protected:
    enum {NormalState = -1, Encryption, Unencryption};
    enum {None = -1, English, Russian};

    int state_cipher;
    int state_language;
public:
    CesarCipher(QWidget* mwdg = 0);
    virtual ~CesarCipher();
	void inputShift();
	void chooseLanguage();
    QString encryption();
    QString unEncryption();
};

