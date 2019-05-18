#include "commonLife.h"
#include <iostream>
#include <vector>

namespace life
{

  class LifeConfig
  {
      private:

          int width;
          int heigth;
          Celula **cellBoard;

      public:

          /// default constructor
          LifeConfig(int w = 0, int h = 0):
              width{w+2}, heigth{h+2} // adding dead cell boundary
          {
              // allocate cell board
              cellBoard = new Celula*[width];
              for(int i = 0; i < width; i++)
              {
                  cellBoard[i] = new Celula[heigth];
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

          /// returns true if not exist any cell alive, else returns false
          bool extinct();


          /// returns the number of neighbors alives of Celula cell
          int getAliveNeighbors(int x, int y);


          /// returns a vector with only cells alive
          std::vector<Celula> getAlive();

          /// return a Cell of cellBoard
          life::Celula getCell(int x, int y);

          /// return the width of cellBoard (withtout dead boundary)
          int getWidth();

          /// return the heigth of cellBoard (withtout dead boundary)
          int getHeigth();


          /// update cellBoard
          // TALVEZ NÃO TENHA QUE SOMAR 1 NAS POSICOES (DEPENDE DE COMO O process_events VAI FAZER)
          // SE A FUNÇÃO QUE LÊ DO ARQUIVO DE ENTRADA COMPENSAR ESTE 1 NA HORA DE DEFINIR O TABULEIRO AQUI, NÃO VAI PRECISAR COMPENSAR MAIS EM QUALQUER LUGAR
          void evolve( life::SimulationState state );

          /// assignment operator
          LifeConfig& operator=(const LifeConfig & other);

          /// assignment operator to set the cellBoard with a vector of alive cells
          LifeConfig& operator=(const std::vector<Celula> alives);

          /// Friend functions

          /// operator << to print a LifeConfig istance
          friend std::ostream& life::operator<<( std::ostream& os, const LifeConfig& lifeBoard )
          {
              // loop excluding dead cell boundary; i.e. interator start at 1 and end one step earlier
              for( int i = 1; i < lifeBoard.heigth-1; i++ )
              {
                  for( int j = 1; j < lifeBoard.width-1; j++ )
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
