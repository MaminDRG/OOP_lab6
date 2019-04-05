#include "PaintTable.h"

PaintTable::PaintTable(QWidget* w) : QWidget(w)
{

}

void PaintTable::paintEvent(QPaintEvent*)
{
    painter.begin(this);
    painter.setPen(Qt::white);
    painter.drawLine(QPoint(50,50),QPoint(100,100));
    painter.end();
}
