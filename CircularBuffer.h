// Copyright 2021 <Zachary Pelley>
#ifndef _HOME_ZS_DESKTOP_PS4A_CIRCULARBUFFER_H_
#define _HOME_ZS_DESKTOP_PS4A_CIRCULARBUFFER_H_
#include <stdint.h>
#include <string>
#include <iostream>
#include <sstream>

class CircularBuffer{
 public:
    int16_t* buff;
    int numEle, capac;
    double decayCon;
    int16_t pluck;
    explicit CircularBuffer(int capacity);
    int size();
    bool isEmpty();
    bool isFull();
    void enqueue(int16_t x);
    int16_t dequeue();
    int16_t peek();
};

#endif  // _HOME_ZS_DESKTOP_PS4A_CIRCULARBUFFER_H_
