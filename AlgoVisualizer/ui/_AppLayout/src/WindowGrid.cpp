/**
 * @file WindowGrid.cpp
 * @brief WindowGrid class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
*/

#include "WindowGrid.h"

_BEGIN_ALGOVIZ_UI

WindowGrid::WindowGrid(QWidget* parent)
: QWidget(parent)
, _mainWindowtitle("AlgoVisualizer")
, _mainWindowLayout(new QGridLayout())
, _header(new Header())
, _central(new Central())
, _leftBar(new SideBar())
, _rightBar(new SideBar())
, _footer(new Footer())
{
    setWindowTitle(_mainWindowtitle);
    resize(800, 600);
    setLayout(_mainWindowLayout); 
    _mainWindowLayout->setColumnStretch(0, 1);
    _mainWindowLayout->setColumnStretch(1, 4);
    _mainWindowLayout->setColumnStretch(2, 1);
    _mainWindowLayout->setRowStretch(0, 1);
    _mainWindowLayout->setRowStretch(1, 4);
    _mainWindowLayout->setRowStretch(2, 1);
    _header->setFixedHeight(50);
    _footer->setFixedHeight(25);

    _mainWindowLayout->addWidget(_header, 0, 0, 1, 3);    
    _mainWindowLayout->addWidget(_leftBar, 1, 0, 1, 1);
    _mainWindowLayout->addWidget(_central, 1, 1, 1, 1);
    _mainWindowLayout->addWidget(_rightBar, 1, 2, 1, 1);
    _mainWindowLayout->addWidget(_footer, 2, 0, 1, 3);

    //utils::loadStyleSheet(this, "WindowGrid.qss");
    
    // for debugging 
    _header->setStyleSheet("border: 1px dashed blue;");
    _footer->setStyleSheet("border: 1px dashed blue;");
    _leftBar->setStyleSheet("border: 1px dashed blue;");
    _rightBar->setStyleSheet("border: 1px dashed blue;");
    _central->setStyleSheet("border: 1px dashed blue;");
}

WindowGrid::~WindowGrid()
{
    delete _mainWindowLayout;
    delete _header;
    delete _central;
    delete _leftBar;
    delete _rightBar;
}

Header* WindowGrid::header() const
{
    return _header;
}

void WindowGrid::setHeader(const Header& header)
{
    _header = const_cast<Header*>(&header);
}

Central* WindowGrid::central() const
{
    return _central;
}

void WindowGrid::setCentral(const Central& central)
{
    _central = const_cast<Central*>(&central);
}

SideBar* WindowGrid::leftBar() const
{
    return _leftBar;
}

void WindowGrid::setLeftBar(const SideBar& leftBar)
{
    _leftBar = const_cast<SideBar*>(&leftBar);
}

SideBar* WindowGrid::rightBar() const
{
    return _rightBar;
}

void WindowGrid::setRightBar(const SideBar& rightBar)
{
    _rightBar = const_cast<SideBar*>(&rightBar);
}

Footer* WindowGrid::footer() const
{
    return _footer;
}

void WindowGrid::setFooter(const Footer& footer)
{
    _footer = const_cast<Footer*>(&footer);
}

_END_ALGOVIZ_UI