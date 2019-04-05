#ifndef PAINTTABLE_H
#define PAINTTABLE_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class PaintTable : public QWidget
{
    QPainter painter;
public:
    PaintTable(QWidget*);

protected:

    void paintEvent(QPaintEvent*);

};

#endif // PAINTTABLE_H
