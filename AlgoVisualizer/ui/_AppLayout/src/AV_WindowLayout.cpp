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
    
    _mainWindowLayout->addWidget(_header, 0, 0, 3, 1);
    _mainWindowLayout->addWidget(_central, 1, 1, 1, 1);
    _mainWindowLayout->addWidget(_leftBar, 1, 0, 1, 1);
    _mainWindowLayout->addWidget(_rightBar, 1, 2, 1, 1);
    _mainWindowLayout->addWidget(_footer, 2, 0, 3, 1);
    
    _mainWindowLayout->setColumnStretch(0, 1);
    _mainWindowLayout->setColumnStretch(1, 4);
    _mainWindowLayout->setColumnStretch(2, 1);
    
    _mainWindowLayout->setRowStretch(0, 1);
    _mainWindowLayout->setRowStretch(1, 4);
    _mainWindowLayout->setRowStretch(2, 1);
    
    //_mainWindowLayout->setColumnMinimumWidth(0, 0);
    //_mainWindowLayout->setColumnMinimumWidth(2, 0);
    
    //_mainWindowLayout->setRowMinimumHeight(0, 0);
    //_mainWindowLayout->setRowMinimumHeight(1, 0);
    //_mainWindowLayout->setRowMinimumHeight(2, 0);
}

WindowGrid::~WindowGrid()
{
    
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