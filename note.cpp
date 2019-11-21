#include "note.h"
#include "ui_note.h"

Note::Note(QString dir, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Note),
    path("D:/Coding/Calendar/notes/" + dir) {
    ui->setupUi(this);
    QFile text_(this->path);
    if (text_.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString buff = text_.readAll();
        ui->TextBox->setText(buff);
    }
    text_.close();
}

Note::~Note() {
    delete ui;
}

void Note::on_DeleteButton_clicked() {
    QFile text_(this->path);
    text_.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text);
    text_.remove();
    text_.close();
    this->deleteLater();
}

void Note::on_SaveButton_clicked() {
    QFile text_(this->path);
    text_.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&text_);
    out << ui->TextBox->toPlainText();
    text_.close();
    this->deleteLater();
}
