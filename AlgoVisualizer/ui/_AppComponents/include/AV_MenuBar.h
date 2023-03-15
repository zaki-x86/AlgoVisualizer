/**
 * @file MenuBar.h
 * @brief MenuBar class implementation
 * @author M Zaki <
 * @version 0.1
 * @date 2023-03-12
 * @note This file is part of AlgoVisualizer project
 */

#ifndef __AV_MENU_BAR_H
#define __AV_MENU_BAR_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
#include <QKeySequence>
#include <QMessageBox>
#include <QTranslator>

_BEGIN_ALGOVIZ_UI

class MenuBar : public QWidget
{
public:
    MenuBar(QWidget* parent = nullptr);
    ~MenuBar();

    void setupMenuBar();

    QMenuBar* menuBar() const;

private:
    QMenuBar* _menuBar;
    QMenu* _fileMenu;
    QMenu* _editMenu;
    QMenu* _viewMenu;
    QMenu* _helpMenu;

    QAction* _newAction;
    QAction* _openAction;
    QAction* _saveAction;
    QAction* _saveAsAction;
    QAction* _exitAction;

    QAction* _undoAction;
    QAction* _redoAction;
    QAction* _cutAction;
    QAction* _copyAction;
    QAction* _pasteAction;
    QAction* _deleteAction;
    QAction* _selectAllAction;

    QAction* _zoomInAction;
    QAction* _zoomOutAction;

    QAction* _aboutAction;
    QAction* _aboutQtAction;

    void setupFileMenu();
    void setupEditMenu();
    void setupViewMenu();
    void setupHelpMenu();

    void setupActions();
    void setupShortcuts();
    void setupSignals();
};

_END_ALGOVIZ_UI

#endif // __AV_MENU_BAR_H