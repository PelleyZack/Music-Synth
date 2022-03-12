// Copyright 2021 <Zachary Pelley>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "./CircularBuffer.h"
#include "./StringSound.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSample(StringSound& gs) {
    std::vector<sf::Int16> samples;
    gs.pluck();
    int dur = 8;  // seconds
    for (int i = 0; i < (SAMPLES_PER_SEC * dur); i++) {
        gs.tic();
        samples.push_back(gs.sample());
    }
    return samples;
}


int main() {
    try {  // Try for the whole main to catch any potential expection
    // Setting up window
    sf::RenderWindow window(sf::VideoMode(300, 200), "SFML KSGuitarSim");
    sf::Event event;
    // Setting up vectors
    std::vector<sf::Int16> samples;
    std::vector<std::vector<sf::Int16>> bigSample;
    std::vector<sf::SoundBuffer> buffers;
    std::vector<sf::Sound> sounds;
    // These variables are used to fill in the above vectors with empty
    // genertic types that will be overridden
    sf::Sound sound1;
    sf::SoundBuffer buf1;
    double freq;  // frequency Variable that will change
    // This loop fills up the big sample vector with the
    // values generated into samples by makeSample
    for (double i = 0; i < 37; i++) {
        freq = 440 * (pow(2, ((i-24)/12)));  // Calculating Freq
        // Setting a new Stringsound to the freq
        StringSound gs1 = StringSound(freq);
        samples = makeSample(gs1);  // Making the vector of samples
        bigSample.push_back(samples);  // Pushing that vector into a vector
        // Filling vector for buffer and sound with empty variables
        buffers.push_back(sf::SoundBuffer(buf1));
        sounds.push_back(sf::Sound(sound1));
    }
    // This loop will re-asign the values of the buffer and the sound
    // vectors to their values, sound counts in reverse as otherwise
    // the scale would be backwards
    for (int i = 0; i < 37; i++) {
        buffers[i].loadFromSamples(bigSample[i].data()
        , (int)samples.size(), 2, SAMPLES_PER_SEC);
        sounds[36-i].setBuffer(buffers[i]);
    }
    // While Loop that keeps the window open
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            // Double switch case that checks if closed or key is pressed
            switch (event.type) {
                case sf::Event::Closed:
                  window.close();
                  break;
                case sf::Event::KeyPressed:
                  // Switch case for the keyboardPiano being pressed
                  switch (event.key.code) {
                      case sf::Keyboard::Q:
                        sounds[0].play();
                        break;
                      case sf::Keyboard::Num2:
                        sounds[1].play();
                        break;
                      case sf::Keyboard::W:
                        sounds[2].play();
                        break;
                    case sf::Keyboard::E:
                        sounds[3].play();
                        break;
                    case sf::Keyboard::Num4:
                        sounds[4].play();
                        break;
                    case sf::Keyboard::R:
                        sounds[5].play();
                        break;
                    case sf::Keyboard::Num5:
                        sounds[6].play();
                        break;
                    case sf::Keyboard::T:
                        sounds[7].play();
                        break;
                    case sf::Keyboard::Y:
                        sounds[8].play();
                        break;
                    case sf::Keyboard::Num7:
                        sounds[9].play();
                        break;
                    case sf::Keyboard::U:
                        sounds[10].play();
                        break;
                    case sf::Keyboard::Num8:
                        sounds[11].play();
                        break;
                    case sf::Keyboard::I:
                        sounds[12].play();
                        break;
                    case sf::Keyboard::Num9:
                        sounds[13].play();
                        break;
                    case sf::Keyboard::O:
                        sounds[14].play();
                        break;
                    case sf::Keyboard::P:
                        sounds[15].play();
                        break;
                    case sf::Keyboard::Hyphen:
                        sounds[16].play();
                        break;
                    case sf::Keyboard::LBracket:
                        sounds[17].play();
                        break;
                    case sf::Keyboard::Equal:
                        sounds[18].play();
                        break;
                    case sf::Keyboard::Z:
                        sounds[19].play();
                        break;
                    case sf::Keyboard::X:
                        sounds[20].play();
                        break;
                    case sf::Keyboard::D:
                        sounds[21].play();
                        break;
                    case sf::Keyboard::C:
                        sounds[22].play();
                        break;
                    case sf::Keyboard::F:
                        sounds[23].play();
                        break;
                    case sf::Keyboard::V:
                        sounds[24].play();
                        break;
                    case sf::Keyboard::G:
                        sounds[25].play();
                        break;
                    case sf::Keyboard::B:
                        sounds[26].play();
                        break;
                    case sf::Keyboard::N:
                        sounds[27].play();
                        break;
                    case sf::Keyboard::J:
                        sounds[28].play();
                        break;
                    case sf::Keyboard::M:
                        sounds[29].play();
                        break;
                    case sf::Keyboard::K:
                        sounds[30].play();
                        break;
                    case sf::Keyboard::Comma:
                        sounds[31].play();
                        break;
                    case sf::Keyboard::Period:
                        sounds[32].play();
                        break;
                    case sf::Keyboard::SemiColon:
                        sounds[33].play();
                        break;
                    case sf::Keyboard::Slash:
                        sounds[34].play();
                        break;
                    case sf::Keyboard::Quote:
                        sounds[35].play();
                        break;
                    case sf::Keyboard::Space:
                        sounds[36].play();
                        break;
                      default:
                        break;
                  }
                default:
                  break;
            }
        window.clear();
        window.display();
        }
    }
    }
    catch(const char* e) {
        std::cout << "Exception:" << e << std::endl;
    }
    catch(const std::invalid_argument& ex) {
        std::cout << "Exception:" << ex.what() << std::endl;
    }
    catch(const std::runtime_error& ex) {
        std::cout << "Exception:" << ex.what() << std::endl;
    }
    return 0;
}
