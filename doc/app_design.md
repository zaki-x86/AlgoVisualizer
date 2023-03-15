# Algo Visualizer

## Overview of The GUI

- The entire app GUI is designed as a library called `AlgoVisualizer_UI` to be linked with the app main executable. The executable will import the necessary GUI facilities frpm `AlgoVisualizer_UI` and will use it to initialize and launch the app.
- The `AlgoVisualizer_UI` library is divided into 3 libraries: `UI_AppCore`, `UI_AppComponents`, `UI_AppLayout`

### Overview of GUI Layout and Components

- The main window is layed out as a "grid".
- The main window is divided into 5 sections: header, center, left bar, right bar and footer.
- The main window is only responsible for managing the 5 sections mentioned above, and nothing else.
- Each section has a grid layout as well and is responsible of managing the organization and the postioning of the components within it.
- Each section has an interface that provide read/write access to the components within it.
- Remember sections are not responsible at all with any thing other than organizing the components. **It is not responsible for components' memory allocation/deallocation**.
- Each component (may have a layout of its own and maybe not) depending on its complexity, but most components have subcomponents as well, and thus it needs a layout to organize and position its subcomponents.

> All GUI components are heap allocated. Later on, we may research how to eliminate memory allocation or at least reduce it.

### GUI Core Utilities: `UI_AppCore`

This library provides core utilities and configurations that are global to the entire UI.
Check the in-source documentation for both files `AV_Config.h` and `AV_Utils.h`

### GUI Layout : `UI_AppLayout`

#### The `WindowGrid` class

as the name suggests, this class provides definitions and implementation of the main window layout. The window class is designed as a singleton class to prevent multiple instances of this type. In order to create an instance of the class, client must use the `init` function that returns a reference to an instance of the window class.

Here is `WindowGrid` interface:

```cpp
class WindowGrid : public QWidget {
private:
    WindowGrid(QWidget* parent = nullptr);
    WindowGrid(HeaderLayout* _header, CentralLayout* _central, SideBarLayout* _leftBar, SideBarLayout* _rightBar, FooterLayout* _footer, QWidget* parent = nullptr);
    ~WindowGrid();

public:
    static WindowGrid& init(HeaderLayout* _header, CentralLayout* _central, SideBarLayout* _leftBar, SideBarLayout* _rightBar, FooterLayout* _footer, QWidget* parent = nullptr);
    
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
```

#### The Window Sections

As mentioned before, the window is divided into 5 sections, each section is modeled as a separate class, and each class is derived from `QWidget`.

Each section class is modeled in a way that:

- upon initialization of the section, its components are passed to it,
- the constructor takes care of organizing the components within the layout,
- Each section class also provides accessors and modifiers of the components within it in case it needed to be changed after the section layout is initialized.

So, here is a psudocode that illustrates this idea:

```java
class SectionLayout extends QWidget {
public:
    constructor(Component1* component1, Component2* component2, .., ComponentX* componentN);

    destructor();

    Component1 component1();
    void setComponent1();
    ...
private:
    Component* _component1;
    ...
    ComponentX* _componentN;
}
```

1. `HeaderLayout`

- contains these components: `AppTitle`, `AppDescription` and `MenuBar`.
- organized as a grid layout.

1. `CentralLayout`

- contains these components: `SimulationPlayGroundHeader` and `SimulationPlayGround`.
- organized as a grid layout.

1. `SideBarLayout`

The side bar class works a bit different than the other layouts, it tends to be more general, and it comes with another class called `SideBarHeader` which defines title and description labels within the side bar.

The sidebar gives you the advantage of adding as many sections as you like while the layout class will keep the layout intact dynaimcally, which comes at a cost, because the class saves each section within it, which increases the object size significantly.

Here is the interface for the side bar layout:

```cpp
class SideBarLayout : public QWidget
{
public:
	explicit SideBarLayout(SideBarHeader* header, QWidget *parent = nullptr);

	~SideBarLayout();

	SideBarHeader *
	sideBarHeader() const;

	void
	setSideBarHeader(SideBarHeader *sideBarHeader);

	// Get a list of sections within the side bar
	QList<QWidget *>
	sections() const;

	// Add a new section to the side bar
	void
	addSection(QWidget *section);

private:
	QGridLayout *_layout;
	SideBarHeader *_sideBarHeader;
	QList<QWidget *> _sections;
};
```

And here is the interface of the sidebar header:

```cpp
class SideBarHeader : public QWidget
{
public:
	explicit SideBarHeader(const QString &title, const QString& desc, QWidget *parent = nullptr);

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
	QLabel *_titleLabel;
	QLabel *_descriptionLabel;
};
```

1. `FooterLayout`

The footer layout is similar to the header and central layouts, excepts that it consists of 2 components, which are: `StatusBar` and `CopyRightLabel`.

#### The Window Components

## The App Entry Point

In the program's entry point (i.e. `main()` function), here is what happens:

1. Qt app is initialized.
2. All app components are imported and initialized
3. All app layouts are imported an initialized
4. Stylesheets are loaded
5. All components are plugged into their corresponding layout

Here is a sample code for the main function:

```cpp
void main (int argc, char** argv) {
    // Initialize QApp
    QApplication app(argc, argv);

    // Initialize App Layouts
    AlgoViz::ui::HeaderLayout* av_header = new HeaderLayout
    AlgoViz::ui::FooterLayout* av_footer = new FooterLayout
    AlgoViz::ui::CentralLayout* av_central = new CentralLayout
    AlgoViz::ui::SideBarLayout* av_rightBar = new SideBarLayout
    AlgoViz::ui::SideBarLayout* av_leftBar = new SideBarLayout

    // Initialize App components
    AlgoViz::ui::AppTitle av_appTitle = new AppTitle;
    AlgoViz::ui::MenuBar av_menuBar = new MenuBar;
    AlgoViz::ui::AlgorithmsList av_algos = new AlgorithmsList;
    AlgoViz::ui::Controls av_controls = new Controls;
    AlgoViz::ui::PlayGroundTitle av_playgroundTitle = new PlayGroundTitle;
    AlgoViz::ui::PlayGround av_playground = new PlayGround;
    AlgoViz::ui::StatusBar av_statusBar = new StatusBar;
    AlgoViz::ui::CopyRightLabel av_copyRightLabel = new CopyRightLabel;

    // Connect App Components to App Layout
    av_header->addWidget(av_appTitle);
    av_header->addWidget(av_menuBar);
    av_leftBar->addWidget(av_algos);
    av_rightBar->addWidget(av_controls);
    av_central->addWidget(av_playgroundTitle);
    av_central->AddWidget(av_playground);
    av_footer->addWidget(av_statusBar);
    av_footer->addWidget(av_copyRightLabel);
    
    // Initialize App Window
	AlgoViz::ui::WindowGrid& _window = AlgoViz::ui::WindowGrid::init(av_header, av_central, av_leftBar, av_rightBar, av_footer);
	_window.show();

    return app.exec();
}