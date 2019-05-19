#include "commonLife.h"
#include <iostream>
#include <vector>

namespace life
{

  class LogLife
  {
      private:
        /// vector of alive cells vector
        std::vector< std::vector<life::Celula> > logData;

        /// return true if, and only if, genetarions are equal
        bool compareGenerations( std::vector< life::Celula > &v1, std::vector< life::Celula > &v2 );

      public:

        // default constructor;
        LogLife()
        {
        logData.reserve(100); // não sei se adianta
        }

        ~LogLife()
        {
          logData.~vector();
        }
        // returns the number of generations saved (size of logData)
        size_t size();

        // adds a generation in logData
        void push_back(std::vector< life::Celula > aliveCells);

        // return true if the simulation becomes stable
        bool isStable();

        // comparar o que exatamente?
        //bool operator==();
  };
}
