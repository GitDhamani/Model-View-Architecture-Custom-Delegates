#include "table.h"
#include <QVector>
#include <QDebug>

table::table(QObject *parent) : QAbstractTableModel(parent)
{
    vec << person({"Mohammed", 5, "blue"});
    vec << person({"James", 4, "green"});
    vec << person({"Mark", 3, "yellow"});
    vec << person({"Paul", 2, "black"});
    vec << person({"Clark", 1, "red"});
}

int table::rowCount(const QModelIndex &parent) const
{
    return vec.size();
}

int table::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant table::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        if (index.column() == 0)
            return vec[index.row()].getName();

        if (index.column() == 1)
            return vec[index.row()].getAge();

        if (index.column() == 2)
            return vec[index.row()].getFavcolour();
    }

    if (role == Qt::TextAlignmentRole)
           return Qt::AlignCenter;

    return QVariant();
}

QVariant table::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal)
        if (role == Qt::DisplayRole)
        {
            if (section == 0) return "Name";
            if (section == 1) return "Rating";
            if (section == 2) return "Fave Colour";
        }

    if (orientation == Qt::Vertical)
        if (role == Qt::DisplayRole)
        return section + 1;

    return QVariant();
}

bool table::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
    {
        if (index.column() == 0)
        {
            vec[index.row()].setName(value.toString());
            return true;
        }

        if (index.column() == 1)
        {
            vec[index.row()].setAge(value.toInt());
            return true;
        }

        if (index.column() == 2)
        {
            vec[index.row()].setFavcolour(value.toString());
            return true;
        }
    }


    return false;
}

Qt::ItemFlags table::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
