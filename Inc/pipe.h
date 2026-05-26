#ifndef PIPE_H
#define PIPE_H

typedef struct
{
    int x;

    int gapY;

} Pipe_t;

extern Pipe_t pipe;

extern int pipeSpeed;

extern int pipeGapSize;

void Pipe_Init(void);

void Pipe_Update(void);

#endif
