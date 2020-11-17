#include "mainwindow.h"
#include <QPainter>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){
    resize(800,600);
    int posicion=0;
    int ciclo=0;
    temporizador = new QTimer();
    temporizador->setInterval(vel);
    temporizador->setSingleShot(false);
    temporizador->start();

    connect(temporizador,SIGNAL(timeout()),this,SLOT(slotRepintar()));
}
void MainWindow::paintEvent(QPaintEvent *evento){
    QPainter pintor(this);
    pintor.fillRect(posicionx,posiciony,200,200,QColor("Red"));
}
void MainWindow::slotRepintar(){
    // Ida y vuelta
    if(ciclox){posicionx=posicionx+1;}else{posicionx=posicionx-1;}
    if(!cicloy){posiciony=posiciony-1;}else{posiciony=posiciony+1;}
    // cambiar ciclos
    if(posicionx>=600){ciclox=false;}else if(posicionx<=0){ciclox=true;}
    if(posiciony>=400){cicloy=false;}else if(posiciony<=0){cicloy=true;}
    // pedimos al motor Qt  que repinte la ventana, que la actualice
    update();
}