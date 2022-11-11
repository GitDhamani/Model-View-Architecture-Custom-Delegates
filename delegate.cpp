#include "delegate.h"
#include <QComboBox>
#include <QPainter>
#include "customeditor.h"

delegate::delegate(QWidget *parent) : QItemDelegate(parent)
{

}
QWidget *delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column()==2)
    {
        QComboBox* combo = new QComboBox(parent);
        for (auto color: QColor::colorNames())
        {
            QPixmap pixmap(50,50);
            pixmap.fill(QColor(color));
            combo->addItem(QIcon(pixmap), color);
        }
        return combo;
    }

    if (index.column()==1)
    {
        CustomEditor* staredit = new CustomEditor(parent);
        staredit->setNumstars(index.data().toInt());
        return staredit;
    }

    return QItemDelegate::createEditor(parent,option,index);
}

void delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(index.column() == 2)
    {
           QComboBox *combo = static_cast<QComboBox *>(editor);
           int idx = QColor::colorNames().indexOf(index.data(Qt::DisplayRole).toString());
           combo->setCurrentIndex(idx);
    }

    else if (index.column() == 1)
    {
        CustomEditor* staredit = static_cast<CustomEditor*>(editor);
        staredit->setNumstars(index.data().toInt());
    }
    else
    QItemDelegate::setEditorData(editor,index);
}

void delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(index.column() == 2)
    {
           QComboBox *combo = static_cast<QComboBox *>(editor);
           model->setData(index,combo->currentText(),Qt::EditRole);
    }
    else if(index.column() == 1)
    {
           CustomEditor *staredit = static_cast<CustomEditor *>(editor);
           model->setData(index,staredit->getNumstars(),Qt::EditRole);
    }
    else
    {
           QItemDelegate::setModelData(editor,model,index);
    }
}


void delegate::paint(QPainter* painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column()==2)
    {
        //Get the text in that cell
        QString currentSelected = index.data(Qt::DisplayRole).toString();

        painter->save();
        painter->setBrush(QColor(currentSelected));
        painter->drawRect(option.rect.adjusted(3,3,-3,-3));

        //Draw White Rectangle on top
        painter->setBrush(Qt::white);
        painter->setPen(Qt::NoPen);
        painter->drawRect(option.rect.adjusted(30,6,-30,-5));
        painter->restore();

    }

    if (index.column()==1)
    {
        int numstars = index.data().toInt();
        QBrush brush(Qt::yellow);
        QPen pen;
        pen.setWidth(10);
        painter->save();
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->setRenderHint(QPainter::Antialiasing, true);

        QPoint points[] = {
            QPoint(0, 85),
            QPoint(75, 75),
            QPoint(100, 10),
            QPoint(125, 75),
            QPoint(200, 85),
            QPoint(150, 125),
            QPoint(160, 190),
            QPoint(100, 150),
            QPoint(40, 190),
            QPoint(50, 125),
        };

        painter->translate(option.rect.x(), option.rect.y());
        painter->scale(0.1, 0.1);
        painter->translate(20,20);
        if (numstars <= 6)
        for (int i = 0; i<numstars; i++)
        {
            painter->drawPolygon(points, 10);
            painter->translate(350, 0);
        }

        painter->restore();

    }

    if (index.column()!=1) //Blocks the numbers in the 1st column from appearing.
    QItemDelegate::paint(painter, option, index);
}
