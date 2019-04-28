#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class ColorDetector{
    public:
        ColorDetector();
        cv::Mat process(const cv::Mat &image);
        void setMinimumThreshHold(int distance);

        // setting the target color
        void setTargetColor(unsigned char red,
                            unsigned char green,
                            unsigned char blue);
        void setTargetColor(cv::Vec3b &color);
        int getDistance(const cv::Vec3b& color);
        int getTargetThreshHold() const;
        cv::Vec3b getTargetColor() const;

    private:

        // minimum acceptable distance
        int minDist;
        // Target color
        cv::Vec3b target;
        // image containing resulting binary map
        cv::Mat result;


};

#endif // COLORDETECTOR_H
