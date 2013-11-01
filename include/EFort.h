/**
 * @file EFort.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _EFORT_H
#define _EFORT_H


#include "AbstractGameEntity.h"

class EFort : public AbstractGameEntity {
    public:
        EFort (float width, float height);

        float getWidth();
        float getHeight();

        b2Body* getBody();

    private:
        float m_width;
        float m_height;
};
#endif
