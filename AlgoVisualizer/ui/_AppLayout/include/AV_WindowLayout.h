/**
 * @file AV_WindowLayout.h
 * @brief WindowLayout class definition
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This class is used to setup the main window layout of the application
 */

#ifndef __WINDOW_GRID_H

#define  __WINDOW_GRID_H


#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QListWidget>
#include <QComboBox>
#include <QPushButton>
#include <QGroupBox>
#include <QFile>
#include <QString>

#include "AV_Utils.h"
#include "AV_CentralLayout.h"
#include "AV_SideBarLayout.h"
#include "AV_HeaderLayout.h"
#include "AV_FooterLayout.h"
#include "AV_CentralLayout.h"


#include "AV_Config.h"
#include "AV_Utils.h"

_BEGIN_ALGOVIZ_UI

/**
 * Main window grid skeleton
*/
class WindowGrid : public QWidget
{
private:
    WindowGrid(HeaderLayout* _header, CentralLayout* _central, SideBarLayout* _leftBar, SideBarLayout* _rightBar, FooterLayout* _footer, QWidget* parent = nullptr);
    ~WindowGrid();

public:
    static WindowGrid& init(HeaderLayout* _header, CentralLayout* _central, SideBarLayout* _leftBar, SideBarLayout* _rightBar, FooterLayout* _footer, QWidget* parent = nullptr);

    // delete copy constructor and assignment operator
    WindowGrid(const WindowGrid&) = delete;
    WindowGrid& operator=(const WindowGrid&) = delete;
    

    HeaderLayout* header() const; 
    void setHeader(HeaderLayout* header);

    CentralLayout* central() const;
    void setCentral(CentralLayout* central);

    SideBarLayout* leftBar() const;
    void setLeftBar(SideBarLayout* leftBar);

    SideBarLayout* rightBar() const;
    void setRightBar(SideBarLayout* rightBar);
    
    FooterLayout* footer() const;
    void setFooter(FooterLayout* footer);
    
private:
    QGridLayout* _mainWindowLayout;
    HeaderLayout* _header;
    CentralLayout* _central;
    SideBarLayout* _leftBar;
    SideBarLayout* _rightBar;
    FooterLayout* _footer;
};

_END_ALGOVIZ_UI

#endif  // __WINDOW_GRID_H