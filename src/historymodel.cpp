#include "historymodel.h"

HistoryModel::HistoryModel(QList<QString> left, QList<QString> right, QObject *parent) :
    QAbstractListModel(parent), lst_left(left), lst_right(right)
{

}

QVariant HistoryModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

bool HistoryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}

int HistoryModel::rowCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant HistoryModel::headerData(int section, Qt::Orientation orientation, int role)
{
    return QVariant();
}

//Qt::ItemFlags HistoryModel::flags(const QModelIndex &index) const
//{
//    return NULL;
//}

bool HistoryModel::insertRows(int row, int count, const QModelIndex &parent)
{
    return true;
}

bool HistoryModel::removeRows(int row, int count, const QModelIndex &parent)
{
    return true;
}
