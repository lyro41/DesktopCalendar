#pragma once

#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include "visual.h"

namespace Ui {
class Note;
}

class Note : public QWidget
{
    Q_OBJECT

public:
    explicit Note(QString dir = "D:/", QWidget *parent = nullptr);
    ~Note();

private:
    Ui::Note *ui;
    QString path;

private slots:
    void on_SaveButton_clicked();

    void on_DeleteButton_clicked();
};

#endif // NOTE_H
