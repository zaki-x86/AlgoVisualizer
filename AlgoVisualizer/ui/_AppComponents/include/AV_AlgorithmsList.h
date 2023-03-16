/**
 * @file AlgorithmsList.h
 * @brief Algorithms list
 * @author Zaki M <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2021-04-01
 * @note This file is part of AlgoVisualizer project
*/

#ifndef __AV_ALGORITHMS_LIST_H
#define __AV_ALGORITHMS_LIST_H

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

class AlgorithmsList : public QWidget
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
    explicit AlgorithmsList(utils::OneToVectorMap<QString, QString> algorithms, QWidget* parent = nullptr);
    ~AlgorithmsList();

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
    utils::OneToVectorMap<QString, QString> getAlgorithmsMap() const;

private:
    // Set a layout for AlgorithmsList
    QGridLayout* _layout;

    // Group all buttons to prevent multiple selection
    QButtonGroup* _group;

    // Map of algorithms
    utils::OneToVectorMap<QString, QString> _algorithmsMap;
    
    
};

_END_ALGOVIZ_UI

#endif // __AV_ALGORITHMS_LIST_H