#pragma once

#include <QAbstractListModel>
#include <QObject>
#include <QString>

class HistoryModel : public QAbstractListModel
{
private:
    QList<QString> lst_left;
    QList<QString> lst_right;
public:
    explicit HistoryModel(QList<QString> left, QList<QString> right,
                          QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role) const;

    bool setData(const QModelIndex &index,
                 const QVariant &value,
                 int role);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole);

    //Qt::ItemFlags flags(const QModelIndex &index) const;

    bool insertRows(int row,
                    int count,
                    const QModelIndex &parent = QModelIndex());

    bool removeRows(int row,
                    int count,
                    const QModelIndex &parent = QModelIndex());
};


