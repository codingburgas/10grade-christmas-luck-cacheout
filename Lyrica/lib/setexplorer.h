#ifndef SETEXPLORER_H
#define SETEXPLORER_H

#include <QDialog>

namespace Ui {
class SetExplorer;
}

class SetExplorer : public QDialog {
    Q_OBJECT

public:
    explicit SetExplorer(QWidget *parent = nullptr);
    ~SetExplorer();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::SetExplorer *ui;
};

#endif // SETEXPLORER_H
