CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(PACKAGE_NAME openbest)
SET(MAJOR_VERSION 0)
SET(MINOR_VERSION 1)
SET(PATCH_VERSION 0)

SET(PACKAGE_VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})

SET(CMAKE_C_COMPILER gcc)

PROJECT(${PACKAGE_NAME} C)

SET(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(LIBRARY_OUTPUT_PATH ${PROJECT_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_DIR}/bin)

FIND_PACKAGE(Doxygen)

IF (DOXYGEN_FOUND)
    ADD_CUSTOM_TARGET(doc ${DOXYGEN_EXECUTABLE} ${PROJECT_DIR}/Doxyfile)
ELSE (DOXYGEN_FOUND)
    MESSAGE(Doxygen not found, doc target is not added to Makefiles)
ENDIF (DOXYGEN_FOUND)

INSTALL(DIRECTORY doc DESTINATION doc/openbest)
INSTALL(DIRECTORY dat DESTINATION dat/)

SET(DEVEL_BUILD on)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

FIND_PACKAGE(GSL REQUIRED)
MESSAGE("GSL libraries:" "${GSL_LIBRARIES}")
MESSAGE("GSL library dirs:" "${GSL_LIBRARY_DIRS}")
FIND_PACKAGE(Atlas REQUIRED)
MESSAGE("Atlas include dirs:" "${ATLAS_INCLUDE_DIR}")
MESSAGE("ATLAS: " "${ATLAS}")
MESSAGE("ATLAS_CBLAS: " "${ATLAS_CBLAS}")
MESSAGE("ATLAS_LAPACK: " "${ATLAS_LAPACK}")

SUBDIRS(src)

SET(CMAKE_VERBOSE_MAKEFILE on)
