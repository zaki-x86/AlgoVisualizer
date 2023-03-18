/**
 * @file AlgoMap.h
 * @brief Algorithms list
 * @author Zaki M <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2021-04-01
 * @note This file is part of AlgoVisualizer project
*/

#ifndef __AV_ALGORITHMS_LIST_H
#define __AV_ALGORITHMS_LIST_H
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

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QString>

#include "AV_Config.h"
#include "AV_Utils.h" 

#include <QButtonGroup>
#include <QGridLayout>
#include <QLabel>
#include <QRadioButton>
#include <QString>
#include <QMap>
#include <QVector>

_BEGIN_ALGOVIZ_UI

class AlgoMap : public QWidget
{
public:
    /**
     * @brief Construct a new Algorithms List object
     * 
     * @param algorithms Map of algorithms
     * @param parent Parent widget
     * 
     * @note The map of algorithms is a map of categories and a vector of algorithms
    */
    explicit AlgoMap(core::OneToVectorMap<QString, QString> algorithms, QWidget* parent = nullptr);
    ~AlgoMap();

    /**
     * @brief Add an algorithm to the list
     * 
     * The function checks if the category exists, if not, it creates a new category
     * and adds the algorithm to it.
     * 
     * @param category Category of the algorithm
     * @param algorithm Name of the algorithm
    */
    void addAlgorithm(const QString& category, const QString& algorithm);

    /**
     * @brief Get the selected algorithm
     * 
     * @return QRadioButton* the selected algorithm button
    */
    QRadioButton* getSelectedAlgorithm() const;

    /**
     * @brief Get a map of algorithms
    */
    core::OneToVectorMap<QString, QString> getAlgorithmsMap() const;

private:
    // Set a layout for AlgoMap
    QGridLayout* _layout;

    // Group all buttons to prevent multiple selection
    QButtonGroup* _group;

    // Map of algorithms
    core::OneToVectorMap<QString, QString> _algorithmsMap;
    
    
};

_END_ALGOVIZ_UI

#endif // __AV_ALGORITHMS_LIST_H