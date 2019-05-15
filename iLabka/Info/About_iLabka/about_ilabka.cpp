#include "about_ilabka.h"
#include "ui_about_ilabka.h"

About_iLabka::About_iLabka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About_iLabka)
{
    ui->setupUi(this);
    setWindowTitle("About iLabka");
}

About_iLabka::~About_iLabka()
{
    delete ui;
}

void About_iLabka::on_pushButton_clicked()
{
    this->close();
}
