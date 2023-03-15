/**
 * @file AV_AppTitle.cpp
 * @brief AV_AppTitle class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for AppTitle class, it contains the title and description of the application.
*/

#include "AV_AppTitle.h"

_BEGIN_ALGOVIZ_UI

AppTitle::AppTitle(const QString& title, QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
, _titleLabel(new QLabel(title))
{
    setLayout(_layout);
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);
    _layout->addWidget(_titleLabel, 0, 0, 1, 1, Qt::AlignCenter);

    _layout->setRowStretch(0, 1);
    _layout->setRowMinimumHeight(0, 0);
}

AppTitle::~AppTitle()
{
    delete _layout;
    delete _titleLabel;
}

QString AppTitle::title() const {
    return _titleLabel->text();
}

void AppTitle::setTitle(const QString& title)
{
    _titleLabel->setText(title);
}

_END_ALGOVIZ_UI
