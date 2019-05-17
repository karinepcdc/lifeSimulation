#include "../include/lifeConfig.h"

////////////// não sei pq nao ta dando certo

/// returns a vector with only cells alive
std::vector<life::Celula> life::LifeConfig::getAlive()
{
  std::vector<life::Celula> cellsAlive;

  // loop excluding dead cell boundary; i.e. interator start at 1 and end one step earlier
  for( int i = 1; i < width-1; i++ )
  {
      for( int j = 1; j < heigth-1; j++ )
      {
          if( cellBoard[i][j].alive )
          {
              // add on vector cellsAlive
              cellsAlive.push_back( cellBoard[i][j] );
          }
      }
  }
  return cellsAlive;
}

/// update cellBoard
// TALVEZ NÃO TENHA QUE SOMAR 1 NAS POSICOES (DEPENDE DE COMO O process_events VAI FAZER)
// SE A FUNÇÃO QUE LÊ DO ARQUIVO DE ENTRADA COMPENSAR ESTE 1 NA HORA DE DEFINIR O TABULEIRO AQUI, NÃO VAI PRECISAR COMPENSAR MAIS EM QUALQUER LUGAR
void life::LifeConfig::evolve(std::vector<Celula> toAlter)
{
  Celula cellAux;
  for(size_t i = 0; i < toAlter.size(); i++)
  {
      cellAux = toAlter[i];
      // x and y are shifted to compensate for dead cell boundery
      cellBoard[cellAux.x+1][cellAux.y+1].x = cellAux.x+1;
      cellBoard[cellAux.x+1][cellAux.y+1].y = cellAux.y+1;
      // change alive status
      cellBoard[cellAux.x+1][cellAux.y+1].alive = !cellAux.alive;
  }
}

/// assignment operator
LifeConfig& life::LifeConfig::operator=(const LifeConfig & other)
{
    this->width = other.width;
    this->heigth = other.heigth;
    this->cellBoard = other.cellBoard;

    return *this;
}

/// assignment operator to set the cellBoard with a vector of alive cells
LifeConfig& life::LifeConfig::operator=(const std::vector<Celula> alives)
{
  // temp cell
  Celula tempCell;
  // loop to acces each element in alives
  for( size_t i = 0; i < alives.size() ; i++ )
  {
    tempCell = alives[i];
    this->cellBoard[ tempCell.x ][ tempCell.y ].x = tempCell.x;
    this->cellBoard[ tempCell.x ][ tempCell.y ].y = tempCell.y;
    this->cellBoard[ tempCell.x ][ tempCell.y ].alive = tempCell.alive;
  }
    return *this;
}

/// Friend functions

/// operator << to print a LifeConfig istance
friend std::ostream& life::operator<<( std::ostream& os, const LifeConfig& lifeBoard )
{
    // loop excluding dead cell boundary; i.e. interator start at 1 and end one step earlier
    for( int i = 1; i < lifeBoard.width-1; i++ )
    {
        for( int j = 1; j < lifeBoard.heigth-1; j++ )
        {
            if( lifeBoard.cellBoard[i][j].alive )
            {
                os << "*";
            }
            else
            {
                os << ".";
            }
        }
        os << "\n";
    }
    return os;
}
