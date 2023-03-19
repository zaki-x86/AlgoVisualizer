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

#include "AlgoVizStore.h"

_BEGIN_ALGOVIZ_MODEL

AlgoVizStore* AlgoVizStore::initStore()
{
    static AlgoVizStore* store = new AlgoVizStore();
    return store;
}

QJsonObject AlgoVizStore::AppDataModel()
{
    return _getComponentData("AppData.json");
}

QJsonObject AlgoVizStore::MenuBarModel()
{
    return _getComponentData("ComponentReference/MenuBar.json");
}

QJsonObject AlgoVizStore::RightBarHeaderModel()
{
    return _getComponentData("ComponentReference/RightBarHeader.json");
}

QJsonObject AlgoVizStore::LeftBarHeaderModel()
{
    return _getComponentData("ComponentReference/LeftBarHeader.json");
}

 QJsonObject AlgoVizStore::ControlsModel() {
        return _getComponentData("ComponentReference/Controls.json");
 }

QJsonObject AlgoVizStore::AlgoMapModel()
{
    return _getComponentData("ComponentReference/AlgoMap.json");
}

QJsonObject AlgoVizStore::MainWindowModel()
{
    return _getComponentData("ComponentReference/MainWindow.json");
}

QJsonObject AlgoVizStore::StatusBarModel()
{
    return _getComponentData("ComponentReference/StatusBar.json");
}

QJsonObject AlgoVizStore::SimulationPlayGroundModel()
{
    return _getComponentData("ComponentReference/SimulationPlayGround.json");
}

QJsonObject AlgoVizStore::SimulationPlayGroundHeaderModel() {
    return _getComponentData("ComponentReference/SimulationPlayGroundHeader.json");
}

void AlgoVizStore::run()
{
    // TODO: Implement this
}

_END_ALGOVIZ_MODEL