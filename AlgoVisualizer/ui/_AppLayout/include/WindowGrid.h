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

#include "AlgoVisualizer/ui/_AppUtils/Utils.h"
#include "Central.h"
#include "SideBar.h"
#include "Header.h"
#include "Footer.h"
#include "Central.h"


#include "AlgoVisualizer/ui/_AppUtils/config.h"


_BEGIN_ALGOVIZ_UI

/**
 * Main window grid skeleton
*/
class WindowGrid : public QWidget
{
public:
        
    WindowGrid(QWidget* parent = nullptr);
    ~WindowGrid();
    
    Header* header() const;
    void setHeader(const Header& header);

    Central* central() const;
    void setCentral(const Central& central);

    SideBar* leftBar() const;
    void setLeftBar(const SideBar& leftBar);

    SideBar* rightBar() const;
    void setRightBar(const SideBar& rightBar);
    
    Footer* footer() const;
    void setFooter(const Footer& footer);
    
private:
    QString _mainWindowtitle;
    QGridLayout* _mainWindowLayout;
    Header* _header;
    Central* _central;
    SideBar* _leftBar;
    SideBar* _rightBar;
    Footer* _footer;
};

_END_ALGOVIZ_UI

#endif