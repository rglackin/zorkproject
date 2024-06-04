#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    driverInstance(ZorkUL::getInstance())
{
    ui->setupUi(this);
    setupRoom();

}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupRoom(){
    ui->lblRoomName->setText("Room: "+QString::fromStdString(driverInstance.currentRoom->getName()));
    ui->lblDesc->setText(QString::fromStdString(driverInstance.currentRoom->getDescription()));
    ui->lblRoomName->adjustSize();
    ui->lblDesc->adjustSize();
    ui->lblOutput->setText("");
    ui->lblOutput->adjustSize();

}

void MainWindow::on_btnNorth_clicked()
{
    //call
    goCommand(Direction::NORTH);

}
void MainWindow::on_btnEast_clicked()
{
    goCommand(Direction::EAST);

}
void MainWindow::on_btnSouth_clicked()
{
    goCommand(Direction::SOUTH);
}
void MainWindow::on_btnWest_clicked()
{
    goCommand(Direction::WEST);
}
void MainWindow::goCommand(Direction d){
    string output = driverInstance.go(d);
    if(output == ""){
        setupRoom();
    }
    //dont setup room if no change is made, output only made when exit is invalid
    else{
        ui->lblOutput->setText(QString::fromStdString(output));
        ui->lblOutput->adjustSize();
    }


}
