#include "../include/logLife.h"

  /// return true if, and only if, genetarions are equal
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
    }
    return true;
  }

  /// returns the number of generations saved (size of logData)
  size_t life::LogLife::size()
  {
    return logData.size();
  }

  /// adds a generation in logData
  void life::LogLife::push_back(std::vector< life::Celula > aliveCells)
  {
    logData.push_back( aliveCells );
  }

  /// looks if the simulation are stable NÃO TÁ FUNCIONANDO, O PROBLEMA É NO VECTOR LOGDATA, ELE COMEÇA COM UM TAMANHO ABSURDO HEHE
  bool life::LogLife::isStable()
  {
    size_t actualGeneration = logData.size() - 1;
    int freq = 0; // 0 ou 1?
    bool stable = false;
    std::cout << "ACTUAL " << actualGeneration << std::endl;
    // is searched a generation equal the actual, if found, is stable
    for( size_t i = 0; i < actualGeneration; i++ )
    {
      if( compareGenerations( logData[i], logData[ actualGeneration ] ) )
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
      return true;
    }
    std::cout << actualGeneration << std::endl;
    return false;
  }
