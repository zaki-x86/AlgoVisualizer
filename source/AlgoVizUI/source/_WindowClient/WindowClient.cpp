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

#include "WindowClient.h"

_BEGIN_ALGOVIZ_UI

WindowClient* WindowClient::initClient(QObject *parent) {
    static WindowClient* client = new WindowClient();
    return client;
}

WindowClient::WindowClient(QObject *parent)
: QObject(parent)
{}

WindowClient::~WindowClient() {
    // delete _window;
    // delete _rightBar;
    // delete _leftBar;
    // delete _central;
    // delete _menuBar;
    // delete _controls;
    // delete _algoMap;
    // delete _simulationPlayGround;
    // delete _simulationPlayGroundHeader;
    // delete _statusBar;
}

void WindowClient::_initMainWindow() {
    _window = new MainWindow();
    
    emit initMainWindow();
}

void WindowClient::_initLayouts() {
    _rightBar = new SideBarLayout();
    _leftBar  = new SideBarLayout();
    _central  = new CentralLayout();

    _window->setLeftBar(_leftBar);
    _window->setRightBar(_rightBar);
    _window->setCentral(_central);

    emit initLayouts();
}

void WindowClient::_initComponents() {
    _menuBar  = new MenuBar();
    _controls = new Controls();
    _algoMap  = new AlgoMap();
    _simulationPlayGround = new SimulationPlayGround();
    _simulationPlayGroundHeader = new SimulationPlayGroundHeader();
    _statusBar = new StatusBar();

    emit initComponents();
}

void WindowClient::_connectComponents () {
    _window->setMenuBar(_menuBar);
    _rightBar->addWidget(_controls);
    _leftBar->setAlgoMap(_algoMap);
    _central->setSimulationPlayGround(_simulationPlayGround);
    _central->setSimulationPlayGroundHeader(_simulationPlayGroundHeader);
    _window->setStatusBar(_statusBar);
}

void WindowClient::run() {
    // init the main window
    _initMainWindow();
    // init the layouts
    _initLayouts();
    // init the components
    _initComponents();
    // show the window 
    _window->show();
}

MainWindow *WindowClient::window() const {
    return _window;
}

SideBarLayout *WindowClient::rightBar() const {
    return _rightBar;
}

SideBarLayout *WindowClient::leftBar() const {
    return _leftBar;
}

CentralLayout *WindowClient::central() const {
    return _central;
}

MenuBar *WindowClient::menuBar() const {
    return _menuBar;
}

Controls *WindowClient::controls() const {
    return _controls;
}

AlgoMap *WindowClient::algoMap() const {
    return _algoMap;
}

SimulationPlayGround *WindowClient::simulationPlayGround() const {
    return _simulationPlayGround;
}

SimulationPlayGroundHeader *WindowClient::simulationPlayGroundHeader() const {
    return _simulationPlayGroundHeader;
}

StatusBar *WindowClient::statusBar() const {
    return _statusBar;
}

void WindowClient::setWindow(MainWindow *window) {
    _window = window;
}

void WindowClient::setRightBar(SideBarLayout *rightBar) {
    _rightBar = rightBar;
}

void WindowClient::setLeftBar(SideBarLayout *leftBar) {
    _leftBar = leftBar;
}

void WindowClient::setCentral(CentralLayout *central) {
    _central = central;
}

void WindowClient::setMenuBar(MenuBar *menuBar) {
    _menuBar = menuBar;
}

void WindowClient::setControls(Controls *controls) {
    _controls = controls;
}

void WindowClient::setAlgoMap(AlgoMap *algoMap) {
    _algoMap = algoMap;
}

void WindowClient::setSimulationPlayGround(SimulationPlayGround *simulationPlayGround) {
    _simulationPlayGround = simulationPlayGround;
}

void WindowClient::setSimulationPlayGroundHeader(SimulationPlayGroundHeader *simulationPlayGroundHeader) {
    _simulationPlayGroundHeader = simulationPlayGroundHeader;
}

void WindowClient::setStatusBar(StatusBar *statusBar) {
    _statusBar = statusBar;
}

_END_ALGOVIZ_UI
