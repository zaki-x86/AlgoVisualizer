/**
 * @file FooterLayout.cpp
 * @brief FooterLayout class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
 */

#include "AV_FooterLayout.h"

_BEGIN_ALGOVIZ_UI

FooterLayout::FooterLayout(StatusBar* statusBar, CopyRightLabel* copyright, QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
, _statusBar(statusBar)
, _copyRightLabel(copyright)
{
    setLayout(_layout);
	_layout->setContentsMargins(5, 5, 5, 5);
	_layout->setSpacing(0);
    
    _layout->addWidget(_statusBar, 0, 0, 1, 1, Qt::AlignLeft);
    _layout->addWidget(_copyRightLabel, 0, 1, 1, 1, Qt::AlignRight);

    _layout->setColumnStretch(0, 1);
    _layout->setColumnStretch(1, 1);
}

FooterLayout::~FooterLayout()
{
    delete _layout;
}

StatusBar* FooterLayout::statusBar()
{
    return _statusBar;
    
}

void FooterLayout::setStatusBar(StatusBar* statusBar)
{
    _statusBar = statusBar;
    //_layout->addWidget(_statusBar);
    //_layout->setColumnStretch(0, 1);

}

CopyRightLabel* FooterLayout::copyRightLabel()
{
    return _copyRightLabel;
}

void FooterLayout::setCopyRightLabel(CopyRightLabel* copyRightLabel)
{
    _copyRightLabel = copyRightLabel;
    //_layout->addWidget(_copyRightLabel);
    //_layout->setColumnStretch(1, 1);
    //_copyRightLabel->setAlignment(Qt::AlignRight);
}

_END_ALGOVIZ_UI