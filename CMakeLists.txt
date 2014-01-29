
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

INCLUDE(qt/qt.cmake)
INCLUDE(files.cmake)

ADD_LIBRARY(gl_wrappers STATIC ${gl_wrappers_files})

IF(QT_FOUND)
	ADD_LIBRARY(qt_gl ${qt_gl_wrappers_files})
	TARGET_LINK_LIBRARIES(qt_gl ${QT_LIBRARIES})
ENDIF()
