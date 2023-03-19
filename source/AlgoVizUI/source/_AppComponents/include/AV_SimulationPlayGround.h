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

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QTime>
#include <QTextEdit>
#include <QThread>    
#include <QRadioButton>
#include <QDebug>

//#include "AV_SortingView.h"

#define MIN 0
#define MAX 100

_BEGIN_ALGOVIZ_UI

enum class SimState { RUNNING = 0, PAUSE = 1, IDLE=2 };

/**
 * @brief The SimulationPlayGround class is responsible for managing the layout organization of the simulation view and the toolbar buttons associated with it
*/
class SimulationPlayGround : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationPlayGround(QWidget* parent = nullptr);
    ~SimulationPlayGround();

    QWidget* view() const;


public slots:
    void setView(QWidget* view);
    void setToolbar(QList<QString> buttons);

 private:
    QGridLayout* _layout;
    QGridLayout* _toolbar_layout;
    core::QElementList<QPushButton*> _toolbar;
    QWidget* _view;
};

_END_ALGOVIZ_UI

#endif // __AV_SIMULATION_PLAYGROUND_H