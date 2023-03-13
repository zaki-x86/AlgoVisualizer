#include "AppUI.h"

_BEGIN_ALGOVIZ_UI

AppUI::AppUI(int &argc, char **argv) 
: QApplication(argc, argv)
, window(new WindowGrid())
{
    
}

AppUI::~AppUI()
{

}


void AppUI::init()
{
    window->show();
}


void AppUI::render()
{

}

void AppUI::shutdown()
{

}

int AppUI::run()
{
    return exec();
}

_END_ALGOVIZ_UI