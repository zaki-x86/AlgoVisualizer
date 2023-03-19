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
 * @file WindowClient.h
 * @brief WindowClient class interface.
 * @details This class acts as an interface to the entire AlgoViz::UI library components.
 * @version 1.0
 * @date 2021-12-3
 * @author M Zaki <zaki.x86@gmail.com>
*/

#ifndef __WINDOW_CLIENT_H
#define __WINDOW_CLIENT_H

#include "AV_Config.h"
#include "AV_Utils.h"

// *** import layouts ***
#include "AV_CentralLayout.h"
#include "AV_SideBarLayout.h"
#include "AV_HeaderLayout.h"
#include "AV_WindowLayout.h"

// *** import components ***
#include "AV_MenuBar.h"
#include "AV_Controls.h"
#include "AV_AlgoMap.h"
#include "AV_SimulationPlayGround.h"
#include "AV_SimulationPlayGroundHeader.h"
#include "AV_StatusBar.h"

_BEGIN_ALGOVIZ_UI

/**
 * This class is responsible for setting up the main window layout and the components of the application. But it is not responsible for the actual implementation of the components, neither the data stored in the components.
*/
class WindowClient : public QObject
{
    Q_OBJECT

public:
    WindowClient(const WindowClient&) = delete;
    WindowClient& operator=(const WindowClient&) = delete;
    WindowClient(WindowClient&&) = delete;
    WindowClient& operator=(WindowClient&&) = delete;
    
    static WindowClient* initClient(QObject *parent = nullptr);
    void run();
    
    // *** getters ***
    MainWindow *window() const;
    SideBarLayout *rightBar() const;
    CentralLayout *central() const;
    SideBarLayout *leftBar() const;
    
    MenuBar *menuBar() const;
    Controls *controls() const;
    AlgoMap *algoMap() const;
    SimulationPlayGround *simulationPlayGround() const;
    SimulationPlayGroundHeader *simulationPlayGroundHeader() const;
    StatusBar *statusBar() const;

    // *** setters ***
    void setWindow(MainWindow *window);
    void setRightBar(SideBarLayout *rightBar);
    void setCentral(CentralLayout *central);
    void setLeftBar(SideBarLayout *leftBar);
    void setMenuBar(MenuBar *menuBar);
    void setControls(Controls *controls);
    void setAlgoMap(AlgoMap *algoMap);
    void setSimulationPlayGround(SimulationPlayGround *simulationPlayGround);
    void setSimulationPlayGroundHeader(SimulationPlayGroundHeader *simulationPlayGroundHeader);
    void setStatusBar(StatusBar *statusBar);

signals:
    void initMainWindow();
    void initLayouts();
    void initComponents();

private:
    WindowClient(QObject *parent = nullptr);
    ~WindowClient();

    void _initMainWindow();
    void _initLayouts();
    void _initComponents();
    void _connectComponents();
    
    // *** layouts ***
    MainWindow *_window;

    SideBarLayout *_rightBar;
    CentralLayout *_central;
    SideBarLayout *_leftBar;

    // *** components ***
    MenuBar *_menuBar;
    Controls *_controls;
    AlgoMap *_algoMap;
    SimulationPlayGround *_simulationPlayGround;
    SimulationPlayGroundHeader *_simulationPlayGroundHeader;
    StatusBar *_statusBar;
    
};

_END_ALGOVIZ_UI

#endif // __WINDOW_CLIENT_H