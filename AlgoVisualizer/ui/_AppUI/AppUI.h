/**
 * @brief   AppUI class
 * @note    This class is used to create the UI of the application
 * @author  M Zaki <zaki.x86@gmail.com>
 * @date    2023-12-3
 * @version 1.0
*/

#ifndef APPUI_H
#define APPUI_H

#include <QApplication>
#include <WindowGrid.h>
#include <QFile>
#include <QTextStream>
#include <QStringConverter>
#include "AlgoVisualizer/ui/_AppUtils/config.h"

_BEGIN_ALGOVIZ_UI

class AppUI : public QApplication
{
public:
    AppUI(int &argc, char **argv);
    ~AppUI();

    void init();
    void render();
    void shutdown();
    int run();
private:
    WindowGrid* window;
};

_END_ALGOVIZ_UI

#endif // APPUI_H