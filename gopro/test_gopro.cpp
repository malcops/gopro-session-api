#include "gopro.hpp"
#include "gtest/gtest.h"

TEST(SystemTest, primaryModes){
    GoPro gp;
    for (auto it = primaryModes.begin(); it != primaryModes.end(); ++it){
        gp.setMode(it->first);
        gp.getStatus();
        EXPECT_EQ(gp.getMode(), it->second);
    }
}

TEST(SystemTest, videoSubmodes){
    GoPro gp;
    for (auto it = videoSubmodes.begin(); it != videoSubmodes.end(); ++it){
        gp.setVideoMode(it->first);
        gp.getStatus();
        EXPECT_EQ(gp.getMode(), primaryModes["Video"]);
        EXPECT_EQ(gp.getSubMode(), it->second);
    }
}

TEST(SystemTest, photoSubmodes){
    GoPro gp;
    for (auto it = photoSubmodes.begin(); it != photoSubmodes.end(); ++it){
        gp.setPhotoMode(it->first);
        gp.getStatus();
        EXPECT_EQ(gp.getMode(), primaryModes["Photo"]);
        EXPECT_EQ(gp.getSubMode(), it->second);
    }
}

TEST(SystemTest, multishotSubmodes){
    GoPro gp;
    for (auto it = multishotSubmodes.begin(); it != multishotSubmodes.end(); ++it){
        gp.setMultishotMode(it->first);
        gp.getStatus();
        EXPECT_EQ(gp.getMode(), primaryModes["Multishot"]);
        EXPECT_EQ(gp.getSubMode(), it->second);
    }
}

static std::string exampleStatus = "{\"status\":{\"1\":1,\"2\":2,\"3\":0,\"4\":0,\"6\":0,\"8\":0,\"9\":0,\"10\":0,\"11\":0,\"13\":0,\"14\":0,\"15\":0,\"16\":0,\"17\":1,\"19\":0,\"20\":0,\"21\":0,\"22\":0,\"23\":0,\"24\":0,\"26\":0,\"27\":0,\"28\":2,\"29\":\"\",\"30\":\"gp-session5\",\"31\":0,\"32\":0,\"33\":0,\"34\":4778,\"35\":7523,\"36\":432,\"37\":114,\"38\":5298,\"39\":114,\"40\":\"%10%08%13%17%13%01\",\"41\":0,\"42\":0,\"43\":0,\"44\":0,\"45\":0,\"46\":0,\"47\":0,\"48\":1,\"49\":0,\"54\":31798784,\"55\":1,\"56\":4,\"57\":932443,\"58\":0,\"59\":0,\"60\":500,\"61\":2,\"62\":0,\"63\":0,\"64\":0,\"65\":0,\"66\":0,\"67\":0}, \
\"settings\":{\"1\":0,\"2\":9,\"3\":8,\"4\":0,\"5\":0,\"6\":1,\"7\":1,\"8\":1,\"9\":0,\"10\":0,\"11\":0,\"12\":0,\"13\":1,\"14\":0,\"15\":4,\"16\":0,\"17\":0,\"18\":0,\"19\":0,\"20\":0,\"21\":1,\"22\":7,\"23\":0,\"24\":0,\"25\":0,\"26\":4,\"27\":0,\"28\":0,\"29\":5,\"30\":0,\"31\":0,\"32\":0,\"33\":0,\"34\":0,\"35\":0,\"36\":0,\"37\":0,\"38\":0,\"39\":4,\"49\":0,\"50\":1,\"51\":1,\"52\":0,\"53\":0,\"54\":1,\"55\":2,\"56\":0,\"57\":0,\"58\":1,\"59\":1,\"60\":8,\"61\":1,\"62\":700000,\"63\":1,\"64\":1,\"68\":0,\"69\":0,\"70\":0,\"72\":1,\"73\":0,\"74\":1,\"75\":2,\"76\":3,\"77\":0,\"78\":0,\"79\":1,\"80\":1,\"81\":0,\"82\":0}}";

TEST(StatusParsing, name){
    GoPro gp;
    gp.m_currentStatus = exampleStatus;
    EXPECT_EQ(gp.cameraName(), "gp-session5");
}

TEST(StatusParsing, batteryLevel){
    GoPro gp;
    gp.m_currentStatus = exampleStatus;
    EXPECT_EQ(gp.getBatteryLevel(), 2);
}

TEST(StatusParsing, sdCard){
    GoPro gp;
    gp.m_currentStatus = exampleStatus;
    EXPECT_EQ(gp.sdCardInserted(), true);
}

TEST(StatusParsing, mode){
    GoPro gp;
    gp.m_currentStatus = exampleStatus;
    EXPECT_EQ(gp.getMode(), 0);
}

TEST(StatusParsing, subMode){
    GoPro gp;
    gp.m_currentStatus = exampleStatus;
    EXPECT_EQ(gp.getSubMode(), 0);
}

TEST(StatusParsing, spaceRemaining){
    GoPro gp;
    gp.m_currentStatus = exampleStatus;
    EXPECT_EQ(gp.getSpaceRemaining(), 31798784);
}

TEST(StatusParsing, orientation){
    GoPro gp;
    gp.m_currentStatus = exampleStatus;
    EXPECT_EQ(gp.getOrientation(), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
