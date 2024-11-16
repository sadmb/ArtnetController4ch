#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    artnet = ofPtr<ofxArtnetSender>(new ofxArtnetSender);
    load();
    artnet->setup(address, 0);
    artnet->setThreadedSend(true);
    artnet->start(60.0);
    
    for(int i = 0; i < 512; i++)
    {
        data[i] = default_value;
    }

    gui.setup();
}

void ofApp::load()
{
    ofBuffer buff = ofBufferFromFile("ip.settings");
    ofBuffer::Lines lines = buff.getLines();
    for(auto& line: lines)
    {
        address = line;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < channel - 1; i+=4)
    {
        setData(i, default_value, default_value, default_value, default_value);
    }
    setData(channel - 1, r, g, b, w);
    for(int i = channel; i < 509; i++)
    {
        setData(i, default_value, default_value, default_value, default_value);
    }
    if(is_sending)
    {
        for (int i = 0; i < NUM_UNIVERSE; i++)
        {
            artnet->sendArtnet(data, MAX_CH);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapStringHighlight("is sending DMX: " + ofToString(is_sending) + ", channel: " + ofToString(channel) + "(r: " + ofToString(r) + ", g: " + ofToString(g) + ", b: " + ofToString(b) + ", w: " + ofToString(w) + ")", ofGetWidth() * 0.3, ofGetHeight() * 0.4 - 20);
    ofPushStyle();
    ofSetColor(r, 0, 0);
    ofDrawRectangle(ofGetWidth() * 0.15, ofGetHeight() * 0.4, ofGetWidth() * 0.2, ofGetHeight() * 0.1);
    ofSetColor(255);
    ofDrawBitmapStringHighlight("R:" + ofToString(channel) + ",val: " + ofToString(r) + ")", ofGetWidth() * 0.15, ofGetHeight() * 0.5 - 20);
    ofSetColor(0, g, 0);
    ofDrawRectangle(ofGetWidth() * 0.35, ofGetHeight() * 0.4, ofGetWidth() * 0.2, ofGetHeight() * 0.1);
    ofSetColor(255);
    ofDrawBitmapStringHighlight("G: " + ofToString(channel + 1) + ",val: " + ofToString(g) + ")", ofGetWidth() * 0.35, ofGetHeight() * 0.5 - 20);
    ofSetColor(0, 0, b);
    ofDrawRectangle(ofGetWidth() * 0.55, ofGetHeight() * 0.4, ofGetWidth() * 0.2, ofGetHeight() * 0.1);
    ofSetColor(255);
    ofDrawBitmapStringHighlight("B: " + ofToString(channel + 2) + ",val: " + ofToString(b) + ")", ofGetWidth() * 0.55, ofGetHeight() * 0.5 - 20);
    ofSetColor(w);
    ofDrawRectangle(ofGetWidth() * 0.75, ofGetHeight() * 0.4, ofGetWidth() * 0.2, ofGetHeight() * 0.1);
    ofSetColor(255);
    ofDrawBitmapStringHighlight("W: " + ofToString(channel + 3) + ",val: " + ofToString(b) + ")", ofGetWidth() * 0.75, ofGetHeight() * 0.5 - 20);
    ofPopStyle();
    gui.begin();
    ImGui::Begin("gui");
    if(ImGui::Checkbox("is sending DMX signal via Artnet", &is_sending))
    {
        
    }
    if(ImGui::DragInt("channels", &channel, 4, 1, 509))
    {
    }
    ImGui::SliderInt("r", &r, 0, 255);
    ImGui::SliderInt("g", &g, 0, 255);
    ImGui::SliderInt("b", &b, 0, 255);
    ImGui::SliderInt("w", &w, 0, 255);
    ImGui::SliderInt("default_value", &default_value, 0, 255);
    ImGui::End();
    gui.end();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::setData(unsigned int channel, unsigned char r, unsigned char g, unsigned char b, unsigned char w)
{
    data[channel] = r;
    data[channel + 1] = g;
    data[channel + 2] = b;
    data[channel + 3] = w;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
