/**
 * @file UnitBox.cpp
 * @author user p4553d
 */

#include "UnitBox.h"
#include "EBox.h"

UnitBox::UnitBox(float width, float height, float density) {
    m_eBox = new EBox(width, height, density);
    b2Color w (1,0,0);
    m_eBox->setColor(w);
}

void UnitBox::render(){
    m_eBox->render();
}

void UnitBox::teleportTo(float x, float y){
    m_eBox->teleportTo(x,y);
}
