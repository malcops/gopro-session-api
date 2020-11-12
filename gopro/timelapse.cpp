#include "gopro.hpp"
#include "HTTPRequest.hpp"
#include <unistd.h>

int main(void){

    GoPro gp;
    std::cout << gp.getStatus() << std::endl;
    std::cout << gp.cameraName() << std::endl;

    // night photo mode
    std::cout << "setPhotoMode" << std::endl;
    gp.setPhotoMode(2);
    sleep(2);

    // shutter 2 sec
    gp.setShutterExposure(1);
    std::cout << gp.getStatus() << std::endl;
    std::cout << gp.cameraName() << std::endl;

    while(1) {
        std::cout << "photo" << std::endl;
        gp.takePhoto();
        sleep(30);
    }

    return 0;
}
