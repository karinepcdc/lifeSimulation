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
    int freq = 0; // 0 ou 1?
    bool stable = false;
    // is searched a generation equal the actual, if found, is stable
    for( size_t i = 0; i < actualGeneration-1; i++ )
    {
      //std::cout << "CHEGUEI AQUI " << actualGeneration << std::endl;
      if( compareGenerations( logData[i], logData[ actualGeneration-1 ] ) )
      {
        stable = true;
      }
      // the freq is the distance between the found genearion and actual generation
      if( stable )
      {
        freq++;
      }
    }
    if( stable )
    {
      freq = freq - 2;
      std::cout << "SIMULAÇÃO ESTAVEL!\nCOM FREQUENCIA: " << freq << std::endl;
      return true;
    }
    
    return false;
  }
