#include "../include/lifeSimulation.h"

void initialize( int argc, char *argv[] )
{

  // welcome message
  std::cout << "Welcome to life Simulation! \n\n"
	    << "Rules:\n\n"
	    << "use option '--help' to display options.\n\n"
	    << std::endl;

  if( argc < 2 ){
    throw std::invalid_argument("Expected a least one argument: .\n Usage: glife [<options>] <input_cfg_file>");

  }
       
  // Read game options
  int i=1;
  while( i < argc-1 ){

    if( argv[i] == "--help"){

      std::cout << "Usage: glife [<options>] <input_cfg_file>\n\n"
		<< "Simulation options:\n\n"
		<< "--help \t Print this help text.\n"
		<< "--imgdir <path> \t Specify directory where output images are written to.\n"
		<< "--maxgen <num> \t Maximum number of generations to simulate.\n"
		<< "--fps <num> \t Number of generations presented per second.\n"
		<< "--blocksize <num> \t Pixel size of a cell. Default = 5.\n"
		<< "--bkgcolor \t Color name for the background. Default GREEN.\n"
		<< "--alivecolor <color> \t Color name for representing alive cells. Default RED.\n"
		<< "--outfile <filename> \t Write the text representation of the simulation \nto the given filename.\n\n"
		<< "Available colors are:\n\n"
		<< "BLACK BLUE CRIMSON DARK_GREEN DEEP_SKY_BLUE DODGER_BLUE\n"
		<< "GREEN LIGHT_BLUE LIGHT_GREY LIGHT_YELLOW RED STEEL_BLUE\n"
		<< "WHITE YELLOW\n"
		<< std::endl;	
      
    } else if( argv[i] == "--imgdir"){

    } else if( argv[i] == "--maxgen"){


    } else if( argv[i] == "--fps"){


    } else if( argv[i] == "--blocksize"){


    } else if( argv[i] == "--bkgcolor"){


    } else if( argv[i] == "--alivecolor"){


    } else if( argv[i] == "--outfile"){


    } 
    
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
