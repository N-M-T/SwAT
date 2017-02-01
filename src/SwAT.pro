greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TEMPLATE = app
TARGET = SwAT

INCLUDEPATH += \
	$$PWD/main \
	$$PWD/main/ \
	$$PWD/main/analysis \
	$$PWD/main/filters \
	$$PWD/main/io \
	$$PWD/main/plotting \
	$$PWD/main/ui \
	$$PWD/external/BTK \
	$$PWD/external/qcustomplot \
	$$PWD/external/qxtSlider

HEADERS += \
	main/ui/mainwindow.h \
	main/ui/resultswindow.h \
	main/ui/ui_mainwindow.h \
	main/ui/ui_resultswindow.h \
	main/plotting/plotting.h \
	main/filters/filterS.h \
	main/io/resizing.h \
	main/io/parser.h \
	main/analysis/basicanalysis.h \
	external/BTK/comb.h \
	external/BTK/filter.h \
	external/BTK/filtfilt.h \
	external/BTK/gammaln.h \
	external/BTK/iirfilterdesign.h \
	external/qcustomplot/qcustomplot.h \
	external/qxtSlider/qxtglobal.h \
	external/qxtSlider/qxtnamespace.h \
	external/qxtSlider/qxtspanslider.h \
	external/qxtSlider/qxtspanslider_p.h

SOURCES += \
	main/main.cpp \
	main/ui/mainwindow.cpp \
	main/ui/resultswindow.cpp \
	main/plotting/plotting.cpp \
	main/filters/filterS.cpp \
	main/io/resizing.cpp \
	main/io/parser.cpp \
	main/analysis/basicanalysis.cpp \
	external/qcustomplot/qcustomplot.cpp \
	external/qxtSlider/qxtglobal.cpp \
	external/qxtSlider/qxtspanslider.cpp \

FORMS += \
	main/ui/mainwindow.ui \
	main/ui/resultswindow.ui \
	main/ui/plotting.ui
