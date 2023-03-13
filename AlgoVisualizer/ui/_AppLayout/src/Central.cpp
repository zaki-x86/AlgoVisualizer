/**
 * @file Central.cpp
 * @brief Central class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to create the UI of the application
 */

#include "Central.h"

Central::Central(QWidget* parent)
: QWidget(parent)
, _layout(new QGridLayout)
, _titleLabel(new QLabel())
, _descriptionLabel(new QLabel())
{
    setLayout(_layout);
	_layout->setContentsMargins(0, 0, 0, 0);
	_layout->setSpacing(0);
    
    // set title and description
    setTitle("Welcome to Algo Visualizer");
    setDescription("This is a simple application to visualize algorithms");

    _layout->addWidget(_titleLabel, 0, 0, 1, 1, Qt::AlignCenter);
    _layout->addWidget(_descriptionLabel, 1, 0, 1, 1, Qt::AlignCenter);
}

Central::~Central()
{

}

QString Central::title() {
    return _titleLabel->text();
}

QString Central::title() const {
    return _titleLabel->text();
}

void Central::setTitle(const QString& title)
{
    _titleLabel->setText(title);
}

QString Central::description() {
    return _descriptionLabel->text();
}

void Central::setDescription(const QString& description)
{
    _descriptionLabel->setText(description);
}