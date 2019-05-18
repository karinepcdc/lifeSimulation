#include <iostream>

#include "../include/lifeSimulation.h"



int main( int argc, char * argv[] )
{
  /*
  life::LifeSimulation simulation;
  life::SimulationState state;


  // Set up simulation
  simulation.initialize( argc, argv );

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
  life::LifeSimulation mySim(vida);

  std::vector< life::Celula> deadCells;
  int itc = 0;
  // preencher o tabuleiro com celulas vivas
  for(int i = 1; i < 11 ; i++)
  {
      life::Celula mortinha(i,5,true);
      deadCells.push_back(mortinha);
      std::cout << deadCells[itc] << std::endl;
      itc++;
  }
  std::cout << deadCells.size() << std::endl;

  vida = deadCells;

  std::cout << vida << std::endl;

  std::cout << "*************************************************************************************************" << std::endl;

  /*
  //lifeSimulation


  std::vector<life::Celula> v;
  //state.cellChanges = v;
  // tem que reservar um espaço no vector
  //state.cellChanges.reserve(100); // não presta mesmo assim, mas passando o vector pro process_events() como parametro funciona
  //std::cout<< "OI SIZE " << state.cellChanges.size() << std::endl;

  //mySim.process_events( state );

  //std::cout << state.cellChanges.size() << std::endl;
  //std::cout << state.cellChanges[1].x << " ," << state.cellChanges[1].y << std::endl;

  //mySim.update( state );

  //std::cout << vida << std::endl;

  std::cout << "oi de novo" << std::endl;
  */

  return EXIT_SUCCESS;


}
