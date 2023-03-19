/*
 * Copyright (c) 2021 M Zaki
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file SideBarLayout.cpp
 * @brief SideBarLayout class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
 */

#include "AV_SideBarLayout.h"

_BEGIN_ALGOVIZ_UI

SideBarHeader::SideBarHeader(QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
{
	setLayout(_layout);
	_layout->setContentsMargins(15, 15, 15, 15);
	_layout->setSpacing(0);
}

SideBarHeader::~SideBarHeader()
{
	delete _layout;
}

QString SideBarHeader::titleLabel() const {
	if (_layout->itemAtPosition(0, 0) == nullptr) {
		return "";
	}

	return static_cast<QLabel*>(_layout->itemAtPosition(0, 0)->widget())->text();
}

void SideBarHeader::setTitleLabel(const QString& titleLabel)
{
	_layout->addWidget(new QLabel, 0, 0, 1, 1, Qt::AlignTop);
	
	static_cast<QLabel*>(_layout->itemAtPosition(0, 0)->widget())->setText(titleLabel);
}

QString SideBarHeader::descriptionLabel() const {
	if (_layout->itemAtPosition(1, 0) == nullptr) {
		return "";
	}
	
	return static_cast<QLabel*>(_layout->itemAtPosition(1, 0)->widget())->text();
}

void SideBarHeader::setDescriptionLabel(const QString& descriptionLabel)
{	
	_layout->addWidget(new QLabel, 1, 0, 1, 1, Qt::AlignTop);
	static_cast<QLabel*>(_layout->itemAtPosition(1, 0)->widget())->setText(descriptionLabel);
}


// ----------------------------------------------


SideBarLayout::SideBarLayout(QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
{
	setLayout(_layout);
	_layout->setContentsMargins(10, 10, 10, 10);
	_layout->setSpacing(0);
}

SideBarLayout::~SideBarLayout()
{
	delete _layout;
}

SideBarHeader* SideBarLayout::sideBarHeader() const {
	return static_cast<SideBarHeader*>(_layout->itemAtPosition(0, 0)->widget());
}

void SideBarLayout::setSideBarHeader(QString title, QString description)
{
	_layout->addWidget(new SideBarHeader, 0, 0, 1, 1, Qt::AlignTop);
	
	_layout->setRowStretch(0, 1);

	_layout->itemAtPosition(0, 0)->widget()->setMinimumHeight(50);

	sideBarHeader()->setTitleLabel(title);
	sideBarHeader()->setDescriptionLabel(description);
}

void SideBarLayout::addWidget(QWidget* widget)
{
	_layout->addWidget(widget, _layout->rowCount(), 0, 1, 1, Qt::AlignTop);
	
	_layout->setRowStretch(_layout->rowCount(), 1);

	// set minimum height to be 5 times the height of the header
	_layout->itemAtPosition(_layout->rowCount() - 1, 0)->widget()->setMinimumHeight(5 * sideBarHeader()->height());
}


_END_ALGOVIZ_UI