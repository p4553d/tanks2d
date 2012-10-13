/**
 * @file UnitGround.cpp
 * @author user p4553d
 */


#include "UnitGround.h"
#include "EGround.h"

UnitGround::UnitGround() {
    m_eGround = new EGround();
    b2Color gc (0.1, 0.8, 0.6);
    m_eGround->setColor(gc);
}

void UnitGround::render(){
    m_eGround->render();
}
