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
#include <QSpinBox>

#include <QIcon>

_BEGIN_ALGOVIZ_UI

class Controls : public QWidget
{
    Q_OBJECT
public:
    explicit Controls(QWidget* parent = nullptr);
    ~Controls();

    // Button accessors functions for (play, pause, speedup and reset)
    QPushButton* play() const;
    QPushButton* pause() const;
    QSpinBox* speed() const;
    QPushButton* reset() const;

signals:
    void initialized();

public slots:
    /**
     * @brief create a control button
    */
    QPushButton* createButton(QString name, QString icon);

private:
    QGridLayout* _layout;
};

_END_ALGOVIZ_UI

#endif // __AV_SIMULATION_CONTROLS_H
