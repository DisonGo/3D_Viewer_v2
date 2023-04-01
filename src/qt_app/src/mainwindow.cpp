#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFontDatabase>
#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->toolButton_tab1, SIGNAL(clicked()), this, SLOT(choose_file()));
    //connect(ui->comboBox_tab1, SIGNAL(clicked()), this, SLOT(choose_file()));
    connect(ui->pushButton_colorVersh, SIGNAL(clicked()), this, SLOT(choose_color()));
    connect(ui->pushButton_colorLine, SIGNAL(clicked()), this, SLOT(choose_color()));
    connect(ui->pushButton_backgroungColor, SIGNAL(clicked()), this, SLOT(choose_color()));

    /* FONT INCLUDE */
    int idFont = QFontDatabase::addApplicationFont(":/Nunito/Nunito-Regular.ttf");
    QString nunitoRegular = QFontDatabase::applicationFontFamilies(idFont).at(0);
    QFont fRegular(nunitoRegular);

    /* ICON */
    QIcon icon1, icon2, icon3;
    QMatrix matrix;
    QSize size;
    ui->tabWidget->setCornerWidget(0);
    size.setWidth(64);
    size.setHeight(32);
    ui->tabWidget->setIconSize(size);
    icon1.addPixmap(QPixmap(":/icons/note.svg").transformed(matrix,Qt::SmoothTransformation));
    ui->tabWidget->setTabIcon(0, icon1);
    icon2.addPixmap(QPixmap(":/icons/tuner.svg").transformed(matrix,Qt::SmoothTransformation));
    ui->tabWidget->setTabIcon(1, icon2);
    icon3.addPixmap(QPixmap(":/icons/settings.svg").transformed(matrix,Qt::SmoothTransformation));
    ui->tabWidget->setTabIcon(2, icon3);
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
    qDebug()<<color;

}
