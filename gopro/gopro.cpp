#include "gopro.hpp"
#include "HTTPRequest.hpp"
#include "json.hpp"

GoPro::GoPro(){}

void GoPro::printDifference(std::string string1, std::string string2){
    // useful for determining the relationship between JSON entries and camera settings
    std::cout << "printDifference" << std::endl;
    auto string1Json = nlohmann::json::parse(string1.c_str());
    auto string2Json = nlohmann::json::parse(string2.c_str());

    // status
    auto status1 = string1Json["status"];
    auto status2 = string2Json["status"];
    nlohmann::json::iterator status1It= status1.begin();
    nlohmann::json::iterator status2It = status2.begin();
    for (; status1It != status1.end(); ++status1It, ++status2It) {
        if (status1It.value() != status2It.value()){
            std::cout << "Status changed: " << status1It.key() << " : " << status1It.value() << " ==> " << status2It.key() << " : " << status2It.value() << std::endl;
        }
    }

    // settings
    auto settings1 = string1Json["settings"];
    auto settings2 = string2Json["settings"];
    nlohmann::json::iterator settings1It = settings1.begin();
    nlohmann::json::iterator settings2It = settings2.begin();
    for (; settings1It != settings1.end(); ++settings1It, ++settings2It) {
        if (settings1It.value() != settings2It.value()){
            std::cout << "Setting changed: " << settings1It.key() << " : " << settings1It.value() << " ==> " << settings2It.key() << " : " << settings2It.value() << std::endl;
        }
    }
}

void GoPro::keepOn(){
    std::string keepOn = "http://10.5.5.9/gp/gpControl/setting/59/0";
    HTTPRequest request1(keepOn);
    std::cout << request1.execute() << std::endl;
}

void GoPro::takePhoto(){
    std::string photoMode = "http://10.5.5.9/gp/gpControl/command/mode?p=1";
    HTTPRequest request1(photoMode);
    request1.execute();

    std::string start = "http://10.5.5.9/gp/gpControl/command/shutter?p=1";
    HTTPRequest request2(start);
    request2.execute();
}

void GoPro::startVideo(){

    std::string videoMode = "http://10.5.5.9/gp/gpControl/command/mode?p=0";
    HTTPRequest request1(videoMode);
    request1.execute();

    std::string start = "http://10.5.5.9/gp/gpControl/command/shutter?p=1";
    HTTPRequest request2(start);
    request2.execute();
}

void GoPro::stopVideo(){

    std::string stop = "http://10.5.5.9/gp/gpControl/command/shutter?p=0";
    HTTPRequest request(stop);
    request.execute();
}

void GoPro::locateOn(){

    std::string locate = "http://10.5.5.9/gp/gpControl/command/system/locate?p=1";
    HTTPRequest request(locate);
    request.execute();
}

void GoPro::locateOff(){

    std::string locate = "http://10.5.5.9/gp/gpControl/command/system/locate?p=0";
    HTTPRequest request(locate);
    request.execute();
}

void GoPro::setPhotoMode(int mode){

        char buf[100];
        snprintf(buf, sizeof(buf), "http://10.5.5.9/gp/gpControl/command/sub_mode?mode=1&sub_mode=%d", mode);
        std::string photoMode(buf);
        std::cout << photoMode << std::endl;
        HTTPRequest request(photoMode);
        request.execute();
}

void GoPro::setShutterExposure(int setting){

        char buf[100];
        snprintf(buf, sizeof(buf), "http://10.5.5.9/gp/gpControl/setting/19/%d", setting);
        std::string exposure(buf);
        std::cout << exposure << std::endl;
        HTTPRequest request(exposure);
        request.execute();
}

std::string GoPro::getStatus(){
    std::string status = "http://10.5.5.9/gp/gpControl/status";
    HTTPRequest request(status);
    std::string response = request.execute();
    this->m_currentStatus = response;
    return response;
}

unsigned GoPro::getBatteryLevel(){
    // 4 = Charging
    // 3 = Full
    // 2 = Halfway
    // 1 = Low
    // 0 = Empty
    auto j = nlohmann::json::parse(this->m_currentStatus.c_str());
    unsigned batteryLevel = j["status"]["2"];
    return batteryLevel;
}

std::string GoPro::cameraName(){
    auto j = nlohmann::json::parse(this->m_currentStatus.c_str());
    std::string name = j["status"]["30"];
    return name;
}

bool GoPro::sdCardInserted(){
    // 0 - inserted
    // 2 - not found
    auto j = nlohmann::json::parse(this->m_currentStatus.c_str());
    unsigned inserted = j["status"]["33"];
    bool sdCardInserted = not static_cast<bool>(inserted);
    return sdCardInserted;
}

unsigned GoPro::getMode(){
    // Video - 0
    // Photo - 1
    // MultiShot - 2
    auto j = nlohmann::json::parse(this->m_currentStatus.c_str());
    unsigned currentMode = j["status"]["43"];
    return currentMode;
}

unsigned GoPro::getSubMode(){
    // 0 = Video/Single Pic/Burst
    // 1 = TL Video/Continuous/TimeLapse
    // 2 = Video+Photo/NightPhoto/NightLapse
    auto j = nlohmann::json::parse(this->m_currentStatus.c_str());
    unsigned subMode = j["status"]["44"];
    return subMode;
}

unsigned GoPro::getSpaceRemaining(){
    // remaining space in bytes
    auto j = nlohmann::json::parse(this->m_currentStatus.c_str());
    unsigned spaceRemaining = j["status"]["54"];
    return spaceRemaining;
}

unsigned GoPro::getOrientation(){
    // Auto - 0
    // UP - 1
    // DOWN - 2
    auto j = nlohmann::json::parse(this->m_currentStatus.c_str());
    unsigned orientation = j["settings"]["52"];
    return orientation;
}

