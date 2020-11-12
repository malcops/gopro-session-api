#include <string>

class GoPro {

    public:
        GoPro();
        // commands
        void keepOn();
        void takePhoto();
        void startVideo();
        void stopVideo();
        void locateOn();
        void locateOff();
        void setPhotoMode(int mode);
        void setShutterExposure(int exposure);
        std::string getStatus();

        // status
        std::string cameraName();
        unsigned getBatteryLevel();
        bool sdCardInserted();
        unsigned getMode();
        unsigned getSubMode();
        unsigned getSpaceRemaining();
        // settings
        unsigned getOrientation();
        void printDifference(std::string string1, std::string string2);
        std::string m_currentStatus;
};

