#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QCustomPlot *plot = new QCustomPlot(this);
    QVector<double> x(101), y(101);
    plot->resize(600, 400);
    for (int i = 0; i < 101; ++i)
    {
        x[i] = 3 * i;
        y[i] = x[i] * 10;
    }
    QCPGraph *pGraph0 = plot->addGraph();

    plot->graph(0)->setData(x, y);
    plot->xAxis->setLabel("x轴");
    plot->yAxis->setLabel("y轴");


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

