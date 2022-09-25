#include <png.h>
#include <string>
#include <optional>

#ifndef PNGPNG_H
#define PNGPNG_H

class PNGPNG {
    public:
        png_bytepp data;
        int width, height, color_type, bit_depth;
        PNGPNG();
        ~PNGPNG();
        int clear();
        bool contains_data();
        PNGPNG copy();
        int get_bytes_per_pixel();
    private:
};

#endif