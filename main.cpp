 /*
A simple implementation of the diamond-square algorithm in 2D

Copyright (C) 2015 Marien Raat
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

#include "diamondsquare.h"
#include "heightmapDrawer.h"
#include <iostream>

int main(int argc, char **argv) {
    int size = 1025;
    double *map = (double*) calloc(size * size, sizeof(double));
    DiamondSquare ds;
    ds.generateMap(size, 0.5, map, size);
    ds.normalizeValues(map, size * size);
    // Print the values
    for (int y = 0; y < size; y++) {
	for (int x = 0; x < size; x++) {
	    std::cout << map[x + y * size] << "\n";
	}
    }
    // Save values to png file
    HeightmapDrawer heightmapDrawer;
    const char *filename = "heightmap.png";
    heightmapDrawer.drawValues(map, size, size, filename);
    return 0;
}
