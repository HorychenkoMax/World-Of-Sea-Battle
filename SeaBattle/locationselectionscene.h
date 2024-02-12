#ifndef LOCATIONSELECTIONSCENE_H
#define LOCATIONSELECTIONSCENE_H

#include "battlefieldscene.h"

class LocationSelectionScene : public BattlefieldScene
{
public:
    explicit LocationSelectionScene(QObject *parent = nullptr);

private:
    void drawShips();
};

#endif // LOCATIONSELECTIONSCENE_H
