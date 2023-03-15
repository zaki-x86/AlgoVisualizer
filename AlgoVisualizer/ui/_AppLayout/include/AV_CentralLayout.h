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