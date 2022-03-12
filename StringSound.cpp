// Copyright 2021 <Zachary Pelley>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/System.hpp>
#include "./CircularBuffer.h"
#include "./StringSound.hpp"

// Constructor using frequency
StringSound::StringSound(double frequency) {
    if (frequency <= 0.0) {
        throw "Invalid Argument DOUBLE: Frequency must be greater then zero";
    }
    _cb = new CircularBuffer(ceil(frequency));
    _time = 0;
    r = 0;
    holder1 = holder2 = holder3 = 0;
}
// Constructor using allready filled vector
StringSound::StringSound(std::vector<sf::Int16> init) {
    if (init.size() < 1) {
        throw "Invalid Argument VECTOR: Size must be greater then zero";
    }
    _cb = new CircularBuffer(init.size());
    _time = 0;
    r = 0;
    holder1 = holder2 = holder3 = 0;
    // Fills the CB with the values in the vector
    for (int i = 0; i < _cb->capac; i++) {
        _cb->enqueue(init[i]);
    }
}
// Destructor, deletes the CB
StringSound::~StringSound() {
    delete _cb;
}
// Plucks the string to randomize it and fill CB
void StringSound::pluck() {
    for (int j = _cb->numEle ; j > -0; j--) {
        _cb->dequeue();
    }
    for (int i = 0; i < _cb->capac; i++) {
        r = rand()% 65535;  // Number generated between 0 and 65535
        // subtract 32768 to get the random negatives from -32768 -> 0
        r = r - 32768;
        _cb ->enqueue((int16_t) r);
    }
}
// Tic progresses the vibration of the pluc and
// preforms the  Karplus-Strong algorithm
void StringSound::tic() {
    if (_cb->isEmpty()) {
        throw "Runetime Error: buffer is empty cannot tic";
    }
    _time++;
    holder1 = _cb->dequeue();
    holder2 = _cb->peek();
    holder3 = ceil((.996*((holder1 + holder2)/2)));
    _cb->enqueue(holder3);
}
// Samples the back of the CB
sf::Int16 StringSound::sample() {
    return _cb->peek();
}
// Returns the time variable
int StringSound::time() {
    return _time;
}
