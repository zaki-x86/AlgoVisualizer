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
 * @file AV_SortingView.cpp
 * @brief Interface of the simulation view for sotring algorithms
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
*/

#ifndef AV_SORTING_VIEW_H
#define AV_SORTING_VIEW_H

#include <vector>
#include <array>

#include "AV_Utils.h"
#include "AV_Config.h"

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpinBox>

#define DEFAULT_LENGTH 10

_BEGIN_ALGOVIZ_UI

/**
 * @brief A playground for sorting algorithms simulations
 * 
 * The sorting view consists of (10 buttons) by default that holds the data to be sorted.
 * The user can change the number of buttons using the spinbox.
 * The user can also change the data of the buttons using the reset button from left bar.
 * 
 * The layout is divided into 2 horizontal sections (2 rows by 1 cols in a grid layout); the first section is for the buttons to be sorted and the second section is for the spinbox.
 * 
*/
class SortingView : public QWidget
{
public:
    SortingView(QWidget* parent = nullptr);
    
    ~SortingView();

    /**
     * @brief Get the Buttons Count object
     * 
     * @return uint8_t 
    */
    uint8_t buttonsCount() const;
    /**
     * @brief Get the Buttons object
     * 
     * @return std::array<QPushButton*, DEFAULT_LENGTH> 
    */
    core::QElementList<QPushButton*> buttons() const;

    /**
     * @brief Add a button to the buttons list
     * 
     * @param button
     * @return QPushButton*
    */
    void addButton(QPushButton* button);

    /**
     * @brief Get the Buttons Layout object
     * 
     * @return QGridLayout* 
    */
    QHBoxLayout* buttonsLayout() const;

    /**
     * @brief Get the Buttons Count Spin Box object
     * 
     * @return QSpinBox* 
    */
    QSpinBox* buttonsCountSpinBox() const;


private:
    QGridLayout* _layout;
    QHBoxLayout* _buttonsLayout;
    uint8_t _buttonsCount;
    QSpinBox* _buttonsCountSpinBox;
    core::QElementList<QPushButton*> _buttons;

protected:    
    void _adjustViewLayout(QLayout* layout, int margin, int spacing) {
        layout->setContentsMargins(margin, margin, margin, margin);
        layout->setSpacing(spacing);
        _layout->setRowStretch(0, 5);
        _layout->setRowStretch(1, 1);

        // Set the view style sheet
        setStyleSheet("background-color: #2c2f33; color: #ffffff;");
    }

    void _adjustButtonsLayout(int margin, int spacing){
        // the buttons layout is a horizontal layout
        // so we need to set the stretch factor for each button
        _buttonsLayout->setContentsMargins(margin, margin, margin, margin);
        _buttonsLayout->setSpacing(spacing);
        for (auto& button : _buttons) {
            _buttonsLayout->addWidget(button);
        }

    }

    void _configureSpinBox(int min, int max, int step, int value, const QString& suffix, Qt::Alignment alignment) {
        _buttonsCountSpinBox->setRange(min, max);
        _buttonsCountSpinBox->setValue(value);
        _buttonsCountSpinBox->setSingleStep(step);
        _buttonsCountSpinBox->setSuffix(suffix);
        _buttonsCountSpinBox->setAlignment(alignment);
    }

    void _configureButtons() {
        for (auto& button : _buttons) {
            button->setMinimumSize(50, 50);
            button->setMaximumSize(50, 50);
            button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        }
    }
};

_END_ALGOVIZ_UI

#endif // AV_SORTING_VIEW_H