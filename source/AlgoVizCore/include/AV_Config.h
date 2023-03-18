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

#define _BEGIN_ALGOVIZ_MODEL namespace AlgoViz::model {
#define _END_ALGOVIZ_MODEL }

#define _BEGIN_ALGOVIZ_CONTROL namespace AlgoViz::control {
#define _END_ALGOVIZ_CONTROL }

#define APP_NAME "AlgoVisualizer"
#define APP_DESCRIPTION "A visualizer for algorithms"
#define APP_VERSION "1.0.0"
#define COPYRIGHT_LABEL "Copyright © 2023 M Zaki <zaki.x86@gmail.com>"


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

#if defined(APP_DATA_PATH)
#define _APP_DATA_PATH APP_DATA_PATH
#else
#define _APP_DATA_PATH ""
#endif

#endif // __CONFIG_H
