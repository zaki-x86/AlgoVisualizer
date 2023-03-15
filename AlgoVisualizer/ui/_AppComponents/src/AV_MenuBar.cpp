/**
 * @file AV_MenuBar.cpp
 * @brief AV_MenuBar class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for MenuBar class, it contains the menu bar of the application.
 */

#include "AV_MenuBar.h"

_BEGIN_ALGOVIZ_UI

MenuBar::MenuBar(utils::QStringOneToVectorMap menus, QWidget* parent)
: QWidget(parent)
, _menuBar(new QMenuBar())
, _menus(menus)
{
    setLayout(new QGridLayout());
    layout()->setSpacing(0);
    layout()->setContentsMargins(0, 0, 0, 0);
    layout()->setAlignment(Qt::AlignTop);
    layout()->addWidget(_menuBar);

    for (auto menu : _menus.keys())
    {
        QMenu* menuBarMenu = new QMenu(menu);
        _menuBar->addMenu(menuBarMenu);

        for (auto action : _menus[menu])
        {
            QAction* menuBarAction = new QAction(action);
            menuBarMenu->addAction(menuBarAction);
        }
    }
}

MenuBar::~MenuBar()
{
    delete _menuBar;
    
}

_END_ALGOVIZ_UI