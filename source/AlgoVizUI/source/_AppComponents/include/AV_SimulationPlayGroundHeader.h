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
 * @file SimulationPlayGroundHeader.h
 * @brief SimulationPlayGroundHeader class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for SimulationPlayGround class, it contains the title and description of the simulation.
 *       This should be plugged in the top section of the central section grid. 
*/

#ifndef __AV_SIMULATION_PLAYGROUND_HEADER_H
#define __AV_SIMULATION_PLAYGROUND_HEADER_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QFont>
#include <QColor>
#include <QLayoutItem>

_BEGIN_ALGOVIZ_UI

class SimulationPlayGroundHeader : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationPlayGroundHeader(QWidget* parent = nullptr);
    ~SimulationPlayGroundHeader();

    QString title() const ;
    QString description() const;

public slots:
    void setTitle(QString title);
    void setDescription(QString description);

signals:
    void initialized();
    void titleChanged(QString title);
    void descriptionChanged(QString description);
private:
    QGridLayout* _layout;
};

_END_ALGOVIZ_UI

#endif // __AV_SIMULATION_PLAYGROUND_HEADER_H
