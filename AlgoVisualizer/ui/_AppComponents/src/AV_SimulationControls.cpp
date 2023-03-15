/**
 * @file AV_SimulationControls.cpp
 * @brief AV_SimulationControls class implementation
 * @author M Zaki <zaki.x86@gmail.com
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for SimulationControls class, it contains the controls of the simulation.
*/

#include "AV_SimulationControls.h"

_BEGIN_ALGOVIZ_UI

SimulationControls::SimulationControls(QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
, _playButton(new QPushButton())
, _pauseButton(new QPushButton())
, _stopButton(new QPushButton())
, _speedUpButton(new QPushButton())
, _resetButton(new QPushButton())
, _speedSlider(new QSlider())
{
    setLayout(_layout);
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);
    _layout->addWidget(_playButton, 0, 0, 1, 1);
    _layout->addWidget(_pauseButton, 0, 1, 1, 1);
    _layout->addWidget(_stopButton, 0, 2, 1, 1);
    _layout->addWidget(_speedUpButton, 0, 3, 1, 1);
    _layout->addWidget(_resetButton, 0, 4, 1, 1);
    _layout->addWidget(_speedSlider, 1, 0, 1, 5);
    _layout->setRowStretch(0, 1);
    _layout->setRowStretch(1, 1);
    _layout->setRowMinimumHeight(0, 0);
    _layout->setRowMinimumHeight(1, 0);
}

SimulationControls::~SimulationControls()
{
    delete _layout;
    delete _playButton;
    delete _pauseButton;
    delete _stopButton;
    delete _speedUpButton;
    delete _resetButton;
    delete _speedSlider;
}

QPushButton* SimulationControls::playButton()
{
    return _playButton;
}

QPushButton* SimulationControls::pauseButton()
{
    return _pauseButton;
}

QPushButton* SimulationControls::stopButton()
{
    return _stopButton;
}

QPushButton* SimulationControls::speedUpButton()
{
    return _speedUpButton;
}

QPushButton* SimulationControls::resetButton()
{
    return _resetButton;
}

QSlider* SimulationControls::speedSlider()
{
    return _speedSlider;
}

_END_ALGOVIZ_UI