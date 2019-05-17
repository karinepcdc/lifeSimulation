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

            /// returns a vector with only cells alive
            std::vector<Celula> getAlive();


            /// update cellBoard
            // TALVEZ NÃO TENHA QUE SOMAR 1 NAS POSICOES (DEPENDE DE COMO O process_events VAI FAZER)
            // SE A FUNÇÃO QUE LÊ DO ARQUIVO DE ENTRADA COMPENSAR ESTE 1 NA HORA DE DEFINIR O TABULEIRO AQUI, NÃO VAI PRECISAR COMPENSAR MAIS EM QUALQUER LUGAR
            void evolve(std::vector<Celula> toAlter);

            /// assignment operator
            LifeConfig& operator=(const LifeConfig & other);

            /// assignment operator to set the cellBoard with a vector of alive cells
            LifeConfig& operator=(const std::vector<Celula> alives);

            /// Friend functions

            /// operator << to print a LifeConfig istance
            friend std::ostream& operator<<( std::ostream& os, const LifeConfig& lifeBoard );

    };
}
