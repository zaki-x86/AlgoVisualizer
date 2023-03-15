/**
 * @file AV_SimulationPlayGround.cpp
 * @brief AV_SimulationPlayGround class implementation
 * @author M Zaki <zaki.x86@gmail.com
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for SimulationPlayGround class, it contains the title and description of the simulation.
*/

#include "AV_SimulationPlayGround.h"

_BEGIN_ALGOVIZ_UI

SimulationPlayGround::SimulationPlayGround(QWidget* parent)
    : QWidget(parent)
{
    _layout = new QGridLayout(this);
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);
}

SimulationPlayGround::~SimulationPlayGround()
{
    delete _layout;
}

_END_ALGOVIZ_UI