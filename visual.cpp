#include "visual.h"

void SetEffect(QLabel *target) {
    QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect(target);
    eff->setOffset(0, 0);
    eff->setBlurRadius(5.0);
    eff->setColor(Qt::black);
    target->setGraphicsEffect(eff);
}

void TableClear(QTableWidget *table) {
    QColor color("#FFFFFF");
    color.setAlpha(64);
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 6; ++j) {
            table->item(i, j)->setText("");
            table->item(i, j)->setBackgroundColor(color);
        }
    }
    return;
}

void TableFill(QTableWidget *month, int64_t q, int64_t &day) {
    QColor holiday_color("#B68A1B");
    holiday_color.setAlpha(64);
    int j = 0;
    for (int i = 1; i <= q; ++i) {
        month->item(day, j)->setText(QString::number(i));
        if (day == 5 || day == 6) {
            month->item(day, j)->setBackgroundColor(holiday_color);
        }
        if ((++day %= 7) == 0) ++j;
    }
    return;
}
