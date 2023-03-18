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
 * @file Controls.h
 * @brief Controls class implementation
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

class Controls : public QWidget
{
public:
    explicit Controls(QVector<QString> buttons, QWidget* parent = nullptr);
    ~Controls();

    // Button accessors functions for (play, pause, speedup and reset)
    QPushButton* playBtn() const;
    QPushButton* pauseBtn() const;
    QPushButton* speedupBtn() const;
    QPushButton* resetBtn() const;

    // Connect the buttons to the slots
    // functions are overloaded to accept a lambda function, so that there is no need to pass a receiver object
    void connectToPlayBtn(QObject* receiver, const char* slot);
    void connectToPlayBtn(core::av_slot_t slot);
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
