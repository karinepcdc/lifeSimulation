#include "../include/lifeSimulation.h"
#include "../include/canvas/commonCanvas.h"


life::Color strToColor( const std::string color )
{

    if( color == "BLACK" ){
	return life::BLACK;
    }

    else if ( color == "WHITE" ){
      return life::WHITE;
      } else if ( color == "DARK_GREEN" ){
      return life::DARK_GREEN;
      } else if ( color == "GREEN" ){
      return life::GREEN;
      } else if ( color == "RED" ){
      return life::RED;
      } else if ( color == "CRIMSON" ){
      return life::CRIMSON;
      } else if ( color == "LIGHT_BLUE" ){
      return life::LIGHT_BLUE;
      } else if ( color == "LIGHT_GREY" ){
      return life::LIGHT_GREY;
      } else if ( color == "DEEP_SKY_BLUE" ){
      return life::DEEP_SKY_BLUE;
      } else if ( color == "DODGER_BLUE" ){
      return life::DODGER_BLUE;
      } else if ( color == "STEEL_BLUE" ){
      return life::STEEL_BLUE;
      } else if ( color == "YELLOW" ){
      return life::YELLOW;
      } else if ( color == "LIGHT_YELLOW" ){
      return life::LIGHT_YELLOW;
      }
    else {

	throw std::invalid_argument("--Invalid color. Check '--help' to see available palette.");
    }
}

void life::LifeSimulation::initialize( int argc, char *argv[], life::SimulationState &state )
{

    // welcome message
    std::cout << " ***********************************\n"
	<< " *** Welcome to life Simulation! ***\n"
	<< " ***********************************\n\n"
	<< " >>> Rules:\n\n"
	<< " >>> use option '--help' to display options.\n\n"
	<< " >>> Ps: Configuration file must be provided at dir: 'SimulationLife/data/'."
	<< " ***********************************\n\n"
	<< std::endl;

	   if( argc < 2 ){
	       throw std::invalid_argument("Expected a least one argument: .\n Usage: glife [<options>] <input_cfg_file> \n Ps: Configuration file should be at dir: 'SimulationLife/data/'.");

	   }

	// Read game options
	std::string option;

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

	    } else if( option == "--imgdir"){ /********* OPTION **********/

		if (i + 1 < argc) { // Make sure we aren't at the end of argv!

		    // fill struct option
		    state.simOptions.imgdir = std::string ( argv[++i] ) ;// Increment 'i' to get the next argument in argv[i].

		} else { // Uh-oh, there was no argument to the destination option.

		    throw std::invalid_argument("--destination option requires one argument.");
		}

	    } else if( option == "--maxgen"){ /********* OPTION **********/

		if (i + 1 < argc) { // Make sure we aren't at the end of argv!

		    // fill struct option
		    state.simOptions.maxgen = std::atoi ( argv[++i] ) ; // Increment 'i' to get the next argument in argv[i].

		} else { // Uh-oh, there was no argument to the destination option.

		    throw std::invalid_argument("--destination option requires one argument.");
		}

	    } else if( option == "--fps"){ /********* OPTION **********/
		if (i + 1 < argc) { // Make sure we aren't at the end of argv!

		    // fill struct option
		    state.simOptions.fps = std::atoi ( argv[++i] ) ; // Increment 'i' to get the next argument in argv[i].

		} else { // Uh-oh, there was no argument to the destination option.

		    throw std::invalid_argument("--destination option requires one argument.");
		}

	    } else if( option == "--blocksize"){ /********* OPTION **********/

		if (i + 1 < argc) { // Make sure we aren't at the end of argv!

		    // fill struct option
		    state.simOptions.blocksize = std::atoi ( argv[++i] ) ; // Increment 'i' to get the next argument in argv[i].

		} else { // Uh-oh, there was no argument to the destination option.

		    throw std::invalid_argument("--destination option requires one argument.");
		}

	    } else if( option == "--bkgcolor"){ /********* OPTION **********/

		if (i + 1 < argc) { // Make sure we aren't at the end of argv!

		    // fill struct option
		    // 1st - Convert c-string to cpp-std::string; 2nd - Convert cpp-std::string to life::color;
		    state.simOptions.bkgcolor = strToColor( std::string ( argv[++i] ) );// Increment 'i' to get the next argument in argv[i].
		    //state.simOptions.bkgcolor = std::string ( argv[++i] );// Increment 'i' to get the next argument in argv[i].


		} else { // Uh-oh, there was no argument to the destination option.

		    throw std::invalid_argument("--destination option requires one argument.");
		}

	    } else if( option == "--alivecolor"){ /********* OPTION **********/

		if (i + 1 < argc) { // Make sure we aren't at the end of argv!

		    // fill struct option
		    //state.simOptions.alivecolor = std::string ( argv[++i] ) ;// Increment 'i' to get the next argument in argv[i].
        state.simOptions.alivecolor = strToColor( std::string ( argv[++i] ) );// Increment 'i' to get the next argument in argv[i].

		} else { // Uh-oh, there was no argument to the destination option.

		    throw std::invalid_argument("--destination option requires one argument.");
		}

	    } else if( option == "--outfile"){ /********* OPTION **********/

		if (i + 1 < argc) { // Make sure we aren't at the end of argv!

		    // fill struct option
		    state.simOptions.outfile = std::string ( argv[++i] ) ;// Increment 'i' to get the next argument in argv[i].

		} else { // Uh-oh, there was no argument to the destination option.

		    throw std::invalid_argument("--destination option requires one argument.");
		}

	    }


	    i++;
	} // end loop

	// Reading configuration file name
	std::string fileName{"../data/"};
	std::string configFileName = std::string ( argv[i] );
	fileName.std::string::append(configFileName);

	// Open configuration file
	std::ifstream configFile;
	configFile.open( fileName.c_str() );
	if( configFile.fail() ){
	    throw std::invalid_argument("--Unable to open configuration file. \n\n It is expected as the last argument:.\n Usage: glife [<options>] <input_cfg_file> \n Ps: Configuration file should be at dir: 'SimulationLife/data/'.");
	}// pode tratar exceção assim 1????????

	// Reading configuration file
	std::string line;

	int w, h;
	getline(configFile, line); // read boad size <nLin> <nCol>
	std::stringstream lineStr(line);
	lineStr >> h >> w >> std::ws; // tá invertido 2???????
	life.setWidth(w+2); // add dead boundary
	life.setHeigth(h+2); // add dead boundary

	//std::cout << w << " " << h << std::endl;
	//std::cout << life.getWidth() << " " << life.getHeigth() << std::endl;

	// Alocate initial lifeconfig cellboard
	life::Celula **init_board = new life::Celula*[ life.getWidth() ];
	for(int j = 0; j < life.getWidth(); j++){
	  init_board[j] = new life::Celula[ life.getHeigth() ];
	}

	getline(configFile, line); // read char representing alive cell

	state.simOptions.char_alive = line[0];
	//std::cout << line[0] << " = " << state.simOptions.char_alive << "?"<< std::endl;
	
	i=0; // line number
	while( getline(configFile, line) ){ 
	  //std::cout << "\nfull line: " << line << std::endl;
	  
	  int j=0; // col number
	  while( line[j] != '\0' && j < life.getWidth()-2 ){ // usar str len??

	    if( line[j] == state.simOptions.char_alive ){
	      std::cout << "(" << i << " " << j << ")";	 
	    } else {
	      std::cout << "0";	 
	    }
	    j++;
	    
	  }
	  i++;
	  std::cout << "\n";	 
	  if( i >= life.getHeigth()-2 ){ break; } // read only cellboard size
	  // Load initial configuration;
	}

	// Process game options
	// print everything





	// instancia loglife e registra primeiro log


	// closing file
        configFile.close();

}

    /// Decide, baseado na configuração atual do ecosistema, quais celulas permanecerão vivas e quais irão morrer.
    void life::LifeSimulation::process_events( life::SimulationState &state )
    {

	//clear the vector of cells that will change
	state.cellChanges.clear();
	//cellChanges.clear();
	life::Celula * willChange = new life::Celula[ this->life.getWidth() * this->life.getHeigth() ];
	life::Celula * it = willChange;
	int addedCells = 0;

	// search cells that will change and add to willChange vector
	for( int i = 1; i <= this->life.getWidth()-1 ; i++ )
	    {

		for( int j = 1; j <= this->life.getHeigth()-1 ; j++ )
		    {
			// temp Cell
			life::Celula tempCell = this->life.getCell(i,j);

			if( tempCell.alive )
			    {
				// if tempCell have 0 or 1 alive neighbor, or 4 or more neighbors alive, will die
				if( this->life.getAliveNeighbors( i, j ) <= 1 || this->life.getAliveNeighbors( i, j ) >= 4)
				    {
					//state.cellChanges.push_back(tempCell);
					*it = tempCell;
					it++;
					addedCells++;
				    }
				// else, will stay alive
			    }
			// if tempCell is dead
			else
			    {
				// if tempCell have 3 alive neighbors, will live
				if( this->life.getAliveNeighbors( i, j ) == 3 )
				    {
					//state.cellChanges.push_back(tempCell);
					*it = tempCell;
					it++;
					addedCells++;
				    }
				// else, will stay dead
			    }
		    }
	    }

	// add the cells that will change on vector of state O JEITO QUE DEU CERTO (POR ALGUMA RAZAO NAO CONSIGO USAR O push_back LA EM CIMA)
	for(int i = 0; i < addedCells; i++)
	    {
		state.cellChanges.push_back( willChange[i] );
		//std::cout << state.cellChanges[i].x << ", " << state.cellChanges[i].y  << std::endl;
	    }

	//std::cout << "OI CHEGUEI AQUI" << std::endl;

	delete [] willChange;

	//std::cout << "OI CHEGUEI AQUI" << std::endl;
    }

/// Atualiza o ecosistema baseado nas decisões do process_events
void life::LifeSimulation::update( SimulationState state )
{

    // update
    life.evolve( state );

    // add generation on loglife data
    log->push_back( life.getAlive() );

    // next generation
    state.currentGeneration += 1;

}

/// Retorna se a simulação acabou (atingiu um estado estável ou houve extinção)
bool life::LifeSimulation::gameover()
{

    if(  life.extinct() || log->isStable() ) {
      return true;
    }

    return false;
}
