#include <string>
#include "PNGPNG.h"
#include "PNGAbstractManager.h"
#define HEADER_SIZE 8

#ifndef PNGWRITER_H_
#define PNGWRITER_H_

class PNGWriter : public PNGAbstractManager{
public:
	PNGWriter();
	virtual ~PNGWriter();
    int write(std::string path, PNGPNG *png);
private:
    int mPngCheck(PNGPNG *png);
    int mWritePng(FILE *target, PNGPNG *png);

};

#endif /* PNGWRITER_H_ */