/**
 * @file Header.cpp
 * @brief Header class implementation
 * @author M Zaki <zaki.x86@gmail.com
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
 */

#include "Header.h"

Header::Header(QWidget* parent)
: QWidget()
, _layout(new QGridLayout())
, _appTitle(new QLabel(this))
, _menuBar(new QMenuBar(this))
{
    setLayout(_layout);
	_layout->setContentsMargins(0, 0, 0, 0);
	_layout->setSpacing(0);
    
    _appTitle->setText("AlgoVisualizer");
    _appTitle->setAlignment(Qt::AlignCenter);


    _layout->addWidget(_appTitle, 0, 0, 1, 1, Qt::AlignLeft);
    _layout->addWidget(_menuBar, 1, 0, 1, 1);
}

Header::~Header()
{
    
}

QString Header::appTitle()
{
    return _appTitle->text();
}

QString Header::appTitle() const
{
    return _appTitle->text();
}

void Header::setAppTitle(const QString& title)
{
    _appTitle->setText(title);
}

QMenuBar* Header::menuBar()
{
    return _menuBar;
}

void Header::setMenuBar(QMenuBar* menu_bar)
{
    _menuBar = menu_bar;
    _menuBar->setFixedHeight(25);
    _layout->addWidget(_menuBar);
}
