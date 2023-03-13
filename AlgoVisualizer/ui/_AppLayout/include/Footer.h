/**
 * @file Footer.h
 * @brief Footer widget
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
*/

#ifndef __FOOTER_H
#define __FOOTER_H

#include "LayoutUtils.h"

#include <QWidget>
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <QListWidget>
#include <QComboBox>
#include <QPushButton>
#include <QStatusBar>

#include <string>

class Footer : public QWidget
{
public:
    explicit Footer(QWidget* parent = nullptr);
    ~Footer();

    QStatusBar* statusBar();
    void setStatusBar(QStatusBar* statusBar);

    QLabel* copyRightLabel();
    void setCopyRightLabel(QLabel* copyRightLabel);

private:
    QGridLayout* _layout;
    QStatusBar* _statusBar;
    QLabel* _copyRightLabel;
};

#endif