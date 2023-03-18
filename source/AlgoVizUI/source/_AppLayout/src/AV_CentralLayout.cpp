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
 * @file AV_CentralLayout.cpp
 * @brief CentralLayout class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
 */

#include "AV_CentralLayout.h"

_BEGIN_ALGOVIZ_UI

CentralLayout::CentralLayout(
	SimulationPlayGroundHeader *simulationPlayGroundHeader, SimulationPlayGround *simulationPlayGround, QWidget *parent)
	: QWidget(parent), _layout(new QGridLayout), _simulationPlayGroundHeader(simulationPlayGroundHeader),
	  _simulationPlayGround(simulationPlayGround)
{
	setLayout(_layout);
	_layout->setContentsMargins(0, 0, 0, 0);
	_layout->setSpacing(0);

	_layout->addWidget(_simulationPlayGroundHeader, 0, 0, 1, 1, Qt::AlignCenter);

	_layout->addWidget(_simulationPlayGround, 1, 0, 1, 1, Qt::AlignCenter);
}

CentralLayout::~CentralLayout() {}

SimulationPlayGround *
CentralLayout::simulationPlayGround() const
{
	return _simulationPlayGround;
}

void
CentralLayout::setSimulationPlayGround(SimulationPlayGround *playGround)
{
	_simulationPlayGround = playGround;
}

SimulationPlayGroundHeader *
CentralLayout::simulationPlayGroundHeader() const
{
	return _simulationPlayGroundHeader;
}

void
CentralLayout::setSimulationPlayGroundHeader(SimulationPlayGroundHeader *playGroundHeader)
{
	_simulationPlayGroundHeader = playGroundHeader;
}

_END_ALGOVIZ_UI