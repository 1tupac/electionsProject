
#include "Interface.hh"
#include <QTime>


Interface::Interface(QWidget *parent)
    : QWidget(parent) {
           
  QPushButton *quitBtn = new QPushButton("Quit", this);
  quitBtn->setGeometry(50, 40, 75, 30);
  connect(quitBtn, SIGNAL(clicked()), qApp, SLOT(quit()));


  QPushButton *update = new QPushButton("update", this);
  update->setGeometry(200,200,50,50);
  connect(update, SIGNAL(clicked()), qApp, SLOT(update()));


}

void Interface::update()
{
	QTime ct = QTime::currentTime();	
	std::cout << "Time: " << std::endl;
}