#include "../include/logLife.h"


  // returns the number of generations saved (size of logData)
  size_t life::LogLife::size()
  {
    return logData.size();
  }

  // adds a generation in logData
  void life::LogLife::push_back(std::vector< life::Celula > aliveCells)
  {
    logData.push_back( aliveCells );
  }
