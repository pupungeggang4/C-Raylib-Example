#include "includes.h"
#include "rect.h"

typedef struct Enemy {
    Rect rect;
    float speed;
    Image* texture;
} Enemy;
