// Copyright 2021 <Zachary Pelley>
#include <stdint.h>
#include <string>
#include <iostream>
#include <sstream>
#include "/home/zs/Desktop/ps4a/CircularBuffer.h"



CircularBuffer::CircularBuffer(int capacity) {
    if (capacity < 1) {
    throw  std::invalid_argument("CircularBuffer constructor: "
    "Capacity Must be greater than zero");
    } else {
    capac = capacity;
    buff = new int16_t[capac];
    decayCon = 0.996;
    pluck = 0;
    numEle = 0;
    }
}

int CircularBuffer::size() {
    return numEle;
}

bool CircularBuffer::isEmpty() {
    if (numEle == 0) {
        return true;
    } else {
        return false;
    }
}
bool CircularBuffer::isFull() {
    if (numEle == capac) {
        return true;
    } else {
        return false;
    }
}
void CircularBuffer::enqueue(int16_t x) {
    if (isFull()) {
        throw std::runtime_error("enqueue: can't enqueue to a full ring");
    } else {
        buff[numEle] = x;
        numEle++;

        return;
    }
}
int16_t CircularBuffer::dequeue() {
    if (isEmpty()) {
     throw std::runtime_error("dequeue: can't dequeue from an empty ring");
    } else {
        pluck = buff[0];
        for (int i = 0; i < numEle; i++) {
            buff[i] = buff[i+1];
        }
        numEle--;
        return pluck;
    }
}
int16_t CircularBuffer::peek() {
    if (isEmpty()) {
     throw std::runtime_error("peek: can't peek into an empty ring");
    } else {
        pluck = buff[0];
        return pluck;
    }
}
