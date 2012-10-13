/**
 * @file UnitBox.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _UNITBOX_H
#define _UNITBOX_H


#include "AbstractGameUnit.h"

class EBox;

class UnitBox :public AbstractGameUnit {
public:
    UnitBox(float width, float height, float density = 3.0f);
    void render();


protected:
    EBox *m_eBox;

};
#endif
