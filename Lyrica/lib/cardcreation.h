#ifndef CARDCREATION_H
#define CARDCREATION_H

#include <QDialog>
#include <QPixmap>
#include <iostream>
#include <QObject>
#include "lib/pageHandler.h"
#include "BLL/lib/customset.h"

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

    void submitClicked();
    void doneClicked();

    customSet currentSet;
    customSetTitle currentTitle;

    int numOfCards;
    int numOfTitles;
};

#endif // CARDCREATION_H
