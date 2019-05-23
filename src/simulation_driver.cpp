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


  // Set up simulation
  mySim.initialize( argc, argv, state );


  ///////////////////////////// Criar imagens /////////////////////////////

  // criar Canvas w*h
  std::string filename = "generation1.png";
  
  short blocksize = 40;

  life::Canvas image(mySim.life.getWidth(), mySim.life.getHeigth(), blocksize);

  
  std::vector<life::Celula> vv;

  int count = 2;
  // The simulation loop

  while(  !mySim.gameover( state ) )
  {
    
    //desenhar
    create_image(image, mySim.life.getWidth(), mySim.life.getHeigth(), mySim.life, filename);
    
    //mudar nome da proxima imagem
    std::string sc = std::to_string(count);
    filename =  "generation" + sc + ".png";
    count++;

    //simulation.render( state );
    std::cout << mySim.life << std::endl;
    //vv = vida.getAlive();
    std::cout << "GERAÇÃO ATUAL: " << mySim.log->size() << std::endl;
    std::cout << "GERAÇÃO ATUAL STATE: " << state.currentGeneration << std::endl;
    //std::cout << "numero de vivas: " << vv.size() << std::endl;

    mySim.process_events( state );
    
    mySim.update( state );
    
  }

  if( mySim.life.extinct())
  {
    //desenhar
    create_image(image, mySim.life.getWidth(), mySim.life.getHeigth(), mySim.life, filename);
    std::cout << mySim.life << std::endl;
    std::cout << "GERAÇÃO ATUAL: " << mySim.log->size() << std::endl;
    std::cout << "GERAÇÃO EXTINTA" << std::endl;
  }

  std::cout << "\n\nTERMINADO!!!\n\n" << std::endl;



  return EXIT_SUCCESS;


}
