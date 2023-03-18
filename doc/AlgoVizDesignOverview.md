# Overview of AlgoViz Design and Frameworks

AlgoViz uses the Qt framework to render its GUI and to define the interactions between the GUI components and the logic of the app. In the application design, we follow the MVC pattern, which enforces that application data, application logic and GUI are separated from each other into separate libraries that are linked to the final executable. These libraries are: `AlgoVizModel`, `AlgoVizControl`, `AlgoVizUI`.

In addition to these libraries, `AlgoVizCore` library defines a set of configurations and utility functions that are global to the entire application and used by all applications components.

![MVC Model of AlgoViz](./images/AlgoVizMVC.svg)

The [AlgoVizUI]() is responsible for managing the UI of AlgoViz. It manages the main window layout and the GUI components within this layout.

Each class member interface in [AlgoVizUI]() library is equipped with a set of functions that facilitate access to its layout and its components, so the control unit can use them to perform the necessary actions.

The [AlgoVizControl]() library is acting as a mediator between the model and the UI, not only does it act as a mediator but it is also equipped with the app logic that controls the app GUI and data. It works by receiving signals from the GUI, usually these signals are user input, and the control will set the actions to be executed upon receiving these signals.

The [AlgoVizModel]() library defines the necessary data that the application uses, such as: the app name, descriptions, algorithms to be simulated and their functions and more.

## `AlgoVizUI` : AlgoViz GUI Library

The **AlgoVizUI** library defines the `AlgoVizUI` class that manages and provides an interface to the entire GUI layout and components.

The AlgoVizUI has a set of sub-libraries that manages different aspects and components of the GUI which are: [UI_AppComponents](), [UI_AppLayout]() and [QBorderLayout]().

## `AlgoVizModel` : AlgoViz Data Library

```