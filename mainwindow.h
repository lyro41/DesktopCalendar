#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "note.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void CalendarClear();

    void CalendarFill(int64_t year, int64_t day);

    void HolidayFill(int64_t year, int64_t day);

    void ChangeBackground(int64_t year);

private slots:
    void on_YearField_returnPressed();

    void on_button_left_clicked();

    void on_button_right_clicked();

    void on_YearField_textChanged(const QString &arg1);

    void on_January_cellClicked(int row, int column);

    void on_February_cellClicked(int row, int column);

    void on_March_cellClicked(int row, int column);

    void on_April_cellClicked(int row, int column);

    void on_May_cellClicked(int row, int column);

    void on_June_cellClicked(int row, int column);

    void on_Jule_cellClicked(int row, int column);

    void on_August_cellClicked(int row, int column);

    void on_September_cellClicked(int row, int column);

    void on_October_cellClicked(int row, int column);

    void on_November_cellClicked(int row, int column);

    void on_December_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    QString path;
    QPixmap background;
};

#endif // MAINWINDOW_H
