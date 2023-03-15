/**
 * @file AV_CopyRightLabel.cpp
 * @brief AV_CopyRightLabel class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for CopyRightLabel class, it contains the copy right statement.
 */

#include "AV_CopyRightLabel.h"

_BEGIN_ALGOVIZ_UI

CopyRightLabel::CopyRightLabel(QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
, _copyRightLabel(new QLabel())
{
    setLayout(_layout);
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);
    _layout->addWidget(_copyRightLabel, 1, 0, 1, 1);
    _layout->setRowStretch(0, 1);
    _layout->setRowStretch(1, 1);
    _layout->setRowMinimumHeight(0, 0);
    _layout->setRowMinimumHeight(1, 0);
}

CopyRightLabel::~CopyRightLabel()
{
    delete _layout;
    delete _copyRightLabel;
}

QString CopyRightLabel::text() const
{
    return _copyRightLabel->text();
}

void CopyRightLabel::setText(const QString& title)
{
    _copyRightLabel->setText(title);
}

_END_ALGOVIZ_UI
