#ifndef PRACTICEWINDOW_H
#define PRACTICEWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QEvent>
#include <QPixmap>
#include <QFontDatabase>
#include <QTransform>
#include "lib/pageHandler.h"

namespace Ui {
class PracticeWindow;
}

class PracticeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PracticeWindow(QWidget *parent = nullptr);
    ~PracticeWindow();
    void actionHandler(PageBools& pages);

signals:
    void pageStateChanged();

private:
    Ui::PracticeWindow *ui;
    void DisplayPracticeWindow();
    bool eventFilter(QObject *obj, QEvent *event) override;
    bool finalCard = true;
};

#endif // PRACTICEWINDOW_H
