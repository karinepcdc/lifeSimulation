#include "commonLife.h"

class LifeConfig
{
    private:

        int width;
        int heigth;
        Celula cellBoard[][];
    
    public:

        /// default constructor
        LifeConfig(int w = 0, int h = 0):
            width{w}, heigth{h}
        { 
            cellBoard = new Celula[width][heigth];
        }


        bool extinct() const;

        Celula[] getAlive();

        void evolve();

        /// assignment operator
        &LifeConfig operator=(const LifeConfig & other)
        {
            this->width = other.width;
            this->heigth = other.heigth;
            this->cellBoard = other.cellBoard;
        }
}
