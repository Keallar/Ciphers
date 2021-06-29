#include <QLayout>
#include <QStringList>
#include <QFormLayout>
#include <QSizePolicy>

#include "cesarCipher.h"

//MAKE VALIDATION
//MAKE CUSTOM ICONS
//MAKE RUS LANGUAGE
//MOVE BUTTONS AND COMBOBOXES
//make spin box instead of combobox for shift

CesarCipher::CesarCipher(QWidget* mwdg): QWidget(mwdg),
    n_shift(0), index_letter(0), state_cipher(Encryption), state_language(English)
{
    str_lang_up = STR_ALPHABET_ENG_UP;
    str_lang_down = STR_ALPHABET_ENG_DOWN;

    ted_input = new QTextEdit;
    ted_input->setPlaceholderText("Enter the text");
    ted_output = new QTextEdit;
    ted_output->setReadOnly(true);
    bt_switch = new QPushButton("Switch");
    connect(bt_switch, SIGNAL(clicked()), this, SLOT(SlotButtonSwitch()));
    QHBoxLayout* hlay_teds = new QHBoxLayout;
    hlay_teds->addWidget(ted_input);
    hlay_teds->addWidget(bt_switch);
    hlay_teds->addWidget(ted_output);

    bt_run = new QPushButton("Run");
    connect(bt_run, SIGNAL(clicked()), this, SLOT(SlotButtonRun()));

    QStringList str_list_lang;
    str_list_lang << "English" << "Russian";
    cmb_lang = new QComboBox;
    cmb_lang->addItems(str_list_lang);
    connect(cmb_lang, SIGNAL(currentIndexChanged(int)), this, SLOT(SlotCmbChooseLang(int)));
    QFormLayout* hlay_lang = new QFormLayout;
    //hlay_lang->setLabelAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    hlay_lang->setSizeConstraint(SetMinimumSize);
    hlay_lang->addRow("Language:", cmb_lang);

    QStringList str_list_shift;
    for (int i = 0; i < 34; ++i) {
        str_list_shift << QString::number(i);
    }
    cmb_shift = new QComboBox;
    cmb_shift->addItems(str_list_shift);
    connect(cmb_shift, SIGNAL(currentIndexChanged(int)), this, SLOT(SlotCmbChangeShift(int)));
    QFormLayout* hlay_shift = new QFormLayout;
    hlay_shift->addRow("Shift: ", cmb_shift);

    QStringList str_list_cipher;
    str_list_cipher << "Encryption" << "Unenctyption";
    cmb_state_of_cipher = new QComboBox;
    cmb_state_of_cipher->addItems(str_list_cipher);
    connect(cmb_state_of_cipher, SIGNAL(currentIndexChanged(int)), this, SLOT(SlotCmbEncrOrUnencr(int)));
    QFormLayout* hlay_cipher = new QFormLayout;
    hlay_cipher->addRow("Encryption", cmb_state_of_cipher);

    QVBoxLayout* vlay_left_down = new QVBoxLayout;
    vlay_left_down->addLayout(hlay_lang);
    vlay_left_down->addLayout(hlay_shift);
    vlay_left_down->addLayout(hlay_cipher);


//    str_list_history = new QStringList;
//    slstm_history = new QStringListModel;
//    slstm_history->insertColumn(1);
//    lst_view_history = new QListView;
//    lst_view_history->setModel(slstm_history);
//    lbl_history = new QLabel("History");
//    QVBoxLayout* vlay_history = new QVBoxLayout;
//    vlay_history->addWidget(lbl_history);
//    vlay_history->addWidget(lst_view_history);

    QHBoxLayout* hlay_down = new QHBoxLayout;
    hlay_down->addLayout(vlay_left_down);
    //hlay_down->addLayout(vlay_history);


    QVBoxLayout* vlay_whole = new QVBoxLayout;
    vlay_whole->addLayout(hlay_teds);
    vlay_whole->addWidget(bt_run);
    vlay_whole->addLayout(hlay_down);

    setLayout(vlay_whole);
}

CesarCipher::~CesarCipher() {}

void CesarCipher::SlotButtonRun()
{
    if (state_cipher == Encryption)
        this->encryption();
    else if (state_cipher == Unencryption)
        this->unEncryption();

    qDebug() << str_output << "\n";
    qDebug() << n_shift << "\n";
    qDebug() << cmb_shift->currentText() << "\n";
    qDebug() << cmb_lang->currentText() << "\n";
    qDebug() << cmb_state_of_cipher->currentText() << "\n";

    ted_output->setText(str_output);
    addHistory(str_input, str_output);
}

void CesarCipher::SlotButtonSwitch()
{
    QString str_temp = str_output;
    str_output.clear();
    str_output = str_input;
    ted_output->setText(str_output);
    str_input.clear();
    ted_input->setText(str_temp);
}

void CesarCipher::SlotCmbChangeShift(int index)
{
    n_shift = cmb_shift->itemText(index).toInt();
}

void CesarCipher::SlotCmbChooseLang(int n_lang)
{
    if (n_lang == English)
    {
        str_lang_up = STR_ALPHABET_ENG_UP;
        str_lang_down = STR_ALPHABET_ENG_DOWN;
        state_language = English;
    }
    else if (n_lang == Russian)
    {
        str_lang_up = STR_ALPHABET_RUS_UP;
        str_lang_down = STR_ALPHABET_RUS_DOWN;
        state_language = Russian;
    }
}

void CesarCipher::SlotCmbEncrOrUnencr(int n_encr)
{
    if (n_encr == Encryption)
        state_cipher = Encryption;
    else if (n_encr == Unencryption)
        state_cipher = Unencryption;
}

void CesarCipher::chooseLanguage()
{
    if (state_language == English)
    {
        str_lang_up = STR_ALPHABET_ENG_UP;
        str_lang_down = STR_ALPHABET_ENG_DOWN;
    }
    else if (state_language == Russian)
    {
        str_lang_up = STR_ALPHABET_RUS_UP;
        str_lang_down = STR_ALPHABET_RUS_DOWN;
    }
}

void CesarCipher::addHistory(const QString &str_history_input, const QString &str_history_output)
{
    //str_list_history->push_back(str_history_input);
}

void CesarCipher::encryption()
{
    str_output.clear();
    str_input.clear();
    str_input = ted_input->toPlainText();
    if (n_shift != 0)
    {
        for (auto it1 = str_input.begin(); it1 < str_input.end(); ++it1)
        {
            if (*it1 != ' ')
            {
                for (auto it2 = str_lang_up.begin(); it2 < str_lang_up.end(); ++it2)
                {
                    if (*it1 == *it2)
                    {
                        index_letter = std::distance(str_lang_up.begin(), it2);
                        index_letter += n_shift;
                        if (index_letter > str_lang_up.length())
                        {
                            index_letter = index_letter - str_lang_up.length();
                        }
                        str_output += str_lang_up.at(index_letter);
                    }
                }
                for (auto it2 = str_lang_down.begin(); it2 < str_lang_down.end(); ++it2)
                {
                    if (*it1 == *it2)
                    {
                        index_letter = std::distance(str_lang_down.begin(), it2);
                        index_letter += n_shift;
                        if (index_letter > str_lang_down.length())
                        {
                            index_letter = index_letter - str_lang_down.length();
                        }
                        str_output += str_lang_down.at(index_letter);
                    }
                }
            }
            else
            {
                str_output += ' ';
            }
        }
    }
    else
    {
        str_output = str_input;
    }
}

void CesarCipher::unEncryption()
{
    str_output.clear();
    str_input.clear();
    str_input = ted_input->toPlainText();
    if (n_shift != 0)
    {
        for (auto it1 = str_input.begin(); it1 < str_input.end(); ++it1)
        {
            for (auto it2 = str_lang_up.begin(); it2 < str_lang_up.end(); ++it2)
            {
                if (*it1 == *it2)
                {
                    index_letter = std::distance(str_lang_up.begin(), it2);
                    index_letter -= n_shift;
                    if (index_letter < 0)
                    {
                        index_letter = index_letter + str_lang_up.length();
                    }
                    str_output += str_lang_up.at(index_letter);
                }
            }
            for (auto it2 = str_lang_down.begin(); it2 < str_lang_down.end(); ++it2)
            {
                if (*it1 == *it2)
                {
                    index_letter = std::distance(str_lang_down.begin(), it2);
                    index_letter -= n_shift;
                    if (index_letter < 0)
                    {
                        index_letter = index_letter + str_lang_down.length();
                    }
                    str_output += str_lang_down.at(index_letter);
                }
            }
        }
    }
    else
    {
        str_output = str_input;
    }
}


