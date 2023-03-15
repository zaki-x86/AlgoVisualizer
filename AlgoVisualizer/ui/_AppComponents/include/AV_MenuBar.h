/**
 * @file MenuBar.h
 * @brief MenuBar class implementation
 * @author M Zaki <
 * @version 0.1
 * @date 2023-03-12
 * @note This file is part of AlgoVisualizer project
 */

#ifndef __AV_MENU_BAR_H
#define __AV_MENU_BAR_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
#include <QKeySequence>
#include <QMessageBox>
#include <QGridLayout>

_BEGIN_ALGOVIZ_UI

class MenuBar : public QWidget
{
public:
    MenuBar(utils::QStringOneToVectorMap menus, QWidget* parent = nullptr);
    ~MenuBar();

    QMenuBar* minuBarWidget() const { return _menuBar; }

private:
    QGridLayout* _layout;
    QMenuBar* _menuBar;
    utils::QStringOneToVectorMap _menus;
};

_END_ALGOVIZ_UI

#endif // __AV_MENU_BAR_H