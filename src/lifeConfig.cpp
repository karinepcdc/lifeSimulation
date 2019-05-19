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

  /// return a Cell of cellBoard
  life::Celula life::LifeConfig::getCell(int x, int y)
  {
    life::Celula cell = this->cellBoard[x][y];
    return cell;
  }

  /// set a cell in cellBoard
  void life::LifeConfig::setCell( life::Celula cell )
  {
    this->cellBoard[ cell.x ][ cell.y ].x = cell.x;
    this->cellBoard[ cell.x ][ cell.y ].y = cell.y;
    this->cellBoard[ cell.x ][ cell.y ].alive = cell.alive;
  }

  /// return the width of cellBoard (withtout dead boundary)
  int life::LifeConfig::getWidth()
  {
    return width-2;
  }

  /// return the heigth of cellBoard (withtout dead boundary)
  int life::LifeConfig::getHeigth()
  {
    return heigth-2;
  }

  /// update cellBoard
  // TALVEZ NÃO TENHA QUE SOMAR 1 NAS POSICOES (DEPENDE DE COMO O process_events VAI FAZER)
  // SE A FUNÇÃO QUE LÊ DO ARQUIVO DE ENTRADA COMPENSAR ESTE 1 NA HORA DE DEFINIR O TABULEIRO AQUI, NÃO VAI PRECISAR COMPENSAR MAIS EM QUALQUER LUGAR
  void life::LifeConfig::evolve( life::SimulationState state )
  {
    Celula cellAux;
    for(size_t i = 0; i < state.cellChanges.size() ; i++)
    {
        cellAux = state.cellChanges[i];
        // x and y are shifted to compensate for dead cell boundery
        cellBoard[cellAux.x][cellAux.y].x = cellAux.x;
        cellBoard[cellAux.x][cellAux.y+1].y = cellAux.y;
        // change alive status
        cellBoard[cellAux.x][cellAux.y].alive = !cellAux.alive;
    }
  }

  /// returns true if not exist any cell alive, else returns false
  bool life::LifeConfig::extinct()
  {
    // vector with only cells alive of this cell board
    std::vector< life::Celula > cellsAlive = getAlive();

    if(cellsAlive.size() == 0)
    {
      return true;
    }
    return false;
  }


  /// returns the number of neighbors alives of Celula cell
  int life::LifeConfig::getAliveNeighbors(int x, int y)
  {
    int aliveN = 0;
    // line above of cell
    if( cellBoard[ x-1 ][ y-1 ].alive ) { aliveN++; }
    if( cellBoard[ x-1 ][ y ].alive ) { aliveN++; }
    if( cellBoard[ x-1 ][ y+1 ].alive ) { aliveN++; }

    // line of cell
    if( cellBoard[ x ][ y-1 ].alive ) { aliveN++; }
    //if( cellBoard[ x ][ cell.y ] ) ....cell
    if( cellBoard[ x ][ y+1 ].alive ) { aliveN++; }

    // line below of cell

    if( cellBoard[ x+1 ][ y-1 ].alive ) { aliveN++; }
    if( cellBoard[ x+1 ][ y ].alive ) { aliveN++; }
    if( cellBoard[ x+1 ][ y+1 ].alive ) { aliveN++; }

    return aliveN;
  }

  /// assignment operator
  life::LifeConfig& life::LifeConfig::operator=(const life::LifeConfig & other)
  {
      this->width = other.width;
      this->heigth = other.heigth;
      this->cellBoard = other.cellBoard;

      return *this;
  }

  /// assignment operator to set the cellBoard with a vector of alive cells
  life::LifeConfig& life::LifeConfig::operator=(std::vector<life::Celula> alives)
  {
    // temp cell
    Celula tempCell;
    // loop to acces each element in alives
    for( size_t i = 0; i < alives.size() ; i++ )
    {
      tempCell = alives[i];
      cellBoard[ tempCell.x ][ tempCell.y ].x = tempCell.x; // Está dando erro nessa linha, mas não faz sentido
      cellBoard[ tempCell.x ][ tempCell.y ].y = tempCell.y;
      cellBoard[ tempCell.x ][ tempCell.y ].alive = tempCell.alive;
    }
      return *this;
  }
