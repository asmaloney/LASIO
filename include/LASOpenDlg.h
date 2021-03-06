#pragma once
// Copyright © EDF R&D / TELECOM ParisTech (ENST-TSI)
// SPDX-License-Identifier: GPL-2.0-or-later

//Local
#include "LASFields.h"

//GUIs generated by Qt Designer
#include <ui_openLASFileDlg.h>

//system
#include <cstring>
#include <vector>

//CCCoreLib
#include <CCGeom.h>

//! Dialog to choose the LAS fields to load
class LASOpenDlg : public QDialog, public Ui::OpenLASFileDialog
{
	Q_OBJECT
	
public:
	explicit LASOpenDlg(QWidget* parent = nullptr);
	
	//! Sets available dimensions
	void setDimensions(const std::vector<std::string>& dimensions);
	
	//! Whether to load a given field
	bool doLoad(LAS_FIELDS field) const;
	
	//! Clears the 'extra bytes' record
	void clearEVLRs();
	
	//! Sets the information about the file
	void setInfo(const QString& filename,
				 unsigned pointCount,
				 const CCVector3d& bbMin,
				 const CCVector3d& bbMax);
	
	//! Adds an 'extra bytes' record entry
	void addEVLR(const QString& description);
	
	//! Returns whether an EVLR is selected for laoding or not
	bool doLoadEVLR(size_t index) const;
	
	//! Auto-skip mode (to use the same parameters for ALL files afterwards)
	inline bool autoSkipMode() const { return m_autoSkip; }
	
	//! Whether 8-bit RGB mode is forced or not
	bool forced8bitRgbMode() const;
	
	//! Resets the "apply all" flag (if set)
	void resetApplyAll();
	
protected:
	void onApplyAll();
	void onBrowse();
	
	bool m_autoSkip;
};
