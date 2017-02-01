Synopsis

The Sway Analysis Toolkit (SwAT). The SwAT is a simple GUI application allowing users to import and analyse postural sway data recorded with AMTI force platforms (Kistler and Bertec coming soon) in .csv format. It is built on C++ with Qt and makes use of the excellent Eigen and Biomechanical Toolkit (BTK) libraries.

Motivation

During one of my PhD investigations, I realised the software which came with our AMTI forceplatform provided only a limited analysis of postural sway data. Although there are a wealth of libraries available in Python, none come with a free and open source graphical user interface (GUI). Hence I wrote the SwAT; credits to my PhD supervisor Theo Bampouras for the abbreviation.

Installation

The SwAT can be downloaded pre-compiled for linux (Windows version available shortly) and run as a standalone application. There is no requirement for installation. Simply download the project as a .zip, extract to a desired location and run the executable found in the build folder. You may need to tick run as an exectuble under the permissions of the file. The current version has been compiled and tested on Ubuntu 16.04. Alternatively feel free to compile the source code on your own machine. To do this you will need qt5 and Eigen. 

Instructions

The GUI was designed to be simple and intuitive. File > open will prompt the user to load a .csv file containing forceplatform data. After the file is selected the sampling frequency at which the data was collected (defaults to 100 Hz) needs to be selected. The raw data will then be displayed in the data viewer. Users can adjust the length of the data (in time), remove the mean of the data by ticking the detrend box, and apply a Butterworth filter. The Butterworth filter gives the option to select order and cuttoff frequencies. Analyse > basic will provide commonly used postural sway parameters including RMS, SD, 95 % confidence ellipse area, total path and average velocity.  Finally, Plot > Plot builder will plot the data in the medial/lateral, anterior/posterior, and resultant directions. There is an option to save both the results and the plots to file.

License

The SwAT is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.