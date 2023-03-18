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
 * @file AlgoVizStore.h
 * @author M Zaki <zaki.x86@gmail.com>
 * @brief AlgoVizStore class definition
 * @version 0.1
 * @date 2023-03-18
 * @note This class defines data access methods and facilities that are used by the controller to access the application data from the json files defined in `data/` directory.
 */

#ifndef __ALGOVIZSTORE_H
#define __ALGOVIZSTORE_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QStandardPaths>
#include <QString>
#include <QByteArray>
#include <QFile>

_BEGIN_ALGOVIZ_MODEL

/**
 * @brief AlgoVizStore that interfaces with data model of the application.
 *
 * All applications are stored in json files within "data/" directory of this library.
 * All component related data are stored in json files in this directory "data/ComponentsReference/".
 * 
 * data/AppData.json contains the meta data of the application such as name, description, author, github, tc.
 * data/ComponentsReference/MenuBar.json contains the data related to the menu bar of the application, such as: menu items, sub menu items, and their actions.
 * data/ComponentsReference/RightBarHeader.json contains the data related to the right bar header of the application, such as: title, description.
 * data/ComponentsReference/LeftBarHeader.json contains the data related to the left bar header of the application, such as: title, description.
 * data/ComponentsReference/Controls.json contains the data related to the control buttons of the simulation, such as: play, pause, speed, reset.
 * data/ComponentsReference/MainWindow.json contains the data related to the main window of the application, such as: title, description, geometry, and the components that are displayed in the main window.
 * data/ComponentsReference/StatusBar.json contains the data related to the status bar of the application, such as the status message displayed.
 * data/ComponentsReference/AlgoMap.json contains the data related to the algorithm map of the application, such as: the algorithm name, description, complexity, and function name.
 * data/ComponentsReference/SimulationPlayGround.json contains the data related to the simulation play ground of the application, such as: the view of the simuation and the state.
 * data/ComponentsReference/SimulationPlayGroundHeader.json contains the data related to the simulation play ground header of the application, such as: the title of the simulation play ground.
 * 
 * This class is a singleton class and can be accessed using the static method `AlgoVizStore::initModel()`.
 * The function members that access and set components data are `JsonObject <ComponentName>Model()`.
 */

class AlgoVizStore : public QObject
{
    //Q_OBJECT

public:

    // delete copy and move constructors and assign operators
    AlgoVizStore(AlgoVizStore const &) = delete;             // Copy construct
    AlgoVizStore(AlgoVizStore &&) = delete;                  // Move construct
    AlgoVizStore &operator=(AlgoVizStore const &) = delete;  // Copy assign

    /**
     * @brief Get the AlgoVizStore object
     * 
     * @return AlgoVizStore* 
     */
    static AlgoVizStore *initStore();

    /**
     * @brief Get the App Data object
     * @return QJsonObject 
     * 
     */
    QJsonObject AppDataModel();

    /**
     * @brief Get the Menu Bar Data object
     * 
     * @return QJsonObject 
     */
    QJsonObject MenuBarModel();

    /**
     * @brief Get the Right Bar Header Data object
     * 
     * @return QJsonObject 
     */
    QJsonObject RightBarHeaderModel();

    /**
     * @brief Get the Left Bar Header Data object
     * 
     * @return QJsonObject 
     */
    QJsonObject LeftBarHeaderModel();

    /**
     * @brief Get the Controls Data object
     * 
     * @return QJsonObject 
     */
    QJsonObject ControlsModel();

    /**
     * @brief Get the Main Window Data object
     * 
     * @return QJsonObject 
     */
    QJsonObject MainWindowModel();

    /**
     * @brief Get the Status Bar Data object
     * 
     * @return QJsonObject 
     */
    QJsonObject StatusBarModel();

    /**
     * @brief Get the Algo Map Data object
     * 
     * @return QJsonObject 
     */
    QJsonObject AlgoMapModel();

    /**
     * @brief Get the Simulation Play Ground Data object
     * 
     * @return QJsonObject 
     */
    QJsonObject SimulationPlayGroundModel();

    /**
     * @brief Get the Simulation Play Ground Header Data object
     * 
     * @return QJsonObject 
     */
    QJsonObject SimulationPlayGroundHeaderModel();

private:
    /**
     * @brief Construct a new Algo Viz Store object
     * 
     * @param parent 
     */
    explicit AlgoVizStore(QObject *parent = nullptr) : QObject(parent) {};

    /**
     * @brief Destroy the Algo Viz Store object
     * 
     */
    ~AlgoVizStore() = default;

    /**
     * @brief Get the json data from the specified `filename` in the `data/ComponentsReference/` directory
     * 
     * Note: 
     * This function is private and can only be accessed by the class members.
     * The filename has to be the name of the json file without the extension, and has the same name as the component name, so it returns the component data directly.
     * The AlgoVizCore contains a macro `_APP_DATA_PATH` which stores the path to the `data/` directory
     * @param filename
     * @return QJsonObject 
     */
    QJsonObject _getComponentData(QString filepath) {
        // get the base file name from file path string
        QString filename = filepath.split("/").last();

        // make sure that it has .json extension, if not it's an error, otherwise, remove .json extension from the filename and store the output in a QString `componentName`.
        if (!filename.contains(".json")) {
            qWarning("Invalid file name.");
            return QJsonObject();
        }
        QString componentName = filename.split(".").first();

        QFile file(_APP_DATA_PATH + filepath);
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning("AlgoVizModel: Couldn't open file data.");
            return QJsonObject();
        }

        QByteArray data = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(data));
        return doc.object().value(componentName).toObject();
    }
};

_END_ALGOVIZ_MODEL

#endif // __ALGOVIZSTORE_H