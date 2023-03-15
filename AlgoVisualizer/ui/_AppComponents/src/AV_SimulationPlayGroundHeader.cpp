/**
 * @file AV_SimulationPlayGroundHeader.cpp
 * @brief AV_SimulationPlayGroundHeader class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for SimulationPlayGroundHeader class, it contains the title and description of the simulation.
 */

#include "AV_SimulationPlayGroundHeader.h"

_BEGIN_ALGOVIZ_UI

SimulationPlayGroundHeader::SimulationPlayGroundHeader(QWidget* parent)
    : QWidget(parent)
{
    _layout = new QGridLayout(this);
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(0);

    _titleLabel = new QLabel("Title", this);
    _titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: #000000;");
    _titleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    _layout->addWidget(_titleLabel, 0, 0, 1, 1);

    _descriptionLabel = new QLabel("Description", this);
    _descriptionLabel->setStyleSheet("font-size: 12px; color: #000000;");
    _descriptionLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    _layout->addWidget(_descriptionLabel, 1, 0, 1, 1);
}

SimulationPlayGroundHeader::~SimulationPlayGroundHeader()
{
    delete _layout;
}

void SimulationPlayGroundHeader::setTitle(const QString& title)
{
    _titleLabel->setText(title);
}

void SimulationPlayGroundHeader::setDescription(const QString& description)
{
    _descriptionLabel->setText(description);
}

_END_ALGOVIZ_UI