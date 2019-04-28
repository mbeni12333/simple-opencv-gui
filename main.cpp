#include "mainwindow.h"
#include <QApplication>
#include "colordetectorcontroller.h"
#include<opencv2/opencv.hpp>
//#include<opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[]){

    //cv::Mat image = cv::imread("gorilla.png");
    //cv::namedWindow("Finnaly");
   // cv::imshow("Finnaly", image);
    //cv::waitKey(5000);

    // get the singleton


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
