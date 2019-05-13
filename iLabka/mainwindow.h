#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QFileDialog>
#include <QInputDialog>

#include "Plots/mplots.h"
#include "Info/About_iLabka/about_ilabka.h"
#include "../qcustomplot/qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionExit_triggered();
    void on_actionSave_triggered();

    void on_actionAbout_iLabka_triggered();

    void on_tabWidget_Plots_tabCloseRequested(int index);

    void on_actionClose_current_Plot_triggered();

private:
    QString projectName = "iLabka";
    Ui::MainWindow * ui;
    About_iLabka * about_ilabka;

    void setupWindow(void);
};

#endif // MAINWINDOW_H
