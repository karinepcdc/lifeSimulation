#include <string>

namespace life
{
  
  /// Classe Que ativa outras classes, instancia objetos e controla o fluxo da simulação (melhorar texto)
  class lifeSimulation()
  {
  private:
    // int generation? (pode ser o size do loglife)
    LifeConfig life; // extrato da simulação; Matriz com células vivas e mortas
    LogLife log;

  public:
  
    /// inicializa a simulação com os parâmetros passados via linha de comando
    void initialize( int argc, string *argv );

    /// 
    void process_events();

    ///
    void update();

    ///
    void render();

    /// Retorna se a simulação acabou (atingiu um estado estável ou houve extinção)
    bool gameover();

  private:
    
    /// Retorna se a simulação atingiu uma configuração estável
    bool stable();

    // métodos consruct, etc...
  
  
  };


}
