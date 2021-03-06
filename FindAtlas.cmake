FIND_PATH(ATLAS_INCLUDE_DIR cblas.h  /usr/include /usr/local/include /usr/local/include/atlas)

#FIND_LIBRARY( BOOST_UNIT_TEST_LIB NAMES boost_unit_test_framework
#             PATHS /usr/lib /usr/local/lib C:\\Boost\\lib )
#FIND_LIBRARY( BOOST_PROGRAM_OPTIONS_LIB NAMES boost_program_options
#             PATHS /usr/lib /usr/local/lib C:\\Boost\\lib )
#FIND_LIBRARY( BOOST_FILESYSTEM_LIB NAMES boost_filesystem
#             PATHS /usr/lib /usr/local/lib C:\\Boost\\lib )

SET(ATLAS_LIB_SEARCH_DIRS /usr/lib/sse2 /usr/lib/atlas/sse2 /usr/local/lib/atlas)

FIND_LIBRARY( ATLAS NAMES atlas PATHS ${ATLAS_LIB_SEARCH_DIRS})
FIND_LIBRARY( ATLAS_CBLAS NAMES cblas PATHS ${ATLAS_LIB_SEARCH_DIRS})
FIND_LIBRARY( ATLAS_LAPACK NAMES lapack PATHS ${ATLAS_LIB_SEARCH_DIRS})

SET( ATLAS_INCLUDE_FILE ${ATLAS_INCLUDE_DIR}/cblas.h )

IF (ATLAS_INCLUDE_DIR)
  SET(ATLAS_FOUND ON)
ENDIF (ATLAS_INCLUDE_DIR)

IF (ATLAS_FOUND)
  IF (NOT ATLAS_FIND_QUIETLY)
     MESSAGE(STATUS "Found ATLAS: ${ATLAS_INCLUDE_DIR}")
  ENDIF (NOT ATLAS_FIND_QUIETLY)
ELSE(ATLAS_FOUND)
  IF (ATLAS_FIND_REQUIRED)
     MESSAGE(FATAL_ERROR "Could not find ATLAS")
  ENDIF (ATLAS_FIND_REQUIRED)
ENDIF (ATLAS_FOUND)
