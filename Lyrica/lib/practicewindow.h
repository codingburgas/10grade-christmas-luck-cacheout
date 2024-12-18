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

class HoverLabel : public QLabel {
    Q_OBJECT
public:
    explicit HoverLabel(QWidget *parent = nullptr);

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
};

class PracticeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PracticeWindow(QWidget *parent = nullptr);
    ~PracticeWindow();
    void DisplayPracticeWindow();

private:
    Ui::PracticeWindow *ui;
    HoverLabel *flashCardHover;
};


#endif // PRACTICEWINDOW_H
