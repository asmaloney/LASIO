
set( LIBLAS_INCLUDE_DIR "" CACHE PATH "libLAS include directory" )
set( LIBLAS_LIB_DIR "" CACHE PATH "libLAS library directory" )

if ( NOT LIBLAS_INCLUDE_DIR )
	message( SEND_ERROR "No libLAS include dir specified (LIBLAS_INCLUDE_DIR)" )
else()
	include_directories( ${LIBLAS_INCLUDE_DIR} )
endif()

if ( NOT LIBLAS_LIB_DIR )
	message( SEND_ERROR "No libLAS lib directory specified (LIBLAS_LIB_DIR)" )
endif()

function( target_link_liblas )
	if ( LIBLAS_LIB_DIR )
		target_link_libraries( ${PROJECT_NAME}
			${LIBLAS_LIB_DIR}/liblas.a
			${LIBLAS_LIB_DIR}/liblas_c.a
			${LIBLAS_LIB_DIR}/liblaszip.a )
	endif()
endfunction()
