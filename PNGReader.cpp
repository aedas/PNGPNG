/*
 * PNGReader.cpp
 *
 *  Created on: 16 Aug 2022
 *      Author: aedas
 */


#include "PNGReader.h"
#include <png.h>
#include <iostream>

PNGReader::PNGReader() {
	// TODO Auto-generated constructor stub

}

PNGReader::~PNGReader() {
	// TODO Auto-generated destructor stub
}

int PNGReader::open(std::string path, PNGPNG *png) {
	FILE *fp = this->mFileOpen(path, "rb");
	if (!fp) {
		return 1;
	}
	return this->mPngCheck(fp)||this->mReadPng(fp, png);
}


int PNGReader::mPngCheck(FILE *fp) {
	unsigned char header[HEADER_SIZE];
	fread(header, 1, HEADER_SIZE, fp);
	bool is_png = !png_sig_cmp(header, 0, HEADER_SIZE);
	if (!is_png) {
		return 1;
	}
	return 0;
}

int PNGReader::mReadPng(FILE *fp, PNGPNG *png) {
	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		return 1;
	}
	png_infop info_ptr= png_create_info_struct(png_ptr);
	if (!info_ptr) {
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return 1;
	}
	png_init_io(png_ptr, fp);
	png_set_sig_bytes(png_ptr, HEADER_SIZE);
	png_read_info(png_ptr, info_ptr);
	png->width = png_get_image_width(png_ptr, info_ptr);
	png->height = png_get_image_height(png_ptr, info_ptr);
	png->color_type = png_get_color_type(png_ptr, info_ptr);
	png->bit_depth = png_get_bit_depth(png_ptr, info_ptr);

	png->data = (png_bytepp) malloc(sizeof(png_bytep) * png->height);
	for (int i = 0; i < png->height; i++) {
		png->data[i] = (png_bytep) malloc(png_get_rowbytes(png_ptr, info_ptr));
	}
	png_read_image(png_ptr, png->data);
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(fp);
	return 0;
}
