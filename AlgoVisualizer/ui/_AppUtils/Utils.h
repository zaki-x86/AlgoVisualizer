#ifndef __APP_UTILS_H
#define __APP_UTILS_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringConverter>
#include <QtDebug>

#include "config.h"


_BEGIN_ALGOVIZ_UI_UTILS

/**
 * @brief Read a stylesheet from a file
 * 
 * @param _fileName The name of the stylesheet file
 * 
 * stylesheet file must be in the ui/_AppStylesheets directory
*/
QString readStyleSheet(QString _fileName);

/**
 * @brief Load a stylesheet from a file
 * @param _obj The widget to apply the stylesheet to
 * @param _filePath The path to the stylesheet file
 * 
 * stylesheet file must be in the ui/_AppStylesheets directory
*/
void loadStyleSheet(QWidget* _obj , QString _filePath);

_END_ALGOVIZ_UI_UTILS

#endif