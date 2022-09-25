#include "PNGWriter.h"
#include <png.h>
#include <iostream>

PNGWriter::PNGWriter() {

}

PNGWriter::~PNGWriter() {

}

int PNGWriter::write(std::string path, PNGPNG *png) {
    if (mPngCheck(png)) {
        return 1;
    }
    FILE *fp = this->mFileOpen(path, "wb");
	if (!fp) {
		return 1;
	}
    return mWritePng(fp, png);
}

int PNGWriter::mPngCheck(PNGPNG *png) {
    if (png->contains_data()) {
        return 0;
    }
    return 1;
}

int PNGWriter::mWritePng(FILE *target, PNGPNG *png) {
    std::cout << png->color_type << std::endl;
    std::cout << png->bit_depth << std::endl;
    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        return 1;
    }
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_write_struct(&png_ptr, NULL);
        return 1;
    }
    png_init_io(png_ptr, target);
    png_set_IHDR(
        png_ptr,
        info_ptr,
        png->width,
        png->height,
        png->bit_depth,
        png->color_type,       
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );
    png_write_info(png_ptr, info_ptr);
    png_write_image(png_ptr, png->data);
    png_write_end(png_ptr, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    return 0;
}
