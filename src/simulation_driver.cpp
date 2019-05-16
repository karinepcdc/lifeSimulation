#include <iostream>

#include "../include/lifeSimulation.h"

int main( int argc, char * argv[] )
{
  life::LifeSimulation simulation;
  life::SimulationState state;
  
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
  
  life::LifeConfig vida(5,5);

  std::cout << vida << std::endl;

  std::vector<life::Celula> cells(5);
  int x = 0;
  int y = 0;
  
  for(int i = 0; i < 5 ; i++)
  {
    cells[i].x = x;
    cells[i].y = y;
    cells[i].alive = false;
    x++;
    y++;
  }

  cells[4].x = 4;
  cells[4].y = 4;
  cells[4].alive = false;
  
  vida.evolve(cells);

  std::cout << vida << std::endl;

  return EXIT_SUCCESS;
  

}
