#include "Tlineedit.h"

TLineEdit::TLineEdit(QString s, QWidget* parent) : QLineEdit (s, parent){};
void TLineEdit::mousePressEvent(QMouseEvent*)
{
    clear();
}
