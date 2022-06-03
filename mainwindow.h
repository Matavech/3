#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class Rect;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    int count = 0, x = 0, y = 0;
    Rect* rect = nullptr;
};
#endif // MAINWINDOW_H
