#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menubar->addMenu("Test");
    ui->pushButton->setText("新窗口"); //将界面上按钮的显示文本更改为“新窗口”

    // 创建新的动作
    QAction *openAction = new QAction(tr("&Open"), this);
    // 设置快捷键
    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));
    // 在文件菜单中设置新的打开动作
    ui->menu_F->addAction(openAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QDialog *dlg = new QDialog(this);
    dlg->show();
}
