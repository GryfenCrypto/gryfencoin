#ifndef GRYFXPAGE_H
#define GRYFXPAGE_H


#include <QWidget>
#include <QString>

class QWebView;
namespace Ui {
    class GryfxWidget;
}
class GryfxPage: public QWidget
{
      Q_OBJECT

public:
    explicit GryfxPage(QWidget *parent = 0);
    ~GryfxPage();

    void loadGryfxPage();


private:
    Ui::GryfxWidget *ui;
    QWebView *gryfxView;

};



#endif // GRYFXPAGE_H
