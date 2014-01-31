#
# Copyright (c) 2014 Nikolay Zapolnov (zapolnov@gmail.com).
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#

############################################################
## Try to determine Qt version and installation directory ##
############################################################

SET(QT_FOUND FALSE)
SET(QT_ERROR FALSE)

IF(NOT QT_INSTALL_DIRECTORY OR NOT QT_LIBS_DIRECTORY)

	FIND_PROGRAM(QMAKE_EXECUTABLE_PATH qmake HINTS ENV QTDIR DOC "Path to the qmake executable")
	IF(NOT QMAKE_EXECUTABLE_PATH)
		MESSAGE(WARNING "Executable 'qmake' was not found in path.")
		SET(QT_ERROR TRUE)
	ENDIF()


	##############################################################################################################
	## Get path to the Qt

	IF(NOT QT_ERROR AND NOT QT_INSTALL_DIRECTORY)

		EXECUTE_PROCESS(COMMAND
			"${QMAKE_EXECUTABLE_PATH}" -query QT_INSTALL_PREFIX
			RESULT_VARIABLE QMAKE_EXEC_RESULT
			OUTPUT_VARIABLE QT_INSTALL_DIRECTORY
			OUTPUT_STRIP_TRAILING_WHITESPACE
		)

		IF(NOT "${QMAKE_EXEC_RESULT}" STREQUAL "0")
			MESSAGE(WARNING "Unable to execute 'qmake -query QT_INSTALL_PREFIX': ${QMAKE_EXEC_RESULT}")
			SET(QT_ERROR TRUE)
		ENDIF()

	ENDIF()

	##############################################################################################################
	## Get path to the Qt 'libs' directory

	IF(NOT QT_ERROR AND NOT QT_LIBS_DIRECTORY)

		EXECUTE_PROCESS(COMMAND
			"${QMAKE_EXECUTABLE_PATH}" -query QT_INSTALL_LIBS
			RESULT_VARIABLE QMAKE_EXEC_RESULT
			OUTPUT_VARIABLE QT_LIBS_DIRECTORY
			OUTPUT_STRIP_TRAILING_WHITESPACE
		)

		IF(NOT "${QMAKE_EXEC_RESULT}" STREQUAL "0")
			MESSAGE(WARNING "Unable to execute 'qmake -query QT_INSTALL_LIBS': ${QMAKE_EXEC_RESULT}")
			SET(QT_ERROR TRUE)
		ENDIF()

	ENDIF()

	##############################################################################################################
	## Get Qt version

	EXECUTE_PROCESS(COMMAND
		"${QMAKE_EXECUTABLE_PATH}" -query QT_VERSION
		RESULT_VARIABLE QMAKE_EXEC_RESULT
		OUTPUT_VARIABLE QT_VERSION
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)

	IF(NOT "${QMAKE_EXEC_RESULT}" STREQUAL "0")
		MESSAGE(WARNING "Unable to execute 'qmake -query QT_VERSION': ${QMAKE_EXEC_RESULT}")
		SET(QT_ERROR TRUE)
	ENDIF()

	##############################################################################################################
	## Parse the Qt version number

	IF(NOT QT_ERROR)
		SET(QT_MAJOR 0)
		STRING(REGEX REPLACE "^([0-9]+)\\.[0-9]+\\.[0-9]+" "\\1" QT_MAJOR "${QT_VERSION}")
		IF(QT_MAJOR EQUAL 4)
			SET(IS_QT4 TRUE CACHE INTERNAL "Is Qt4" FORCE)
		ELSE(IF QT_MAJOR GREATER 4)
			SET(IS_QT4 FALSE CACHE INTERNAL "Is Qt4" FORCE)
		ELSE()
			MESSAGE(WARNING "Unable to parse Qt version string (\"${QT_VERSION}\").")
			SET(QT_ERROR TRUE)
		ENDIF()
	ENDIF()

	##############################################################################################################
	## Report that we have found a Qt library

	IF(NOT QT_ERROR)
		MESSAGE(STATUS "Found Qt ${QT_VERSION}: ${QT_INSTALL_DIRECTORY}")
		SET(QT_INSTALL_DIRECTORY "${QT_INSTALL_DIRECTORY}" CACHE PATH "Path to the Qt SDK" FORCE)
		SET(QT_LIBS_DIRECTORY "${QT_LIBS_DIRECTORY}" CACHE PATH "Path to the Qt SDK libraries" FORCE)
	ENDIF()

ENDIF()

#######################
## Search for the Qt ##
#######################

SET(QT_FOUND FALSE)
IF(NOT QT_ERROR)

	SET(CMAKE_PREFIX_PATH "${QT_INSTALL_DIRECTORY}" ${CMAKE_PREFIX_PATH})

	IF(NOT IS_QT4)
		FIND_PACKAGE(Qt5Widgets)
		IF(Qt5Widgets_FOUND)
			FIND_PACKAGE(Qt5Network REQUIRED)
			FIND_PACKAGE(Qt5Gui REQUIRED)
			FIND_PACKAGE(Qt5OpenGL REQUIRED)
			FIND_PACKAGE(Qt5Xml REQUIRED)
			FIND_PACKAGE(Qt5WebKit REQUIRED)
			FIND_PACKAGE(Qt5WebKitWidgets REQUIRED)
			SET(QT_FOUND TRUE)
			SET(QT_LIBRARIES ${Qt5Widgets_LIBRARIES} ${Qt5Network_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
				${Qt5Gui_LIBRARIES} ${Qt5Xml_LIBRARIES} ${Qt5WebKit_LIBRARIES} ${Qt5WebKitWidgets_LIBRARIES})
		ENDIF()
	ENDIF()

	IF(NOT QT_FOUND)
		FIND_PACKAGE(Qt4 4.8.1 COMPONENTS QtCore QtGui QtXml QtNetwork QtOpenGL QtWebKit)
		IF(QT4_FOUND)
			SET(QT_FOUND TRUE)
			SET(IS_QT4 TRUE CACHE INTERNAL "Is Qt4" FORCE)
		ENDIF()
	ENDIF()

	IF(NOT QT_FOUND)
		SET(QT_LIBRARIES)
	ENDIF()

ENDIF()

###############################################
## Configure build options and macros for Qt ##
###############################################

IF(QT_FOUND AND NOT QT_ERROR)
	LINK_DIRECTORIES("${QT_LIBS_DIRECTORY}")
ENDIF()

IF(QT_FOUND)
	IF(Qt5Widgets_FOUND)
		INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDES} ${Qt5Network_INCLUDES} ${Qt5Gui_INCLUDES} ${Qt5Xml_INCLUDES}
			${Qt5OpenGL_INCLUDES} ${Qt5WebKit_INCLUDES} ${Qt5WebKitWidgets_INCLUDES})
		INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS}
			${Qt5Xml_INCLUDE_DIRS} ${Qt5OpenGL_INCLUDE_DIRS} ${Qt5WebKit_INCLUDE_DIRS}
			${Qt5WebKitWidgets_INCLUDE_DIRS})
		ADD_DEFINITIONS(${Qt5Widgets_DEFINITIONS} ${Qt5Network_DEFINITIONS} ${Qt5Gui_DEFINITIONS}
			${Qt5Xml_DEFINITIONS} ${Qt5OpenGL_DEFINITIONS} ${Qt5WebKit_DEFINITIONS}
			${Qt5WebKitWidgets_DEFINITIONS})
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Gui_EXECUTABLE_COMPILE_FLAGS}")
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Network_EXECUTABLE_COMPILE_FLAGS}")
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Xml_EXECUTABLE_COMPILE_FLAGS}")
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5OpenGL_EXECUTABLE_COMPILE_FLAGS}")
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5WebKit_EXECUTABLE_COMPILE_FLAGS}")
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5WebKitWidgets_EXECUTABLE_COMPILE_FLAGS}")
		MACRO(QT_WRAP_UI var)
			QT5_WRAP_UI(${var} ${ARGN})
		ENDMACRO()
		MACRO(QT_ADD_RESOURCES var)
			QT5_ADD_RESOURCES(${var} ${ARGN})
		ENDMACRO()
	ELSE()
		INCLUDE(${QT_USE_FILE})
		MACRO(QT_WRAP_UI var)
			QT4_WRAP_UI(${var} ${ARGN})
		ENDMACRO()
		MACRO(QT_ADD_RESOURCES var)
			QT4_ADD_RESOURCES(${var} ${ARGN})
		ENDMACRO()
	ENDIF()
ENDIF()

#######################
## Search for OpenGL ##
#######################

IF(WIN32 AND Qt5OpenGL_FOUND)
	SET(OPENGL_FOUND TRUE)
	IF(${Qt5Gui_VERSION_MAJOR} GREATER 5 OR ${Qt5Gui_VERSION_MINOR} GREATER 0)
		SET(OPENGL_LIBRARIES ${Qt5Gui_EGL_LIBRARIES} ${Qt5Gui_OPENGL_LIBRARIES})
		INCLUDE_DIRECTORIES(${Qt5Gui_EGL_INCLUDE_DIRS} ${Qt5Gui_OPENGL_INCLUDE_DIRS})
	ELSE()
		GET_TARGET_PROPERTY(path Qt5::Gui IMPORTED_IMPLIB_RELEASE)
		GET_FILENAME_COMPONENT(path "${path}" PATH)
		SET(OPENGL_LIBRARIES "${path}/libEGL.lib" "${path}/libGLESv2.lib")
	ENDIF()
ELSE()
	FIND_PACKAGE(OpenGL)
	IF(OPENGL_FOUND)
		IF (OPENGL_INCLUDE_DIR)
			INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
		ENDIF()
	ELSE()
		SET(OPENGL_LIBRARIES)
	ENDIF()
ENDIF()

SET(QT_LIBRARIES ${QT_LIBRARIES} ${OPENGL_LIBRARIES})

MARK_AS_ADVANCED(QMAKE_EXECUTABLE_PATH)
MARK_AS_ADVANCED(QT_QMAKE_EXECUTABLE)
MARK_AS_ADVANCED(QT_INSTALL_DIRECTORY)
MARK_AS_ADVANCED(QT_LIBS_DIRECTORY)
MARK_AS_ADVANCED(Qt5Core_DIR)
MARK_AS_ADVANCED(Qt5Gui_DIR)
MARK_AS_ADVANCED(Qt5Xml_DIR)
MARK_AS_ADVANCED(Qt5OpenGL_DIR)
MARK_AS_ADVANCED(Qt5Positioning_DIR)
MARK_AS_ADVANCED(Qt5PrintSupport_DIR)
MARK_AS_ADVANCED(Qt5Qml_DIR)
MARK_AS_ADVANCED(Qt5Quick_DIR)
MARK_AS_ADVANCED(Qt5Sensors_DIR)
MARK_AS_ADVANCED(Qt5Network_DIR)
MARK_AS_ADVANCED(Qt5Widgets_DIR)
MARK_AS_ADVANCED(Qt5Multimedia_DIR)
MARK_AS_ADVANCED(Qt5MultimediaWidgets_DIR)
MARK_AS_ADVANCED(Qt5WebKit_DIR)
MARK_AS_ADVANCED(Qt5WebKitWidgets_DIR)
