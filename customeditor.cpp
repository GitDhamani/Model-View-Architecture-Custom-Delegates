#include "customeditor.h"
#include <QMouseEvent>
#include <QBrush>

CustomEditor::CustomEditor(QWidget *parent) : QWidget(parent)
{ }

void CustomEditor::DrawStar(QColor colour, float scale, int num)
{
    QPainter painter(this);
    QBrush brush(colour);
    QPen pen;
    pen.setWidth(10);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setRenderHint(QPainter::Antialiasing, true);

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

    painter.scale(scale, scale);
    painter.translate(20,20);
    for (int i = 0; i<num; i++)
    {
        painter.drawPolygon(points, 10);
        painter.translate(350, 0);
    }
}

int CustomEditor::getNumstars() const
{
    return numstars;
}

void CustomEditor::setNumstars(int newNumstars)
{
    rect();
    numstars = newNumstars;
}

void CustomEditor::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);

    QBrush brush;
    brush.setColor(QColor("dodgerblue"));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    //Draw Stars
    painter.drawRect(rect().adjusted(-3,-3,3,3));
        DrawStar(Qt::yellow, 0.1, numstars);
}

void CustomEditor::mouseMoveEvent(QMouseEvent *event)
{
    numstars = event->x()/(200/6) + 1;
    if (numstars<1) numstars = 1;
    if (numstars>6) numstars = 6;
    update();
}

void CustomEditor::mousePressEvent(QMouseEvent *event)
{
    numstars = event->x()/(200/6) + 1;
    if (numstars<1) numstars = 1;
    if (numstars>6) numstars = 6;
    update();
}
