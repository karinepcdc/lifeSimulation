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


      public:

        // default constructor;
        LogLife()
        { /* empty */}

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
