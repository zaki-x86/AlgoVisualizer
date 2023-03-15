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
	std::string title = std::string(APP_NAME) + std::string(" ") + std::string(APP_VERSION) + std::string(" : ") + std::string(APP_DESCRIPTION) ;
	
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
			{"Help", {"About", "Docs"}}
		}
	);

	AlgoViz::ui::utils::StringList buttons_list(
		{
			"Play", "Pause", "Stop", "Speed Up", "Reset"
		}
	);


	// Initialize QApp
	QApplication app(argc, argv);

	// Initialize App components
	//AlgoViz::ui::AppTitle *av_appTitle = new AlgoViz::ui::AppTitle(title.c_str());
	//AlgoViz::ui::AppDescription *av_appDescription = new AlgoViz::ui::AppDescription(APP_DESCRIPTION);
	
	AlgoViz::ui::MenuBar *av_menuBar = new AlgoViz::ui::MenuBar(menubar_map);
	AlgoViz::ui::AlgorithmsList *av_algos = new AlgoViz::ui::AlgorithmsList(algorithms_map);
	AlgoViz::ui::SimulationControls *av_controls = new AlgoViz::ui::SimulationControls(buttons_list);
	AlgoViz::ui::SimulationPlayGroundHeader *av_playgroundHeader = new AlgoViz::ui::SimulationPlayGroundHeader;
	AlgoViz::ui::SimulationPlayGround *av_playground = new AlgoViz::ui::SimulationPlayGround;
	AlgoViz::ui::StatusBar *av_statusBar = new AlgoViz::ui::StatusBar;
	AlgoViz::ui::CopyRightLabel *av_copyRightLabel = new AlgoViz::ui::CopyRightLabel(COPYRIGHT_LABEL);

	// Initialize App Layout and plug in its components
	//AlgoViz::ui::HeaderLayout *av_header = new AlgoViz::ui::HeaderLayout(av_appTitle, av_appDescription, av_menuBar);
	
	AlgoViz::ui::FooterLayout *av_footer = new AlgoViz::ui::FooterLayout(av_statusBar, av_copyRightLabel);
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

	// Initialize App Window
	AlgoViz::ui::WindowGrid &_window = AlgoViz::ui::WindowGrid::init(nullptr, av_central, av_leftBar, av_rightBar, av_footer);
	_window.setWindowTitle(title.c_str());
	_window.layout()->setMenuBar(av_menuBar);
	_window.resize(800, 600);
	_window.show();

	// -------Simulation-------------
	// when reset button is pressed, generate another random set of array
	// and update it in GUI
	qDebug() << "Connecting reset button...";
	QObject::connect(av_playground->resetBtn(), &QPushButton::clicked, [&]() {
		// when reset button is pressed generate another random set of array
		// and update it in GUI
		av_playground->updateArray();
		av_playground->updateButton(av_playground->button);
		av_playground->sortBtn()->setText("SORT");
	});

	// --------------------
	// when sort button is pressed, sort the array
	qDebug() << "Connecting sort button...";
	QObject::connect(av_playground->sortBtn(), &QPushButton::clicked, [&]() {
		if (av_playground->sorting() == true)
		{
			// if _sorting already in place don't do anything
			return;
		}
		av_playground->setSorting(true);
		av_playground->resetBtn()->setVisible(false);
		av_playground->sortBtn()->setText("_sorting...");
		// if binary sort radio button is clicked do binary sort
		// else do selection sort
		av_playground->radioBubble()->isChecked() ? av_playground->bubbleSort(av_playground->button) : av_playground->selectionSort(av_playground->button);
		av_playground->resetBtn()->setVisible(true);
		av_playground->sortBtn()->setText("SORT");
		av_playground->setSorting(false);
	});

	return app.exec();
}
