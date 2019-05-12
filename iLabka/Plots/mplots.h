#ifndef PLOT_H
#define PLOT_H

#include <QWidget>
#include <QValidator>


#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>

#include "../GraphBuilder-develop/decoder/Decoder.h"
#include "../GraphBuilder-develop/checker/Checker.h"
#include "../GraphBuilder-develop/tests/tests.h"
#include "../GraphBuilder-develop/checker/utils/EmptyStringException.h"
#include "../GraphBuilder-develop/parallel/execute.h"


namespace Ui {
class mPlots;
}

class mPlots : public QWidget
{
    Q_OBJECT

public:
    explicit mPlots(QWidget *parent = nullptr);
    ~mPlots();

private:
    Ui::mPlots *ui;

    void setupPlot(void);
    void setupDefault(void);
    void buildGraph(const QString &);

private slots:
    void Function2ButtonOk(const QString &);
    void on_ButtonClear_clicked();
    void on_ButtonOk_clicked();
    void on_pushButton_clicked();
};

#endif // MPLOTS_H
