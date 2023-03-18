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
 * @file AV_CentralLayout.h
 * @brief CentralLayout widget Layout
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This file is part of AlgoVisualizer project
 */

#ifndef __CENTRAL_H
#define __CENTRAL_H

#include "AV_Config.h"
#include "LayoutUtils.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QString>

#include <AV_SimulationPlayGround.h>
#include <AV_SimulationPlayGroundHeader.h>

#include "AV_Utils.h"
#include "AV_Config.h"

_BEGIN_ALGOVIZ_UI

class CentralLayout : public QWidget
{
public:
	explicit CentralLayout(SimulationPlayGroundHeader *simulationPlayGroundHeader, SimulationPlayGround *simulationPlayGround, QWidget *parent = nullptr);
	~CentralLayout();

	SimulationPlayGround *
	simulationPlayGround() const;

	void
	setSimulationPlayGround(SimulationPlayGround *playGround);

	SimulationPlayGroundHeader *
	simulationPlayGroundHeader() const;

	void
	setSimulationPlayGroundHeader(SimulationPlayGroundHeader *playGroundHeader);

private:
	QGridLayout *_layout;
	SimulationPlayGroundHeader *_simulationPlayGroundHeader;
	SimulationPlayGround *_simulationPlayGround;
};

_END_ALGOVIZ_UI

#endif