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
    _layout->setContentsMargins(20, 20, 20, 20);
    _layout->setAlignment(Qt::AlignTop);

    if (_validate_buttons())
    {
        // Add the buttons to the layout
        for (int i = 0; i < _buttons.size(); i++)
        {
            QPushButton* button = new QPushButton(_buttons[i]);
            _layout->addWidget(button, i, 0);
        }
    }
}

SimulationControls::~SimulationControls()
{
    delete _layout;
    
    // delete buttons
    for (int i = 0; i < _layout->count(); i++)
    {
        delete _layout->itemAt(i)->widget();
    }
}

QPushButton* SimulationControls::playBtn() const
{
    return (QPushButton*)_layout->itemAtPosition(0, 0)->widget();
}


QPushButton* SimulationControls::pauseBtn() const
{
    return (QPushButton*)_layout->itemAtPosition(1, 0)->widget();
}


QPushButton* SimulationControls::speedupBtn() const
{
    return (QPushButton*)_layout->itemAtPosition(2, 0)->widget();
}

QPushButton* SimulationControls::resetBtn() const
{
    return (QPushButton*)_layout->itemAtPosition(3, 0)->widget();
}

void SimulationControls::connectToPlayBtn(QObject* receiver, const char* slot)
{
    connect(playBtn(), SIGNAL(clicked()), receiver, slot);
}

void SimulationControls::connectToPlayBtn(utils::av_slot_t slot)
{
    QObject::connect(playBtn(), &QPushButton::clicked, slot);
}

_END_ALGOVIZ_UI