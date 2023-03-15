/**
 * @file StatusBar.h
 * @brief StatusBar class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This file is part of AlgoVisualizer project
*/

#ifndef __AV_STATUS_BAR_H
#define __AV_STATUS_BAR_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QWidget>
#include <QGridLayout>
#include <QStatusBar>


_BEGIN_ALGOVIZ_UI

class StatusBar : public QStatusBar
{
public:
    explicit StatusBar(QWidget* parent = nullptr);
    ~StatusBar();
    
private:
    QGridLayout* _layout;
};

_END_ALGOVIZ_UI

#endif // __AV_STATUS_BAR_H