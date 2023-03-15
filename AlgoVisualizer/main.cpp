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
#include "AV_AlgorithmsList.h"
#include "AV_SimulationControls.h"
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
	std::string title = std::string(APP_NAME) + std::string(" ") + std::string(APP_VERSION);
	
	// init algorithms vector with default algorithms
	// setup a map of (group_name, algorithms_list)
	AlgoViz::ui::utils::QStringOneToVectorMap algorithms_map(
		{
			{"Sorting", {"Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort"}},
			{"Path Finding", {"Dijkstra", "A*", "BFS", "DFS", "Bellman-Ford", "Floyd-Warshall"}},
			{"Graph", {"Kruskal", "Prim", "Topological Sort", "Hamiltonian Cycle"}},
			{"Neural Network", {"Perceptron", "Backpropagation", "Genetic Algorithm", "Reinforcement Learning"}}
		}
	);

	AlgoViz::ui::utils::QStringOneToVectorMap menubar_map(
		{
			{"File", {"New", "Open", "Save", "Save As", "Exit"}},
			{"Edit", {"Undo", "Redo", "Cut", "Copy", "Paste", "Delete"}},
			{"View", {"Zoom In", "Zoom Out"}},
			{"Help", {"About", "Help"}}
		}
	);


	// Initialize QApp
	QApplication app(argc, argv);

	// Initialize App components
	AlgoViz::ui::AppTitle *av_appTitle = new AlgoViz::ui::AppTitle(title.c_str());
	AlgoViz::ui::AppDescription *av_appDescription = new AlgoViz::ui::AppDescription(APP_DESCRIPTION);
	AlgoViz::ui::MenuBar *av_menuBar = new AlgoViz::ui::MenuBar;
	AlgoViz::ui::AlgorithmsList *av_algos = new AlgoViz::ui::AlgorithmsList(algorithms_map);
	AlgoViz::ui::SimulationControls *av_controls = new AlgoViz::ui::SimulationControls;
	AlgoViz::ui::SimulationPlayGroundHeader *av_playgroundHeader = new AlgoViz::ui::SimulationPlayGroundHeader;
	AlgoViz::ui::SimulationPlayGround *av_playground = new AlgoViz::ui::SimulationPlayGround;
	AlgoViz::ui::StatusBar *av_statusBar = new AlgoViz::ui::StatusBar;
	AlgoViz::ui::CopyRightLabel *av_copyRightLabel = new AlgoViz::ui::CopyRightLabel;

	// Initialize App Layout and plug in its components
	AlgoViz::ui::HeaderLayout *av_header = new AlgoViz::ui::HeaderLayout(av_appTitle, av_appDescription, av_menuBar);
	AlgoViz::ui::FooterLayout *av_footer = new AlgoViz::ui::FooterLayout;
	AlgoViz::ui::CentralLayout *av_central = new AlgoViz::ui::CentralLayout(av_playgroundHeader, av_playground);

	AlgoViz::ui::SideBarHeader *av_rightBarHeader = new AlgoViz::ui::SideBarHeader("Controls", "Simulation Controls");
	AlgoViz::ui::SideBarHeader *av_leftBarHeader = new AlgoViz::ui::SideBarHeader("Algorithms", "Algorithms List");

	AlgoViz::ui::SideBarLayout *av_rightBar = new AlgoViz::ui::SideBarLayout(av_rightBarHeader);
	AlgoViz::ui::SideBarLayout *av_leftBar = new AlgoViz::ui::SideBarLayout(av_leftBarHeader);
	av_rightBar->addSection(av_controls);
	av_leftBar->addSection(av_algos);
	
	// load stylesheets
	QString _Styles = AlgoViz::ui::utils::readStyleSheet("General.qss");
	app.setStyleSheet(_Styles);

	// Connect App Components to App Layout
	//av_header->setAppTitle(av_appTitle);
	//av_header->setMenuBar(av_menuBar);
	//av_leftBar->addSection(av_algos);
	//av_rightBar->addSection(av_controls);
	//av_central->setSimulationPlayGroundHeader(av_playgroundHeader);
	//av_central->setSimulationPlayGround(av_playground);
	av_footer->setStatusBar(av_statusBar);
	av_footer->setCopyRightLabel(av_copyRightLabel);

	// Initialize App Window
	AlgoViz::ui::WindowGrid &_window = AlgoViz::ui::WindowGrid::init(av_header, av_central, av_leftBar, av_rightBar, av_footer);
	_window.resize(800, 600);
	_window.show();

	return app.exec();
}
