#ifndef DATA_H

#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void pre_asembler(const char* inputFilename, const char* outputFilename);
void copyFile(const char* inputFilename, const char* outputFilename);
void removeEmptyLines(const char* fileName);
void removeComments(const char* fileName);
void removeMcroLines(const char* filename);
#endif
