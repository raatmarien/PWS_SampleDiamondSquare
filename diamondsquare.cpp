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
#include "diamondsquare.h"
#include <math.h>
#include <iostream>

DiamondSquare::DiamondSquare() {
    randomD = new std::random_device;
    mt = new std::mt19937((*randomD)());
    dist = new std::normal_distribution<double>(-0.0, 1.0);

}

double* DiamondSquare::generateMap(int size, double h, double *map, int passSize) {
    PassSettings settings;
    settings.map = map;
    settings.displacementModifier = 1.0;
    settings.passSize = passSize;
    settings.mapSize = size;
    while (settings.passSize > 1) {
        // std::cout << settings.passSize << "\n";
        passDiamondSquare(&settings);
        settings.passSize /= 2;
        settings.displacementModifier *= pow(2.0, -1.0 * h);
    }
    return map;
}

void DiamondSquare::passDiamondSquare(PassSettings *settings) {
    // Pass diamond
    for (int x = settings->passSize / 2; x < settings->mapSize;
         x += settings->passSize) {
        for (int y = settings->passSize / 2; y < settings->mapSize;
             y += settings->passSize) {
            diamond(x, y, settings);
        }
    }
    // Pass square
    for (int x = 0; x < settings->mapSize; x += settings->passSize / 2) {
        for (int y = settings->passSize / 2; y < settings->mapSize;
             y += settings->passSize) {
            square(x, y, settings);
        }
        x += settings->passSize / 2;
        if (x < settings->mapSize) {
            for (int y = 0; y < settings->mapSize; y += settings->passSize) {
                square(x, y, settings);
            }
        }
    }
}

void DiamondSquare::diamond(int x, int y, PassSettings *settings) {
    int points = 0;
    double total = 0.0;
    int dif = settings->passSize / 2;
    // Top left
    if (isValid(x - dif, y - dif, settings->mapSize)) {
        points++;
        total += (settings->map)[(y - dif) * settings->mapSize + (x - dif)];
    }
    // Top right
    if (isValid(x + dif, y - dif, settings->mapSize)) {
        points++;
        total += (settings->map)[(y - dif) * settings->mapSize + (x + dif)];
    }
    // Bottom right
    if (isValid(x + dif, y + dif, settings->mapSize)) {
        points++;
        total += (settings->map)[(y + dif) * settings->mapSize + (x + dif)];
    }
    // Bottom left
    if (isValid(x - dif, y + dif, settings->mapSize)) {
        points++;
        total += (settings->map)[(y + dif) * settings->mapSize + (x - dif)];
    }

    total /= (double) points;
    total += drand() * settings->displacementModifier;
    (settings->map)[y * settings->mapSize + x] = total;
}

void DiamondSquare::square(int x, int y, PassSettings *settings) {
    int points = 0;
    double total = 0.0;
    int dif = settings->passSize / 2;
    // Left
    if (isValid(x - dif, y, settings->mapSize)) {
        points++;
        total += (settings->map)[(y) * settings->mapSize + (x - dif)];
    }
    // Top
    if (isValid(x, y - dif, settings->mapSize)) {
        points++;
        total += (settings->map)[(y - dif) * settings->mapSize + (x)];
    }
    // Right
    if (isValid(x + dif, y, settings->mapSize)) {
        points++;
        total += (settings->map)[(y) * settings->mapSize + (x + dif)];
    }
    // Bottom
    if (isValid(x, y + dif, settings->mapSize)) {
        points++;
        total += (settings->map)[(y + dif) * settings->mapSize + (x)];
    }

    total /= (double) points;
    total += drand() * settings->displacementModifier;
    (settings->map)[y * settings->mapSize + x] = total;
}

bool DiamondSquare::isValid(int x, int y, int size) {
    return x >= 0 && x < size && y >= 0 && y < size;
}

double DiamondSquare::drand() {
    return (*(dist))((*mt));
}

void DiamondSquare::normalizeValues(double *values, int size) {
    double max = -1.0 / 0.0, min = 1.0 / 0.0;
    for (int i = 0; i < size; i++) {
	max = std::max(values[i], max);
        min = std::min(values[i], min);
    }
    for (int i = 0; i < size; i++) {
        values[i] -= min;
        values[i] /= (max - min);
    }
}
