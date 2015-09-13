/*
A simple implementation of the diamond-square algorithm in 2D
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

#pragma once

#include <random>

struct PassSettings {
    double *map; // Map to run the pass on
    double displacementModifier; // Displacement from drand() is multiplied
                                 // by this value. Given by 2 ^ (- (h * pass))
    int passSize; // Length of the sides of the square
    int mapSize; // Size of each side of the map
};

class DiamondSquare {
public:
    DiamondSquare();
    std::random_device *randomD;
    std::mt19937 *mt;
    std::normal_distribution<double> *dist;

    double* generateMap
    (int size, // Size of the square, should be a power of 2 plus 1
     double h, // The displacement will be decreased by 2 ^ (- h) each pass
               // A high h-value will result in a smooth map and a low h-value
               // will result in a rough map
     double *map, // The array of doubles to fill, should be allocated
                  // and filled with zeroes, for example with `calloc`
     int startPassSize // The pass size to start with, usefull for
                       // doing the first few passes manually
     ); // Returns a pointer to an array of the length size * size
    void passDiamondSquare(PassSettings *settings);
    void diamond(int x, int y, PassSettings *settings);
    void square(int x, int y, PassSettings *settings);
    bool isValid(int x, int y, int size);
    double drand(); // Returns a double between -1 and 1

    void normalizeValues(double *values, int size);
};
