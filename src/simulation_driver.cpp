#include <iostream>

#include "../include/lifeSimulation.h"
#include "../include/canvas/canvas.h"
#include "../include/canvas/lodepng.h"

/// encode Canvas to png
void encode_png(std::string filename, const unsigned char * image, unsigned width, unsigned height)
{
    //Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);

    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

// prototipo criar imagens
void create_image(life::Canvas& image, size_t width, size_t height, life::LifeConfig& vida, std::string filename)
{
  // desenhar
  // mudar a cor das vivas
  for(size_t a=0; a < width+2; a++)
  {
    for(size_t b=0; b < width+2; b++)
    {
      life::Celula temp = vida.getCell(a,b);
      if(temp.alive)
      {
        image.pixel( life::Point2(b,a), life::RED);
      }
      else
      {
        image.pixel( life::Point2(b,a), life::YELLOW);
      }
    }
  }
  // salvar imagem
  encode_png(filename, image.pixels(), image.width(), image.height() );
}

/// main function
int main( int argc, char * argv[] )
{

  life::LifeConfig vida(10,10);
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
  std::cout << vida.getCell(8,6) << std::endl;

  ///////////////////////////// Criar imagens /////////////////////////////

  // criar Canvas w*h
  std::string filename = "image.png";
  int w = 10;
  int h = 10;
  short blocksize = 40;

  life::Canvas image(w+2, h+2, blocksize);

  //desenhar
  create_image(image, w, h, vida, filename);
  /////////////////////////////////////////////////////////////////////////

  // Set up simulation
  mySim.initialize( argc, argv, state );

  //std::cout << "imgdir: " << state.simOptions.imgdir << "\n" << std::endl;
  std::cout << "maxgen: " << state.simOptions.maxgen << "\n" << std::endl;
  
  
  std::vector<life::Celula> vv;
  // Initial message
  std::cout << vida << std::endl;
  // tem que add manualmente na primeira vez
  log.push_back( vida.getAlive() );

  int count = 1;
  // The simulation loop
  while(  !mySim.gameover() )
  {

    mySim.process_events( state );

    mySim.update( state );


    //desenhar
    create_image(image, w, h, vida, filename);
    //mudar nome da proxima imagem
    std::string sc = std::to_string(count);
    filename =  "image" + sc + ".png";
    count++;

    //simulation.render( state );
    //std::cout << vida << std::endl;
    vv = vida.getAlive();
    //std::cout << "GERAÇÃO ATUAL: " << log.size() << std::endl;
    //std::cout << "numero de vivas: " << vv.size() << std::endl;
  }

  std::cout << "\n\nTERMINADO!!!\n\n" << std::endl;



  return EXIT_SUCCESS;


}
