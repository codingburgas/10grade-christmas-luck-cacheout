#ifndef CARDCREATION_H
#define CARDCREATION_H

#include <QDialog>
#include <QPixmap>
#include <iostream>
#include <QObject>
#include "lib/pageHandler.h"
#include "BLL/lib/customset.h"
#include "DAL/lib/files.h"

namespace Ui {
class cardCreation;
}

class cardCreation : public QDialog
{
    Q_OBJECT

public:
    explicit cardCreation(QWidget *parent = nullptr);
    ~cardCreation();
    void actionHandler(PageBools& pages);

signals:
    void pageStateChanged();

private:
    Ui::cardCreation *ui;
    customCard newCard;

    void submitClicked();
    void doneClicked();
    void cardCreationHandler();

    int numOfCards;
    int numOfTitles;
};

#endif // CARDCREATION_H
