#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QPixmap>
namespace Ui {
class dashboard;
}

class dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();

private:
    Ui::dashboard *ui;
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // DASHBOARD_H
