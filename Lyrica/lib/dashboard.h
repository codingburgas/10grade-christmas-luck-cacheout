#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QPixmap>
#include "lib/pageHandler.h"

namespace Ui {
class dashboard;
}

class dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();
    void actionHandler(PageBools& pages);

signals:
    void pageStateChanged();

private:
    Ui::dashboard *ui;
    void displayDashboard();
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // DASHBOARD_H
