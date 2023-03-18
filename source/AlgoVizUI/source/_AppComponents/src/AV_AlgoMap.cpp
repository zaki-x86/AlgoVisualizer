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
 * @file AV_AlgorithmList.cpp
 * @brief Implementation of AV_AlgorithmList class
 * @author Zaki M <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-02-13
 * @note This file is part of AlgoVisualizer project
*/

#include "AV_AlgoMap.h"

_BEGIN_ALGOVIZ_UI

AlgoMap::AlgoMap(core::OneToVectorMap<QString, QString> algorithms, QWidget* parent)
    : QWidget(parent)
    , _layout(new QGridLayout(this))
    , _group(new QButtonGroup(this))
    , _algorithmsMap(algorithms)
{
    _group->setExclusive(true);

    setLayout(_layout);
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);

    for (auto it = algorithms.begin(); it != algorithms.end(); it++)
    {
        auto category = it.key();
        auto algorithms = it.value();
    
        QLabel* categoryLabel = new QLabel(category, this);
        categoryLabel->setStyleSheet("font-weight: bold;");
        _layout->addWidget(categoryLabel, _layout->rowCount(), 0);
        // set padding for category label
        _layout->setRowMinimumHeight(_layout->rowCount(), 50);

        for (auto& algorithm : algorithms)
        {
            auto algorithmButton = new QRadioButton(algorithm, this);
            _group->addButton(algorithmButton);
            _layout->addWidget(algorithmButton, _layout->rowCount(), 0);
        }
    }
}

AlgoMap::~AlgoMap()
{
    // delete buttons
    for (auto it = _group->buttons().begin(); it != _group->buttons().end(); it++)
    {
        delete *it;
    }

    // delete labels
    for (auto it = _layout->children().begin(); it != _layout->children().end(); it++)
    {
        if (dynamic_cast<QLabel*>(*it))
        {
            delete *it;
        }
    }

    delete _layout;
    delete _group;
}

void AlgoMap::addAlgorithm(const QString& category, const QString& algorithm)
{
    
}

QRadioButton* AlgoMap::getSelectedAlgorithm() const
{
    return (QRadioButton*)_group->checkedButton();
}

core::OneToVectorMap<QString, QString> AlgoMap::getAlgorithmsMap() const
{
    return _algorithmsMap;
}

_END_ALGOVIZ_UI