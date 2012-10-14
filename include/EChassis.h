/**
 * @file EChassis.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _ECHASSIS_H
#define _ECHASSIS_H


#include "AbstractGameEntity.h"

class EChassis : public AbstractGameEntity {
public:
    EChassis(float width, float height, float density = 3.0f);

    float getWidth();
    float getHeight();

    b2Body* getBody();


protected:
    float m_width;
    float m_height;
    float m_density;
};
#endif
