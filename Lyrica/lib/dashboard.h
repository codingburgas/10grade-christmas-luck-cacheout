#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QPixmap>
#include "lib/pageHandler.h"
#include "BLL/lib/credentials.h"

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
    void displayDashboard();

signals:
    void pageStateChanged();

private:
    Ui::dashboard *ui;
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // DASHBOARD_H
