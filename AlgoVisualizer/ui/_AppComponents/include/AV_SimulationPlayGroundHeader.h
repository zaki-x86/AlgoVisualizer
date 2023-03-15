/**
 * @file SimulationPlayGroundHeader.h
 * @brief SimulationPlayGroundHeader class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for SimulationPlayGround class, it contains the title and description of the simulation.
 *       This should be plugged in the top section of the central section grid. 
*/

#ifndef __AV_SIMULATION_PLAYGROUND_HEADER_H
#define __AV_SIMULATION_PLAYGROUND_HEADER_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

_BEGIN_ALGOVIZ_UI

class SimulationPlayGroundHeader : public QWidget
{
public:
    explicit SimulationPlayGroundHeader(QWidget* parent = nullptr);
    ~SimulationPlayGroundHeader();

    QString title() const ;
    void setTitle(const QString& title);

    QString description() const;
    void setDescription(const QString& description);

private:
    QGridLayout* _layout;
    QLabel* _titleLabel;
    QLabel* _descriptionLabel;
};

_END_ALGOVIZ_UI

#endif // __AV_SIMULATION_PLAYGROUND_HEADER_H
