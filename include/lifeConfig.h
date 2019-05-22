#ifndef LIFECONFIG_H
#define LIFECONFIG_H

#include "commonLife.h"
#include <iostream>
#include <vector>

namespace life
{

  class LifeConfig
  {
      private:
          /// LifeConfig data
          int width;
          int heigth;
          life::Celula **cellBoard;

      public:

          /// Default constructor: criate a empty cell board
	  LifeConfig(){
	      width=0;
	      heigth=0;
	      cellBoard = nullptr;
	  }

          /// Parameter initialization constructor
                /**
          * Constructor thats create the cell board of width * height size
          *
          * @param w: width
          * @param h: heigth
          */
          LifeConfig(int w, int h):
              width{w+2}, heigth{h+2} // adding dead cell boundary
          {
              // allocate cell board
              cellBoard = new life::Celula*[width];
              for(int i = 0; i < width; i++)
              {
                  cellBoard[i] = new life::Celula[heigth];
              }

              // set cells positions
              for(int i = 0; i < width; i++)
              {
                  for(int j = 0; j < heigth; j++)
                  {
                      cellBoard[i][j].x = i;
                      cellBoard[i][j].y = j;
                      cellBoard[i][j].alive = false;
                  }
              }

          }

          /// destructor
          ~LifeConfig()
          {
              for(int i = 0; i < width; i++)
              {
                  delete [] cellBoard[i];
              }
              delete cellBoard;
          }

          /// checks if the generation are extinct
          /**
          * Checks if don't have any cell alive
          *
          * return true if extinct
          */
          bool extinct();


          /// checks the number of alive neighbors of the cell
          /**
          * Checks the number of alive neighbors of the cell in x,y position
          *
          * @param x: position x of the cell
          * @param y: position y of the cell
          *
          * return a int, that is the number of alive neighbors
          */
          int getAliveNeighbors(int x, int y);


          /// Get alive cells
          /**
          * Checks the alive cells of the cellBoard
          *
          * return a vector of cells alive
          */
          std::vector<life::Celula> getAlive();

          /// Get cell
          /**
          * Get a copy of the cell in x,y position in cellBoard
          *
          * @param x: position x of the cell
          * @param y: position y of the cell
          *
          * return the cell;
          */
          life::Celula getCell(int x, int y);

          /// set cell
          /**
          * Set a cell in cell board
          *
          * @param cell: cell to add to cell board
          */
          void setCell( life::Celula cell );

          /// Get Width
          /**
          * return the width of cell board
          */
          int getWidth();

          /// Get Heigth
          /**
          * return the heigth of cell board
          */
          int getHeigth();

          /// Reset cell board
          /**
          * return the cell board pointer of pointers
          */
          int resetCellboard( life::Celula** &newcellBoard  );

          /// Evolve to next generation
          /**
          * Envolve the generation changing cells in vector of state
          *
          * @param state: Simulation state that contains the vector of cells that must die or live
          */
          void evolve( life::SimulationState state );

          /// assignment operator
          /**
          * Copys other LifeConfig
          *
          * @param other: LifeConfig that will be copied
          * return a reference to this LifeConfig
          */
          LifeConfig& operator=(const LifeConfig & other);

          /// assignment operator to set the cellBoard with a vector of alive cells
          /**
          * Change this cellBoard adding alives cells
          *
          * @param alives:: vector of alive cells
          * return a reference to this LifeConfig
          */
          LifeConfig& operator=(const std::vector<life::Celula> alives);

          /// Friend functions

          /// operator << to print a LifeConfig istance
          /**
          * Prints the generation (cellBoard)
          *
          * @param os: output
          * @param lifeBoard: LifeConfig that will be printed out
          */
          friend std::ostream& life::operator<<( std::ostream& os, const LifeConfig& lifeBoard )
          {
              // loop excluding dead cell boundary; i.e. interator start at 1 and end one step earlier
              for( int i = 1; i < lifeBoard.width-1; i++ )
              {
                  for( int j = 1; j < lifeBoard.heigth-1; j++ )
                  {
                      if( lifeBoard.cellBoard[i][j].alive )
                      {
                          os << "*";
                      }
                      else
                      {
                          os << ".";
                      }
                  }
                  os << "\n";
              }
              return os;
          }

  };
}

#endif
