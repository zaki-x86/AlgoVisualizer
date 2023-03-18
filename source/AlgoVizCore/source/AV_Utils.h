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

#ifndef __APP_UTILS_H
#define __APP_UTILS_H

#include <functional>

#include <QWidget>
#include <QMap>
#include <QVector>
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringConverter>
#include <QtDebug>
#include <QPushButton>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include <QTimer>
#include <QThread>
#include <QList>

#include "AV_Config.h"

_BEGIN_ALGOVIZ_CORE


// =================================
// =========== Utility Types =======
// =================================

/**
 * @brief A map of algorithms type, used by the AlgoMap class
 */
template<typename _T1, typename _T2>
using OneToVectorMap = QMap<_T1, QVector<_T2>>;

using QStringOneToVectorMap = OneToVectorMap<QString, QString>;

using StringVector = QVector<QString>;

template<typename _QElement>
using QElementList = QList<_QElement *>;

/**
 * @brief a function type that accepts lambdas function with no arguments and no return value
 *
 * @note used by the buttons to connect a sepcific function to a button
 */
using av_slot_t = std::function<void()>;


// =================================
// =========== Utility Functions ===
// =================================

/**
 * @brief Read a stylesheet from a file
 *
 * @param _fileName The name of the stylesheet file
 *
 * @return QString The stylesheet content
 *
 * @note stylesheet file must be located in the ui/_AppResources/stylesheets directory
 */
QString
readStyleSheet(QString _fileName);

/**
 * @brief Load a stylesheet from a file, and apply it to a qt widget
 *
 * @param _obj The qt widget to apply the stylesheet to
 * @param _filePath The path to the stylesheet file
 *
 * @note stylesheet file must be located in the ui/_AppResources/stylesheets directory
 */
void
loadStyleSheet(QWidget *_obj, QString _filePath);

/**
 * @brief set the value of a button
 */
void
setButtonValue(QPushButton *button, QString _data);

/**
 * @brief set highlight stylesheet of a button
 * 
 * Accepts a stylesheet string to be applied to the button
 */
void
highlightButton(QPushButton *button, QString stylesheet );

/**
 * @brief set highlight stylesheet of a button
*/
void
highlightButton(QPushButton *button, QFile _stylesheetFile );

void
unhighlightButton(QPushButton *button, QString stylesheet);

void
unhighlightButton(QPushButton *button, QFile _stylesheetFile);

void
delay(unsigned int _SleepDuration_ms);

_END_ALGOVIZ_CORE

#endif