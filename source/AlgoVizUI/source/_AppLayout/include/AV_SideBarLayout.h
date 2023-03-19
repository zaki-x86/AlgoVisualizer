/*
 * Copyright (c) 2021 M Zaki
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file SideBarLayout.h
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
#include <QLayout>
#include <QGridLayout>
#include <QLabel>
#include <QList>
#include <QComboBox>
#include <QPushButton>
#include <QGroupBox>
#include <QString>

#include <AV_AlgoMap.h>
#include <AV_Controls.h>

#include "AV_Utils.h"
#include "AV_Config.h"

_BEGIN_ALGOVIZ_UI

class SideBarHeader : public QWidget
{
public:
	explicit SideBarHeader(QWidget *parent = nullptr);

	~SideBarHeader();

	QString
	titleLabel() const;
	
    void
	setTitleLabel(const QString& titleLabel);

	QString
	descriptionLabel() const;
	
    void
	setDescriptionLabel(const QString& descriptionLabel);

private:
	QGridLayout *_layout;
};

class SideBarLayout : public QWidget
{
public:
	explicit SideBarLayout(QWidget *parent = nullptr);

	~SideBarLayout();

	SideBarHeader *
	sideBarHeader() const;

	void
	setSideBarHeader(QString title, QString description);

	void addWidget(QWidget *widget);

private:
	QGridLayout *_layout;
};

_END_ALGOVIZ_UI

#endif // __RIGHTBAR_H