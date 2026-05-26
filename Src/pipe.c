#include "pipe.h"

#include <stdlib.h>

Pipe_t pipe;

int pipeSpeed = 2;

int pipeGapSize = 40;

void Pipe_Init(void)
{
    pipe.x = 128;

    pipe.gapY = 40;
}

void Pipe_Update(void)
{
    pipe.x -= pipeSpeed;

    if(pipe.x < -10)
    {
        pipe.x = 128;

        pipe.gapY = 20 + rand()%60;
    }
}
