/*
Copyright (C) 2015  Marien Raat
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "heightmapDrawer.h"
#include "lodepng.h" // Png writing
#include <vector>

void HeightmapDrawer::drawValues(double *values, unsigned width
			       , unsigned height, const char *filename) {
    std::vector<unsigned char> image;
    image.resize(width * height * 4);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            unsigned char value = values[y * width + x] * 255;
            image[4 * width * y + 4 * x + 0] = value;
            image[4 * width * y + 4 * x + 1] = value;
            image[4 * width * y + 4 * x + 2] = value;
            image[4 * width * y + 4 * x + 3] = 255;
        }
    }
    lodepng::encode(filename, image, width, height);
}
