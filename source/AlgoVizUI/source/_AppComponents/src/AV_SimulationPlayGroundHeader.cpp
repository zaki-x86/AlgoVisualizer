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
    , _titleLabel(new QLabel(this))
    , _descriptionLabel(new QLabel(this))
{
    setLayout(_layout);

    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);

    _titleLabel->setAlignment(Qt::AlignHCenter);
    _layout->addWidget(_titleLabel, 0, 0, 1, 1);

    _descriptionLabel->setAlignment(Qt::AlignCenter);
    _layout->addWidget(_descriptionLabel, 1, 0, 1, 1);
}

SimulationPlayGroundHeader::~SimulationPlayGroundHeader()
{
    delete _layout;
}

void SimulationPlayGroundHeader::setTitle(const QString& title)
{
    _titleLabel->setText(title);
}

void SimulationPlayGroundHeader::setDescription(const QString& description)
{
    _descriptionLabel->setText(description);
}

_END_ALGOVIZ_UI