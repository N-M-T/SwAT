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

#include "basicanalysis.h"

#include "eigen-eigen-26667be4f70b/Eigen/Dense"

using namespace Eigen;

analysed results(ArrayXd newX, ArrayXd newY, int newLength, int tempFreq)
{
    analysed analysedData;

    //total path calculations

    //first calculate discrete difference along axis of X and Y arrays

    ArrayXd diffX;
    ArrayXd diffY;

    diffX.resize(newLength-1,1);
    diffY.resize(newLength-1,1);

    int m;

    for (m = 0; m < newLength-1; m++)
        diffX(m) = newX(m+1) - newX(m);

    int n;

    for (n = 0; n < newLength-1; n++)
        diffY(n) = newY(n+1) - newY(n);

    //then calculate the sum of the square root of the 2 diff
    //time series after they have been squared for the resultant path

    analysedData.tp = ((diffX.square()+diffY.square()).sqrt()).sum();

    //calculate average velocity

    analysedData.avgVel = analysedData.tp / (newLength / tempFreq);

    //calculate resultant trajectory

    //ArrayXd resultant = (X.square() + Y.square()).square();

    double pi = M_PI;

    //calculations for 95% confidence ellipse area
    //calculate average of X and Y

    double xMean = newX.mean();
    double yMean = newY.mean();

    //calculate standard deviation of X and Y

    analysedData.sdX = sqrt((newX - xMean).square().abs().mean());
    analysedData.sdY = sqrt((newY - yMean).square().abs().mean());

    //calculate covariance of X and Y

    double cov = ((newX - xMean) * (newY - yMean)).sum() / newLength;

    //area of 95% confidence ellipse

    analysedData.ce = 2 * pi * 3.00 * sqrt(pow(analysedData.sdX, 2) * pow(analysedData.sdY, 2) - pow(cov, 2));

    //calculate root mean square of X and Y

    analysedData.rmsX = sqrt((pow(newX,2).mean()));
    analysedData.rmsY = sqrt((pow(newY,2).mean()));

    return analysedData;
}
