/**
 * @file AppTitle.h
 * @brief AppTitle class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This file is part of AlgoVisualizer project
*/

#ifndef __AV_APP_TITLE_H
#define __AV_APP_TITLE_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

_BEGIN_ALGOVIZ_UI

class AppTitle : public QWidget
{
public:
    explicit AppTitle(const QString& title, QWidget* parent = nullptr);
    ~AppTitle();

    QString title() const ;
    void setTitle(const QString& title);

private:
    QGridLayout* _layout;
    QLabel* _titleLabel;
};

_END_ALGOVIZ_UI

#endif // __AV_APP_TITLE_H