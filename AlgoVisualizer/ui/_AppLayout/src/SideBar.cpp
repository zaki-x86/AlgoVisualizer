/**
 * @file SideBar.cpp
 * @brief SideBar class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
 */

#include "SideBar.h"

SideBar::SideBar(QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
{
    setLayout(_layout);
	_layout->setContentsMargins(0, 0, 0, 0);
	_layout->setSpacing(0);
}


SideBar::~SideBar()
{
    
}
