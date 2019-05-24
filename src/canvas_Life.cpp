#include "../include/canvas/canvas_Life.h"

/**
* Convert Canvas to png file
*
* @param filename: name of the image file that will be saved
* @param image: canvas
* @param width: width of canvas
* @param height: height of canvas
*/
void encode_png( std::string filename, const unsigned char * image, unsigned width, unsigned height )
{
    //Encode the image
    unsigned error = lodepng::encode( filename, image, width, height );

    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

/**
* Draws in the canvas
*
* @param image: canvas
* @param width: width of canvas
* @param height: height of canvas
* @param vida: LifeConfig istance to be drawned
* @param filename: name of file to save image
* @param bkgcolor: color of dead cells
* @param alivecolor: color of alive cells
*/
void create_image( life::Canvas& image, size_t width, size_t height, life::LifeConfig& vida, std::string filename, life::Color bkgcolor, life::Color alivecolor )
{
  // draw image
  for(size_t a=0; a < width; a++)
  {
    for(size_t b=0; b < height; b++)
    {
      life::Celula temp = vida.getCell(a,b);

      if(temp.alive)
      {
        image.pixel( life::Point2(a,b), alivecolor);
      }
      else
      {
        image.pixel( life::Point2(a,b), bkgcolor);
      }
    }

  }


  // salvar imagem
  encode_png( filename, image.pixels(), image.width(), image.height() );
}
