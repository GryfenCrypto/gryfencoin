#ifndef GRYFXPAGE_H
#define GRYFXPAGE_H


#include <QWidget>

namespace Ui {
    class GryfxWidget;
}
class GryfxPage: public QWidget
{
      Q_OBJECT

public:
    explicit GryfxPage(QWidget *parent = 0);
    ~GryfxPage();


private:
    Ui::GryfxWidget *ui;

};



#endif // GRYFXPAGE_H
