# #####################################################################
# Automatically generated by qmake (2.01a) Thu Sep 30 14:21:47 2010
# #####################################################################
QT += svg \
	opengl
TEMPLATE = app
TARGET =
DEPENDPATH += . \
	gui \
	generator \
	models
INCLUDEPATH += . \
	gui \
	generator \
	models

# Input
HEADERS += gui/gui.h \
	gui/cell.h \
	generator/generator.h \
	models/maze.h \
	gui/graphicsview.h \
    algorithms/solver.h
FORMS += gui/gui.ui \
	gui/newmaze.ui
SOURCES += gui/gui.cpp \
	gui/main.cpp \
	gui/cell.cpp \
	generator/generator.cpp \
	models/maze.cpp \
	gui/graphicsview.cpp \
    algorithms/solver.cpp
