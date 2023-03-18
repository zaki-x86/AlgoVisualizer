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
#include "AV_Config.h"
#include "AV_Utils.h"

// --- import UI components ---
#include "AV_AppTitle.h"
#include "AV_AppDescription.h"
#include "AV_MenuBar.h"
#include "AV_AlgoMap.h"
#include "AV_Controls.h"
#include "AV_SimulationPlayGroundHeader.h"
#include "AV_SimulationPlayGround.h"
#include "AV_StatusBar.h"
#include "AV_CopyRightLabel.h"

// --- import UI layout ---
#include "AV_WindowLayout.h"
#include "AV_HeaderLayout.h"
#include "AV_CentralLayout.h"
#include "AV_SideBarLayout.h"
#include "AV_FooterLayout.h"


int
main(int argc, char *argv[])
{
	// Initialize QApp
	QApplication app(argc, argv);

	// Initialize App Model

	// Initialize App Controller

	// Initialize App UI


	return app.exec();
}
