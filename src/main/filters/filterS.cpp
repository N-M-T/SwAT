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

#include "filterS.h"
#include "filter.h"
#include "external/BTK/filtfilt.h"
#include "external/BTK/iirfilterdesign.h"

filtered filtering(ArrayXd X, ArrayXd Y, int order, int cuttoff, int tempFreq)
{
    filtered filteredData;

    //create filter coefficients

    Matrix<double,Eigen::Dynamic,1> a,b;

    double C = pow(pow(2, 0.25) - 1, 0.25); //adjust for multiple passes of dataset (Winter, 2008)

    btkEigen::butter(&b, &a, order, (cuttoff/C)/(tempFreq/2));

    //use coefficients to filter timeseries

    filteredData.tempX = btkEigen::filtfilt(b, a, X);
    filteredData.tempY = btkEigen::filtfilt(b, a, Y);

    return filteredData;
}
