#ifndef BIRD_H
#define BIRD_H

typedef struct
{
    float y;

    float velocity;

} Bird_t;

extern Bird_t bird;

void Bird_Init(void);

void Bird_Update(void);

void Bird_Jump(void);

#endif
