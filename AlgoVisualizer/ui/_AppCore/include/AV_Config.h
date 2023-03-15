/**
 * @file AV_Config.h
 * @brief App UI configurations
 * @author M Zaki <zaki.x86@gmail.com>
 * @date 2023-12-3
 * @version 1.0
 * @note This file contains the configurations of the UI of the application
 */

#ifndef __CONFIG_H
#define __CONFIG_H


// ===============================================================
// ========= Macros for the namespaces of the application ========
// ===============================================================

#define _BEGIN_ALGOVIZ_UI_UTILS namespace AlgoViz::ui::utils {
#define _END_ALGOVIZ_UI_UTILS }

#define _BEGIN_ALGOVIZ_UI namespace AlgoViz::ui {
#define _END_ALGOVIZ_UI }



#define APP_NAME "AlgoVisualizer"
#define APP_DESCRIPTION "A visualizer for algorithms"
#define APP_VERSION "1.0.0"


// ===============================================================
// ========= Paths to the resources of the application ===========
// ===============================================================

#if defined(APP_STYLESHEETS_PATH)
#define _APP_STYLESHEETS_PATH APP_STYLESHEETS_PATH
#else
#define _APP_STYLESHEETS_PATH ""
#endif

#if defined(APP_ICONS_PATH)
#define _APP_ICONS_PATH APP_ICONS_PATH
#else
#define _APP_ICONS_PATH ""
#endif

#if defined(APP_IMAGES_PATH)
#define _APP_IMAGES_PATH APP_IMAGES_PATH
#else
#define _APP_IMAGES_PATH ""
#endif

#if defined(APP_FONTS_PATH)
#define _APP_FONTS_PATH APP_FONTS_PATH
#else
#define _APP_FONTS_PATH ""
#endif


#endif // __CONFIG_H
