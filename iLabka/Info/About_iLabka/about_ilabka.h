#ifndef ABOUT_ILABKA_H
#define ABOUT_ILABKA_H

#include <QDialog>

namespace Ui {
class About_iLabka;
}

class About_iLabka : public QDialog
{
    Q_OBJECT

public:
    explicit About_iLabka(QWidget *parent = nullptr);
    ~About_iLabka();

private slots:
    void on_pushButton_clicked();

private:
    Ui::About_iLabka *ui;
};

#endif // ABOUT_ILABKA_H
