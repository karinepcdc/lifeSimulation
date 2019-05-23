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
  
  for(size_t a=0; a < width; a++)
  {
    for(size_t b=0; b < height; b++)
    {
      life::Celula temp = vida.getCell(a,b);
      
      if(temp.alive)
      {
        image.pixel( life::Point2(a,b), life::RED);
      }
      else
      {
        image.pixel( life::Point2(a,b), life::YELLOW);
      }
    }
    
  }
  // salvar imagem
  encode_png(filename, image.pixels(), image.width(), image.height() );
}

/// main function
int main( int argc, char * argv[] )
{

  life::LifeConfig vida;
  life::LogLife log;
  life::LifeSimulation mySim(vida,log); // CAUSA DO ERRO DE MEMÓRIA
  life::SimulationState state;


  state.currentGeneration = 0;

  // Set up simulation
  mySim.initialize( argc, argv, state );

  std::cout << "imgdir: " << state.simOptions.imgdir << "\n" << std::endl;
  std::cout << "maxgen: " << state.simOptions.maxgen << "\n" << std::endl;
  std::cout << "fps: " << state.simOptions.fps << "\n" << std::endl;
  std::cout << "blocksize: " << state.simOptions.blocksize << "\n" << std::endl;
  //std::cout << "bkgcolor: " << life::BLACK.channels[0] << " ." << state.simOptions.bkgcolor.channels[1] << ". " << state.simOptions.bkgcolor.channels[3] << "\n" << std::endl;
  std::cout << "bkgcolor: " << state.simOptions.bkgcolor << "\n" << std::endl;
  std::cout << "alivecolor: " << state.simOptions.alivecolor << "\n" << std::endl;
  std::cout << "outfile: " << state.simOptions.outfile << "\n" << std::endl;


  ///////////////////////////// Criar imagens /////////////////////////////

  // criar Canvas w*h
  std::string filename = "image.png";
  
  short blocksize = 40;

  life::Canvas image(mySim.life.getWidth(), mySim.life.getHeigth(), blocksize);

  
  std::vector<life::Celula> vv;
  // Initial message
  //std::cout << mySim.life << std::endl;
  // tem que add manualmente na primeira vez
  mySim.log->push_back( mySim.life.getAlive() );

  int count = 1;
  // The simulation loop

  while(  !mySim.gameover() )
  {
    
    //desenhar
    create_image(image, mySim.life.getWidth(), mySim.life.getHeigth(), mySim.life, filename);
    
    //mudar nome da proxima imagem
    std::string sc = std::to_string(count);
    filename =  "image" + sc + ".png";
    count++;

    //simulation.render( state );
    std::cout << mySim.life << std::endl;
    //vv = vida.getAlive();
    std::cout << "GERAÇÃO ATUAL: " << mySim.log->size() << std::endl;
    //std::cout << "numero de vivas: " << vv.size() << std::endl;

    mySim.process_events( state );
    
    mySim.update( state );


    
  }

  std::cout << "\n\nTERMINADO!!!\n\n" << std::endl;



  return EXIT_SUCCESS;


}
