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


class CesarCipher : public QWidget
{
    Q_OBJECT
private:
    unsigned int n_shift;
    unsigned int index_letter;
    QString str_lang_up;
    QString str_lang_down;
    QString str_input;
    QString str_output;

    const QString STR_ALPHABET_RUS_UP = "�����Ũ��������������������������";
    const QString STR_ALPHABET_RUS_DOWN = "��������������������������������";
    const QString STR_ALPHABET_ENG_UP = "ABCDEFGHIKLMNOPQRSTVXYZ";
    const QString STR_ALPHABET_ENG_DOWN = "abcdefghiklmnopqrstvxyz";
private:
    QTextEdit* ted_input;
    QTextEdit* ted_output;
    QPushButton* bt_switch;
    QLabel* lbl_lang;
    QComboBox* cmb_lang;
    QLabel* lbl_shift;
    QComboBox* cmb_shift;
    QLabel* lbl_cipher;
    QComboBox* cmb_state_of_cipher;
    QPushButton* bt_run;
    QLabel* lbl_history;
    QStringList* str_list_history;
    QStringListModel* slstm_history;
    QListView* lst_view_history ;
protected:
    enum {NormalState = -1, Encryption, Unencryption};
    enum {None = -1, English, Russian};

    int state_cipher;
    int state_language;
public:
    CesarCipher(QWidget* mwdg = 0);
    virtual ~CesarCipher();
    void chooseLanguage();
    void encryption();
    void unEncryption();
    void addHistory(const QString &str_history);
private slots:
    void SlotButtonRun();
    void SlotButtonSwitch();
    void SlotCmbChangeShift(int);
    void SlotCmbChooseLang(int);
    void SlotCmbEncrOrUnencr(int);
};

