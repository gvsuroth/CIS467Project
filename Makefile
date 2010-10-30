#############################################################################
# Makefile for building: CIS467Project.app/Contents/MacOS/CIS467Project
# Generated by qmake (2.01a) (Qt 4.7.0) on: Thu Oct 28 12:57:31 2010
# Project:  CIS467Project.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/local/Qt4.7/mkspecs/macx-g++ -o Makefile CIS467Project.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_SVG_LIB -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -gdwarf-2 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -gdwarf-2 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Qt4.7/mkspecs/macx-g++ -I. -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/Library/Frameworks/QtOpenGL.framework/Versions/4/Headers -I/usr/include/QtOpenGL -I/Library/Frameworks/QtSvg.framework/Versions/4/Headers -I/usr/include/QtSvg -I/usr/include -I. -Igui -Igenerator -Imodels -I/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/System/Library/Frameworks/AGL.framework/Headers -I. -I. -F/Library/Frameworks
LINK          = g++
LFLAGS        = -headerpad_max_install_names
LIBS          = $(SUBLIBS) -F/Library/Frameworks -L/Library/Frameworks -framework QtSvg -L/tmp/qt-stuff-6474/source/qt-everywhere-opensource-src-4.7.0/lib -F/tmp/qt-stuff-6474/source/qt-everywhere-opensource-src-4.7.0/lib -framework QtOpenGL -framework QtGui -framework QtCore -framework OpenGL -framework AGL 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = gui/gui.cpp \
		gui/main.cpp \
		gui/cell.cpp \
		generator/generator.cpp \
		models/maze.cpp \
		gui/graphicsview.cpp \
		algorithms/solver.cpp moc_gui.cpp \
		moc_generator.cpp \
		moc_maze.cpp \
		moc_graphicsview.cpp \
		moc_solver.cpp
OBJECTS       = gui.o \
		main.o \
		cell.o \
		generator.o \
		maze.o \
		graphicsview.o \
		solver.o \
		moc_gui.o \
		moc_generator.o \
		moc_maze.o \
		moc_graphicsview.o \
		moc_solver.o
DIST          = /usr/local/Qt4.7/mkspecs/common/unix.conf \
		/usr/local/Qt4.7/mkspecs/common/mac.conf \
		/usr/local/Qt4.7/mkspecs/common/mac-g++.conf \
		/usr/local/Qt4.7/mkspecs/qconfig.pri \
		/usr/local/Qt4.7/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Qt4.7/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.7/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.7/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.7/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.7/mkspecs/features/debug.prf \
		/usr/local/Qt4.7/mkspecs/features/default_post.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.7/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.7/mkspecs/features/qt.prf \
		/usr/local/Qt4.7/mkspecs/features/unix/opengl.prf \
		/usr/local/Qt4.7/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.7/mkspecs/features/moc.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.7/mkspecs/features/resources.prf \
		/usr/local/Qt4.7/mkspecs/features/uic.prf \
		/usr/local/Qt4.7/mkspecs/features/yacc.prf \
		/usr/local/Qt4.7/mkspecs/features/lex.prf \
		/usr/local/Qt4.7/mkspecs/features/include_source_dir.prf \
		CIS467Project.pro
QMAKE_TARGET  = CIS467Project
DESTDIR       = 
TARGET        = CIS467Project.app/Contents/MacOS/CIS467Project

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-gdwarf-2 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile CIS467Project.app/Contents/PkgInfo CIS467Project.app/Contents/Resources/empty.lproj CIS467Project.app/Contents/Info.plist $(TARGET)

$(TARGET): ui_gui.h ui_newmaze.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) CIS467Project.app/Contents/MacOS/ || $(MKDIR) CIS467Project.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: CIS467Project.pro  /usr/local/Qt4.7/mkspecs/macx-g++/qmake.conf /usr/local/Qt4.7/mkspecs/common/unix.conf \
		/usr/local/Qt4.7/mkspecs/common/mac.conf \
		/usr/local/Qt4.7/mkspecs/common/mac-g++.conf \
		/usr/local/Qt4.7/mkspecs/qconfig.pri \
		/usr/local/Qt4.7/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Qt4.7/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.7/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.7/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.7/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.7/mkspecs/features/debug.prf \
		/usr/local/Qt4.7/mkspecs/features/default_post.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.7/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.7/mkspecs/features/qt.prf \
		/usr/local/Qt4.7/mkspecs/features/unix/opengl.prf \
		/usr/local/Qt4.7/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.7/mkspecs/features/moc.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.7/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.7/mkspecs/features/resources.prf \
		/usr/local/Qt4.7/mkspecs/features/uic.prf \
		/usr/local/Qt4.7/mkspecs/features/yacc.prf \
		/usr/local/Qt4.7/mkspecs/features/lex.prf \
		/usr/local/Qt4.7/mkspecs/features/include_source_dir.prf \
		/Library/Frameworks/QtSvg.framework/QtSvg.prl \
		/Library/Frameworks/QtGui.framework/QtGui.prl \
		/Library/Frameworks/QtCore.framework/QtCore.prl \
		/Library/Frameworks/QtOpenGL.framework/QtOpenGL.prl
	$(QMAKE) -spec /usr/local/Qt4.7/mkspecs/macx-g++ -o Makefile CIS467Project.pro
/usr/local/Qt4.7/mkspecs/common/unix.conf:
/usr/local/Qt4.7/mkspecs/common/mac.conf:
/usr/local/Qt4.7/mkspecs/common/mac-g++.conf:
/usr/local/Qt4.7/mkspecs/qconfig.pri:
/usr/local/Qt4.7/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Qt4.7/mkspecs/features/qt_functions.prf:
/usr/local/Qt4.7/mkspecs/features/qt_config.prf:
/usr/local/Qt4.7/mkspecs/features/exclusive_builds.prf:
/usr/local/Qt4.7/mkspecs/features/default_pre.prf:
/usr/local/Qt4.7/mkspecs/features/mac/default_pre.prf:
/usr/local/Qt4.7/mkspecs/features/mac/dwarf2.prf:
/usr/local/Qt4.7/mkspecs/features/debug.prf:
/usr/local/Qt4.7/mkspecs/features/default_post.prf:
/usr/local/Qt4.7/mkspecs/features/mac/default_post.prf:
/usr/local/Qt4.7/mkspecs/features/mac/objective_c.prf:
/usr/local/Qt4.7/mkspecs/features/warn_on.prf:
/usr/local/Qt4.7/mkspecs/features/qt.prf:
/usr/local/Qt4.7/mkspecs/features/unix/opengl.prf:
/usr/local/Qt4.7/mkspecs/features/unix/thread.prf:
/usr/local/Qt4.7/mkspecs/features/moc.prf:
/usr/local/Qt4.7/mkspecs/features/mac/rez.prf:
/usr/local/Qt4.7/mkspecs/features/mac/sdk.prf:
/usr/local/Qt4.7/mkspecs/features/resources.prf:
/usr/local/Qt4.7/mkspecs/features/uic.prf:
/usr/local/Qt4.7/mkspecs/features/yacc.prf:
/usr/local/Qt4.7/mkspecs/features/lex.prf:
/usr/local/Qt4.7/mkspecs/features/include_source_dir.prf:
/Library/Frameworks/QtSvg.framework/QtSvg.prl:
/Library/Frameworks/QtGui.framework/QtGui.prl:
/Library/Frameworks/QtCore.framework/QtCore.prl:
/Library/Frameworks/QtOpenGL.framework/QtOpenGL.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/local/Qt4.7/mkspecs/macx-g++ -o Makefile CIS467Project.pro

CIS467Project.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) CIS467Project.app/Contents || $(MKDIR) CIS467Project.app/Contents 
	@$(DEL_FILE) CIS467Project.app/Contents/PkgInfo
	@echo "APPL????" >CIS467Project.app/Contents/PkgInfo
CIS467Project.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) CIS467Project.app/Contents/Resources || $(MKDIR) CIS467Project.app/Contents/Resources 
	@touch CIS467Project.app/Contents/Resources/empty.lproj
	
CIS467Project.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) CIS467Project.app/Contents || $(MKDIR) CIS467Project.app/Contents 
	@$(DEL_FILE) CIS467Project.app/Contents/Info.plist
	@sed -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,CIS467Project,g" -e "s,@TYPEINFO@,????,g" /usr/local/Qt4.7/mkspecs/macx-g++/Info.plist.app >CIS467Project.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/CIS467Project1.0.0 || $(MKDIR) .tmp/CIS467Project1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/CIS467Project1.0.0/ && $(COPY_FILE) --parents gui/gui.h gui/cell.h generator/generator.h models/maze.h gui/graphicsview.h algorithms/solver.h .tmp/CIS467Project1.0.0/ && $(COPY_FILE) --parents gui/gui.cpp gui/main.cpp gui/cell.cpp generator/generator.cpp models/maze.cpp gui/graphicsview.cpp algorithms/solver.cpp .tmp/CIS467Project1.0.0/ && $(COPY_FILE) --parents gui/gui.ui gui/newmaze.ui .tmp/CIS467Project1.0.0/ && (cd `dirname .tmp/CIS467Project1.0.0` && $(TAR) CIS467Project1.0.0.tar CIS467Project1.0.0 && $(COMPRESS) CIS467Project1.0.0.tar) && $(MOVE) `dirname .tmp/CIS467Project1.0.0`/CIS467Project1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/CIS467Project1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r CIS467Project.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_gui.cpp moc_generator.cpp moc_maze.cpp moc_graphicsview.cpp moc_solver.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_gui.cpp moc_generator.cpp moc_maze.cpp moc_graphicsview.cpp moc_solver.cpp
moc_gui.cpp: models/maze.h \
		generator/generator.h \
		algorithms/solver.h \
		gui/graphicsview.h \
		gui/gui.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ gui/gui.h -o moc_gui.cpp

moc_generator.cpp: models/maze.h \
		generator/generator.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ generator/generator.h -o moc_generator.cpp

moc_maze.cpp: models/maze.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ models/maze.h -o moc_maze.cpp

moc_graphicsview.cpp: gui/graphicsview.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ gui/graphicsview.h -o moc_graphicsview.cpp

moc_solver.cpp: models/maze.h \
		algorithms/solver.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ algorithms/solver.h -o moc_solver.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all: ui_gui.h ui_newmaze.h
compiler_uic_clean:
	-$(DEL_FILE) ui_gui.h ui_newmaze.h
ui_gui.h: gui/gui.ui
	/Developer/Tools/Qt/uic gui/gui.ui -o ui_gui.h

ui_newmaze.h: gui/newmaze.ui
	/Developer/Tools/Qt/uic gui/newmaze.ui -o ui_newmaze.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

gui.o: gui/gui.cpp gui/gui.h \
		models/maze.h \
		generator/generator.h \
		algorithms/solver.h \
		gui/graphicsview.h \
		ui_gui.h \
		ui_newmaze.h \
		gui/cell.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gui.o gui/gui.cpp

main.o: gui/main.cpp gui/gui.h \
		models/maze.h \
		generator/generator.h \
		algorithms/solver.h \
		gui/graphicsview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o gui/main.cpp

cell.o: gui/cell.cpp gui/cell.h \
		models/maze.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cell.o gui/cell.cpp

generator.o: generator/generator.cpp generator/generator.h \
		models/maze.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o generator.o generator/generator.cpp

maze.o: models/maze.cpp models/maze.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o maze.o models/maze.cpp

graphicsview.o: gui/graphicsview.cpp gui/graphicsview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o graphicsview.o gui/graphicsview.cpp

solver.o: algorithms/solver.cpp algorithms/solver.h \
		models/maze.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o solver.o algorithms/solver.cpp

moc_gui.o: moc_gui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gui.o moc_gui.cpp

moc_generator.o: moc_generator.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_generator.o moc_generator.cpp

moc_maze.o: moc_maze.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_maze.o moc_maze.cpp

moc_graphicsview.o: moc_graphicsview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_graphicsview.o moc_graphicsview.cpp

moc_solver.o: moc_solver.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_solver.o moc_solver.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

