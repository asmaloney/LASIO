cmake_minimum_required( VERSION 3.0 )

option( INSTALL_LAS_IO_PLUGIN "Check to install LASIO plugin" OFF )

if ( INSTALL_LAS_IO_PLUGIN )
	project( LASIO )

	include_directories( src )
	
	add_subdirectory( src )
	add_subdirectory( ui )
	
	include( cmake/libLASSupport.cmake )
	
	include( ../../CMakePluginTpl.cmake )
	
	target_link_liblas()
endif()
