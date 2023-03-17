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

AlgorithmsList::~AlgorithmsList()
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

void AlgorithmsList::addAlgorithm(const QString& category, const QString& algorithm)
{
    
}

QRadioButton* AlgorithmsList::getSelectedAlgorithm() const
{
    return (QRadioButton*)_group->checkedButton();
}

utils::OneToVectorMap<QString, QString> AlgorithmsList::getAlgorithmsMap() const
{
    return _algorithmsMap;
}

_END_ALGOVIZ_UI