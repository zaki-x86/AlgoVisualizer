/**
 * @file AV_StatusBar.cpp
 * @brief AV_StatusBar class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for StatusBar class, it contains the status of the running simulation.
 *      It also contains the status of the simulation output.
 */

#include "AV_StatusBar.h"

_BEGIN_ALGOVIZ_UI

StatusBar::StatusBar(QWidget* parent)
    : QStatusBar(parent)
{
    _statusMessage = "Ready";
    showMessage(_statusMessage);
}

StatusBar::~StatusBar()
{
}

_END_ALGOVIZ_UI 