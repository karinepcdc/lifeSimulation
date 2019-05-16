#ifndef _COMMOMLIFE_H
#define _COMMOMLIFE_H

typedef struct Celula_t
{
    int x;
    int y;
    bool alive;
} Celula;

typedef struct Options
{
    
} Options;


typedef struct SimulationState_t{
  int currentGeneration;
  // vector with cell that will change state
} SimulationState;

#endif
