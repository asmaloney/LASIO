
set( LIBLAS_INCLUDE_DIR "" CACHE PATH "libLAS include directory" )
set( LIBLAS_LIB_DIR "" CACHE PATH "libLAS library directory" )
set( LIBLAS_RELEASE_LIBRARY_FILE "" CACHE FILEPATH "libLAS library file (release mode)" )

if ( NOT LIBLAS_INCLUDE_DIR )
	message( SEND_ERROR "No libLAS include dir specified (LIBLAS_INCLUDE_DIR)" )
else()
	include_directories( ${LIBLAS_INCLUDE_DIR} )
endif()

if ( NOT LIBLAS_RELEASE_LIBRARY_FILE )
	message( SEND_ERROR "No libLAS lib specified (LIBLAS_RELEASE_LIBRARY_FILE)" )
endif()

function( target_link_liblas )
	if ( LIBLAS_RELEASE_LIBRARY_FILE )
		target_link_libraries( ${PROJECT_NAME} ${LIBLAS_RELEASE_LIBRARY_FILE} )
		target_link_libraries( ${PROJECT_NAME} ${LIBLAS_LIB_DIR}/liblas_c.a )
		target_link_libraries( ${PROJECT_NAME} ${LIBLAS_LIB_DIR}/liblaszip.a )
	endif()
endfunction()
