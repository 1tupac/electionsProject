#pragma once 
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QList>
#include <QTextStream>
#include <iostream>




class Interface : public QWidget {
    
 public:
     Interface(QWidget *parent = 0);
     void update();

};