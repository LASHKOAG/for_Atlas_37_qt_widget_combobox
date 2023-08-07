#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnOn, SIGNAL(clicked()), this, SLOT(on_btnOn()));
    connect(ui->btnOff, SIGNAL(clicked()), this, SLOT(on_btnOff()));
    connect(ui->chkBlinkBlue, SIGNAL(clicked()), this, SLOT(on_chkBlinkBlueClicked()));

    ui->comboBoxPort->addItem("None");
    ui->comboBoxPort->addItem("/dev/ttyUSB0");
    ui->comboBoxPort->addItem("/dev/ttyUSB1");

    ui->comboBoxSpeed->addItem("None");
    ui->comboBoxSpeed->addItem("9600");
    ui->comboBoxSpeed->addItem("19200");

    qDebug() << ui->comboBoxPort->currentIndex();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOn()
{
    qDebug() << "btnOn Clicked";
    system("./py_led_on.py");
}

void MainWindow::on_btnOff()
{
    qDebug() << "btnOff Clicked";
    system("./py_led_off.py");
}

void MainWindow::on_chkBlinkBlueClicked()
{
    qDebug() << "---------------------------------------------";
    qDebug() << "Checkbox blink blue clicked";
    if (ui->chkBlinkBlue->isChecked())
    {
        qDebug() << "State: True";
//        isCheckBoxBlinkBlue = true;
        isCheckBoxBlinkBlue = !isCheckBoxBlinkBlue;
    }
    if (!ui->chkBlinkBlue->isChecked())
    {
        qDebug() << "State: False";
        isCheckBoxBlinkBlue = !isCheckBoxBlinkBlue;
    }
    qDebug() << "---------------------------------------------";
}

void MainWindow::on_checkBoxForGetSensorData_stateChanged(int arg1)
{
    qDebug() << "++++++++++++++++++++++++++++++++++++++++++++++++++++";
    qDebug() << "Checkbox state changed";
    if (ui->checkBoxForGetSensorData->isChecked())
    {
        qDebug() << "True";
        qDebug() << "arg1: " << arg1;
        Qt::Checked;
    }
    if (!ui->checkBoxForGetSensorData->isChecked())
    {
        qDebug() << "False";
        qDebug() << "arg1: " << arg1;
    }

    qDebug() << "++++++++++++++++++++++++++++++++++++++++++++++++++++";
}

void MainWindow::on_comboBoxPort_activated(const QString &arg1)
{
    qDebug() << "vomboBoxPort: activated;\n" << ui->comboBoxPort->currentIndex();
}

void MainWindow::on_comboBoxSpeed_activated(const QString &arg1)
{
    qDebug() << arg1;
    qDebug() << "vomboBoxSpeed: activated;\n" << ui->comboBoxSpeed->currentIndex();
    qDebug() << ui->comboBoxSpeed->currentText();
}
