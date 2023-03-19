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

#include <map>
#include <vector>
#include <string>

#include <QApplication>

// --- import UI components ---


#include "AV_MenuBar.h"
#include "AV_AlgoMap.h"
#include "AV_Controls.h"
#include "AV_SimulationPlayGroundHeader.h"
#include "AV_SimulationPlayGround.h"
#include "AV_StatusBar.h"


// --- import UI layout ---
#include "AV_WindowLayout.h"
#include "AV_HeaderLayout.h"
#include "AV_CentralLayout.h"
#include "AV_SideBarLayout.h"



// *** delete this later
#include "AV_Config.h"
#include "Store/AlgoVizStore.h"
#include "Algos/Sort/BubbleSort.h"
#include "Algos/Sort/SelectionSort.h"
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
// *************************

// implement a swap function that takes two push buttons as input and swap the text values within them


int
main(int argc, char *argv[])
{
	using namespace AlgoViz;

	// Initialize QApp
	QApplication app(argc, argv);

	// Initialize App Model

	// Initialize App Controller

	// Initialize App UI

	// -- TEST CODE (TEMPORARY SECTION) --
	// debug a message when status bar sends initialize() signal
	ui::StatusBar *statusBar = new ui::StatusBar();
	QObject::connect(statusBar, &ui::StatusBar::initialized,[]() {
		qDebug() << "Status bar initialized";
	});
	
	return app.exec();
}
