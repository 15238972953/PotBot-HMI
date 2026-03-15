#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateYawAngle(double angle);
    void updateBattery(int value);
    void updateLatitude(double lat);
    void updateLongitude(double lon);

private slots:

    // 开始运行按钮的槽函数
    void on_StartLabel_clicked();
    // 设置按钮的槽函数
    void on_SettingLabel_clicked();

private:

    Ui::MainWindow *ui;

    bool robotRunning;
};

#endif