#include "gryfxpage.h"
#include "ui_gryfx.h"
#include <QtWebKitWidgets>


GryfxPage::GryfxPage(QWidget *parent) :QWidget(parent),
    ui(new Ui::GryfxWidget)
{
    ui->setupUi(this);
    gryfxView = new QWebView(this);
//    ui->verticalLayout->addWidget(gryfxView);
    loadGryfxPage();
    gryfxView->show();
}

void GryfxPage::loadGryfxPage()
{
     gryfxView->load(QUrl("http://gryfx.com"));
}


GryfxPage::~GryfxPage()
{
    delete ui;
}

