#include "PNGPNG.h"
#include <iostream>

PNGPNG::PNGPNG() {
    this->data = NULL;
    this->height = -1;
    this->width = -1;
    this->color_type = -1;
    this->bit_depth = -1;
}

PNGPNG::~PNGPNG() {
}

int PNGPNG::clear() {
	for (int i = 0; i < this->height; i++) {
		free(this->data[i]);
	}
	free(this->data);
    this->data = NULL;
    this->height = -1;
    this->width = -1;
    this->color_type = -1;
    this->bit_depth = -1;
    return 0;
}

bool PNGPNG::contains_data() {
    return (this->data != NULL && this->height != -1 && this->width != -1 && this->color_type != -1 && this->bit_depth != -1);
}


PNGPNG PNGPNG::copy() {
    PNGPNG res = PNGPNG();
    res.height = height;
    res.width = width;
    res.color_type = color_type;
    std::cout << res.color_type << std::endl;
    std::cout << "f" << std::endl;
    res.bit_depth = bit_depth;
    res.data = (png_bytepp) malloc(sizeof(png_bytep) * height);
    int mul = get_bytes_per_pixel();
    for (int i = 0; i < height; i++) {
        res.data[i] = (png_bytep) malloc(mul * width);
        
        for (int j = 0; j < mul * width; j++) {
            res.data[i][j] = data[i][j];
        }
    }
    return res;
}

int PNGPNG::get_bytes_per_pixel() {
    int byte_depth = bit_depth / 8;
    int num_channels = 3;
    if (color_type == 4 || color_type == 6) {
        num_channels++;
    }
    return byte_depth * num_channels;
}