#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QList>
#include <QTextStream>
#include <QTime>
#include "Interface.hh"

/*class Interface : public QWidget {
    
 public:
     Interface(QWidget *parent = 0);
};


Interface::Interface(QWidget *parent)
    : QWidget(parent) {
           
  QPushButton *quitBtn = new QPushButton("Quit", this);
  quitBtn->setGeometry(50, 40, 75, 30);

  connect(quitBtn, SIGNAL(clicked()), qApp, SLOT(quit()));
}

*/

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
  QTextStream out(stdout);

  QList<QString> politicians_list;
  politicians_list << "Balzac" << "Tolstoy" << "Guldbrassen"
       << "London" << "Galsworthy" << "Sienkiewicz";

  qSort(politicians_list);

  for (int i = 0; i < politicians_list.size(); ++i) {
  
    out << politicians_list.at(i) << endl;
  }

    
  Interface window;

  window.resize(450, 650);  
  window.setWindowTitle("QPushButton");
  window.setToolTip("Button");
  window.show();

  return app.exec();
}