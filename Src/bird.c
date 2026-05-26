#include "bird.h"

Bird_t bird;

#define GRAVITY      0.25f
#define JUMP_FORCE  -3.5f

void Bird_Init(void)
{
    bird.y = 60;

    bird.velocity = 0;
}

void Bird_Update(void)
{
    bird.velocity += GRAVITY;

    bird.y += bird.velocity;
}

void Bird_Jump(void)
{
    bird.velocity = JUMP_FORCE;
}
