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
	      << " ***********************************\n\n"
	      << std::endl;

    if( argc < 2 ){
	throw std::invalid_argument("Expected a least one argument: .\n Usage: glife [<options>] <input_cfg_file>.");

    }


    // definied default game option
	   state.simOptions.imgdir = "";
	   state.simOptions.maxgen = 0;
	   state.simOptions.fps = 1;
	   state.simOptions.blocksize = 40;
	   state.simOptions.bkgcolor = life::YELLOW;
	   state.simOptions.alivecolor = life::RED;
	   state.simOptions.outfile = "";
	   state.simOptions.char_alive = '*';

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
        std::cout << "COOOOOOOOOR " << std::string ( argv[++i] ) << std::endl;
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
	std::string fileName{""};
	std::string configFileName = std::string ( argv[i] );
	fileName.std::string::append(configFileName);

	// Open configuration file
	std::ifstream configFile;
	configFile.open( fileName.c_str() );

	// If file fail to open throw expetion
	if( configFile.fail() ){
	    throw std::invalid_argument("--Unable to open configuration file. \n\n It is expected as the last argument:.\n Usage: glife [<options>] <input_cfg_file>.");
	}


	// Reading configuration file
	std::string line;

	int w, h; // temp with and height
	getline(configFile, line); // read board size <nLin> <nCol>
	std::stringstream lineStr(line);
	lineStr >> h >> w >> std::ws;
	h += 2; // add dead boundary
	w += 2; // add dead boundary
	//life.setWidth(w+2); // add dead boundary
	//life.setHeigth(h+2); // add dead boundary

	// Alocate initial lifeconfig cellboard
	life::Celula **init_board = new life::Celula*[ w ];
	for(int j = 0; j < w; j++){
	  init_board[j] = new life::Celula[ h ];
	}

	// Initialize cellboard with deadcells only
	for(int i = 0; i < w; i++) {
	  for(int j = 0; j < h; j++) {
		init_board[i][j].x = i;
		init_board[i][j].y = j;
		init_board[i][j].alive = false;
	      }
	  }

	// reset current life cellboard to new cellboard
	life.resetCellboard( init_board, w, h );


	// read char representing alive cell
	getline(configFile, line);
	state.simOptions.char_alive = line[0];

	// Read configuratio file board; get cell alives and put them in the life cell board
	i=0; // line number
	while( getline(configFile, line) ){

	  int j=0; // col number
	  while( line[j] != '\0' && j < life.getWidth()-2 ){

	    if( line[j] == state.simOptions.char_alive ){
	      Celula tmp_cell;

	      // set cell position and state as alive
	      tmp_cell.x=j+1;
	      tmp_cell.y=i+1;
	      tmp_cell.alive=true;

	      life.setCell(tmp_cell);
	    }
	    j++;

	  }
	  i++;
	  if( i >= life.getHeigth()-2 ){ break; } // read only cellboard size

	}

	// closing file
        configFile.close();

	// Process game options
	std::cout << "\n\n *** Starting simulation *** \n\n"
		  << " *Simulation parameters* \n"
		  << " Cell board size: " <<  life.getHeigth()-2
		  << " x " << life.getWidth()-2 << "\n";

	if( state.simOptions.maxgen == 0 ){
	    std::cout << " No generation limit set.\n";
	} else {
	    std::cout << " Max generation: " << state.simOptions.maxgen << "\n";
	}

	std::cout << "\n *Image generation parameters* \n";
	if( state.simOptions.imgdir == "" ){
	    std::cout << "\n>>> Printing in console.\n"
		      << "    Figures per second: " << state.simOptions.fps << "\n";
	} else {
	    std::cout << "\n>>> Printing graphic images. \n"
		      << "    Image will be saved at: " <<  state.simOptions.imgdir << "\n"
	    	      << "    Block size: " <<  state.simOptions.blocksize << "\n"
		      << "    Dead cell color: " << state.simOptions.bkgcolor << "\n"
		      << "    Alive cell color: " <<  state.simOptions.alivecolor << "\n";

	}

	if( state.simOptions.outfile != "" ){
	  std::cout << "Printing in text file. \n"
		    << "Text file will be saved at: " <<  state.simOptions.outfile << "\n"
		      << "Char representing alive cells: " << state.simOptions.char_alive;
	}
	std::cout << std::endl;

	//  Registra primeiro loglife
	log->push_back( life.getAlive() );

	// Update current generation
	state.currentGeneration = 1;

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
	for( int i = 1; i < this->life.getWidth()-1 ; i++ )
	    {
		for( int j = 1; j < this->life.getHeigth()-1 ; j++ )
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

	delete [] willChange;

    }

/// Atualiza o ecosistema baseado nas decisões do process_events
void life::LifeSimulation::update( SimulationState &state )
{

    // update
    life.evolve( state );

    // add generation on loglife data
    log->push_back( life.getAlive() );

    // next generation
    state.currentGeneration += 1;

}

/// Retorna se a simulação acabou (atingiu um estado estável ou houve extinção)
bool life::LifeSimulation::gameover( SimulationState &state )
{

  bool LimitGen = false;

  // check if there is a max generation
  if( state.simOptions.maxgen != 0 and state.currentGeneration >= state.simOptions.maxgen ){
      LimitGen = true;
  }

  // check if any gameover condition have happened
  if(  life.extinct() || log->isStable() || LimitGen ) {


    return true;
  }

  return false;

}


void life::LifeSimulation::render( SimulationState &state )
{

  if( state.simOptions.imgdir == "" ){  // Printing in console


    // defining images per second in console
    if( state.simOptions.fps != 0 ){
      std::this_thread::sleep_for( std::chrono::milliseconds( 1000/state.simOptions.fps*2 ) );
    }

    // print current configuration

      std::cout << "GENERATION " << state.currentGeneration << std::endl;
      std::cout << life << std::endl;


    // check if simulation is over and print final message
    if( life.extinct() ){
      std::cout << " *EXTINCT GENERATION* " << std::endl;

    } else if ( log->isStable() ){

      std::cout << " *STABILITY ACHIEVED* " << std::endl;
      std::cout << " Frequency: " << log->getFreq() << std::endl;

    } else if( state.simOptions.maxgen != 0 and state.currentGeneration >= state.simOptions.maxgen ){

      std::cout << " *MAXIMUM GENERATION NUMBER ACHIEVED* " << std::endl;
    }


  } else { // Printing graphic images

    // Create canvas
    short blocksize = state.simOptions.blocksize;
    life::Canvas image( life.getWidth(), life.getHeigth(), blocksize );

    // define nome da proxima imagem e local onde irá salvar a imagem
    std::string filename;
    std::string sc = std::to_string( state.currentGeneration );
    filename =  state.simOptions.imgdir + "generation" + sc + ".png";

    life::Color bkgcolor = state.simOptions.bkgcolor;
    life::Color alivecolor = state.simOptions.alivecolor;

    /// desenhar no canvas!
    create_image( image, life.getWidth(), life.getHeigth(), life, filename, bkgcolor, alivecolor );

  }

  if( state.simOptions.outfile != "" ){ // Printing in text file


    // Reading output text file name
    std::string fileName{ state.simOptions.outfile };

    // Open output text file
    std::ofstream outputFile;
    outputFile.open( fileName.c_str(), std::ios_base::app );

    // If file fail to open throw expetion
    if( outputFile.fail() ){
      throw std::invalid_argument("--Unable to open output text file. Check program argument definitions with option --help.");
    }

    // print current configuration
      outputFile << "GENERATION " << state.currentGeneration << std::endl;
      outputFile << life << std::endl;


    // check if simulation is over and print final message
    if( life.extinct() ){
      outputFile << " *EXTINCT GENERATION* " << std::endl;

    } else if ( log->isStable() ){

      outputFile << " *STABILITY ACHIEVED* " << std::endl;
      // to compensate the frenquency counter
      if( state.simOptions.imgdir == "" )
      {
        outputFile << " Frequency: " << log->getFreq()-1 << std::endl;
      }
      else
      {
        outputFile << " Frequency: " << log->getFreq() << std::endl;
      }


    } else if( state.simOptions.maxgen != 0 and state.currentGeneration >= state.simOptions.maxgen ){

      outputFile << " *MAXIMUM GENERATION NUMBER ACHIEVED* " << std::endl;
    }

    // closing file
    outputFile.close();

    //state.simOptions.char_alive
  }


}
