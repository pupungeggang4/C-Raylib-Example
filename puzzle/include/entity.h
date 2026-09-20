#pragma once
#include "includes.hpp"

typedef struct {
    int type;
    int movable;
    int solid;
    int pos[2];
    Rectangle texClip;
} Entity;
