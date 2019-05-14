#include "common.h"

class LifeConfig
{
    private:

        int width;
        int height;
        Celula vivas[];
    
    public:

        bool extinct() const;

        Celula[] getAlive();

        void evolve();

        &LifeConfig operator=(const )
}