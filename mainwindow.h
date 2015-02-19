#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QFile>
#include <qxmlstream.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_InsertButton_clicked();

    void on_pushButtonPing_clicked();


    void on_pushButtonDelete_clicked();

    void on_pushButtonClear_clicked();

    void on_checkBox_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
