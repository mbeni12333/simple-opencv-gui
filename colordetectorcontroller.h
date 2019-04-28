#ifndef COLORDETECTORCONTROLLER_H
#define COLORDETECTORCONTROLLER_H

#include "colordetector.h"

class ColorDetectorController{
    public:
        ColorDetectorController();
        ~ColorDetectorController();
        static ColorDetectorController* getInstance();
        static void destroy();
        // color threshhold getters and setters
        void setColorDistanceThreshHold(int distance);
        int getColorDistanceThreshHold() const;


        // target color getters and setters
        void setTargetColor(unsigned char red,
                            unsigned char green,
                            unsigned char blue);

        void getTargetColor(unsigned char &red,
                            unsigned char &green,
                            unsigned char &blue) const;
        //void setTargetColor(cv::Vec3b color);
        //cv::Vec3b getTargetColor();
        // images getters and setters
        bool setInputImage(std::string filename);
        const cv::Mat getInputImage() const;
        void process();
        const cv::Mat getLastResult() const;
    private:
        // singleton
        static ColorDetectorController* singleton;
        // the algorithm
        ColorDetector *cdetect;
        // the image
        cv::Mat image;
        // the result
        cv::Mat result;
};

#endif // COLORDETECTORCONTROLLER_H
