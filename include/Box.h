/**
 * @file Box.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _BOX_H
#define _BOX_H


#include "AbstractGameEntity.h"
#include "AbstractGameUnit.h"

class UnitBox : public AbstractGameEntity, public AbstractGameUnit {
public:
    UnitBox(float width, float height, float density = 3.0f);

    virtual ~UnitBox();

    void render();


protected:
    float m_width;

    float m_height;

    float m_density;

};
#endif
