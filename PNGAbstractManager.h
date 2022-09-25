#include <png.h>
#include "PNGPNG.h"

#ifndef PNGABSTRACTMANAGER_H
#define PNGABSTRACTMANAGER_H

class PNGAbstractManager {
public:
    int close(PNGPNG *png);
protected:
    FILE *mFileOpen(std::string path, char *mode);
    int mFreePng(PNGPNG *png);
};

#endif