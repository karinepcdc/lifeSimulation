#ifndef _COMMOMLIFE_H
#define _COMMOMLIFE_H

#include <vector>
#include <string>

#include "../include/canvas/commonCanvas.h"

namespace life {
  
  typedef struct Celula_t
  {
    int x;
    int y;
    bool alive;
  } Celula;

  typedef struct Options
  {
    std::string imgdir;      //!< output images file
    int maxgen;              //!< Maximum number of generations to simulate
    int fps;                 //!< Number of generations presented per second
    int blocksize;           //!< Pixel size of a cell
    Color bkgcolor;          //!< Background color ?????????? check
    Color alivecolor;        //!< alive cells color ????????? check
    std::string outfile;     //!< text representation file
     
  } Options;


  typedef struct SimulationState_t{
    int currentGeneration; // number of current generation 
    std::vector< Celula > cellChanges[0]; // vector with cell that will change state
  
  } SimulationState;
}

#endif
