#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include "delegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Custom Table View");
    setFixedSize(570, 180);

    delegate* Delegate = new delegate(this);
    tablemodel = new table(this);
    QTableView* tableview = new QTableView(this);
    tableview->resize(width(),height());
    tableview->setFont(QFont("Arial",12));
    tableview->setAlternatingRowColors(true);
    tableview->setModel(tablemodel);
    tableview->setColumnWidth(0, 150);
    tableview->setColumnWidth(1, 200);
    tableview->setColumnWidth(2, 200);
    tableview->setItemDelegate(Delegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

