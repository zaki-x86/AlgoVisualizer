/**
 * @file AppDescription.h
 * @brief AppDescription class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This file is part of AlgoVisualizer project
*/

#ifndef __AV_APP_DESCRIPTION_H
#define __AV_APP_DESCRIPTION_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QString>

_BEGIN_ALGOVIZ_UI

class AppDescription : public QWidget
{
public:
    explicit AppDescription(const QString& desc, QWidget* parent = nullptr);
    ~AppDescription();

    QString description() const;
    void setDescription(const QString& description);

private:
    QGridLayout* _layout;
    QLabel* _descriptionLabel;
};

_END_ALGOVIZ_UI

#endif // __AV_APP_DESCRIPTION_H