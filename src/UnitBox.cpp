/**
 * @file UnitBox.cpp
 * @author user p4553d
 */

#include "UnitBox.h"
#include "EBox.h"

UnitBox::UnitBox(float width, float height, float density) {
    m_eBox = new EBox(width, height, density);
    b2Color w (1,1,1);
    m_eBox->setColor(w);
}

void UnitBox::render(){
    m_eBox->render();
}
