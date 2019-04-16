#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if( !fileName.isEmpty())
    {
        ui->textEdit->setText(fileName);
        readDatFile(fileName.toStdString());
    }
}

void MainWindow::readDatFile(const std::string fileName)
{

    in.open(fileName.c_str());

    if(in.rdstate())
        QMessageBox::information(this, tr("Application Name"), tr("Невозможно открыть файл ") );
    if( !in)
    {
        QMessageBox::information(this,
            tr("Application Name"),
            tr("Невозможно открыть файл ") );
    }
    else
        QMessageBox::information(this, tr("readDAT"), tr("File is open"));
    in.close();
}
