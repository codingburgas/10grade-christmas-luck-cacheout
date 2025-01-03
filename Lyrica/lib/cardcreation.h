#ifndef CARDCREATION_H
#define CARDCREATION_H

#include <QDialog>
#include <QPixmap>
#include "../models/user.h"
#include "../models/customset.h"
#include "../models/card.h"
namespace Ui {
class cardCreation;
}

class cardCreation : public QDialog
{
    Q_OBJECT

public:
    explicit cardCreation(QWidget *parent = nullptr);
    ~cardCreation();

private slots:

    void on_submit_clicked();

private:
    Ui::cardCreation *ui;
    customSet currentSet;
    int numOfCards;
};

#endif // CARDCREATION_H
