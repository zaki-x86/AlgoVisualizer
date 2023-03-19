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
 * @file AlgoVizController.h
 * @brief AlgoVizController class
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-19
 * @note This file is part of AlgoVisualizer project
 */

#ifndef __ALGOVIZ_CONTROLLER_H
#define __ALGOVIZ_CONTROLLER_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QElapsedTimer>
#include <QString>

// import AlgoViz store
#include "Store/AlgoVizStore.h"
#include "WindowClient.h"

_BEGIN_ALGOVIZ_CONTROL

/**
 * @brief AlgoVizController is a singleton class that controls the simulation and control the flow of data between the model and the UI.
 * 
 * @note This class is a singleton class, so it can only be instantiated once.
*/
class AlgoVizController : public QObject
{
    Q_OBJECT    

public:
    static AlgoVizController* initController(model::AlgoVizStore*, ui::WindowClient*, QObject* parent = nullptr);

    void run();

public slots:
    void onInitMainWindow();
    void onInitLayouts();
    void onInitComponents();
    
private:
    AlgoVizController(model::AlgoVizStore* store, ui::WindowClient* view, QObject *parent = nullptr);
    ~AlgoVizController();

    // AlgoVizController is a singleton class, so it can only be instantiated once.
    AlgoVizController(const AlgoVizController&) = delete;
    AlgoVizController& operator=(const AlgoVizController&) = delete;

    // AlgoVizController is a singleton class, so it can only be instantiated once.
    AlgoVizController(AlgoVizController&&) = delete;
    AlgoVizController& operator=(AlgoVizController&&) = delete;
    
    model::AlgoVizStore* _store;
    ui::WindowClient* _view;
};

_END_ALGOVIZ_CONTROL

#endif // __ALGOVIZ_CONTROLLER_H



