#pragma once
// Copyright © Andy Maloney <asmaloney@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "FileIOFilter.h"

//! ASPRS LAS point cloud file I/O filter
class LASFilter : public FileIOFilter
{
public:
	LASFilter();
	
	CC_FILE_ERROR loadFile(const QString& filename, ccHObject& container, LoadParameters& parameters) override;

	bool canSave(CC_CLASS_ENUM type, bool& multiple, bool& exclusive) const override;
	CC_FILE_ERROR saveToFile(ccHObject* entity, const QString& filename, const SaveParameters& parameters) override;
};
