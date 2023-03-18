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