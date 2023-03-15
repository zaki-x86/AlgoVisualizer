/**
 * @file AV_MenuBar.cpp
 * @brief AV_MenuBar class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for MenuBar class, it contains the menu bar of the application.
 */

#include "AV_MenuBar.h"

_BEGIN_ALGOVIZ_UI

MenuBar::MenuBar(QWidget* parent)
: QWidget(parent)
{
    _menuBar = new QMenuBar(this);
    setupMenuBar();
}

MenuBar::~MenuBar()
{
    delete _menuBar;
}

void MenuBar::setupMenuBar()
{
    _fileMenu = _menuBar->addMenu("File");
    _editMenu = _menuBar->addMenu("Edit");
    _viewMenu = _menuBar->addMenu("View");
    _helpMenu = _menuBar->addMenu("Help");

    _newAction = _fileMenu->addAction("New");
    _openAction = _fileMenu->addAction("Open");
    _saveAction = _fileMenu->addAction("Save");
    _saveAsAction = _fileMenu->addAction("Save As");
    _fileMenu->addSeparator();
    _exitAction = _fileMenu->addAction("Exit");

    _undoAction = _editMenu->addAction("Undo");
    _redoAction = _editMenu->addAction("Redo");
    _editMenu->addSeparator();
    _cutAction = _editMenu->addAction("Cut");
    _copyAction = _editMenu->addAction("Copy");
    _pasteAction = _editMenu->addAction("Paste");
    _deleteAction = _editMenu->addAction("Delete");
    _editMenu->addSeparator();
    _selectAllAction = _editMenu->addAction("Select All");

    _zoomInAction = _viewMenu->addAction("Zoom In");
    _zoomOutAction = _viewMenu->addAction("Zoom Out");

    _aboutAction = _helpMenu->addAction("About");

    _newAction->setShortcut(QKeySequence::New);
    _openAction->setShortcut(QKeySequence::Open);
    _saveAction->setShortcut(QKeySequence::Save);
    _saveAsAction->setShortcut(QKeySequence::SaveAs);
    _exitAction->setShortcut(QKeySequence::Quit);
    _undoAction->setShortcut(QKeySequence::Undo);
    _redoAction->setShortcut(QKeySequence::Redo);
    _cutAction->setShortcut(QKeySequence::Cut);
    _copyAction->setShortcut(QKeySequence::Copy);
    _pasteAction->setShortcut(QKeySequence::Paste);
    _deleteAction->setShortcut(QKeySequence::Delete);
    _selectAllAction->setShortcut(QKeySequence::SelectAll);
    _zoomInAction->setShortcut(QKeySequence::ZoomIn);
    _zoomOutAction->setShortcut(QKeySequence::ZoomOut);
}

QMenuBar* MenuBar::menuBar() const
{
    return _menuBar;
}

_END_ALGOVIZ_UI