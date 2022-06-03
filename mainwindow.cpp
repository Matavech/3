#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rect.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    (*ui).setupUi(this);

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    count++;
    if (count == 1){
        x = (*event).x();
        y = (*event).y();
    }
    else if (count == 2){
        rect = new Rect(x, y, (*event).x(), (*event).y());
    }
    else {
         QMessageBox msgBox;
          msgBox.setDefaultButton(QMessageBox::Ok);
          if ((*rect).hit((*event).x(), (*event).y())==true)
          {
              msgBox.setText("Попали!");
              msgBox.setInformativeText("Точность на высшем уровне!");
          }
          else {
              msgBox.setText("Не попали :(");
              msgBox.setInformativeText("Нажмите Ок и попробуйте еще раз");
          }
          msgBox.exec();
    }
    repaint();
}

bool Rect::hit(int x, int y)
{
    if ((originX + weidth >= x) && (originX <= x) && (originY + height >=y) && (originY <= y)) {
        return true;
    }
    else {
        return false;
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if (rect != nullptr){
       QPainter painter(this);
       painter.drawLine((*rect).getOriginX(), (*rect).getOriginY(), (*rect).getOriginX() + (*rect).getWeidth(), (*rect).getOriginY());
       painter.drawLine((*rect).getOriginX(), (*rect).getOriginY() +  (*rect).getHeight(), (*rect).getOriginX() + (*rect).getWeidth(), (*rect).getOriginY() +(*rect).getHeight());
       painter.drawLine((*rect).getOriginX(), (*rect).getOriginY(), (*rect).getOriginX(), (*rect).getOriginY() + (*rect).getHeight());
       painter.drawLine((*rect).getOriginX() + (*rect).getWeidth(), (*rect).getOriginY(), (*rect).getOriginX() + (*rect).getWeidth(), (*rect).getOriginY() + (*rect).getHeight());
   }

}

