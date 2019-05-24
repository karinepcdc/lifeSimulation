#ifndef _COMMOMLIFE_H
#define _COMMOMLIFE_H

#include <vector>
#include <string>

#include "../include/canvas/commonCanvas.h"

namespace life {

  /// struct of Cell
  typedef struct Celula
  {
    public:

      /// Celula data
      int x;
      int y;
      bool alive;

      /**
      * Operator= to this cell copy other cell
      *
      * @param a: other cell
      *
      * @returns a reference to this cell
      */
      Celula& operator =(const Celula& a)
      {
        x = a.x;
        y = a.y;
        alive = a.alive;
        return *this;
      }

      /// operator == to compare cells
      /**
      * Compare this cell with other cell
      *
      * @param other: other cell
      *
      * @returns true if the cells are equals
      */
      bool operator==(const Celula& other) const
      {
        if( (x == other.x) && (y == other.y) && (alive == other.alive) )
        {
          return true;
        }
        return false;
      }

      /// operator << to print a cell
      /**
      * Prints the Cell in console
      *
      * @param os: output
      * @param cell: the cell that will be printed out
      *
      * @returns the output
      */
      friend std::ostream& operator<<( std::ostream& os, const Celula& cell )
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

  /// struct of options
  typedef struct Options
  {
    std::string imgdir;      //!< output images file
    int maxgen;              //!< Maximum number of generations to simulate
    int fps;                 //!< Number of generations presented per second
    short blocksize;           //!< Pixel size of a cell
    //std::string bkgcolor;    //!< Background color
    //std::string alivecolor;  //!< Name of alive cells color
    life::Color bkgcolor;
    life::Color alivecolor;
    std::string outfile;     //!< text representation file

  } Options;

  /// struct of Simulation State
  typedef struct SimulationState_t
  {
    int currentGeneration; // number of current generation
    std::vector< Celula > cellChanges; // vector with cell that will change state
    Options simOptions; // Option chosen by user

  } SimulationState;

} //end life namespace;

#endif
