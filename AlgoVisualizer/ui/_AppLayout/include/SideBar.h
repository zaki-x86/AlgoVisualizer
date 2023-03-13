/**
 * @file SideBar.h
 * @brief Right bar widget
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This class is used to create the UI of the application
*/

#ifndef __RIGHTBAR_H
#define __RIGHTBAR_H

#include "LayoutUtils.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QListWidget>
#include <QComboBox>
#include <QPushButton>
#include <QGroupBox>
#include <QFrame>

#include <string>

class SideBar : public QWidget
{
public:
    explicit SideBar(QWidget* parent = nullptr);
    ~SideBar();

private:
    QGridLayout* _layout;
};

#endif