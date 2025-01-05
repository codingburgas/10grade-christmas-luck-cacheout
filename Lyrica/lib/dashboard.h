#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QPixmap>
#include "lib/pageHandler.h"
#include "BLL/lib/credentials.h"
#include "../BLL/lib/customset.h"
#include "../BLL/lib/readySets.h"
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
    void displayReadySets(int cardNum);
    void displayCustomSets(int cardNum);
    bool eventFilter(QObject *obj, QEvent *event) override;
    bool setsGroup1 = true;
    bool setsGroup2 = false;
    bool setsGroup3 = false;
    bool customSetsGroup1 = true;
    bool customSetsGroup2 = false;
    bool customSetsGroup3 = false;

};

#endif // DASHBOARD_H
