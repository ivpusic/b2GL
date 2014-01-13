#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/GL/GLF.o \
	${OBJECTDIR}/src/GL/GLI.o \
	${OBJECTDIR}/src/GL/GLRect.o \
	${OBJECTDIR}/src/GL/GLSprite.o \
	${OBJECTDIR}/src/aux/Image.o \
	${OBJECTDIR}/src/aux/Player.o \
	${OBJECTDIR}/src/b2GL/b2GLBase.o \
	${OBJECTDIR}/src/b2GL/b2GLCicle.o \
	${OBJECTDIR}/src/b2GL/b2GLDraw.o \
	${OBJECTDIR}/src/b2GL/b2GLMain.o \
	${OBJECTDIR}/src/b2GL/b2GLMouseClickCallback.o \
	${OBJECTDIR}/src/b2GL/b2GLRectangle.o \
	${OBJECTDIR}/src/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lGL -lGLU -lglut -L/home/ivpusic/libs/Box2D_v2.3.0/Box2D/Build/gmake/bin/Debug -lBox2D

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/b2gl

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/b2gl: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/b2gl ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/GL/GLF.o: src/GL/GLF.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GL
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GL/GLF.o src/GL/GLF.cpp

${OBJECTDIR}/src/GL/GLI.o: src/GL/GLI.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GL
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GL/GLI.o src/GL/GLI.cpp

${OBJECTDIR}/src/GL/GLRect.o: src/GL/GLRect.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GL
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GL/GLRect.o src/GL/GLRect.cpp

${OBJECTDIR}/src/GL/GLSprite.o: src/GL/GLSprite.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GL
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GL/GLSprite.o src/GL/GLSprite.cpp

${OBJECTDIR}/src/aux/Image.o: src/aux/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/aux
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/aux/Image.o src/aux/Image.cpp

${OBJECTDIR}/src/aux/Player.o: src/aux/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/aux
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/aux/Player.o src/aux/Player.cpp

${OBJECTDIR}/src/b2GL/b2GLBase.o: src/b2GL/b2GLBase.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/b2GL
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/b2GL/b2GLBase.o src/b2GL/b2GLBase.cpp

${OBJECTDIR}/src/b2GL/b2GLCicle.o: src/b2GL/b2GLCicle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/b2GL
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/b2GL/b2GLCicle.o src/b2GL/b2GLCicle.cpp

${OBJECTDIR}/src/b2GL/b2GLDraw.o: src/b2GL/b2GLDraw.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/b2GL
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/b2GL/b2GLDraw.o src/b2GL/b2GLDraw.cpp

${OBJECTDIR}/src/b2GL/b2GLMain.o: src/b2GL/b2GLMain.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/b2GL
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/b2GL/b2GLMain.o src/b2GL/b2GLMain.cpp

${OBJECTDIR}/src/b2GL/b2GLMouseClickCallback.o: src/b2GL/b2GLMouseClickCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/b2GL
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/b2GL/b2GLMouseClickCallback.o src/b2GL/b2GLMouseClickCallback.cpp

${OBJECTDIR}/src/b2GL/b2GLRectangle.o: src/b2GL/b2GLRectangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/b2GL
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/b2GL/b2GLRectangle.o src/b2GL/b2GLRectangle.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/ivpusic/libs/Box2D_v2.3.0/Box2D -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/b2gl

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
