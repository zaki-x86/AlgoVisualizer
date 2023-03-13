/**
 * @file Header.h
 * @brief Header widget
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
*/

#ifndef __HEADER_H
#define __HEADER_H

#include "LayoutUtils.h"

#include <QWidget>
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <QListWidget>
#include <QComboBox>
#include <QPushButton>
#include <QMenuBar>
#include <QWidget>
#include <string>

class Header : public QWidget
{
public:
    explicit Header(QWidget* parent = nullptr);
    ~Header();

    QString appTitle();
    QString appTitle() const;
    void setAppTitle(const QString& title);

    QMenuBar* menuBar();
    void setMenuBar(QMenuBar* menuBar);

private:
    QGridLayout* _layout;
    QLabel* _appTitle;
    QMenuBar* _menuBar;
};

#endif