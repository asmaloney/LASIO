cmake_minimum_required( VERSION 3.0 )

option( PLUGIN_LAS_IO "Install LASIO plugin" OFF )

if ( PLUGIN_LAS_IO )
	project( LASIO )

	include_directories( src )
	
	add_subdirectory( src )
	add_subdirectory( ui )
	
	include( cmake/libLASSupport.cmake )
	
	include( ../../CMakePluginTpl.cmake )
	
	target_link_liblas()
endif()
