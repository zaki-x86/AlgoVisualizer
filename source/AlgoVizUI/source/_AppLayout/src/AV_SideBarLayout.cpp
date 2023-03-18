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

SideBarHeader::SideBarHeader(const QString& title, const QString& desc, QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
, _titleLabel(new QLabel(title))
, _descriptionLabel(new QLabel(desc))
{
	setLayout(_layout);
	_layout->setContentsMargins(15, 15, 15, 15);
	_layout->setSpacing(0);

	_titleLabel->setStyleSheet("font-size: 20px; font-weight: bold;");
	_descriptionLabel->setStyleSheet("font-size: 12px;");

	_layout->addWidget(_titleLabel, 0, 0, 1, 1, Qt::AlignTop);
	_layout->addWidget(_descriptionLabel, 1, 0, 1, 1, Qt::AlignTop);
}

SideBarHeader::~SideBarHeader()
{
	delete _layout;
	delete _titleLabel;
	delete _descriptionLabel;
}

QString SideBarHeader::titleLabel() const {
	return _titleLabel->text();
}

void SideBarHeader::setTitleLabel(const QString& titleLabel)
{
	_titleLabel->setText(titleLabel);
}

QString SideBarHeader::descriptionLabel() const {
	return _descriptionLabel->text();
}

void SideBarHeader::setDescriptionLabel(const QString& descriptionLabel)
{
	_descriptionLabel->setText(descriptionLabel);
}


// ----------------------------------------------


SideBarLayout::SideBarLayout(SideBarHeader* header, QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
, _sideBarHeader(nullptr)
, _sections()
{
	setLayout(_layout);
	_layout->setContentsMargins(10, 10, 10, 10);
	_layout->setSpacing(0);

	_sections.append(header);
	_layout->addWidget(header, 0, 0, 1, 1, Qt::AlignTop);
	_layout->setRowStretch(0, 0);
}

SideBarLayout::~SideBarLayout()
{
	delete _layout;
}

SideBarHeader* SideBarLayout::sideBarHeader() const {
	return _sideBarHeader;
}

void SideBarLayout::setSideBarHeader(SideBarHeader* sideBarHeader)
{
	_sideBarHeader = sideBarHeader;
}

QList<QWidget*> SideBarLayout::sections() const {
	return _sections;
}

void SideBarLayout::addSection(QWidget* section)
{
	_sections.append(section);
	_layout->addWidget(section, _sections.size(), 0, 1, 1);
	_layout->setRowStretch(_sections.size(), 1);
}

_END_ALGOVIZ_UI