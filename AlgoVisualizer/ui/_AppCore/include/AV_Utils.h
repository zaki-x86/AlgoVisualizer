#ifndef __APP_UTILS_H
#define __APP_UTILS_H

#include <QWidget>
#include <QMap>
#include <QVector>
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringConverter>
#include <QtDebug>

#include "AV_Config.h"


_BEGIN_ALGOVIZ_UI_UTILS

/**
 * @brief A map of algorithms type, used by the AlgorithmsList class
*/
template <typename _T1, typename _T2>
using OneToVectorMap = QMap<_T1, QVector<_T2>>;

using QStringOneToVectorMap = OneToVectorMap<QString, QString>;

using StringList = QList<QString>;

/**
 * @brief Read a stylesheet from a file
 * 
 * @param _fileName The name of the stylesheet file
 * 
 * @return QString The stylesheet content
 * 
 * @note stylesheet file must be located in the ui/_AppResources/stylesheets directory
*/
QString readStyleSheet(QString _fileName);

/**
 * @brief Load a stylesheet from a file, and apply it to a qt widget
 * 
 * @param _obj The qt widget to apply the stylesheet to
 * @param _filePath The path to the stylesheet file
 * 
 * @note stylesheet file must be located in the ui/_AppResources/stylesheets directory
*/
void loadStyleSheet(QWidget* _obj , QString _filePath);

_END_ALGOVIZ_UI_UTILS

#endif