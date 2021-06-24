#include <QLayout>
#include <QStringList>

#include "cesarCipher.h"

//MAKE VALIDATION

CesarCipher::CesarCipher(QWidget* mwdg): QWidget(mwdg)
{
    ted_input = new QTextEdit("Enter the text");
    ted_output = new QTextEdit;
    ted_output->setReadOnly(true);
    QHBoxLayout* hlay_teds = new QHBoxLayout;
    hlay_teds->addWidget(ted_input);
    hlay_teds->addWidget(ted_output);

    bt_run = new QPushButton("Run");

    lbl_lang = new QLabel("Language");
    QStringList str_list_lang;
    str_list_lang << "English" << "Russian";
    cmb_lang = new QComboBox;
    cmb_lang->addItems(str_list_lang);
    QHBoxLayout* hlay_lang = new QHBoxLayout;
    hlay_lang->addWidget(lbl_lang);
    hlay_lang->addWidget(cmb_lang);

    lbl_shift = new QLabel("Shift");
    led_shift = new QLineEdit("Enter the shift");
    QHBoxLayout* hlay_shift = new QHBoxLayout;
    hlay_shift->addWidget(lbl_shift);
    hlay_shift->addWidget(led_shift);

    lbl_cipher = new QLabel("(Un)encryption");
    QStringList str_list_cipher;
    str_list_cipher << "Encryption" << "Unenctyption";
    cmb_state_of_cipher = new QComboBox;
    cmb_state_of_cipher->addItems(str_list_cipher);
    QHBoxLayout* hlay_cipher = new QHBoxLayout;
    hlay_cipher->addWidget(lbl_cipher);
    hlay_cipher->addWidget(cmb_state_of_cipher);

    QVBoxLayout* vlay_whole = new QVBoxLayout;
    vlay_whole->addLayout(hlay_teds);
    vlay_whole->addWidget(bt_run);
    vlay_whole->addLayout(hlay_lang);
    vlay_whole->addLayout(hlay_shift);
    vlay_whole->addLayout(hlay_cipher);

    setLayout(vlay_whole);

    state_cipher = Encryption;
    state_language = English;
	str_lang_up = STR_ALPHABET_ENG_UP;
	str_lang_down = STR_ALPHABET_ENG_DOWN;
}

CesarCipher::~CesarCipher() {}

void CesarCipher::inputShift()
{

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

QString CesarCipher::encryption()
{
	str_output.clear();
	str_input.clear();
	printf("\n");
	if (n_shift != 0)
	{
		for (auto it1 = str_input.begin(); it1 < str_input.end(); ++it1)
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
	}
	else
	{
		str_output = str_input;
	}
	return str_output;
}

QString CesarCipher::unEncryption()
{
	str_output.clear();
	str_input.clear();
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
	return str_output;
}
