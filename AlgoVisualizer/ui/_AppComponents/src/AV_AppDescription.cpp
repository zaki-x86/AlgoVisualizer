/**
 * @file AV_AppDescription.cpp
 * @brief AV_AppDescription class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for AppDescription class, it contains the title and description of the application.
 */

#include "AV_AppDescription.h"

_BEGIN_ALGOVIZ_UI

AppDescription::AppDescription(const QString& desc, QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
, _descriptionLabel(new QLabel(desc))
{
    setLayout(_layout);
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);
    _layout->addWidget(_descriptionLabel, 0, 0, 1, 1, Qt::AlignCenter);
    _layout->setRowMinimumHeight(0, 0);
}

AppDescription::~AppDescription()
{
    delete _layout;
    delete _descriptionLabel;
}

QString AppDescription::description() const {
    return _descriptionLabel->text();
}

void AppDescription::setDescription(const QString& description)
{
    _descriptionLabel->setText(description);
}

_END_ALGOVIZ_UI
