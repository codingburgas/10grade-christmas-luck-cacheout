#ifndef PRACTICEWINDOW_H
#define PRACTICEWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QEvent>
#include <QPixmap>
#include <QFontDatabase>
#include <QTransform>
#include "lib/pageHandler.h"
#include "BLL/lib/readySets.h"
#include "BLL/lib/customset.h"
#include "lib/finalwindow.h"

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
    void resetPracticeWindow();

signals:
    void pageStateChanged();

private:
    Ui::PracticeWindow *ui;
    void DisplayPracticeWindow();
    void displayReadySet();
    void displayCustomSet();

    bool finalCard;
};

#endif // PRACTICEWINDOW_H
