#include <string>
#include <iostream>


#include "commonLife.h"
#include "lifeConfig.h"
#include "logLife.h"

namespace life
{
  
  /// Classe que ativa outras classes, instancia objetos e controla o fluxo da simulação (melhorar texto)
  class LifeSimulation()
  {
  private:

    LifeConfig life;    // Ecosistema da simulação; Matriz com células vivas e mortas
    LogLife log;        // Log das gerações 
    Options simOptions; // Opções da simulações 
    
    
  public:
  
    /// Initialize simulation with a welcome menssage; Read and register game options and process some of them; Load initial configuration;
    void initialize( int argc, char *argv[] );

    /// Decide, baseado na configuração atual do ecosistema, quais celulas permanecerão vivas e quais irão morrer.
    void process_events();

    /// Atualiza o ecosistema baseado nas decisões do process_events
    void update();

    /// Imprime a configuração atual do ecosistema
    void render() const;

    /// Retorna se a simulação acabou (atingiu um estado estável ou houve extinção)
    bool gameover() const;

  private:
    
    /// Retorna se a simulação atingiu uma configuração estável
    bool stable() const;

    // métodos construct, etc...
  
  
  };


}
