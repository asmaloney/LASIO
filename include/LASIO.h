#ifndef LAS_IO_HEADER
#define LAS_IO_HEADER
//##########################################################################
//#                                                                        #
//#                              LASIO                                     #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 or later of the License.      #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#                     COPYRIGHT: Andy Maloney                            #
//#                                                                        #
//##########################################################################

#include "ccIOPluginInterface.h"

class LASIO : public QObject, public ccIOPluginInterface
{
	Q_OBJECT
	Q_INTERFACES( ccPluginInterface ccIOPluginInterface )

	Q_PLUGIN_METADATA( IID "cccorp.cloudcompare.plugin.LASIO" FILE "../info.json" )

public:
	explicit LASIO( QObject *parent = nullptr );

	void registerCommands( ccCommandLineInterface *cmd ) override;

	FilterList getFilters() override;
};

#endif
