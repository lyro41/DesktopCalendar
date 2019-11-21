#pragma once

#ifndef VISUAL_H
#define VISUAL_H

#include "calculations.h"
#include <QFile>
#include <QLabel>
#include <QMainWindow>
#include <QTableWidget>
#include <fstream>
#include <string>
#include <QGraphicsOpacityEffect>
#include <QTextStream>

void SetEffect(QLabel *name);

void TableClear(QTableWidget *table);

void TableFill(QTableWidget *month, int64_t q, int64_t &day);

#endif // VISUAL_H
