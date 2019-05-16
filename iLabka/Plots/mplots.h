#ifndef PLOT_H
#define PLOT_H

#include <QWidget>
#include <QValidator>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QKeyEvent>


#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>
#include <QLineEdit>

#include "../../decoder/Decoder.h"
#include "../../checker/Checker.h"
#include "../../checker/utils/EmptyStringException.h"
#include "../../parallel/execute.h"

namespace Ui {
class mPlots;
}

class mPlots : public QWidget
{
    Q_OBJECT

public:
    explicit mPlots(QWidget *parent = nullptr);
    ~mPlots();

    const QPushButton & getButtonOk(void);
    QLineEdit         & getFunction(void);

    bool getButtonStatus(void);

    void buildGraph(const QString &);

private:
    Ui::mPlots *ui;

    void setupPlot(void);
    void setupDefault(void);

private slots:
    void Function2ButtonOk(const QString &);
    void on_ButtonClear_clicked();
    void on_ButtonOk_clicked();
    void on_pushButton_clicked();
};

#endif // MPLOTS_H
