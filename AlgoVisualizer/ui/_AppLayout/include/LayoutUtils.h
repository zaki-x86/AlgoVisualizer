/**
 * @file LayoutUtils.h
 * @brief LayoutUtils class definition
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This class is used to create the UI of the application
 */

#ifndef __LAYOUT_UTILS_H
#define __LAYOUT_UTILS_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

#include <string>

#include "AV_Utils.h"
#include "AV_Config.h"

_BEGIN_ALGOVIZ_UI

enum _ComponentStretch
{
    Minimum = 0,
    Standard = 1,
    Twice = 2,
    _3_Times = 3,
    _4_Times = 4,
};

_END_ALGOVIZ_UI

#endif // __LAYOUT_UTILS_H