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