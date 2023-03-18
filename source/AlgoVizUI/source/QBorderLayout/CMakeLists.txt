add_library(QBorderLayout borderlayout.cpp)

target_link_libraries(
    QBorderLayout
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core
)