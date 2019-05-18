#include "../include/lifeSimulation.h"

  void life::LifeSimulation::initialize( int argc, char *argv[] )
  {

    // welcome message
    std::cout << " ***********************************\n"
  	    << " *** Welcome to life Simulation! ***\n"
  	    << " ***********************************\n\n"
  	    << " >>> Rules:\n\n"
  	    << " >>> use option '--help' to display options.\n\n"
  	    << " ***********************************\n\n"
  	    << std::endl;

    if( argc < 2 ){
      throw std::invalid_argument("Expected a least one argument: .\n Usage: glife [<options>] <input_cfg_file>");

    }

    // Read game options
    std::string option, destination;

    int i=1;
    while( i < argc-1 ){

      option = argv[i];

      if( option == "--help"){

        std::cout << " >>> Usage: glife [<options>] <input_cfg_file>\n\n"
  		<< " >>> Simulation options:\n\n"
  		<< " --help \t Print this help text.\n"
  		<< " --imgdir <path> \t Specify directory where output images are written to.\n"
  		<< " --maxgen <num> \t Maximum number of generations to simulate.\n"
  		<< " --fps <num> \t Number of generations presented per second.\n"
  		<< " --blocksize <num> \t Pixel size of a cell. Default = 5.\n"
  		<< " --bkgcolor \t Color name for the background. Default GREEN.\n"
  		<< " --alivecolor <color> \t Color name for representing alive cells. Default RED.\n"
  		<< " --outfile <filename> \t Write the text representation of the simulation \nto the given filename.\n\n"
  		<< " >>> Available colors are:\n\n"
  		<< " BLACK BLUE CRIMSON DARK_GREEN DEEP_SKY_BLUE DODGER_BLUE\n"
  		<< " GREEN LIGHT_BLUE LIGHT_GREY LIGHT_YELLOW RED STEEL_BLUE\n"
  		<< " WHITE YELLOW\n"
  		<< std::endl;

      } else if( option == "--imgdir"){

        if (i + 1 < argc) { // Make sure we aren't at the end of argv!
  	destination = argv[i++]; // Increment 'i' so we don't get the argument as the next argv[i].
        } else { // Uh-oh, there was no argument to the destination option.
  	throw std::invalid_argument("--destination option requires one argument.");
        }

        // preencher struct option

      } else if( option == "--maxgen"){
        //usar atoi ou opção que fiz em search project... qual melhor?

      } else if( option == "--fps"){


      } else if( option == "--blocksize"){


      } else if( option == "--bkgcolor"){


      } else if( option == "--alivecolor"){


      } else if( option == "--outfile"){


      }



      i++;
    }

  // abrir o argv[i] que vai ser o config file
  // se não localizar lançar throw exception

    // Register game options; Fill structure option


    // Process game options


    // Load initial configuration;
    // instancia a lifeconfig

    // instancia loglife e registra primeiro log

  }

  /// Decide, baseado na configuração atual do ecosistema, quais celulas permanecerão vivas e quais irão morrer.
  void life::LifeSimulation::process_events( life::SimulationState state)
  {

    //clear the vector of cells that will change
    state.cellChanges.clear();

    // temp Cell
    life::Celula tempCell;

    for( int i = 1; i <= life.getHeigth() ; i++ )
    {

      for( int j = 1; j <= life.getWidth() ; j++ )
      {

        tempCell = life.getCell(i,j);
        std::cout << "testando" << std::endl;
        if( tempCell.alive )
        {
          // if tempCell have 0 or 1 alive neighbor, or 4 or more neighbors alive, will die
          if( life.getAliveNeighbors(tempCell) <= 1 || life.getAliveNeighbors(tempCell) >= 4)
          {
            state.cellChanges.push_back(tempCell);
          }
          // else, will stay alive
        }
        // if tempCell is dead
        else
        {
          // if tempCell have 3 alive neighbors, will live
          if( life.getAliveNeighbors(tempCell) == 3 )
          {
            state.cellChanges.push_back(tempCell);
          }
          // else, will stay dead
        }
      }
    }

  }

  /// Atualiza o ecosistema baseado nas decisões do process_events
  void life::LifeSimulation::update( SimulationState state )
  {
    // update
    life.evolve( state );

    // next generation
    state.currentGeneration += 1;

  }
