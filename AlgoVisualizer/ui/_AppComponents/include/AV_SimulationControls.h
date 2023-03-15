/**
 * @file SimulationControls.h
 * @brief SimulationControls class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This class is for simulation controls button, such as: play, pause, stop, speedup and reset. This should be plugged in the right bar in the right section of the window grid.
*/

#ifndef __AV_SIMULATION_CONTROLS_H
#define __AV_SIMULATION_CONTROLS_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QList>

_BEGIN_ALGOVIZ_UI

class SimulationControls : public QWidget
{
public:
    explicit SimulationControls(QList<QString> buttons, QWidget* parent = nullptr);
    ~SimulationControls();


private:
    QGridLayout* _layout;
    QList<QString> _buttons;
};

_END_ALGOVIZ_UI

#endif // __AV_SIMULATION_CONTROLS_H
