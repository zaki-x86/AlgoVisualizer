---
title: AlgoVizModel Library
---

# AlgoVizModel : The data library of AlgoViz

This library acts as a data store for the library it contains all the necessary information needed by the application.

Each UI component has its own data representation on a separate JSON file, located in the `data/` directory within the `AlgoVizModel` library source directory.

## Directory Structure

```bash
|- AlgoVizModel\
|--- data\
|----- ComponentsReference\
|------- ... Components data in JSON format ...
|----- AppData.json
|----- MainWindow.json
|--- source\
|----- Algos\
|------- Graph\
|--------- ... Graph algos implementation ...
|------- ML\
|--------- ... ML algos implementation ...
|------- Sort\
|--------- ... Sort algos implementation ...
|------- Search\
|--------- ... Search algos implementation ...
|----- Store\
|------- AlgoVizStore.h
|------- AlgoVizStore.cpp
|--- CMakeLists.txt
```

## Components data schemes

### Application Data Scheme

```python

AppData {
    AppName,
    AppDescription,
    AppVersion,
    AppIcon,
    Github,
    HomePage,
    CopyRight,
    Author,
    License,
    LicenseUrl
    LicenseText,
    LicenseFile
}
```

### Algorithms Data Scheme

```python
AlgoMap {
    algorithm_category {
        name {time_complexity, space_complexity, description}
    }
}
```

### Controls Data Scheme

```python
Controls [
    {id, type, triggers}
]
```

### SideBarHeaders

```python
Left(or Right)BarHeader {
    title,
    description
}
```

### MenuBar Data Scheme

```python
MenuBar {
    type,
    menus {
       id {
            type,
            [resource],
            triggers,
            items {
                id {type, triggers}
            }
        }
    }
}
```

> The resource field is optional and it is only necessary when the type is `icon` or `image`

### Simulation Playground Data Schemes

```
SimulationPlayGround {
        view,
        state
    }
```

```
SimulationPlayGroundHeader {
        title,
        description
    }
```

### StatusBar Data Scheme

```
StatusBar {
    status
}
```

### MainWindow Data Scheme

```
MainWindow {
    title,
    icon,
    geometry {
        x,
        y,
        width,
        height
    },
    state,
    maximized,
    fullscreen,
    visible,
    enabled,
    style,
    styleSheet
}
```

## Algorithms implementation

## `AlgoVizStore` : An interface to components data

Whenever an object requests data, they will have a requet in this form:

```cpp
#include <AlgoVizStore>

using namespace AlgoViz::Model;

class Requester {
public:
    Requester : store(AlgoVizStore::initStore()) {}
    QString getAppName() {
        return store->AppDataModel()["AppName"].toString();
    }

    QString getHomeIcon() {
        return store->MenuBarModel()["menus"].toObject()["home"].toObject()["resource"].toString();
    }

private:
    AlgoVizStore* store; 
}

```