#include "colordetector.h"

ColorDetector::ColorDetector(): minDist(100){
    target[0] = target[1] = target[2] = 0;
}
cv::Mat ColorDetector::process(const cv::Mat &image){
    // allocate space if it's not already done
    result.create(image.size(), image.type());


    // set up the iterartors
    cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator itEnd = image.end<cv::Vec3b>();

    cv::Mat_<cv::Vec3b>::iterator itout = result.begin<cv::Vec3b>();
    // iterate over the image
    for(; it != itEnd; ++it, ++itout){
        *itout = getDistance(*it) < minDist ? *it: cv::Vec3b(0, 0, 0);
    }

    return result;
}
void ColorDetector::setMinimumThreshHold(int distance){
    if(distance < 0)
        distance = 0;

    minDist = distance;
}

// setting the target color
void ColorDetector::setTargetColor(unsigned char red,
                                   unsigned char green,
                                   unsigned char blue){

        target[2] = red;
        target[1] = green;
        target[0] = blue;
}
void ColorDetector::setTargetColor(cv::Vec3b &color){
    target = color;
}


int ColorDetector::getDistance(const cv::Vec3b& color){

    return static_cast<int>(cv::norm<int, 3>(cv::Vec3i(color[0] - target[0],
                                                       color[1] - target[1],
                                                       color[2] - target[2])));
}
int ColorDetector::getTargetThreshHold() const{
    return minDist;
}
cv::Vec3b ColorDetector::getTargetColor() const{
    return target;
}
