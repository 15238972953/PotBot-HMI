#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QString>
#include <QMessageBox>

// 构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      robotRunning(false)
{
    ui->setupUi(this);

    ui->ReadyStatusValueLabel->setText("Idle");
    ui->BatteryValueLabel->setText("0%");
    ui->YawAngleValueLabel->setText("0");

    ui->LatitudeValueLabel->setText("0.0");
    ui->LongitudeValueLabel->setText("0.0");
}

// 析构函数
MainWindow::~MainWindow()
{
    delete ui;
}

// 开始运行按钮的槽函数
void MainWindow::on_StartLabel_clicked()
{
    robotRunning = !robotRunning;

    if(robotRunning)
    {
        ui->StartLabel->setText("STOP");
        ui->ReadyStatusValueLabel->setText("Running");

        qDebug() << "Robot Started";
    }
    else
    {
        ui->StartLabel->setText("START");
        ui->ReadyStatusValueLabel->setText("Stopped");

        qDebug() << "Robot Stopped";
    }
}

// 设置按钮的槽函数
void MainWindow::on_SettingLabel_clicked()
{
    QMessageBox::information(
        this,
        "Software Information",
        "PotBot HMI\n"
        "Version: 1.0\n"
        "Author: Peng Defeng\n"
        "Robot: Pot Transport Robot\n"
        "Platform: Jetson Orin Nano"
    );
}

void MainWindow::updateYawAngle(double angle)
{
    ui->YawAngleValueLabel->setText(QString::number(angle,'f',2));
}

void MainWindow::updateBattery(int value)
{
    ui->BatteryValueLabel->setText(QString::number(value) + "%");
}

void MainWindow::updateLatitude(double lat)
{
    ui->LatitudeValueLabel->setText(QString::number(lat,'f',6));
}

void MainWindow::updateLongitude(double lon)
{
    ui->LongitudeValueLabel->setText(QString::number(lon,'f',6));
}