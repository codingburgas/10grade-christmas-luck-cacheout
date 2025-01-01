#ifndef SETEXPLORER_H
#define SETEXPLORER_H

#include <QDialog>
#include "lib/pageHandler.h"

namespace Ui {
class SetExplorer;
}

class SetExplorer : public QDialog {
    Q_OBJECT

public:
    explicit SetExplorer(QWidget *parent = nullptr);
    ~SetExplorer();
    void actionHandler(PageBools& pages);

signals:
    void pageStateChanged();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::SetExplorer *ui;
    void displaySetExplorer();
};

#endif // SETEXPLORER_H
