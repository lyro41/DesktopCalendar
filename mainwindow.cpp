#include "mainwindow.h"
#include "ui_mainwindow.h"

int64_t year_ = 0;


void MainWindow::ChangeBackground(int64_t year) {
    QString dir = path + QString::number(year) + ".jpg";
    QPixmap background(dir);
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background.isNull() ? this->background : background);
    this->setPalette(palette);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    path("D:/Coding/Calendar/background/") {
    ui->setupUi(this);

    this->background.load(path + "1.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QColor label_color(0, 0, 0, 255);

    SetEffect(ui->JanuaryLabel);
    SetEffect(ui->FebruaryLabel);
    SetEffect(ui->MarchLabel);
    SetEffect(ui->AprilLabel);
    SetEffect(ui->MayLabel);
    SetEffect(ui->JuneLabel);
    SetEffect(ui->JuleLabel);
    SetEffect(ui->AugustLabel);
    SetEffect(ui->SeptemberLabel);
    SetEffect(ui->OctoberLabel);
    SetEffect(ui->NovemberLabel);
    SetEffect(ui->DecemberLabel);
    SetEffect(ui->YearCounter);
    ui->YearCounter->setPalette(label_color);


    std::string options = "{color: rgba(0, 0, 0, 100%); background-color: rgba(255, 255, 255, 25%);}";
    ui->January->setStyleSheet(QLatin1String(("#January" + options).c_str()));
    ui->February->setStyleSheet(QLatin1String(("#February" + options).c_str()));
    ui->March->setStyleSheet(QLatin1String(("#March" + options).c_str()));
    ui->April->setStyleSheet(QLatin1String(("#April" + options).c_str()));
    ui->May->setStyleSheet(QLatin1String(("#May" + options).c_str()));
    ui->June->setStyleSheet(QLatin1String(("#June" + options).c_str()));
    ui->Jule->setStyleSheet(QLatin1String(("#Jule" + options).c_str()));
    ui->August->setStyleSheet(QLatin1String(("#August" + options).c_str()));
    ui->September->setStyleSheet(QLatin1String(("#September" + options).c_str()));
    ui->October->setStyleSheet(QLatin1String(("#October" + options).c_str()));
    ui->November->setStyleSheet(QLatin1String(("#November" + options).c_str()));
    ui->December->setStyleSheet(QLatin1String(("#December" + options).c_str()));


    ui->JanuaryLabel->setPalette(label_color);
    ui->FebruaryLabel->setPalette(label_color);
    ui->MarchLabel->setPalette(label_color);
    ui->AprilLabel->setPalette(label_color);
    ui->MayLabel->setPalette(label_color);
    ui->JuneLabel->setPalette(label_color);
    ui->JuleLabel->setPalette(label_color);
    ui->AugustLabel->setPalette(label_color);
    ui->SeptemberLabel->setPalette(label_color);
    ui->OctoberLabel->setPalette(label_color);
    ui->NovemberLabel->setPalette(label_color);
    ui->DecemberLabel->setPalette(label_color);
}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::on_YearField_returnPressed() {
    ui->YearCounter->setText(ui->YearField->text());
    ui->YearField->setText(ui->YearCounter->text());
}

void MainWindow::on_button_left_clicked() {
    QString now = ui->YearField->text();
    ui->YearField->setText(QString::number(now.toInt() - 1));
}

void MainWindow::on_button_right_clicked() {
    QString now = ui->YearField->text();
    ui->YearField->setText(QString::number(now.toInt() + 1));
}

void MainWindow::CalendarClear() {
    TableClear(ui->January);
    TableClear(ui->February);
    TableClear(ui->March);
    TableClear(ui->April);
    TableClear(ui->May);
    TableClear(ui->June);
    TableClear(ui->Jule);
    TableClear(ui->August);
    TableClear(ui->September);
    TableClear(ui->October);
    TableClear(ui->November);
    TableClear(ui->December);
}

void MainWindow::CalendarFill(int64_t year, int64_t day) {
    TableFill(ui->January, DaysInMonth(1, year), day);
    TableFill(ui->February, DaysInMonth(2, year), day);
    TableFill(ui->March, DaysInMonth(3, year), day);
    TableFill(ui->April, DaysInMonth(4, year), day);
    TableFill(ui->May, DaysInMonth(5, year), day);
    TableFill(ui->June, DaysInMonth(6, year), day);
    TableFill(ui->Jule, DaysInMonth(7, year), day);
    TableFill(ui->August, DaysInMonth(8, year), day);
    TableFill(ui->September, DaysInMonth(9, year), day);
    TableFill(ui->October, DaysInMonth(10, year), day);
    TableFill(ui->November, DaysInMonth(11, year), day);
    TableFill(ui->December, DaysInMonth(12, year), day);
}

void MainWindow::HolidayFill(int64_t year, int64_t day) {
    QFile read("D:/Coding/Calendar/holidays");
    int64_t d, m, dotw, i, j;
    if (!read.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QColor color;
    QString hex("#FF0000");
    std::string buff;
    QTableWidgetItem *item;
    while(!read.atEnd()) {
        buff = read.readLine().toStdString();
        if (buff.length() == 1) continue;
        d = std::atoi(buff.substr(0, 2).c_str());
        m = std::atoi(buff.substr(3, 2).c_str());
        hex = QString::fromStdString(buff.substr(6, 7));
        color.setNamedColor(hex);
        color.setAlpha(64);
        dotw = WeekDay(1, 1, year, day, 1, m, year) - 1;
        dotw += d - 1;
        i = dotw % 7;
        j = dotw / 7;
        switch (m) {
            case 1: item = ui->January->item(i, j); break;
            case 2: item = ui->February->item(i, j); break;
            case 3: item = ui->March->item(i, j); break;
            case 4: item = ui->April->item(i, j); break;
            case 5: item = ui->May->item(i, j); break;
            case 6: item = ui->June->item(i, j); break;
            case 7: item = ui->Jule->item(i, j); break;
            case 8: item = ui->August->item(i, j); break;
            case 9: item = ui->September->item(i, j); break;
            case 10: item = ui->October->item(i, j); break;
            case 11: item = ui->November->item(i, j); break;
            case 12: item = ui->December->item(i, j); break;
        }
        item->setBackground(color);
    }
}

void MainWindow::on_YearField_textChanged(const QString &arg1) {
    year_ = arg1.toInt();
    int64_t day = WeekDay(3, 1, 2004, 6, 1, 1, year_) - 1;

    CalendarClear();
    CalendarFill(year_, day);
    HolidayFill(year_, day + 1);
    ChangeBackground(year_);
}

void MainWindow::on_January_cellClicked(int row, int column) {
    if (ui->January->item(row, column)->text().length() == 0) return;
    QString file_name = ui->January->item(row, column)->text() + "_01_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}

void MainWindow::on_February_cellClicked(int row, int column) {
    if (ui->February->item(row, column)->text().length() == 0) return;
    QString file_name = ui->February->item(row, column)->text() + "_02_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}

void MainWindow::on_March_cellClicked(int row, int column) {
    if (ui->March->item(row, column)->text().length() == 0) return;
    QString file_name = ui->March->item(row, column)->text() + "_03_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}

void MainWindow::on_April_cellClicked(int row, int column) {
    if (ui->April->item(row, column)->text().length() == 0) return;
    QString file_name = ui->April->item(row, column)->text() + "_04_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}

void MainWindow::on_May_cellClicked(int row, int column) {
    if (ui->May->item(row, column)->text().length() == 0) return;
    QString file_name = ui->May->item(row, column)->text() + "_05_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}

void MainWindow::on_June_cellClicked(int row, int column) {
    if (ui->June->item(row, column)->text().length() == 0) return;
    QString file_name = ui->June->item(row, column)->text() + "_06_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}

void MainWindow::on_Jule_cellClicked(int row, int column) {
    if (ui->Jule->item(row, column)->text().length() == 0) return;
    QString file_name = ui->Jule->item(row, column)->text() + "_07_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}

void MainWindow::on_August_cellClicked(int row, int column) {
    if (ui->August->item(row, column)->text().length() == 0) return;
    QString file_name = ui->August->item(row, column)->text() + "_08_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}

void MainWindow::on_September_cellClicked(int row, int column) {
    if (ui->September->item(row, column)->text().length() == 0) return;
    QString file_name = ui->September->item(row, column)->text() + "_09_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}

void MainWindow::on_October_cellClicked(int row, int column) {
    if (ui->October->item(row, column)->text().length() == 0) return;
    QString file_name = ui->October->item(row, column)->text() + "_10_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}

void MainWindow::on_November_cellClicked(int row, int column) {
    if (ui->November->item(row, column)->text().length() == 0) return;
    QString file_name = ui->November->item(row, column)->text() + "_11_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}

void MainWindow::on_December_cellClicked(int row, int column) {
    if (ui->December->item(row, column)->text().length() == 0) return;
    QString file_name = ui->December->item(row, column)->text() + "_12_" + QString::number(year_);
    Note *my_note = new Note(file_name);
    my_note->setWindowTitle(file_name);
    my_note->show();
}
