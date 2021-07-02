#include "algorithmlhuna.h"

#include <QLayout>
#include <cctype>

///MAKE VALIDATION

AlgorithmLhuna::AlgorithmLhuna(QWidget* wdg): QWidget(wdg)
{
    n_last_digit = 0;
    n_next_check_digit = 0;

    QVBoxLayout* vlay_main = new QVBoxLayout;
    QWidget* wdg_empty = new QWidget;

    lbl_sequence_digits = new QLabel("Sequence of digits");
    ted_include = new QTextEdit;
    ted_include->setPlaceholderText("Enter the digits");
    ted_include->setMaximumHeight(30);
    ted_include->setMaximumWidth(400);
    QGridLayout* glay_teds = new QGridLayout;
    glay_teds->addWidget(lbl_sequence_digits, 0, 0);
    glay_teds->addWidget(ted_include, 1, 0);

    bt_calculate = new QPushButton("Calculate");
    connect(bt_calculate, SIGNAL(clicked()), this, SLOT(SlotButtonRunAlg()));
    bt_calculate->setMaximumSize(100, 30);
    glay_teds->addWidget(bt_calculate, 2, 0);
    glay_teds->addWidget(wdg_empty, 3, 0);

    lbl_last_digit = new QLabel("Last digit of sequence: ");

    lbl_next_check_digit = new QLabel("Digit for correctly sequence: ");

    lbl_error = new QLabel;

    QVBoxLayout* vlay_msg = new QVBoxLayout;
    vlay_msg->addWidget(lbl_last_digit);
    vlay_msg->addWidget(lbl_next_check_digit);
    vlay_msg->addWidget(lbl_error);

    QVBoxLayout* vlay_digits = new QVBoxLayout;
    vlay_digits->addWidget(lbl_last_digit);
    vlay_digits->addWidget(lbl_next_check_digit);

    vlay_main->addLayout(glay_teds);
    vlay_main->addLayout(vlay_digits);
    vlay_main->addLayout(vlay_msg);
    vlay_main->setSpacing(10);

    setLayout(vlay_main);
    setMaximumSize(400, 250);
}

AlgorithmLhuna::~AlgorithmLhuna()
{}

void AlgorithmLhuna::SlotButtonRunAlg()
{
    //if (isdigit(ted_include->toPlainText().toInt())){
    this->runAlgorithm();
    QString str_temp_one = QString::number(n_last_digit);
    QString str_temp_two = QString::number(n_next_check_digit);
    lbl_error->clear();
    lbl_last_digit->setText("Last digit of sequence: " + str_temp_one);
    lbl_next_check_digit->setText("Digit for correctly sequence: " + str_temp_two);
    //    } else {
    //        QString str_error = "Entered issue data";
    //        lbl_error->setText(str_error);
    //        qDebug() << str_error;
    //    }
}

void AlgorithmLhuna::runAlgorithm()
{
    int n = ted_include->toPlainText().toInt();
    std::vector<int> vec;
    int res = 0;
    while(n != 0)
    {
        vec.push_back(n%10);
        n /= 10;
        if (vec.back() == 0)
        {
            n_last_digit += vec.back() * 2;
            if (n_last_digit >= 10){
                n_last_digit -= 9;
                res += n_last_digit;
            }
            else{
                res += n_last_digit;
            }
        }
        else {
            res += vec.back();
        }
    }
    n_last_digit = res % 10;
    n_next_check_digit = 10 - (res % 10);
}
