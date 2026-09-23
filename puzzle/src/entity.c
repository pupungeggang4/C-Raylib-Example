#include "entity.h"

void setEntity(Entity* entity, int ID) {
    entity->valid = 1;
    entity->type = ID;
    
}
