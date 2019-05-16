#include <iostream>

#include "../include/lifeSimulation.h"

int main( int argc, char * argv[] )
{
  
  life::LifeSimulation simulation;

  // Set up simulation
  simulation.initialize( argc, argv );

  // Initial message

  simulation.render();

  // The simulation loop
  while( not simulation.gameover() ){
    
    simulation.process_events();
    simulation.update();
    simulation.render();
  }

  

  life::LifeConfig vida(5,5);

  std::cout << vida << std::endl;

  std::vector<Celula> cells(5);
  int x = 0;
  int y = 0;
  std::cout << "OI" << std::endl;
  
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
