#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
using std::vector;
#include <stdexcept>
#include <iostream>
#include <algorithm>

#include "../include/canvas/commonCanvas.h"

namespace life {

    //! Provides methods for drawing on an image.
    /*!
     * This is a drawing area on which we shall draw a Life representation.
     *
     * Here some information on the canvas properties:
     *
     * 1. The drawing area has the origin set to the bottom left corner, with
     * positive `X` axis going to the right and positive `Y` axis going to
     * the top of the canvas.
     * 2. A pixel on the canvas has a square shape based on the pixel size
     * set when the canvas is instantiated.
     * 3. Because of 2, we have the `virtual` dimension (set by the client), 
     * and the `real` dimension, which is w * pixel_size by h * pixel_size.
     *
     * This class returns to the client an image (object) representation of the maze,
     * which might be recorded by the client as a PNG image file.
     */
    class Canvas
    {
        public:
            //=== Alias
            typedef unsigned char component_t; //!< Type of a color channel.
            static constexpr int image_depth=4; //!< Default value is RGBA (4 channels).

        public:

            //=== Special members
            /// Constructor
            /*! Creates an empty canvas of the requested size.
             * @param w The canvas width in pixels.
             * @param h The canvas height in pixels.
             */
            Canvas( size_t w=0, size_t h=0, short bs=4 )
                : m_width{w*bs}, m_height{h*bs}, m_block_size{ bs }
            {
                // Remember to adjust the virtual size to real dimensions.
                m_pixels.resize( m_width * m_height * image_depth );
            }

            /// Destructor.
            virtual ~Canvas( void )
            {
                // Do nothing, RAII (resource acquisition is resource initialization) approach
            }

            //=== Special members
            /// Copy constructor.
            Canvas( const Canvas & );
            /// Assignment operator.
            Canvas & operator=( const Canvas & );
            /// Move constructor.
            Canvas( Canvas && clone );
            /// Move assignment operator.
            Canvas & operator=( Canvas && );

            //=== Members
            /// Clear the canvas with black color.
            void clear( const life::Color& color );
	    
            ///////////////////////////////////////////////
            /// Set the color of a big pixel on the canvas.
            void pixel( const life::Point2& p, const life::Color& color);

            /// Get the pixel color from the canvas.
            Color pixel( const Point2& ) const;

            //=== Attribute accessors members.
            /// Get the canvas width.
            size_t width( void ) const
            { return m_width; }
            /// Get the canvas height.
            size_t height( void ) const
            { return m_height; }
            /// Get the canvas pixels, as an array of `unsigned char`.
            const component_t* pixels( void ) const
            { return m_pixels.data(); }

            /// Draw a horizontal line with `length` pixels on the canvas, starting at a `p` location.
            /*
             * Example:
             *
             * ```
             * (p.x, p.y), length = 15.
             *  |
             *  v
             *  . . . . . . . . . . . . . . .
             *  ```
             */
            void hline( const Point2 &p, size_t length, const Color& );
            /// Draw a vertical line with `length` pixels on the canvas, starting at a `p` location.
            /*
             * Example:
             *
             * ```
             * (p.x, p.y), length = 6.
             *  |
             *  v
             *  .
             *  .
             *  .
             *  .
             *  .
             *  .
             *  ```
             */
            void vline( const Point2 &p, size_t length, const Color & );

            /////////////////////////////////////////
            /// Desenha o bloco de pixels da mesma cor
            void pblock(const life::Point2 &p, size_t width, size_t height, const life::Color & c)
            {

            }

        private:
            size_t m_width;    //!< The image width in pixel units.
            size_t m_height;   //!< The image height in pixel units.
            short m_block_size; //!< Cell size in pixels
            vector< component_t > m_pixels; //!< The pixels, stored as 3 RGB components.
    };
} // namespace

#endif // CANVAS_H
