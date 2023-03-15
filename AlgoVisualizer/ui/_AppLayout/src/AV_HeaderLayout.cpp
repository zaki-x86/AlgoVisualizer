/**
 * @file AV_HeaderLayout.cpp
 * @brief HeaderLayout class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
 */

#include "AV_HeaderLayout.h"

_BEGIN_ALGOVIZ_UI

HeaderLayout::HeaderLayout(AppTitle* appTitle, AppDescription* appDesciption, MenuBar* menuBar, QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout)
, _appTitle(appTitle)
, _appDescription(appDesciption)
, _menuBar(menuBar)
{
    setLayout(_layout);
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);

    _layout->addWidget(_appTitle, 0, 0, 1, 1, Qt::AlignLeft);
    _layout->addWidget(_appDescription, 1, 0, 1, 1, Qt::AlignLeft);
    
    parent->layout()->setMenuBar(_menuBar);
}

HeaderLayout::~HeaderLayout()
{

}

AppTitle* HeaderLayout::appTitle() const {
    return _appTitle;
}

void HeaderLayout::setAppTitle(AppTitle* appTitle)
{
    _appTitle = appTitle;
}

AppDescription* HeaderLayout::appDescription() const {
    return _appDescription;
}

void HeaderLayout::setAppDescription(AppDescription* appDescription)
{
    _appDescription = appDescription;
}

MenuBar* HeaderLayout::menuBar() {
    return _menuBar;
}

void HeaderLayout::setMenuBar(MenuBar* menuBar)
{
    _menuBar = menuBar;
}


_END_ALGOVIZ_UI