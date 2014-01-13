/* 
 * File:   Image.cpp
 * Author: ivpusic
 * 
 * Created on December 23, 2013, 6:00 PM
 */

#include "Image.h"
#include <string>
#include <string.h>

using namespace std;

Image::Image() {
    
}

Image::Image(char *parh) {
    FILE *fin;
    char line[256];
    int slikaX, slikaY, imax, ix, iy, i, ib;
    GLubyte *pixmap;

    if (!(fin = fopen(parh, "r"))) printf("ne mogu otvoriti datoteku!\n");
    fgets(line, 256, fin);
    if (strcmp(line, "P3\n")) printf("nije PPM format!\n");
    fgets(line, 256, fin);
    if (line[0] != '#') printf("ocekujemo komentar!\n");
    fscanf(fin, "%d%d", &slikaX, &slikaY);
    printf("dimX = %d   dimY = %d\n", slikaX, slikaY);
    fscanf(fin, "%d", &imax);
    if (imax != 255) printf("ocekujemo imax = 255!\n");

    pixmap = (GLubyte *) malloc(slikaY * slikaX * 3 * sizeof (GLubyte));

    for (iy = 0; iy < slikaY; iy++)
        for (ix = 0; ix < slikaX; ix++)
            for (i = 0; i < 3; i++) {
                fscanf(fin, "%d", &ib);
                pixmap[((slikaY - 1 - iy) * slikaX + ix) * 3 + i] = (GLubyte) ib;
            }
    fclose(fin);

    pic.dimX = slikaX;
    pic.dimY = slikaY;
    pic.pixmap = pixmap;
}

void Image::drawImage() {
    glRasterPos2i(0, 0);

    glDrawPixels(pic.dimX, pic.dimY, GL_RGB,
            GL_UNSIGNED_BYTE, pic.pixmap);
}

Image::~Image() {
}

