#include <_AppUI/AppUI.h>


int main(int argc, char *argv[])
{
    AlgoViz::ui::AppUI app(argc, argv);
    QString _Styles = AlgoViz::ui::utils::readStyleSheet("General.qss");
    app.setStyleSheet(_Styles);
    app.init();
    return app.run();
}
