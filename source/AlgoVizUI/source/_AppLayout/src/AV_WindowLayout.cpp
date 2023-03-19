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
 * @file MainWindow.cpp
 * @brief MainWindow class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
 */

#include "AV_WindowLayout.h"

_BEGIN_ALGOVIZ_UI


MainWindow::MainWindow(QWidget *parent) 
: _mainWindowLayout(new QGridLayout()), QWidget(parent)
{
	setLayout(_mainWindowLayout);
	_mainWindowLayout->setContentsMargins(5, 5, 5, 5);
	_mainWindowLayout->setSpacing(0);

	emit initialized();
}

MainWindow::~MainWindow()
{
	delete _mainWindowLayout;
}

CentralLayout *
MainWindow::central() const
{
	// get the central layout from the grid layout
	return static_cast<CentralLayout *>(_mainWindowLayout->itemAtPosition(0, 1)->widget());
}

void
MainWindow::setCentral(CentralLayout *central)
{
	// set the central layout in the grid layout, remove the old one if it exists
	if (_mainWindowLayout->itemAtPosition(0, 1))
	{
		_mainWindowLayout->removeWidget(_mainWindowLayout->itemAtPosition(0, 1)->widget());
	}
	_mainWindowLayout->addWidget(central, 0, 1, 1, 1);

	_adjustCentralLayout();
}

SideBarLayout *
MainWindow::leftBar() const
{
	return static_cast<SideBarLayout *>(_mainWindowLayout->itemAtPosition(0, 0)->widget());
}

void
MainWindow::setLeftBar(SideBarLayout *leftBar)
{
	// set the left sidebar layout in the grid layout, remove the old one if it exists
	if (_mainWindowLayout->itemAtPosition(0, 0))
	{
		_mainWindowLayout->removeWidget(_mainWindowLayout->itemAtPosition(0, 0)->widget());
	}
	_mainWindowLayout->addWidget(leftBar, 0, 0, 1, 1);
	_adjustSideBarsLayout();
}

SideBarLayout *
MainWindow::rightBar() const
{
	return static_cast<SideBarLayout *>(_mainWindowLayout->itemAtPosition(0, 2)->widget());
}

void
MainWindow::setRightBar(SideBarLayout *rightBar)
{
	// set the right sidebar layout in the grid layout, remove the old one if it exists
	if (_mainWindowLayout->itemAtPosition(0, 2))
	{
		_mainWindowLayout->removeWidget(_mainWindowLayout->itemAtPosition(0, 2)->widget());
	}
	_mainWindowLayout->addWidget(rightBar, 0, 2, 1, 1);
	_adjustSideBarsLayout();
}



_END_ALGOVIZ_UI