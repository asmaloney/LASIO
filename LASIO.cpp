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

#include "qLASIO.h"

#include "LASFilter.h"


LASIO::LASIO( QObject* parent ) :
	QObject( parent )
  , ccIOFilterPluginInterface( ":/CC/plugin/LASIO/info.json" )
{
}

void LASIO::registerCommands( ccCommandLineInterface *cmd )
{
}

QVector<FileIOFilter::Shared> LASIO::getFilters()
{
	return QVector<FileIOFilter::Shared>{
		FileIOFilter::Shared( new LASFilter ),
	};
}
