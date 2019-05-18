#ifndef _COMMOMLIFE_H
#define _COMMOMLIFE_H

#include <vector>
#include <string>

#include "../include/canvas/commonCanvas.h"

namespace life {

  class Celula
  {
    public:

      /// Celula data
      int x;
      int y;
      bool alive;

      /// default constructor
      Celula(int x=0, int y=0, bool alive=false):
        x{x}, y{y}, alive{alive}
      { /* empty */}

      /// copy constructor
      Celula( const Celula& other ):
        x{other.x}, y{other.y}, alive{other.alive}
      { /* empty */ }

      /// default destructor
      ~Celula()
      {/* empty? */}

      Celula& operator =(const Celula& a)
      {
        x = a.x;
        y = a.y;
        alive = a.alive;
        return *this;
      }

  };

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
    std::vector< Celula > cellChanges; // vector with cell that will change state

  } SimulationState;
}

#endif
