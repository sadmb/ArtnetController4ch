#pragma once

#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxArtnet.h"

class ofApp : public ofBaseApp{

public:
    ofxImGui::Gui gui;
    int channel = 1;
    int r = 255;
    int g = 255;
    int b = 255;
    int w = 255;
    int default_value = 0;
    int pSec = 0;
    unsigned char data[512];
    
    bool is_sending = true;
    
    ofPtr<ofxArtnetSender> artnet;
    ofPixels pixs;
    const int MAX_CH = 512;
    const static int MAX_NUM_UNIVERSE = 1;
    int ips[4] = {192, 168, 0, 110};
    string address = "";
    int NUM_UNIVERSE = 1;
    
    void load();
    
    void setup() override;
    void update() override;
    void draw() override;
    void exit() override;
    
    void setData(unsigned int channel, unsigned char r, unsigned char g, unsigned char b, unsigned char w);
    
    void keyPressed(int key) override;
    void keyReleased(int key) override;
    void mouseMoved(int x, int y ) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
    void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
    void mouseEntered(int x, int y) override;
    void mouseExited(int x, int y) override;
    void windowResized(int w, int h) override;
    void dragEvent(ofDragInfo dragInfo) override;
    void gotMessage(ofMessage msg) override;
		
};
