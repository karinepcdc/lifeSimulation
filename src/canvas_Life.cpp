#include "../include/canvas/canvas_Life.h"

void encode_png( std::string filename, const unsigned char * image, unsigned width, unsigned height )
{
    //Encode the image
    unsigned error = lodepng::encode( filename, image, width, height );

    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}


void create_image( life::Canvas& image, size_t width, size_t height, life::LifeConfig& vida, std::string filename, life::Color bkgcolor, life::Color alivecolor )
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
  encode_png( filename, image.pixels(), image.width(), image.height() );
}


