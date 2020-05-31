option( PLUGIN-3rdParty_LAS_IO "Install LASIO plugin" OFF )

if ( PLUGIN-3rdParty_LAS_IO )
	project( LASIO )

	find_package( libLAS CONFIG REQUIRED )
	
    AddPlugin( NAME ${PROJECT_NAME} TYPE io )
    	
	add_subdirectory( include )
	add_subdirectory( src )
	add_subdirectory( ui )

	target_link_libraries( ${PROJECT_NAME}
		${libLAS_LIBRARIES}
	)
endif()
