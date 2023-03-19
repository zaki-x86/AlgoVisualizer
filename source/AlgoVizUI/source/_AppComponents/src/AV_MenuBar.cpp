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
 * @file AV_MenuBar.cpp
 * @brief AV_MenuBar class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for MenuBar class, it contains the menu bar of the application.
 */

#include "AV_MenuBar.h"

_BEGIN_ALGOVIZ_UI

MenuBar::MenuBar(QWidget* parent)
: QWidget(parent)
, _menuBar(new QMenuBar())
{
    setLayout(new QGridLayout());
    layout()->setSpacing(0);
    layout()->setContentsMargins(0, 0, 0, 0);
    layout()->setAlignment(Qt::AlignTop);
    layout()->addWidget(_menuBar);
}

MenuBar::~MenuBar()
{
    delete _menuBar;
    
}

void MenuBar::addMenu(const QString& menuName, const QStringList& actions)
{
    QMenu* menu = _menuBar->addMenu(menuName);
    for (const QString& action : actions)
    {
        menu->addAction(action);
    }
}

_END_ALGOVIZ_UI