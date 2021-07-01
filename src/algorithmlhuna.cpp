#include "algorithmlhuna.h"

#include <QLayout>

AlgorithmLhuna::AlgorithmLhuna(QWidget* wdg)
{
    n_last_digit = 0;
    n_next_check_digit = 0;

    QVBoxLayout* vlay_main = new QVBoxLayout;

    ted_include = new QTextEdit;

    bt_calculate = new QPushButton("Calculate");
    connect(bt_calculate, SIGNAL(clicked()), this, SLOT(SlotButtonRunAlg()));

    lbl_last_digit = new QLabel;

    lbl_next_check_digit = new QLabel;

    QVBoxLayout* vlay_digits = new QVBoxLayout;
    vlay_digits->addWidget(lbl_last_digit);
    vlay_digits->addWidget(lbl_next_check_digit);

    vlay_main->addLayout(vlay_digits);

    setLayout(vlay_main);
}

AlgorithmLhuna::~AlgorithmLhuna() {}

void AlgorithmLhuna::SlotButtonRunAlg()
{

}

void AlgorithmLhuna::runAlgorithm()
{

}
