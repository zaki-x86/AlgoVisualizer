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
 * @file AV_SimulationPlayGroundHeader.cpp
 * @brief AV_SimulationPlayGroundHeader class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for SimulationPlayGroundHeader class, it contains the title and description of the simulation.
 */

#include "AV_SimulationPlayGroundHeader.h"

_BEGIN_ALGOVIZ_UI

SimulationPlayGroundHeader::SimulationPlayGroundHeader(QWidget* parent)
    : QWidget(parent)
    , _layout(new QGridLayout(this))
{
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);
    
    QLabel* title = new QLabel(this);
    _layout->addWidget(title, 0, 0, 1, 1, Qt::AlignCenter);
    QLabel* description = new QLabel(this);
    _layout->addWidget(description, 1, 0, 1, 1, Qt::AlignLeft);

    //The description label should have a smaller font size and a lighter color. The row that contains the description label should be higher than the row that contains the title label.
    QFont font = description->font();
    font.setPointSize(8);
    description->setFont(font);
    description->setStyleSheet("QLabel { color : gray; }");
    _layout->setRowMinimumHeight(1, 50);

    //The title label should have a bigger font size and a darker color. The row that contains the title label should be higher than the row that contains the description label.
    font.setPointSize(12);
    title->setFont(font);
    title->setStyleSheet("QLabel { color : black; }");
    _layout->setRowMinimumHeight(0, 20);   

    emit initialized();
}

SimulationPlayGroundHeader::~SimulationPlayGroundHeader()
{
    // look for items in the layout and delete
    for (int i = 0; i < _layout->count(); i++)
    {
        QLayoutItem* item = _layout->itemAt(i);
        if (item->widget())
        {
            delete item->widget();
        }
    }
    delete _layout;
}

QString SimulationPlayGroundHeader::title() const
{
    return static_cast<QLabel*>(_layout->itemAtPosition(0, 0)->widget())->text();
}

QString SimulationPlayGroundHeader::description() const
{
    return static_cast<QLabel*>(_layout->itemAtPosition(1, 0)->widget())->text();
}

void SimulationPlayGroundHeader::setTitle(QString title)
{
    emit titleChanged(title);
    static_cast<QLabel*>(_layout->itemAtPosition(0, 0)->widget())->setText(title);
}

void SimulationPlayGroundHeader::setDescription(QString description)
{
    emit descriptionChanged(description);
    static_cast<QLabel*>(_layout->itemAtPosition(1, 0)->widget())->setText(description);
}

_END_ALGOVIZ_UI
