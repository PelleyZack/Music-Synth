// Copyright 2021 <Zachary Pelley>
#ifndef _HOME_ZS_DESKTOP_PS4B_STRINGSOUND_HPP_
#define _HOME_ZS_DESKTOP_PS4B_STRINGSOUND_HPP_
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/System.hpp>
#include "./CircularBuffer.h"
class StringSound {
 public:
    explicit StringSound(double frequency);
    explicit StringSound(std::vector<sf::Int16> init);
    StringSound (const StringSound &obj) {delete this;}
    ~StringSound();
    void pluck();
    void tic();
    sf::Int16 sample();
    int time() , r;
 private:
    int16_t holder1, holder2, holder3;
    CircularBuffer * _cb;
    int _time;
};

#endif  // _HOME_ZS_DESKTOP_PS4B_STRINGSOUND_HPP_
