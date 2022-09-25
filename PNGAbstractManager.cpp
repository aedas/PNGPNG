#include "PNGAbstractManager.h"

int PNGAbstractManager::close(PNGPNG *png) {
    return this->mFreePng(png);
}

FILE *PNGAbstractManager::mFileOpen(std::string path, char *mode) {
	FILE *ans = fopen(path.c_str(), mode);
	if (!ans) {
		return NULL;
	}
	return ans;
}

int PNGAbstractManager::mFreePng(PNGPNG *png) {
    png->clear();
    return 0;
}