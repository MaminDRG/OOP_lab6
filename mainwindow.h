#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "PaintTable.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
   // void on_pushButton_pressed();
    void readParams();
    void clear();

  //  void lineEdit_side1(double);
  //  void lineEdit_side2(double);
  //  void lineEdit_angle12(double);
  //  void lineEdit_Area(double);
  //  void lineEdit_Perimeter(double);

private:
    Ui::MainWindow *ui;
    PaintTable * desk;


};

#endif // MAINWINDOW_H
