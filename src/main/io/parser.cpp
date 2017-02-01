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

#include "parser.h"

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#include "eigen-eigen-26667be4f70b/Eigen/Dense"

using namespace std;
using namespace Eigen;

typedef vector <double> record_t;
typedef vector <record_t> data_t;

istream& operator >> ( istream& ins, record_t& record )
  {
    record.clear();
    string line;
    getline( ins, line );
    stringstream ss(line);
    string field;

    while (getline( ss, field, ',' ))
    {
      stringstream fs( field );
      double f = 0.0;
      fs >> f;
      record.push_back( f );
    }
    return ins;
  }

istream& operator >> ( istream& ins, data_t& data )
  {
    data.clear();
    record_t record;

    while (ins >> record)
      {
        data.push_back( record );
      }
    return ins;
  }

parsed parsing(const char *c_str2)
{
    //construct empty variables

    parsed parsedData;

    int tempLength = 0;

    ArrayXXd tempData;

    //read in data from file and save in data vector

    data_t data;
    ifstream infile(c_str2);
    infile >> data;
    infile.close();

    //check if data is the correct size

    if (data[5].size() != 6)
    {
        parsedData.X.resize(0);
        parsedData.Y.resize(0);
    }
    else
    {
        //check if data read in has first row of zeros.
        //allocate to X,Y Eigen arrays as appropriate (removing the zeros)

        if (data[0][3] < 10)  //row index 2 corresponds to vertical ground reaction force,
        {                    //and must be less than 10 if accurate data was collected

            tempLength = data.size()-1; //the size of the vector (data) gives the length of the vector, whereas
            parsedData.X.resize(tempLength);   //you need to find size of one column of eigen array to find its length
            parsedData.Y.resize(tempLength);

            tempData.resize(tempLength, 6);

            int i, j;

            for (i = 0; i < tempLength; i++)
                for (j = 0; j < 6; j++)
                     tempData(i, j) = data[i+1][j]; //row index 1 corresponds to the second row (skipping the 0s) from data
        }
        else
        {
            tempLength = data.size();
            parsedData.X.resize(tempLength);
            parsedData.Y.resize(tempLength);

            tempData.resize(tempLength, 6);

            int i, j;

            for (i = 0; i < tempLength; i++)
                for (j = 0; j < 6; j++)
                     tempData(i, j) = data[i][j]; //no removal of first row this time
        }

        //parse tempData for X and Y timeseries and append them to the X and Y global variables

        int i;

        for (i = 0; i < tempLength; i++)
            parsedData.X(i) = (-0*tempData(i,0)-tempData(i,4))/tempData(i,2)*100;

        int j;

        for (j = 0; j < tempLength; j++)
            parsedData.Y(j) = (-0*tempData(j,1)+tempData(j,3))/tempData(j,2)*100;


    }

    return parsedData;
}

