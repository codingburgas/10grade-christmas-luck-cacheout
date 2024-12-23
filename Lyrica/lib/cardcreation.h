#ifndef CARDCREATION_H
#define CARDCREATION_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class cardCreation;
}

class cardCreation : public QDialog
{
    Q_OBJECT

public:
    explicit cardCreation(QWidget *parent = nullptr);
    ~cardCreation();

private:
    Ui::cardCreation *ui;
};

#endif // CARDCREATION_H
