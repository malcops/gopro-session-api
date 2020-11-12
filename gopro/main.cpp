#include "gopro.hpp"
#include "HTTPRequest.hpp"
#include <unistd.h>

int main(void){

    GoPro gp;
    std::cout << gp.getStatus() << std::endl;
    std::cout << gp.cameraName() << std::endl;
    std::cout << gp.getBatteryLevel() << std::endl;
    std::cout << gp.sdCardInserted() << std::endl;
    std::cout << gp.getMode() << std::endl;
    std::cout << gp.getSubMode() << std::endl;
    std::cout << gp.getSpaceRemaining() << std::endl;
    std::cout << gp.getOrientation() << std::endl;
    sleep(5);
    gp.takePhoto();
    gp.locateOn();
    sleep(2);
    gp.locateOff();

    return 0;
}
