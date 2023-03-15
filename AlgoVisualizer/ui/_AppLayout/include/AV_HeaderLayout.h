/**
 * @file HeaderLayout.h
 * @brief HeaderLayout widget
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
*/

#ifndef __HEADER_H
#define __HEADER_H

#include "LayoutUtils.h"

#include <QWidget>
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <QListWidget>
#include <QComboBox>
#include <QPushButton>
#include <QMenuBar>
#include <QWidget>
#include <QString>

#include <AV_AppTitle.h>
#include <AV_AppDescription.h>
#include <AV_MenuBar.h>

#include "AV_Utils.h"
#include "AV_Config.h"

_BEGIN_ALGOVIZ_UI

class HeaderLayout : public QWidget
{
public:
    explicit HeaderLayout(QWidget* parent = nullptr);

    explicit HeaderLayout(AppTitle* appTitle, AppDescription* appDesciption, MenuBar* menuBar, QWidget* parent = nullptr);
    
    ~HeaderLayout();

    AppTitle* appTitle() const;
    void setAppTitle(AppTitle* title);

    AppDescription* appDescription() const;
    void setAppDescription(AppDescription* description);

    MenuBar* menuBar();
    void setMenuBar(MenuBar* menuBar);

private:
    QGridLayout* _layout;
    AppTitle* _appTitle;
    AppDescription* _appDescription;
    MenuBar* _menuBar;
};

_END_ALGOVIZ_UI

#endif  // __HEADER_H