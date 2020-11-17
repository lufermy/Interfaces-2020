#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QPaintEvent>
class MainWindow : public QMainWindow {
Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);
        void paintEvent(QPaintEvent *event);
        int posicionx=0;
        int posiciony=0;
        bool ciclox=true;
        bool cicloy=true;        
        int vel=5;// velocidad del coso
        QTimer *temporizador;
    public slots:
    void slotRepintar();
};
#endif