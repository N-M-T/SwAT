/***************************************************************************
**                                                                        **
**  Sway Analysis Toolkit (SwAT)                                          **
**                                                                        **
**  Copyright (C) 2016-2017 Neil Thomas                                   **
**  All rights reserved.                                                  **
**                                                                        **
**  This file is part of the SwAT.                                        **
**                                                                        **
**  The SwAT is free software: you can redistribute it and/or modify      **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Neil Thomas                                          **
**          Contact: neil.thomas@uni.cumbria.ac.uk                        **
**             Date: 10.01.17                                             **
**          Version: 1.0.0-beta                                           **
****************************************************************************/

#include "resizing.h"

#include "eigen-eigen-26667be4f70b/Eigen/Dense"

using namespace Eigen;

newData resizing(ArrayXd X, ArrayXd Y, int minLength, int maxLength)
{
    int newLength = maxLength - minLength;

    //new arrays
    newData resized;

    resized.newX.resize(newLength, 1);
    resized.newY.resize(newLength, 1);

    int i,j;

    for (i = 0, j = minLength; i < newLength && j < maxLength; i++, j++)
        resized.newX(i) = X(j);

    int k,l;

    for (k = 0, l = minLength; k < newLength && l < maxLength; k++, l++)
        resized.newY(k) = Y(l);

    return resized;
}
