#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::setupWindow(void) {
    setWindowTitle(projectName);

    setWindowIcon(QIcon("C:/Programming/iLabka/GraphBuilder-1/iLabka/Info/iLabka(GraphBuilder)"));

    //delete one tab with plot
    ui->tabWidget_Plots->removeTab(1);
}

void
MainWindow::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
        case Qt::Key_F7:
        {
        if(!ui->tab->getButtonStatus()) {
            QString function = ui->tab->getFunction().text();

            ui->tab->getFunction().setEnabled(false);
            ui->tab->buildGraph((static_cast<const QString>(function)));
            ui->tab->getFunction().setEnabled(true);
        }
        }
        break;

    }
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionNew_triggered()
{
    bool ok = true;
    QString plot_name = "1";

    do {
        if(plot_name.isEmpty())
            QMessageBox::information(this, "New Plot", "Name can not be empty");

        plot_name = QInputDialog::getText(this,
                                          "New Plot",
                                          "Plot Name:",
                                          QLineEdit::Normal,
                                          "Plot",
                                          &ok);
        if(!ok)
            return;
    } while(plot_name.isEmpty());

   ui->tabWidget_Plots->addTab(new mPlots(), plot_name);
}

void MainWindow::on_actionAbout_iLabka_triggered()
{
    about_ilabka = new About_iLabka(this);
    about_ilabka->show();
}



void MainWindow::on_tabWidget_Plots_tabCloseRequested(int index)
{
    ui->tabWidget_Plots->removeTab(index);
}

void MainWindow::on_actionClose_current_Plot_triggered()
{
    int index = ui->tabWidget_Plots->currentIndex();
    ui->tabWidget_Plots->removeTab(index);
}
