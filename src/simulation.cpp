#include <iostream>

#include "../include/lifeSimulation.h"

int main( int argc, char * argv[] ){

  life::LifeSimulation simulation;

  // Set up simulation
  simulation.initialize( argc, argv );

  // Initial message
  simulation.render();

  // The simulation loop
  while( not simulation.game_over() ){
    
    simulation.process_events();
    simulation.update();
    simulation.render();
  }

  
  return EXIT_SUCCESS;

}
