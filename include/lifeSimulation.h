#ifndef LIFESIM_H
#define LIFESIM_H

#include <string>
#include <iostream>
#include <fstream> // file manipulation
#include <sstream> // string stream

#include "commonLife.h"
#include "lifeConfig.h"
#include "logLife.h"

namespace life
{

  /// Classe que ativa outras classes, instancia objetos e controla o fluxo da simulação (melhorar texto)
  class LifeSimulation
  {
  private:

    life::LifeConfig life;    // Ecosistema da simulação; Matriz com células vivas e mortas
    life::LogLife* log;        // Log das gerações
    //Options simOptions; // Opções da simulações


  public:

    /// Default constructor ????????????????????? pode?
    LifeSimulation()
    {/* empty */}

    /// constructor
    /**
    * Constructor thats receveis LifeConfig and LogLife istances
    *
    * @param lf: LifeConfig istance
    * @param lg: LogLife istance
    */
    LifeSimulation(life::LifeConfig& lf, life::LogLife& lg):
      life{lf}, log{&lg}
    {/* empty */}


    /// Default destructor
    ~LifeSimulation()
    {
      life.~LifeConfig();
    }

    /// Initialize simulation with a welcome menssage; Read and register game options and process some of them; Load initial configuration;
    /**
     *  Itializes the simulation
     *
     *  @param argc, number of arguments
     *  @param argv, arguments of comand line
     *
     *  Prints the welcome message, decides the config of the simulation
     *  looking the arguments. Read the initial configuration file and begins the simulation
     */
    void initialize( int argc, char *argv[], life::SimulationState &state );

    /// Decides the cells that will live or die
    /**
     *  Decides the cells that will live or die in next generation
     *
     *  @param state: state of that contais the number of current genearion and std::vector of cells
     *
     *  Looking the rules, the process_events() will decide to each cell in board of LifeConfig istance
     *  if the cell must die or live, if the cell must change, is added to vector in state that will be used in update()
     */
    void process_events( life::SimulationState &state );

    /// Updates the cells board with decisions made by process_events
    /**
     * Updates the cells board of the LifeConfig istance
     *
     * @param state: SimulationState that contais the number of current generation and the cells that must die or live
     *
     *  Calls the methodo of LifeConfig evolve() to change the state of the cells
     *  ,add the cew generation in the log and sum 1 to state.currentGeneration
     */
    void update( SimulationState state);

    /// printout the state of simulation
    /**
    * Prints the simulation
    *
    * @param state: state of simulation
    */
    void render( SimulationState state ) const;

    /// Checks if the game over
    /*
     * Checks if the game over, looking if the generations are stable or extinct
     *
     * Returns true if the game over, else, returns false
     */
    bool gameover();

  private:

    /**
    *  Checks if the simulation are stable
    *
    * return true if are
    */
    // ??????????
    //bool stable() const;


  };


}

#endif
