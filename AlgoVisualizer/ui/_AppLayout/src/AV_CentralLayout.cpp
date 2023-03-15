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