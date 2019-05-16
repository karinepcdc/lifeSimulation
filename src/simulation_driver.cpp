#include <iostream>

#include "../include/lifeSimulation.h"

int main( int argc, char * argv[] ){

  life::LifeSimulation simulation;
  SimulationState state;
  
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

  
  return EXIT_SUCCESS;

}
