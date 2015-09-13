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

#pragma once

class HeightmapDrawer {
public:
    // Draw a grayscale png of the given values with white
    // representing 1.0 and black representing 0.0. The values
    // should already be normalized.
    void drawValues(double *values, unsigned width, unsigned height
		    , const char * filename);
};
