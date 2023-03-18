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
 * @file AV_Controls.cpp
 * @brief AV_Controls class implementation
 * @author M Zaki <zaki.x86@gmail.com
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for Controls class, it contains the controls of the simulation.
*/

#include "AV_Controls.h"

_BEGIN_ALGOVIZ_UI

Controls::Controls(QList<QString> buttons, QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
, _buttons(buttons)
{
    setLayout(_layout);
    _layout->setSpacing(0);
    _layout->setContentsMargins(20, 20, 20, 20);
    _layout->setAlignment(Qt::AlignTop);

    if (_validate_buttons())
    {
        // Add the buttons to the layout
        for (int i = 0; i < _buttons.size(); i++)
        {
            QPushButton* button = new QPushButton(_buttons[i]);
            _layout->addWidget(button, i, 0);
        }
    }
}

Controls::~Controls()
{
    delete _layout;
    
    // delete buttons
    for (int i = 0; i < _layout->count(); i++)
    {
        delete _layout->itemAt(i)->widget();
    }
}

QPushButton* Controls::playBtn() const
{
    return (QPushButton*)_layout->itemAtPosition(0, 0)->widget();
}


QPushButton* Controls::pauseBtn() const
{
    return (QPushButton*)_layout->itemAtPosition(1, 0)->widget();
}


QPushButton* Controls::speedupBtn() const
{
    return (QPushButton*)_layout->itemAtPosition(2, 0)->widget();
}

QPushButton* Controls::resetBtn() const
{
    return (QPushButton*)_layout->itemAtPosition(3, 0)->widget();
}

void Controls::connectToPlayBtn(QObject* receiver, const char* slot)
{
    connect(playBtn(), SIGNAL(clicked()), receiver, slot);
}

void Controls::connectToPlayBtn(core::av_slot_t slot)
{
    QObject::connect(playBtn(), &QPushButton::clicked, slot);
}

_END_ALGOVIZ_UI