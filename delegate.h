#ifndef DELEGATE_H
#define DELEGATE_H

#include <QItemDelegate>

class delegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit delegate(QWidget *parent = nullptr);


    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
#endif // DELEGATE_H
