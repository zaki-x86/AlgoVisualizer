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

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QVector>

_BEGIN_ALGOVIZ_UI

class SimulationControls : public QWidget
{
public:
    explicit SimulationControls(QVector<QString> buttons, QWidget* parent = nullptr);
    ~SimulationControls();

    // Button accessors functions for (play, pause, speedup and reset)
    QPushButton* playBtn() const;
    QPushButton* pauseBtn() const;
    QPushButton* speedupBtn() const;
    QPushButton* resetBtn() const;

    // Connect the buttons to the slots
    // functions are overloaded to accept a lambda function, so that there is no need to pass a receiver object
    void connectToPlayBtn(QObject* receiver, const char* slot);
    void connectToPlayBtn(utils::av_slot_t slot);
    void connectToPauseBtn(QObject* receiver, const char* slot);
    void connectToSpeedupBtn(QObject* receiver, const char* slot);
    void connectToResetBtn(QObject* receiver, const char* slot);


private:
    QGridLayout* _layout;
    QVector<QString> _buttons; //{play, pause, speedup, reset}

    // Validate the buttons, they must contain (play, pause, speedup and reset)
    // TODO implementation needs to be completed
    bool _validate_buttons() { return true; }
};

_END_ALGOVIZ_UI

#endif // __AV_SIMULATION_CONTROLS_H
