#include <string>
#include <map>

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
        void voiceControl(int mode);
        void setMode(std::string mode);
        void setVideoMode(std::string mode);
        void setPhotoMode(std::string mode);
        void setMultishotMode(std::string mode);
        void setShutterExposure(int exposure);
        void refreshContents();
        void deleteContents();
        void downloadContents();
        std::map<std::string, int> parseContents(std::string);
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
        std::map<std::string, int> m_contents;
        std::string m_currentStatus;
};

static std::map<std::string, int> primaryModes = {{"Video", 0}, {"Photo", 1}, {"Multishot", 2}};
static std::map<std::string, int> videoSubmodes = {{"Video", 0}, {"Timelapse", 1}, {"VideoPhoto", 2}, {"Looping", 3}, {"Timewarp", 4}};
static std::map<std::string, int> photoSubmodes = {{"Single", 0}, {"Continuous", 1}, {"Night", 2}};
static std::map<std::string, int> multishotSubmodes = {{"Burst", 0}, {"Timelapse", 1}, {"Nightlapse", 2}};
