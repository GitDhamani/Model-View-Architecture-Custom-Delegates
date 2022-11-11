#ifndef CUSTOMEDITOR_H
#define CUSTOMEDITOR_H

#include <QWidget>
#include <QPainter>

class CustomEditor : public QWidget
{
    Q_OBJECT
public:
    explicit CustomEditor(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    int getNumstars() const;
    void setNumstars(int newNumstars);

private:
    void DrawStar(QColor colour, float scale, int num);
    int numstars;
};

#endif // CUSTOMEDITOR_H
