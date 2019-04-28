#include "colordetectorcontroller.h"

ColorDetectorController* ColorDetectorController::singleton = 0;

ColorDetectorController::ColorDetectorController(){
    cdetect = new ColorDetector;
}
ColorDetectorController::~ColorDetectorController(){
    delete cdetect;
}
ColorDetectorController* ColorDetectorController::getInstance(){
    // create instance once
    if(!singleton)
        singleton = new ColorDetectorController;

    return singleton;
}
void ColorDetectorController::destroy(){
    if(singleton)
        delete singleton;
    singleton = 0;
}
// color threshhold getters and setters
void ColorDetectorController::setColorDistanceThreshHold(int distance){
    cdetect->setMinimumThreshHold(distance);
}
int ColorDetectorController::getColorDistanceThreshHold() const{
    return cdetect->getTargetThreshHold();
}

// target color getters and setters
void ColorDetectorController::setTargetColor(unsigned char red,
                                             unsigned char green,
                                             unsigned char blue){
    cdetect->setTargetColor(red, green, blue);
}

void ColorDetectorController::getTargetColor(unsigned char &red,
                                             unsigned char &green,
                                             unsigned char &blue) const{
    cv::Vec3b color = cdetect->getTargetColor();
    red = color[2];
    green = color[1];
    blue = color[0];
}
//void setTargetColor(cv::Vec3b color);
//cv::Vec3b getTargetColor();
// images getters and setters
bool ColorDetectorController::setInputImage(std::string filename){
    image = cv::imread(filename);

    return image.data != nullptr;
}
const cv::Mat ColorDetectorController::getInputImage() const{
    return image;
}
void ColorDetectorController::process(){
    result = cdetect->process(image);
}
const cv::Mat ColorDetectorController::getLastResult() const{
    return result;
}
