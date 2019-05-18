#include <iostream>

#include "../include/lifeSimulation.h"


int main( int argc, char * argv[] )
{
  life::LifeSimulation simulation;
  life::SimulationState state;

  state.currentGeneration = 0;

  // Set up simulation
  simulation.initialize( argc, argv );
  /*
  // Initial message
  simulation.render( state );

  // The simulation loop
  while( not simulation.game_over( state ) ){

    simulation.process_events( state );
    simulation.update( state );
    simulation.render( state );
  }
  */

  // testes

  /*
  life::LifeConfig vida(5,5);

  std::cout << vida << std::endl;

  std::vector<life::Celula> cells(5);
  int x = 0;
  int y = 0;

  for(int i = 0; i < 5 ; i++)
  {
    cells[i].x = 1;
    cells[i].y = 1;
    cells[i].alive = false;
    x++;
    y++;
  }

  life::Celula celula;
  celula.x = 6;
  celula.y = 6;
  celula.alive = true;

  std::cout << vida.extinct() << std::endl;

  //vida.evolve(cells);

  std::cout << vida << std::endl;

  std::cout << vida.getAliveNeighbors(celula) << std::endl;

  vida = vida.getAlive();

  std::cout << vida << std::endl;
  */

  // Teste serios

  life::LifeConfig vida(10,10);
  std::vector< life::Celula> deadCells;

  life::Celula mortinha;
  mortinha.alive = false;
  // preencher o tabuleiro com celulas mortas
  for(int i = 0; i < 10 ; i++)
  {
    for(int j = 0; j < 10 ; j++)
    {
      mortinha.x = i;
      mortinha.y = j;

      deadCells.push_back(mortinha);
    }
  }

  // definir uma configuração para começar a simulação (o operator=(vector<Celula>) faz isso), aqui deve compensar o dead boundary
  std::vector< life::Celula> aliveCells;

  life::Celula vivinha;
  vivinha.alive = true;
  vivinha.y = 5;
  // vou colocar uma coluna inteira só de vivas;
  for(int i = 1; i < 11 ; i++)
  {
    vivinha.x = i;
    aliveCells.push_back(vivinha);
  }

  //Seta a configuração
  vida = aliveCells;

  std::cout << vida << std::endl;

  std::cout << "*************************************************************************************************" << std::endl;


  //lifeSimulation
  life::LifeSimulation mySim(vida); // só o fato de criar esta istancia está dando o erro "double free or corruption"

  // tem que reservar um espaço no vector
  state.cellChanges.reserve(100); // não presta mesmo assim, mas passando o vector pro process_events() como parametro funciona

  std::vector<life::Celula> cellsChange(100);
  mySim.process_events( state );

  state.cellChanges = cellsChange;
  std::cout << cellsChange[0].x << " ," << cellsChange[0].y << std::endl;
  std::cout << cellsChange.size() << std::endl;
  mySim.update( state );

  std::cout << vida << std::endl;

  std::cout << "oi de novo" << std::endl;

  return EXIT_SUCCESS;


}
