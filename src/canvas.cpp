#include "../include/canvas/canvas.h"

//=== Special members
/*
Canvas( const Canvas & )
{
}

Canvas & operator=( const Canvas & )
{
}

Canvas( Canvas && clone )
{
}

Canvas & operator=( Canvas && )
{
}

*/


//=== Members

void life::Canvas::clear( const life::Color& color )
{
  //  std::memset( m_pixels.data(), 0, m_width * m_height * image_depth ); // Clear the canvas with black color.
  life::Point2 p;
  
  for( unsigned int i=0; i < m_width/m_block_size; i++ ){

    p.x=i;
    for( unsigned int j=0; j < m_height/m_block_size; j++ ){
      p.y=j;

      life::Canvas::pixel( p,  color );
      
    }
  }
  
}

void life::Canvas::pixel( const life::Point2& p,  const life::Color& color )
{
  //Até onde percorrer as colunas de mini pixeis
  int limiteHorizontal = m_block_size * 4;
  int limiteVertical = limiteHorizontal  * m_width ;
  
  //Acessar a posicao exata de um pequeno pixel no vector m_pixels
  int it = p.x * limiteHorizontal + p.y * limiteVertical;
  int acessador = it;
  
  //contador para linhas
  short linhabs = m_block_size;
  
  //contador para colunas
  short colunabs = linhabs;
  
  //Saltador de linha
  int saltoDeLinha = (m_width * 4) - limiteHorizontal ;
                
  //Irá repetir o número de linhas do big pixel, por exemplo um bloco de 40px, tem 40 linhas
  while(linhabs != 0)
    {
      //Enquanto o acessador do vetor for menor que ele mesmo + o limite Horizontal
      while(acessador < it + limiteHorizontal)
	{
	  
	  //set_pixel(acessador, color);
	  // R
	  m_pixels[acessador] = color.channels[0];
                  
	  // G
	  m_pixels[acessador+1] = color.channels[1];

	  // B
	  m_pixels[acessador+2] = color.channels[2];

	  // alpha
	  m_pixels[acessador+3] = 255;

	  //Itera +4 pois a função set_pixel() modifica os 4 sucessores consecutivos de acessador
	  acessador = acessador + 4;
	}
      //O salto de linha faz com q o acessador vá precisamente para a outra linha do mesmo bloco, para continuar a pintura
      acessador = acessador + saltoDeLinha;
      it = acessador;

      linhabs = linhabs-1;
    }
  
}

/*
life::Color life::Canvas::pixel( const life::Point2& ) const
{

}


void life::Canvas::hline( const life::Point2 &p, size_t length, const life::Color& )
{
}

void life::Canvas::vline( const life::Point2 &p, size_t length, const life::Color & )
{
}


void life::Canvas::pblock(const life::Point2 &p, size_t width, size_t height, const life::Color & c)
{

}


*/
