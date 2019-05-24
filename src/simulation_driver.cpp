#include <iostream>
#include "../include/lifeSimulation.h"
#include "../include/canvas/canvas_Life.h"


std::string stopMessage( InitMessages flag ){

  std::string message;

    switch ( flag ) {
    case HELP:
      message = "*** FIM ***";
	break;
    default:
      message = "Stop message flag not valid.";
    }

  return message;
}


/// main function
int main( int argc, char * argv[] )
{

  life::LifeConfig vida;
  life::LogLife log;
  life::LifeSimulation mySim(vida,log); 
  life::SimulationState state;

   // Set up simulation
  InitMessages outputFlag = mySim.initialize( argc, argv, state );
  
  // stop simulation in case user invoque help menu
  if( outputFlag == HELP ){
    std::cout << stopMessage( HELP ) << std::endl;
    return EXIT_SUCCESS;
  }
  

  // print current configuration in console or/and write in file
  mySim.render( state );
    
  
  // The simulation loop
  while(  !mySim.gameover( state ) )
  {
    
    // Check changes in the next generation
    mySim.process_events( state );

    // Update changes
    mySim.update( state );

    // print current configuration in console or/and write in file
    mySim.render( state );

  }

  std::cout << "\n\n *** FIM DA SIMULAÇÃO ***\n\n" << std::endl;

  
  return EXIT_SUCCESS;

}
