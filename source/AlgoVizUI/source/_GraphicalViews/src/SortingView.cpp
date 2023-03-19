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
 * @file AV_SortingView.cpp
 * @brief Interface of the simulation view for sotring algorithms
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 */

#include "SortingView.h"

_BEGIN_ALGOVIZ_UI


SortingView::SortingView(QWidget* parent)
    : QWidget(parent)
    , _layout(new QGridLayout(this))
    , _buttonsLayout(new QGridLayout(this))
    , _buttonsCount(DEFAULT_LENGTH)
    , _data()
    , _buttons()
    , _buttonsCountSpinBox(new QSpinBox(this))
{
    // Set the view layout
    setLayout(_layout);

    // Configure the view layout
    _configureViewLayout(_layout, 5, 0);

    // Configure the buttons layout
    _configureButtonsLayout(_buttonsLayout, 1, 0);

    // Configure the buttons count spinbox
    _configureSpinBox(1, 100, 1, DEFAULT_LENGTH, " Buttons", Qt::AlignCenter);

    //connect(_buttonsCountSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onButtonsCountChanged(int)));
    //onButtonsCountChanged(DEFAULT_LENGTH);
    
    // add the buttons layout to the view layout
    _layout->addLayout(_buttonsLayout, 0, 0, 1, 1, Qt::AlignLeft);
    // add the buttons count spinbox to the view layout
    _layout->addWidget(_buttonsCountSpinBox, 1, 0, 1, 1, Qt::AlignCenter);

    // Configure the buttons: set text inside the buttons
    _configureButtons();

}

SortingView::~SortingView()
{
    // delete the buttons

}

_END_ALGOVIZ_UI