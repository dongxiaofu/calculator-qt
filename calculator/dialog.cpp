#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_loginBtn_clicked()
{
    // 判断用户名和密码是否正确，
    // 如果错误则弹出警告对话框
        if(ui->userLineEdit->text().trimmed() == tr("cg") &&
               ui->pwdLineEdit->text() == tr("123456"))
        {
           accept();
        } else {
           QMessageBox::warning(this, tr("Waring"),
                                 tr("user name or password error!"),
                                 QMessageBox::Yes);
           ui->userLineEdit->clear();
           ui->pwdLineEdit->clear();
           ui->userLineEdit->setFocus();
        }
}
