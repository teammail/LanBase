#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ipbankclass.h"

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

void MainWindow::on_InsertButton_clicked()
{   // Переменные для хранения IP  и Имени хоста
    QString strIP = ui->lineEditIP->text();
    QString strName = ui->lineEditName->text();
    if (strIP != NULL && strName != NULL) // Проверяем, что данные введены
    {
        ui->treeWidgetIP->setFocus(); // Устанавливаем фокус на наше дерево
        // Если отмечена установка подгруппы оборудования
        if (ui->checkBox->isChecked()){
            // Создаем дочерний объект от выделенного
            QTreeWidgetItem *Name = new QTreeWidgetItem(ui->treeWidgetIP->currentItem());
            Name->setText(0, tr(strName.toStdString().c_str()));
            Name->setText(1, tr(strIP.toStdString().c_str()));
        }else {
            QTreeWidgetItem *Name = new QTreeWidgetItem(ui->treeWidgetIP);
            Name->setText(0, tr(strName.toStdString().c_str()));
        }
    }
    else {
        ui->textEditConsole->append("Неверно IP-адрес или Имя Хоста");
    }



}

void MainWindow::on_pushButtonPing_clicked()
{
    /*if (ui->listWidget->currentItem()->isSelected()
            &&
        ui->listWidget->currentItem() != NULL) {
            // Функция пинг через системную консоль
            // Передать необходимо IP
            QString strIP = "ping " + ui->listWidget->currentItem()->text() + " -t";
            const char* str = strIP.toStdString().c_str(); //
            system(str);
            ui->textEditConsole->append("Пинг " + strIP + " перенаправлен в консоль ");
    }
            else {
            ui->textEditConsole->append(" Не выбран элемент! ");
    }*/
}

void MainWindow::on_pushButtonDelete_clicked()
{
    if (ui->treeWidgetIP->currentItem() != NULL)
    ui->textEditConsole->append(" Элемент удалён! ");
    delete ui->treeWidgetIP->currentItem();

}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->treeWidgetIP->clear();
    ui->textEditConsole->append(" Очищен список элементов! ");
}

void MainWindow::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
        ui->lineEditIP->setEnabled(true);
    else ui->lineEditIP->setEnabled(false);
}
// Открываем XML файл
void MainWindow::on_action_triggered()
{
    QFile* file = new QFile("config.xml");
        if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->textEditConsole->append("Невозможно открыть XML-конфиг");
        }
        QXmlStreamReader xml(file);
}

void MainWindow::on_action_2_triggered()
{
   // QTreeWidgetItemIterator it(&twg, QTreeWidgetItemIterator::All);
    //while(*(++it))
    //{
    //qDebug()<<(*it)->text(1);
    //}
}
