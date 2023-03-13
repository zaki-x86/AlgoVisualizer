/**
 * @file Central.h
 * @brief Central widget
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
*/

#ifndef __CENTRAL_H
#define __CENTRAL_H

#include "LayoutUtils.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

#include <string>

class Central : public QWidget
{
public:
    explicit Central(QWidget* parent = nullptr);
    ~Central();

    
    QString title();
    QString title() const ;
    void setTitle(const QString& title);

    QString description();
    void setDescription(const QString& description);

private:
    QGridLayout* _layout;
    QLabel* _titleLabel;
    QLabel* _descriptionLabel;
};

#endif