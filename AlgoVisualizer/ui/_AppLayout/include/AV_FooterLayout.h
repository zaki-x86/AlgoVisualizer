/**
 * @file FooterLayout.h
 * @brief FooterLayout widget
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
*/

#ifndef __FOOTER_H
#define __FOOTER_H

#include "AV_Config.h"
#include "LayoutUtils.h"

#include <QWidget>
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <QListWidget>
#include <QComboBox>
#include <QPushButton>
#include <QStatusBar>
#include <QString>

#include <AV_StatusBar.h>
#include <AV_CopyRightLabel.h>

#include "AV_Utils.h"
#include "AV_Config.h"

_BEGIN_ALGOVIZ_UI

class FooterLayout : public QWidget
{
public:
    explicit FooterLayout(StatusBar* statusBar, CopyRightLabel* copyright, QWidget* parent = nullptr);
    ~FooterLayout();

    StatusBar* statusBar();
    void setStatusBar(StatusBar* statusBar);

    CopyRightLabel* copyRightLabel();
    void setCopyRightLabel(CopyRightLabel* copyRightLabel);

private:
    QGridLayout* _layout;
    StatusBar* _statusBar;
    CopyRightLabel* _copyRightLabel;
};

_END_ALGOVIZ_UI

#endif