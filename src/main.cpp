#include "mainwindow.h"

#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // 设置应用程序信息
    QApplication::setApplicationName("PotBot HMI");
    QApplication::setApplicationVersion("2.1.0");
    QApplication::setOrganizationName("Peng Defeng");
    
    // 创建主窗口
    MainWindow w;
    
    // 显示主窗口（会自动全屏）
    w.show();
    
    return a.exec();
}