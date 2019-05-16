#include "commonLife.h"
#include <iostream>
#include <vector>

namespace life {
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

            /// 
            bool extinct() const;

            Celula* getAlive();

            /// update cellBoard
            void evolve(std::vector<Celula> toAlter)
            {   
                Celula cellAux;
                for(size_t i = 0; i < toAlter.size(); i++)
                {
                    cellAux = toAlter[i];
                    // x and y are shifted to compensate for dead cell boundery
                    cellBoard[cellAux.x+1][cellAux.y+1].x = cellAux.x+1;
                    cellBoard[cellAux.x+1][cellAux.y+1].y = cellAux.y+1;
                    // change alive status
                    cellBoard[cellAux.x+1][cellAux.y+1].alive = !cellAux.alive;
                }
                
            }

            /// assignment operator
            LifeConfig& operator=(const LifeConfig & other)
            {
                this->width = other.width;
                this->heigth = other.heigth;
                this->cellBoard = other.cellBoard;

                return *this;
            }

            /// Friend functions
            friend std::ostream& operator<<( std::ostream& os, const LifeConfig& lifeBoard )
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