#include "mplots.h"
#include "ui_mplots.h"

mPlots::mPlots(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mPlots)
{
    ui->setupUi(this);
    setupPlot();
}

mPlots::~mPlots()
{
    delete ui;
}

void
mPlots::setupPlot(void) {
    //Setup default setting
    setupDefault();

    //Enable only doubles in range lines
    ui->Left_Side->setValidator(new QDoubleValidator(this));
    ui->Right_Side->setValidator(new QDoubleValidator(this));

    //Enable only unsighned in split range
    QRegExp rx("[0-9]+");
    ui->SplitEdit->setValidator(new QRegExpValidator(rx , this));


    connect(ui->Function,   SIGNAL(textChanged(const QString &)) ,
            this , SLOT(Function2ButtonOk(const QString &)));
    connect(ui->Left_Side,  SIGNAL(textChanged(const QString &)) ,
            this , SLOT(Function2ButtonOk(const QString &)));
    connect(ui->Right_Side, SIGNAL(textChanged(const QString &)) ,
            this , SLOT(Function2ButtonOk(const QString &)));
    connect(ui->SplitEdit,  SIGNAL(textChanged(const QString &)) ,
            this , SLOT(Function2ButtonOk(const QString &)));
}

void
mPlots::setupDefault(void) {
    //Default buttons' state
    ui->ButtonOk->setEnabled(true);
    ui->ButtonClear->setEnabled(true);

    //Default text
    ui->Function->setText("x^2");
    ui->Left_Side->setText("-1");
    ui->Right_Side->setText("1");
    ui->SplitEdit->setText("1000");


    //Default setting for plot
    ui->pl->xAxis->setRange(0,1);
    ui->pl->yAxis->setRange(0,1);

    ui->pl->clearGraphs();
    ui->pl->clearItems();
    ui->pl->clearPlottables();
    ui->pl->clearMask();
    ui->pl->clearFocus();
    ui->pl->replot();
}

void
mPlots::Function2ButtonOk(const QString & str) {
    QString left_range  = ui->Left_Side->text();
    QString right_range = ui->Right_Side->text();
    QString function    = ui->Function->text();
    QString split       = ui->SplitEdit->text();

    if(left_range.isEmpty() ||
        right_range.isEmpty() ||
        function.isEmpty() ||
        split.isEmpty())  {
        ui->ButtonOk->setEnabled(false);
        ui->ButtonClear->setEnabled(false);
    }
    else {
        //Check left and right range
        double left  = ui->Left_Side->text().toDouble();
        double right = ui->Right_Side->text().toDouble();

        if(left >= right) {
            ui->Left_Side->setStyleSheet("QLineEdit {background-color: red;}");
            ui->Right_Side->setStyleSheet("QLineEdit {background-color: red;}");
        }
        else {
            ui->Left_Side->setStyleSheet("QLineEdit {background-color: white;}");
            ui->Right_Side->setStyleSheet("QLineEdit {background-color: white;}");

            ui->ButtonOk->setEnabled(true);
            ui->ButtonClear->setEnabled(true);
        }
    }
}


void
mPlots::on_ButtonClear_clicked()
{
    setupDefault();
}

void
mPlots::on_ButtonOk_clicked()
{
    QString function = ui->Function->text();



    ui->Function->setEnabled(false);
    buildGraph(((const QString)function));
    ui->Function->setEnabled(true);
}

void
mPlots::buildGraph(const QString & s) {
    std::string str = s.toStdString();

    QString xaxis_name = ui->XAxisName->text();
    QString yaxis_name = ui->YAxisName->text();

    int split = ui->SplitEdit->text().toInt();

    double left_range = ui->Left_Side->text().toDouble();
    double right_range = ui->Right_Side->text().toDouble();

    double maxY = 0.0;
    double minY = 0.0;

    double k = (right_range - left_range) / split;
    QVector<double> x(split), y(split); // initialize with entries 0..100
    for(int i=0; i<split; ++i)
    {
      x[i] = i*k + left_range; // x goes from left_range to right_range
      y[i] = x[i] * x[i];

      if(i == 0) {
          maxY = minY = y[0];
      }
      else if(maxY < y[i]) maxY = y[i];
      else if(minY > y[i]) minY = y[i];
    }


    // create graph and assign data to it:
    ui->pl->addGraph();
    ui->pl->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->pl->xAxis->setLabel(xaxis_name.isEmpty() ? "x" : xaxis_name);
    ui->pl->yAxis->setLabel(yaxis_name.isEmpty() ? "y" : yaxis_name);
    // set axes ranges, so we see all data:
    ui->pl->xAxis->setRange(left_range, right_range);
    ui->pl->yAxis->setRange(minY, maxY);

    ui->pl->replot();
}



void mPlots::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save file");

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << file.errorString();
    } else {
        ui->pl->savePng(fileName);
    }
}
