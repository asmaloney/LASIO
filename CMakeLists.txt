option( PLUGIN-3rdParty_LAS_IO "Install LASIO plugin" OFF )

if ( PLUGIN-3rdParty_LAS_IO )
	project( LASIO )

    AddPlugin( NAME ${PROJECT_NAME} TYPE io )
    	
	add_subdirectory( include )
	add_subdirectory( src )
	add_subdirectory( ui )
	
	include( cmake/libLASSupport.cmake )
		
	target_link_liblas()
endif()
