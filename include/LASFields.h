#pragma once
// Copyright © EDF R&D / TELECOM ParisTech (ENST-TSI)
// SPDX-License-Identifier: GPL-2.0-or-later

//Local
#include "qCC_io.h"

//Qt
#include <QSharedPointer>

//System
#include <vector>

class ccScalarField;
class ccPointCloud;

static const char LAS_SCALE_X_META_DATA[] = "LAS.scale.x";
static const char LAS_SCALE_Y_META_DATA[] = "LAS.scale.y";
static const char LAS_SCALE_Z_META_DATA[] = "LAS.scale.z";

enum LAS_FIELDS {
	LAS_X = 0,
	LAS_Y = 1,
	LAS_Z = 2,
	LAS_INTENSITY = 3,
	LAS_RETURN_NUMBER = 4,
	LAS_NUMBER_OF_RETURNS = 5,
	LAS_SCAN_DIRECTION = 6,
	LAS_FLIGHT_LINE_EDGE = 7,
	LAS_CLASSIFICATION = 8,
	LAS_SCAN_ANGLE_RANK = 9,
	LAS_USER_DATA = 10,
	LAS_POINT_SOURCE_ID = 11,
	LAS_RED = 12,
	LAS_GREEN = 13,
	LAS_BLUE = 14,
	LAS_TIME = 15,
	LAS_EXTRA = 16,
	//Sub fields
	LAS_CLASSIF_VALUE = 17,
	LAS_CLASSIF_SYNTHETIC = 18,
	LAS_CLASSIF_KEYPOINT = 19,
	LAS_CLASSIF_WITHHELD = 20,
	//Invald flag
	LAS_INVALID = 255
};

const char LAS_FIELD_NAMES[][28] = {"X",
									"Y",
									"Z",
									"Intensity",
									"Return Number",
									"Number of Returns",
									"Scan Direction",
									"Flightline Edge",
									"Classification",
									"Scan Angle Rank",
									"User Data",
									"Point Source ID",
									"Red",
									"Green",
									"Blue",
									"Time",
									"extra",
									"[Classif] Value",
									"[Classif] Synthetic flag",
									"[Classif] Key-point flag",
									"[Classif] Withheld flag",
};

//! LAS field descriptor
class QCC_IO_LIB_API LasField
{
public:
	//! Shared type
	using Shared = QSharedPointer<LasField>;

public:
	LasField(LAS_FIELDS fieldType = LAS_INVALID, double defaultVal = 0, double min = 0.0, double max = -1.0);
	virtual ~LasField() = default;
	
	//! Returns official field name
	virtual inline QString getName() const { return type < LAS_INVALID ? QString(LAS_FIELD_NAMES[type]) : QString(); }

	//! Returns the (compliant) LAS fields in a point cloud
	static bool GetLASFields(ccPointCloud* cloud, std::vector<LasField>& fieldsToSave);

	LAS_FIELDS type;
	ccScalarField* sf;
	double firstValue;
	double minValue;
	double maxValue;
	double defaultValue;
};
