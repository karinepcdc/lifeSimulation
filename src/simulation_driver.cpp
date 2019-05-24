#include <iostream>
#include "../include/lifeSimulation.h"
#include "../include/canvas/canvas_Life.h"


/// main function
int main( int argc, char * argv[] )
{

  life::LifeConfig vida;
  life::LogLife log;
  life::LifeSimulation mySim(vida,log);
  life::SimulationState state;

  //std::vector<life::Celula> vv;

  // Set up simulation
  mySim.initialize( argc, argv, state );


  // print in console or/and write in file
  mySim.render( state );


  // The simulation loop
  while(  !mySim.gameover( state ) )
  {

    // Check changes in the next generation
    mySim.process_events( state );

    // Update changes
    mySim.update( state );

    // print in console or/and write in file
    mySim.render( state );

    //vv = vida.getAlive();
    //std::cout << "numero de vivas: " << vv.size() << std::endl;

  }

  std::cout << "\n\n *** END OF SIMULATION ***\n\n" << std::endl;


  return EXIT_SUCCESS;

}
