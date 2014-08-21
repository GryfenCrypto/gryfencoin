#include "gryfxpage.h"
#include "ui_gryfx.h"


GryfxPage::GryfxPage(QWidget *parent) :QWidget(parent),
    ui(new Ui::GryfxWidget)
{
    ui->setupUi(this);
}



GryfxPage::~GryfxPage()
{
    delete ui;
}

