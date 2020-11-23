#include "gopro.hpp"
#include "HTTPRequest.hpp"
#include <unistd.h>

int main(void){

    GoPro gp;
    std::cout << gp.getStatus() << std::endl;
    gp.setPhotoMode("Single");
    sleep(2);
    gp.setShutterExposure(0);

    while(gp.getBatteryLevel() > 0 && gp.getSpaceRemaining() > 5000) {
        std::cout << "photo" << std::endl;
        gp.takePhoto();
        sleep(30);
    }

    return 0;
}
