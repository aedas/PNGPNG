/*
 * PNGReader.h
 *
 *  Created on: 16 Aug 2022
 *      Author: aedas
 */

#include <string>
#include "PNGPNG.h"
#include "PNGAbstractManager.h"
#define HEADER_SIZE 8

#ifndef PNGREADER_H_
#define PNGREADER_H_

class PNGReader : public PNGAbstractManager{
public:
	PNGReader();
	virtual ~PNGReader();
	int open(std::string path, PNGPNG *png);
private:
	int mPngCheck(FILE *fp);
	int mReadPng(FILE *fp, PNGPNG *png);
};

#endif /* PNGREADER_H_ */
