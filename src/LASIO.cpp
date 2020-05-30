// Copyright © Andy Maloney <asmaloney@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "LASIO.h"

#include "LASFilter.h"


LASIO::LASIO( QObject* parent ) :
	QObject( parent )
  , ccIOPluginInterface( ":/CC/plugin/LASIO/info.json" )
{
}

void LASIO::registerCommands( ccCommandLineInterface *cmd )
{
	Q_UNUSED( cmd );
}

ccIOPluginInterface::FilterList LASIO::getFilters()
{
	return { FileIOFilter::Shared( new LASFilter ) };
}
