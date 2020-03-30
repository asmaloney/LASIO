
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
	
	# Boost
	set( Boost_USE_STATIC_LIBS ON )
	set( Boost_USE_MULTITHREADED ON )
	set( Boost_USE_STATIC_RUNTIME OFF )
	
	# libLAS requires Boost >= 1.38 according to docs
	# this list comes from the CMake file for LibLAS
	find_package(Boost 1.38 COMPONENTS
		program_options
		thread system
		iostreams
		filesystem
		REQUIRED )
	
	if( Boost_FOUND )
		target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )
	endif()
endfunction()
