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
 * @file FooterLayout.cpp
 * @brief FooterLayout class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
 */

#include "AV_FooterLayout.h"

_BEGIN_ALGOVIZ_UI

FooterLayout::FooterLayout(StatusBar* statusBar, CopyRightLabel* copyright, QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
, _statusBar(statusBar)
, _copyRightLabel(copyright)
{
    setLayout(_layout);
	_layout->setContentsMargins(5, 5, 5, 5);
	_layout->setSpacing(0);
    
    _layout->addWidget(_statusBar, 0, 0, 1, 1, Qt::AlignLeft);
    _layout->addWidget(_copyRightLabel, 0, 1, 1, 1, Qt::AlignRight);

    _layout->setColumnStretch(0, 1);
    _layout->setColumnStretch(1, 1);
}

FooterLayout::~FooterLayout()
{
    delete _layout;
}

StatusBar* FooterLayout::statusBar()
{
    return _statusBar;
    
}

void FooterLayout::setStatusBar(StatusBar* statusBar)
{
    _statusBar = statusBar;
    //_layout->addWidget(_statusBar);
    //_layout->setColumnStretch(0, 1);

}

CopyRightLabel* FooterLayout::copyRightLabel()
{
    return _copyRightLabel;
}

void FooterLayout::setCopyRightLabel(CopyRightLabel* copyRightLabel)
{
    _copyRightLabel = copyRightLabel;
    //_layout->addWidget(_copyRightLabel);
    //_layout->setColumnStretch(1, 1);
    //_copyRightLabel->setAlignment(Qt::AlignRight);
}

_END_ALGOVIZ_UI