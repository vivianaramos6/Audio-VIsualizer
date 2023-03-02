#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    sound.load("beat.wav");           // Loads a sound file (in bin/data/)
    sound.setLoop(false);              // Makes the song loop indefinitely
    sound.setVolume(1);               // Sets the song volume
    ofSetBackgroundColor(40, 21, 150); // Sets the Background Color
}

void ofApp::update() {
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSoundUpdate();               // Updates all sound players
    visualizer.updateAmplitudes(); // Updates Amplitudes for visualizer
    progress = sound.getPosition();
}

//--------------------------------------------------------------
void ofApp::draw() {
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */

    // Progress Bar
    ofSetColor(256);
    ofFill();

    float pos = playing ? progress : lastPos;
    int percent = pos * 100;
    ofDrawBitmapString("Song Progress: " + ofToString(percent) + "%", 0, 30);

    // Mode Selection
    if (!playing) {
        ofDrawBitmapString("Press 'p' to play some music!", ofGetWidth() / 2 - 50, ofGetHeight() / 2);
    }
    amplitudes = visualizer.getAmplitudes();
    if (mode == '1') {
        drawMode1(amplitudes);
         ;
    } else if (mode == '2') {
        drawMode2(amplitudes);
         
    } else if (mode == '3') {
        drawMode3(amplitudes);
    
    }

     //ofDrawBitmapString("Current Mouse Position: " + ofToString(cur_x) + ", " + ofToString(cur_y), 0, 30);

     
}
void ofApp::drawMode1(vector<float> amplitudes) {
    ofFill();        // Drawn Shapes will be filled in with color
    ofSetColor(256); // This resets the color of the "brush" to white
    ofDrawBitmapString("Rectangle Height Visualizer", 0, 15);
    ofSetBackgroundColor(214,212,226);
    ofSetColor(ofRandom(130), ofRandom(250), 255);
    if (!isPaused){
        ofDrawRectRounded(2, ofGetHeight() - 100, 50, amplitudes[0],10);
    }
    else{
        ofDrawRectRounded(2, ofGetHeight() - 100, 50, ampcopy[0],10);
    }

}

void ofApp::drawMode2(vector<float> amplitudes) {
    ofSetLineWidth(5); // Sets the line width
    ofNoFill();        // Only the outline of shapes will be drawn
    ofSetColor(256);   // This resets the color of the "brush" to white
    ofDrawBitmapString("Circle Radius Visualizer", 0, 15);
    ofSetBackgroundColor(153,153,255);
    int bands = amplitudes.size();
    if (!isPaused){
    for (int i = 0; i < bands; i++) {
        ofSetColor((bands - i) * 32 % 256, 186, 151); // Color varies between frequencies
        ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, amplitudes[0] / (i + 1));
    }
    }
    else{
        for (int i = 0; i < bands; i++) {
        ofSetColor((bands - i) * 32 % 256, 186, 151); // Color varies between frequencies
        ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, ampcopy[0] / (i + 1));
    }
    }
}

void ofApp::drawMode3(vector<float> amplitudes) {
    ofSetColor(256); // This resets the color of the "brush" to white
    ofDrawBitmapString("Rectangle Width Visualizer", 0, 15);
    ofSetBackgroundColor(204,255,204);
    // YOUR CODE HERE
}
 void ofApp::songlist(vector<string>songs){
    songs.push_back("beat.wav");
        songs.push_back("rock-song.wav");
        songs.push_back("pigeon-coo.wav");
 }
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    // This method is called automatically when any key is pressed
    switch (key) {
    case 'p':
        if (playing) {
            sound.stop();
        } else {
            sound.play();
        }
        playing = !playing;
        break;
    case 'a':
        isPaused = !isPaused;
        ampcopy = amplitudes;
        break;

    case 'c' :
        sound.load("beat.wav");           // Loads a sound file (in bin/data/)
        sound.setLoop(true);              // Makes the song loop indefinitely
        sound.setVolume(1);               // Sets the song volume
        playing = !playing;
        break;

    case 'd' :
        sound.load("geesebeat.wav");           // Loads a sound file (in bin/data/)
        sound.setLoop(false);              // Makes the song loop indefinitely
        sound.setVolume(1);               // Sets the song volume
        playing = !playing;
        break;

    case 'e' :
        sound.load("pigeon-coo.wav");           // Loads a sound file (in bin/data/)
        sound.setLoop(false);              // Makes the song loop indefinitely
        sound.setVolume(1);               // Sets the song volume
        playing = !playing;
        break;
    
    case 'f' :
        sound.load("rock-song.wav");           // Loads a sound file (in bin/data/)
        sound.setLoop(false);              // Makes the song loop indefinitely
        sound.setVolume(1);               // Sets the song volume
        playing = !playing;
        break;
        
    case '-' :                                                          // lower volume
        if (sound.getVolume() <= 1 && sound.getVolume() > 0) {
            sound.setVolume(sound.getVolume() - 0.1);
        } else {
            sound.setVolume(0);
        }
        break;

    case '=' :                                                          // raise volume 
        if (sound.getVolume() < 1 && sound.getVolume() >= 0) {
            sound.setVolume(sound.getVolume() + 0.1);
        } else {
            sound.setVolume(1);
        }
        break;

    case '1':
        mode = '1';
        break;
    case '2':
        mode = '2';
        break;
    case '3':
        mode = '3';
        break;
    case 'r':
    repeat=!repeat;
    if(!repeat){
        sound.setLoop(true);
    }
    else{
        sound.setLoop(false);
    }
    break;


    case 'l':
     loop=!loop;
        
        song_index=0;
        loop=!loop;
       

    sound.setLoop(false);

        while(!loop){
            
            sound.load(songs[song_index]);
             sound.setVolume(1);
             sound.play();
        
            song_index+=1;
            if(song_index==3){
                song_index=0;
            }
        }

    if(loop){
        sound.stop();
    }

        

        break;

    }
}

    


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    cur_x = x;
    cur_y = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}
//--------------------------------------------------------------