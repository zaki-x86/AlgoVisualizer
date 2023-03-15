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

SimulationControls::SimulationControls(QList<QString> buttons, QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
, _buttons(buttons)
{
    setLayout(_layout);
    _layout->setSpacing(0);
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setAlignment(Qt::AlignTop);

    for (int i = 0; i < _buttons.size(); i++)
    {
        QPushButton* button = new QPushButton(_buttons[i]);
        _layout->addWidget(button, i, 0);
    }
}

SimulationControls::~SimulationControls()
{
}

_END_ALGOVIZ_UI