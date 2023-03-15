/**
 * @file CopyRightLabel.h
 * @brief CopyRightLabel class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date 2023-03-12
 * @note This file is part of AlgoVisualizer project
 */

#ifndef __AV_COPY_RIGHT_LABEL_H
#define __AV_COPY_RIGHT_LABEL_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

_BEGIN_ALGOVIZ_UI

class CopyRightLabel : public QWidget
{
public:
    explicit CopyRightLabel(QWidget* parent = nullptr);
    ~CopyRightLabel();

    QString text() const ;
    void setText(const QString& title);

private:
    QGridLayout* _layout;
    QLabel* _copyRightLabel;
};

_END_ALGOVIZ_UI

#endif // __AV_COPY_RIGHT_LABEL_H