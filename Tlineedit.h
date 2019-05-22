#ifndef TLINEEDIT_H
#define TLINEEDIT_H
#include <QLineEdit>

class TLineEdit : public QLineEdit
{
public:
    TLineEdit(QString,QWidget* = 0);
protected:
    void mousePressEvent(QMouseEvent*);
};

#endif // TLINEEDIT_H
