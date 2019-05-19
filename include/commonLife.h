#ifndef _COMMOMLIFE_H
#define _COMMOMLIFE_H

#include <vector>
#include <string>

#include "../include/canvas/commonCanvas.h"

namespace life {

  typedef struct Celula
  {
    public:

      /// Celula data
      int x;
      int y;
      bool alive;


      Celula& operator =(const Celula& a)
      {
        x = a.x;
        y = a.y;
        alive = a.alive;
        return *this;
      }

      /// operator == to compare cells
      bool operator==(const Celula& other) const
      {
        if( (x == other.x) && (y == other.y) && (alive == other.alive) )
        {
          return true;
        }
        return false;
      }

      /// operator << to print a cell
      friend std::ostream& life::operator<<( std::ostream& os, const Celula& cell )
      {
          std::string alive = "false";
          if(cell.alive)
          {
            alive = "true";
          }
          os << "x: " << cell.x << ", y: " << cell.y << ", alive?: " << alive;
          return os;
      }


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


  typedef struct SimulationState_t
  {
    int currentGeneration; // number of current generation
    std::vector< Celula > cellChanges; // vector with cell that will change state

  } SimulationState;
}

#endif
