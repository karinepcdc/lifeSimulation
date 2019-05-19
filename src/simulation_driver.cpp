#include <iostream>

#include "../include/lifeSimulation.h"



int main( int argc, char * argv[] )
{

  life::LifeConfig vida(20,20);
  life::LogLife log;
  life::LifeSimulation mySim(vida,log); // CAUSA DO ERRO DE MEMÓRIA
  life::SimulationState state;


  state.currentGeneration = 0;

  std::vector< life::Celula> deadCells;
  int itc = 0;
  // preencher o tabuleiro com celulas vivas
  for(int i = 1; i < 11 ; i++)
  {
      life::Celula mortinha;
      mortinha.x = i;
      mortinha.y = 5;
      mortinha.alive = true;

      deadCells.push_back(mortinha);
      //std::cout << deadCells[itc] << std::endl;
      itc++;
  }
  std::cout << deadCells.size() << std::endl;

  vida = deadCells;

  // Set up simulation
  //mySim.initialize( argc, argv );

  // Initial message
  std::cout << vida << std::endl;


  // The simulation loop
  while(  !mySim.gameover() ){

    mySim.process_events( state );

    mySim.update( state );

    //simulation.render( state );
    std::cout << vida << std::endl;
  }


  // testes

  /*
  life::LifeConfig vida(5,5);

  std::cout << vida << std::endl;

  std::vector<life::Celula> cells(5);
  int x = 0;
  int y = 0;

  for(int i = 0; i < 5 ; i++)
  {
    cells[i].x = 1;
    cells[i].y = 1;
    cells[i].alive = false;
    x++;
    y++;
  }

  life::Celula celula;
  celula.x = 6;
  celula.y = 6;
  celula.alive = true;

  std::cout << vida.extinct() << std::endl;

  //vida.evolve(cells);

  std::cout << vida << std::endl;

  std::cout << vida.getAliveNeighbors(celula) << std::endl;

  vida = vida.getAlive();

  std::cout << vida << std::endl;
  */

  // Teste serios








  /*
  std::cout << vida << std::endl;

  std::cout << "*************************************************************************************************" << std::endl;



  std::cout << vida << std::endl;

  mySim.process_events(state);

  mySim.update(state);

  std::cout << "******************************************************" << std::endl;

  std::cout << vida << std::endl;

  mySim.process_events(state);

  mySim.update(state);

  std::cout << "******************************************************" << std::endl;

  std::cout << vida << std::endl;

  mySim.process_events(state);

  mySim.update(state);

  std::cout << "******************************************************" << std::endl;

  std::cout << vida << std::endl;

  mySim.process_events(state);

  mySim.update(state);

  std::cout << "******************************************************" << std::endl;

  std::cout << vida << std::endl;
  */

  /*
  //lifeSimulation


  std::vector<life::Celula> v;
  //state.cellChanges = v;
  // tem que reservar um espaço no vector
  //state.cellChanges.reserve(100); // não presta mesmo assim, mas passando o vector pro process_events() como parametro funciona
  //std::cout<< "OI SIZE " << state.cellChanges.size() << std::endl;

  //mySim.process_events( state );

  //std::cout << state.cellChanges.size() << std::endl;
  //std::cout << state.cellChanges[1].x << " ," << state.cellChanges[1].y << std::endl;

  //mySim.update( state );

  //std::cout << vida << std::endl;

  std::cout << "oi de novo" << std::endl;
  */

  return EXIT_SUCCESS;


}
