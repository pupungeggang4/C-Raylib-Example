#pragma once
#include "includes.h"

typedef struct Entity {
    int valid;
    int type;
    int movable;
    int solid;
    int pos[2];
    Rectangle texClip;
} Entity;

void setEntity(Entity*, int);