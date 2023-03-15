/**
 * @file SideBarLayout.h
 * @brief Right bar widget
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This class is used to create the UI of the application
 */

#ifndef __RIGHTBAR_H
#define __RIGHTBAR_H

#include "LayoutUtils.h"

#include <QWidget>
#include <QLayout>
#include <QGridLayout>
#include <QLabel>
#include <QList>
#include <QComboBox>
#include <QPushButton>
#include <QGroupBox>
#include <QString>

#include <AV_AlgorithmsList.h>
#include <AV_SimulationControls.h>

#include "AV_Utils.h"
#include "AV_Config.h"

_BEGIN_ALGOVIZ_UI

class SideBarHeader : public QWidget
{
public:
	explicit SideBarHeader(const QString &title, const QString& desc, QWidget *parent = nullptr);

	~SideBarHeader();

	QString
	titleLabel() const;
	
    void
	setTitleLabel(const QString& titleLabel);

	QString
	descriptionLabel() const;
	
    void
	setDescriptionLabel(const QString& descriptionLabel);

private:
	QGridLayout *_layout;
	QLabel *_titleLabel;
	QLabel *_descriptionLabel;
};

class SideBarLayout : public QWidget
{
public:
	explicit SideBarLayout(SideBarHeader* header, QWidget *parent = nullptr);

	~SideBarLayout();

	SideBarHeader *
	sideBarHeader() const;

	void
	setSideBarHeader(SideBarHeader *sideBarHeader);

	// Get a list of sections within the side bar
	QList<QWidget *>
	sections() const;

	// Add a new section to the side bar
	void
	addSection(QWidget *section);

private:
	QGridLayout *_layout;
	SideBarHeader *_sideBarHeader;
	QList<QWidget *> _sections;
};

_END_ALGOVIZ_UI

#endif // __RIGHTBAR_H