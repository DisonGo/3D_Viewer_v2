#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->toolButton_tab1, SIGNAL(clicked()), this, SLOT(choose_file()));
    connect(ui->comboBox_tab1, SIGNAL(clicked()), this, SLOT(choose_file()));
    //connect(ui->visualisation_form, SIGNAL(clicked()), this, SLOT(choose_file()));
    //connect(ui->tabWidget, SIGNAL(clicked()), this, SLOT(choose_file()));
    connect(ui->pushButton_colorLine, SIGNAL(clicked()), this, SLOT(choose_color()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::choose_file(){
    //ui->tabWidget->tab_1->setIcon(QIcon("/home/mortalan/Downloads/note.svg"));
    //ui->tabWidget->tab_2->setIcon(QIcon("/home/mortalan/Downloads/tuner.svg"));
    /*ui->comboBox->addItem("kitten");
    ui->comboBox->addItem("car");
    ui->comboBox->addItem("plane");*/

    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "/home/mortalan/",
                "All files (*.*);;Text File (*.txt);;Objects (*.obj)"
                );
    //QMessageBox::information(this, tr("File Name"), filename);
    ui->comboBox_tab1->addItem(filename);

}

void MainWindow::choose_color(){
    QColor color = QColorDialog::getColor(Qt::red, this);

}
