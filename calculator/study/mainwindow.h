#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void newFile();   // 新建操作
    bool maybeSave();
    bool save();
    bool saveAs();
    bool saveFile(const QString &filenamne);
    bool loadFile(const QString &fileName); // 加载文件

protected:
    void closeEvent(QCloseEvent *event); // 关闭事件

private slots:
    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionOpen_triggered();

    void on_actionClose_triggered();

    void on_actionundo_triggered();

    void on_actioncut_triggered();

    void on_actioncopy_triggered();

    void on_actionpast_triggered();

private:
    Ui::MainWindow *ui;
    // 为真表示文件没有保存过，为假表示文件已经被保存过了
    bool isUntitled;
    // 保存当前文件的路径
    QString curFile;
};
#endif // MAINWINDOW_H
