#ifndef PRACTICEWINDOW_H
#define PRACTICEWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QEvent>
#include <QPixmap>
#include <QFontDatabase>
#include <QTransform>

namespace Ui {
class PracticeWindow;
}

class PracticeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PracticeWindow(QWidget *parent = nullptr);
    ~PracticeWindow();
    void DisplayPracticeWindow();

private:
    Ui::PracticeWindow *ui;
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // PRACTICEWINDOW_H
