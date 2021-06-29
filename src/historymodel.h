#pragma once

#include <QAbstractListModel>
#include <QObject>

class HistoryModel : public QAbstractListModel
{
public:
    explicit HistoryModel(QObject *parent = nullptr);
};


