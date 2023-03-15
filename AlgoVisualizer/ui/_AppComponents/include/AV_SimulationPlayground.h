/**
 * @file   SimulationPlayGround.h
 * @brief  SimulationPlayGround class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date   2023-03-12
 * @note   This class is the main class for the simulation playground.
 *         It contains the simulation canvas and the simulation output.
 *         This class should be plugged in the central section of the window grid.
*/

#ifndef __AV_SIMULATION_PLAYGROUND_H
#define __AV_SIMULATION_PLAYGROUND_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QScrollArea>

_BEGIN_ALGOVIZ_UI

class SimulationPlayGround : public QWidget
{
public:
    explicit SimulationPlayGround(QWidget* parent = nullptr);
    ~SimulationPlayGround();


private:
    QGridLayout* _layout;
};

_END_ALGOVIZ_UI

#endif // __AV_SIMULATION_PLAYGROUND_H