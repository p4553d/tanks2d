/**
 * @file EBox.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _EBOX_H
#define _EBOX_H


#include "AbstractGameEntity.h"

class EBox : public AbstractGameEntity{
public:
    EBox(float width, float height, float density = 3.0f);


protected:
    float m_width;
    float m_height;
    float m_density;

};
#endif
