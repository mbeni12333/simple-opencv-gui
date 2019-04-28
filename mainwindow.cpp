#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colordetectorcontroller.h"
#include <opencv2/opencv.hpp>
#include <QImage>
#include <iostream>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    ColorDetectorController *controller = ColorDetectorController::getInstance();
    // Initialize the algorithm
    controller->setInputImage("D:/gorilla.png");
    controller->setTargetColor(232, 225, 135);
    controller->setColorDistanceThreshHold(30);
    // do the work
    controller->process();
    cv::Mat image = controller->getLastResult();

    //ui->imageLabel->setPixmap(QPixmap::fromImage(img));
    //ui->imageLabel->resize(ui->imageLabel->pixmap()->size());
    // show it
    cv::namedWindow("result");
    //cv::imshow("result", image);
    cv::imshow("result", controller->getInputImage());
    // read an image
     /*cv::Mat image = cv::imread("D:/gorilla.png");
     if(!image.data){
         std::cout<<"ya7re9 JED MOUk";
     }
     // create image window named "My Image"
     cv::namedWindow("FUCK YEAAAH");
     // show the image on window
     cv::imshow("FUCK YEAAAH", image);*/
}
QImage cv2qt(cv::Mat image){
    // flip the image on the first axis
    cv::flip(image, image, 1);
    // convert the color space
    cv::cvtColor(image, image, CV_BGR2RGB);
    // instantiate a QImage
    QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, image.step1(), QImage::Format_RGB888);

    return img;
}
MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_open_clicked(){

}

void MainWindow::on_colorPicker_clicked(){

}

void MainWindow::on_threshhold_valueChanged(int value){

}

void MainWindow::on_process_clicked(){

}
