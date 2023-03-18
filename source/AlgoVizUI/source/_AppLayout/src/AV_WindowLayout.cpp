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
 * @file WindowGrid.cpp
 * @brief WindowGrid class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
*/

#include "AV_WindowLayout.h"

_BEGIN_ALGOVIZ_UI

WindowGrid& WindowGrid::init(HeaderLayout* _header, CentralLayout* _central, SideBarLayout* _leftBar, SideBarLayout* _rightBar, FooterLayout* _footer, QWidget* parent)
{
    static WindowGrid _instance(_header, _central, _leftBar, _rightBar, _footer, parent);
    return _instance;
}

WindowGrid::WindowGrid(HeaderLayout* header, CentralLayout* central, SideBarLayout* leftBar, SideBarLayout* rightBar, FooterLayout* footer, QWidget* parent) 
: _mainWindowLayout (new QGridLayout())
, QWidget(parent)
, _header(header)
, _central(central)
, _leftBar(leftBar)
, _rightBar(rightBar)
, _footer(footer)
{
    setLayout(_mainWindowLayout);
    _mainWindowLayout->setContentsMargins(0, 0, 0, 0);
    _mainWindowLayout->setSpacing(0);
    
    // if every section is defined_mainWindowLayout->addWidget(_footer, 2, 0, 1, 3);
    if(_header && _central && _leftBar && _rightBar && _footer) {
        _mainWindowLayout->addWidget(_header, 0, 0, 1, 3);
        _mainWindowLayout->addWidget(_leftBar, 1, 0, 1, 1);
        _mainWindowLayout->addWidget(_rightBar, 1, 2, 1, 1);
        _mainWindowLayout->addWidget(_central, 1, 1, 1, 1);
        
        _mainWindowLayout->setColumnStretch(0, 1);
        _mainWindowLayout->setColumnStretch(1, 4);
        _mainWindowLayout->setColumnStretch(2, 1);
        
        _mainWindowLayout->setRowStretch(0, 1);
        _mainWindowLayout->setRowStretch(1, 4);
        _mainWindowLayout->setRowStretch(2, 1);
    }

    // if no header is provided, then the window will only have 2 rows, 3 columns
    else if(_central && _leftBar && _rightBar && _footer) {
        _mainWindowLayout->addWidget(_leftBar, 0, 0, 1, 1);
        _mainWindowLayout->addWidget(_rightBar, 0, 2, 1, 1);
        _mainWindowLayout->addWidget(_central, 0, 1, 1, 1);
        _mainWindowLayout->addWidget(_footer, 1, 0, 1, 3);

        _mainWindowLayout->setColumnStretch(0, 1);
        _mainWindowLayout->setColumnStretch(1, 4);
        _mainWindowLayout->setColumnStretch(2, 1);
        
        _mainWindowLayout->setRowStretch(0, 4);
        _mainWindowLayout->setRowStretch(1, 1);
    }

    // if no header and footer is provided, then the window will only have 1 row, 3 columns
    else if(_central && _leftBar && _rightBar) {
        _mainWindowLayout->addWidget(_leftBar, 0, 0, 1, 1);
        _mainWindowLayout->addWidget(_rightBar, 0, 2, 1, 1);
        _mainWindowLayout->addWidget(_central, 0, 1, 1, 1);

        _mainWindowLayout->setColumnStretch(0, 1);
        _mainWindowLayout->setColumnStretch(1, 4);
        _mainWindowLayout->setColumnStretch(2, 1);
        
        _mainWindowLayout->setRowStretch(0, 1);
    }
    // if no header, footer and right bar is provided, then the window will only have 1 row, 2 columns
    else if(_central && _leftBar) {
        _mainWindowLayout->addWidget(_leftBar, 0, 0, 1, 1);
        _mainWindowLayout->addWidget(_central, 0, 1, 1, 1);

        _mainWindowLayout->setColumnStretch(0, 1);
        _mainWindowLayout->setColumnStretch(1, 4);        
    }
    // if no header, footer, right bar and left bar is provided, then the window will only have 1 row, 1 column
    else if(_central) {
        _mainWindowLayout->addWidget(_central, 0, 0, 1, 1);

        _mainWindowLayout->setColumnStretch(0, 1);
        
        _mainWindowLayout->setRowStretch(0, 1);
    }    
}

WindowGrid::~WindowGrid()
{
    delete _mainWindowLayout;
}

HeaderLayout* WindowGrid::header() const
{
    return _header;
}

void WindowGrid::setHeader(HeaderLayout* header)
{
    _header = header;
}

CentralLayout* WindowGrid::central() const
{
    return _central;
}

void WindowGrid::setCentral(CentralLayout* central)
{
    _central = central;
}

SideBarLayout* WindowGrid::leftBar() const
{
    return _leftBar;
}

void WindowGrid::setLeftBar(SideBarLayout* leftBar)
{
    _leftBar = leftBar;
}

SideBarLayout* WindowGrid::rightBar() const
{
    return _rightBar;
}

void WindowGrid::setRightBar(SideBarLayout* rightBar)
{
    _rightBar = rightBar;
}

FooterLayout* WindowGrid::footer() const
{
    return _footer;
}

void WindowGrid::setFooter(FooterLayout* footer)
{
    _footer = footer;
}

_END_ALGOVIZ_UI