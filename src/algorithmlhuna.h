#pragma once

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>

class AlgorithmLhuna : public QWidget
{
public:
    AlgorithmLhuna(QWidget* wdg = 0);
    virtual ~AlgorithmLhuna();
    bool runAlgorithm();
private:
    QLabel* lbl_sequence_digits;
    QTextEdit* ted_include;
    QPushButton* bt_calculate;
    QLabel* lbl_last_digit;
    QLabel* lbl_next_check_digit;
    int n_last_digit;
    int n_next_check_digit;
public slots:
    void SlotButtonRunAlg();
};

