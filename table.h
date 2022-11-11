#ifndef TABLE_H
#define TABLE_H

#include <QAbstractTableModel>
#include <QObject>
#include "person.h"

class table : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit table(QObject *parent = nullptr);

private:
    QVector<person> vec;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // TABLE_H
