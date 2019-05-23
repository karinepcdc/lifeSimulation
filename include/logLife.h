#ifndef LOGLIFE_H
#define LOGLIFE_H

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

        /// Comapre generations
        /**
        * Compare two generations
        *
        * @param v1: vector of alive cells
        * @param v2: vector of alive cells
        *
        * Checks if the two vector of alives cells (generations) are indentics
        *
        * @Returns true if the vectors are indentics
        */
        bool compareGenerations( std::vector< life::Celula > &v1, std::vector< life::Celula > &v2 );

      public:

        /// default constructor;
        LogLife()
        {
        logData.reserve(100); // não sei se adianta
        }

        /// destructor
        ~LogLife()
        {
          logData.~vector();
        }

        /// returns the number of generations saved (size of logData)
        /**
        * Looks the size of the log
        *
        * @Returns the size of the log
        */
        size_t size();

        /// adds a generation in logData
        /**
        * Add a new generation in the log
        *
        * @param aliveCells: vector of alive cells
        *
        */
        void push_back(std::vector< life::Celula > aliveCells);

        /// Checks if the simulation are stable
        /**
        * Checks if the simulation are stable comparing each generation saved
        * in log with the actual generation (last saved in log)
        *
        * @Returns true if are stable
        */
        bool isStable();

        // comparar o que exatamente?
        //bool operator==();
  };
}

#endif
