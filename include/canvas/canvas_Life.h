#ifndef CANVAS_LIFE
#define CANVAS_LIFE

#include "../include/canvas/commonCanvas.h"
#include "../include/canvas/canvas.h"
#include "../include/canvas/lodepng.h"
#include "../lifeConfig.h"

/// encode Canvas to png
void encode_png(std::string filename, const unsigned char * image, unsigned width, unsigned height);

// prototipo criar imagens
void create_image(life::Canvas& image, size_t width, size_t height, life::LifeConfig& vida, std::string filename, life::Color bkgcolor, life::Color alivecolor);

#endif
