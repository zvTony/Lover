#include "crm.h"
#include "ui_crm.h"

crm::crm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::crm)
{
    ui->setupUi(this);
}

crm::~crm()
{
    delete ui;
}
