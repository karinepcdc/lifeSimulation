#include "../include/logLife.h"


  bool life::LogLife::compareGenerations( std::vector< life::Celula > &v1, std::vector< life::Celula > &v2 )
  {
    // looks if the size of both are equals
    if( v1.size() == v2.size() )
    {
      size_t i;
      for(i = 0; i < v1.size(); i++)
      {
        // if the vector of alive cells at the same position on v1 and v2 are diferents, return false
        if( !(v1[i] == v2[i]) ) { return false; }
      }
      return true;
    }
    else
    {
      return false;
    }
  }


  size_t life::LogLife::size()
  {
    return logData.size();
  }


  void life::LogLife::push_back(std::vector< life::Celula > aliveCells)
  {
    logData.push_back( aliveCells );
  }


  bool life::LogLife::isStable()
  {
    size_t actualGeneration = logData.size();
    bool stable = false;

    // Searching a generation equal to the actual. If it is found, then we have a stable life dynamic
    for( size_t i = 0; i < actualGeneration-1; i++ )
    {
      if( compareGenerations( logData[i], logData[ actualGeneration-1 ] ) )
      {
        stable = true;
      }

      // the frequency is the distance between the found generaion and actual generation
      if( stable )
      {
        frequency++;
      }

    }

    return stable;
  }
