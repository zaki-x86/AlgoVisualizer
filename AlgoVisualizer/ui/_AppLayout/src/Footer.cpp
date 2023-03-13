/**
 * @file Footer.cpp
 * @brief Footer class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
 */

#include "Footer.h"

Footer::Footer(QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout())
, _statusBar(new QStatusBar())
, _copyRightLabel(new QLabel())
{
    setLayout(_layout);
	_layout->setContentsMargins(0, 0, 0, 0);
	_layout->setSpacing(0);

    _copyRightLabel->setText("M Zaki © 2023 AlgoVisualizer");
    _copyRightLabel->setAlignment(Qt::AlignRight);
    
    _layout->addWidget(_statusBar, 0, 0, 1, 1, Qt::AlignLeft);
    _layout->addWidget(_copyRightLabel, 0, 1, 1, 1, Qt::AlignRight);

    _layout->setColumnStretch(0, 1);
    _layout->setColumnStretch(1, 1);
}

Footer::~Footer()
{

}

QStatusBar* Footer::statusBar()
{
    return _statusBar;
    
}

void Footer::setStatusBar(QStatusBar* statusBar)
{
    _statusBar = statusBar;
    _statusBar->setFixedHeight(25);
    _layout->addWidget(_statusBar);
    _layout->setColumnStretch(0, 1);

}

QLabel* Footer::copyRightLabel()
{
    return _copyRightLabel;
}

void Footer::setCopyRightLabel(QLabel* copyRightLabel)
{
    _copyRightLabel = copyRightLabel;
    _layout->addWidget(_copyRightLabel);
    _layout->setColumnStretch(1, 1);
    _copyRightLabel->setAlignment(Qt::AlignRight);
}
