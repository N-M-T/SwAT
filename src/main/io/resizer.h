#ifndef RESIZE_H
#define RESIZE_H

#include "eigen-eigen-26667be4f70b/Eigen/Dense"

#include "main/ui/mainwindow.h"

using namespace Eigen;

struct newSizeData
{
    ArrayXd newX, newY;
};

struct newSizeData resizer(ArrayXd X, ArrayXd Y, int minLength, int maxLength)
{
    int newLength = maxLength - minLength;

    //new arrays
    newSizeData data;

    data.newX.resize(newLength, 1);
    data.newY.resize(newLength, 1);

    int i,j;

    for (i = 0, j = minLength; i < newLength && j < maxLength; i++, j++)
        data.newX(i) = X(j);

    int k,l;

    for (k = 0, l = minLength; k < newLength && l < maxLength; k++, l++)
        data.newY(k) = Y(l);

    return data;
}

#endif // RESIZE_H
