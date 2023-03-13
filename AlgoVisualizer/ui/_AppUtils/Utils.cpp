
#include "Utils.h"

_BEGIN_ALGOVIZ_UI_UTILS

QString readStyleSheet(QString _fileName)
{
    QString _path = _APP_STYLESHEETS_PATH + _fileName;
    qDebug() << "Loading stylesheet from " << _path;

    QFile _filePath(_path);

    if (!_filePath.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Could not open file ";
        return "";
    }

    QTextStream stream(&_filePath);
    stream.setEncoding(QStringConverter::Encoding::Utf8);
    return stream.readAll();
}

void loadStyleSheet(QWidget* _obj , QString _fileName)
{    
    _obj->setStyleSheet(readStyleSheet(_fileName));
}

_END_ALGOVIZ_UI_UTILS