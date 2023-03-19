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

Controls::Controls(QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
{
    setLayout(_layout);
    _layout->setSpacing(0);
    _layout->setContentsMargins(20, 20, 20, 20);
    _layout->setAlignment(Qt::AlignTop);
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


QPushButton* Controls::createButton(QString name, QString icon)
{
    QString _iconpath = QString(_APP_ICONS_PATH) + icon;
    QPushButton* button = new QPushButton(name);
    button->setObjectName(name);
    button->setFixedSize(100, 30);
    button->setIcon(QIcon(_iconpath));
    button->setIconSize(QSize(20, 20));
    button->setStyleSheet("QPushButton { background-color: #2c2c2c; color: #ffffff; border: 1px solid #ffffff; border-radius: 5px; } QPushButton:hover { background-color: #3c3c3c; } QPushButton:pressed { background-color: #1c1c1c; }");
    return button;
}

QPushButton* Controls::play() const
{
    // looks for a button in the grid layout items that has the text "Play" or "play"
    for (int i = 0; i < _layout->count(); i++)
    {
        if (static_cast<QPushButton*>(_layout->itemAt(i)->widget())->text().toLower() == "play")
        {
            return (QPushButton*)_layout->itemAt(i)->widget();
        }
    }
}


QPushButton* Controls::pause() const
{
    // looks for a button in the grid layout items that has the text "pause" or "Pause"
    for (int i = 0; i < _layout->count(); i++)
    {
        // cast he widget to a push button first before checking the text
        if (static_cast<QPushButton*>(_layout->itemAt(i)->widget())->text().toLower() == "pause")
        {
            return (QPushButton*)_layout->itemAt(i)->widget();
        }
    }
}


QSpinBox* Controls::speed() const
{
    // looks for a spinbox in the grid layout items that has the object name "speed"
    // it casts the widget to a spinbox before it extracts the text
    for (int i = 0; i < _layout->count(); i++)
    {
        if (static_cast<QPushButton*>(_layout->itemAt(i)->widget())->objectName() == "speed")
        {
            return (QSpinBox*)_layout->itemAt(i)->widget();
        }
    }
}

QPushButton* Controls::reset() const
{
    // looks for a button in the grid layout items that has the text "reset" or "Reset"
    for (int i = 0; i < _layout->count(); i++)
    {
        if (static_cast<QPushButton*>(_layout->itemAt(i)->widget())->text().toLower() == "reset")
        {
            return (QPushButton*)_layout->itemAt(i)->widget();
        }
    }
}

_END_ALGOVIZ_UI