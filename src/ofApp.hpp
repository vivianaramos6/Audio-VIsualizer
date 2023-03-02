#pragma once

#include "AudioVisualizer.hpp"
#include "ofMain.h"

class ofApp : public ofBaseApp {

  private:
    ofSoundPlayer sound;
    AudioVisualizer visualizer;

    bool playing = false;
    char mode = '1';
    bool isPaused = false;

    int cur_x, cur_y = 0;
    float sound_length;

    float progress = 0;
    float lastPos = 0;


    vector<float> ampcopy;
    vector<float> amplitudes;
    vector<string> songs={"beat.wav","geesebeat.wav","pigeon-coo.wav","rock-song.wav"};
    int randomizer;
    bool repeat=false;
    bool loop=false;
    int song_index;

  public:
    void setup();
    void update();
    void draw();

    void drawMode1(vector<float> amplitudes);
    void drawMode2(vector<float> amplitudes);
    void drawMode3(vector<float> amplitudes);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
};
