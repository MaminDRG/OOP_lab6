#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{







    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);

   // editSide1 = new TLineEdit("side1",this);
   // editSide1->setGeometry(ui->lineEdit_side1->x(),ui->lineEdit_side1->y()+14,ui->lineEdit_side1->width(),ui->lineEdit_side1->height());

   // editSide1 = new TLineEdit("side2",this);
   // editSide1->setGeometry(ui->lineEdit_side1->x(),ui->lineEdit_side1->y()+14,ui->lineEdit_side1->width(),ui->lineEdit_side1->height());

   // editSide1 = new TLineEdit("angle12",this);
   // editSide1->setGeometry(ui->lineEdit_side1->x(),ui->lineEdit_side1->y()+14,ui->lineEdit_side1->width(),ui->lineEdit_side1->height());

    connect(ui->PushButton, SIGNAL(clicked()), this, SLOT(readParams()));
    connect(ui->PushButtonClear, SIGNAL(clicked()), this, SLOT(clear()));

    desk = new PaintTable(this);

    this->setFixedSize(490, 420);
    desk->setGeometry(0,100,490,310);



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::readParams()

{
    double side1 = ui->lineEdit_side1->text().toDouble(); // получаем строку из первого QLineEdit
    double side2 = ui->lineEdit_side2->text().toDouble(); // получаем строку из второго QLineEdit
    double angle12 = ui->lineEdit_angle12->text().toDouble();
    double triangleParamsMas[3] = {side1,side2,angle12};





    desk->setParams(triangleParamsMas);


    desk->repaint();

    double* masInfo = new double[2];
    desk->getAreaPerimeter(masInfo);
    QString Area = QString::number(masInfo[0]);
    QString Perimeter = QString::number(masInfo[1]);
    ui->lineEdit_Area->setText(Area);
    ui->lineEdit_Perimeter->setText(Perimeter);
    delete[] masInfo;




}
void MainWindow::clear()
{
    ui->lineEdit_Area->setText("");
    ui->lineEdit_Perimeter->setText("");
    ui->lineEdit_side1->setText("");
    ui->lineEdit_side2->setText("");
    ui->lineEdit_angle12->setText("");
    double triangleParamsMas[3] = {0,0,0};
    desk->setParams(triangleParamsMas);
    desk->repaint();
}



void MainWindow::on_radioButton_Arbitrary_clicked()
{
    desk->setTriangleType(0);
}

void MainWindow::on_radioButton_Isosceles_clicked()
{
    desk->setTriangleType(1);
}



void MainWindow::on_radioButton_Equilateral_clicked()
{
    desk->setTriangleType(2);
}
