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

#include "AV_SimulationPlayGround.h"

_BEGIN_ALGOVIZ_UI

SimulationPlayGround::SimulationPlayGround(QWidget *parent) :   QWidget(parent)
, _layout(new QGridLayout(this))
, _toolbar_layout(new QGridLayout(this))
, _view(new QWidget(this))
{
    // set the layout of the widget
    setLayout(_layout);

    // set the view to the layout
    _layout->addWidget(_view, 0, 0, 1, 1);

    _layout->addLayout(_toolbar_layout, 1, 0, 1, 1);

    _layout->setRowStretch(0, 1);
    _layout->setRowStretch(1, 0);
    _layout->setColumnStretch(0, 1);
    _layout->setColumnStretch(1, 0);

    _toolbar_layout->setRowStretch(0, 1);
    _toolbar_layout->setRowStretch(1, 0);
    _toolbar_layout->setColumnStretch(0, 1);
    _toolbar_layout->setColumnStretch(1, 0);

    // set the hight of _view to be 5 times that of the toolbar
    _layout->setRowMinimumHeight(0, 5 * _layout->rowMinimumHeight(1));

    // set the layout of the toolbar
    _toolbar_layout->setContentsMargins(0, 0, 0, 0);
    _toolbar_layout->setSpacing(0);

    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);
}

SimulationPlayGround::~SimulationPlayGround()
{
    delete _layout;
    delete _toolbar_layout;
    delete _view;
}

void SimulationPlayGround::setView(QWidget *view)
{
    _view->setLayout(view->layout());
}

void SimulationPlayGround::setToolbar(QList<QString> buttons)
{
    for (int i = 0; i < buttons.size(); i++)
    {
        QPushButton *button = new QPushButton(buttons[i], this);
        _toolbar_layout->addWidget(button, 0, i, 1, 1);
    }
}


_END_ALGOVIZ_UI

