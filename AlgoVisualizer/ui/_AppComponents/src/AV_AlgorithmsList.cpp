/**
 * @file AV_AlgorithmList.cpp
 * @brief Implementation of AV_AlgorithmList class
 * @author Zaki M <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-02-13
 * @note This file is part of AlgoVisualizer project
*/

#include "AV_AlgorithmsList.h"

_BEGIN_ALGOVIZ_UI

AlgorithmsList::AlgorithmsList(utils::OneToVectorMap<QString, QString> algorithms, QWidget* parent)
    : QWidget(parent)
    , _algorithmsMap(algorithms)
{
    _layout = new QVBoxLayout(this);
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);

    for (auto& category : algorithms.keys())
    {
        auto categoryBox = new QGroupBox(category, this);
        auto categoryLayout = new QVBoxLayout(categoryBox);
        categoryLayout->setContentsMargins(0, 0, 0, 0);
        categoryLayout->setSpacing(0);

        for (auto& algorithm : algorithms[category])
        {
            auto algorithmButton = new QRadioButton(algorithm, categoryBox);
            categoryLayout->addWidget(algorithmButton);
        }

        _layout->addWidget(categoryBox);
    }
}

AlgorithmsList::~AlgorithmsList()
{
    delete _layout;
}

void AlgorithmsList::addAlgorithm(const QString& category, const QString& algorithm)
{
    if (!_algorithmsMap.contains(category))
    {
        _algorithmsMap[category] = QVector<QString>();
    }

    _algorithmsMap[category].push_back(algorithm);
}

QString AlgorithmsList::getSelectedAlgorithm() const
{
    for (auto& category : _algorithmsMap.keys())
    {
        for (auto& algorithm : _algorithmsMap[category])
        {
            auto algorithmButton = findChild<QRadioButton*>(algorithm);
            if (algorithmButton->isChecked())
            {
                return algorithm;
            }
        }
    }

    return QString();
}

utils::OneToVectorMap<QString, QString> AlgorithmsList::getAlgorithmsMap() const
{
    return _algorithmsMap;
}

_END_ALGOVIZ_UI