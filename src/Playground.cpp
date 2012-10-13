/**
 * @file Playground.cpp
 * @author user p4553d
 */


#include "Playground.h"
#include "AbstractGameUnit.h"
#include "Config.h"
#include "Log.h"
#include "Team.h"
#include "ITeam.h"

Playground::~Playground() {
}

void Playground::registerEntity(AbstractGameUnit * agu) {
// Obsolete?
}

void Playground::step() {
}

// Simple decoration of box2d interface

// Simple decoration of box2d interface

b2Body * Playground::createBody(const b2BodyDef * def) {
}

// create physical body
b2Joint * Playground::createJoint(const b2JointDef * def) {
}

// create joint
void Playground::destructBody(b2Body * b) {
}

// destruct body
Playground::Playground() {
}

Playground::Playground(const Playground & ) {
}

Playground & Playground::operator =(const Playground & ) {
}

const float32 Playground::sm_timeStep;

const int32 Playground::sm_velocityIterations;

const int32 Playground::sm_positionIterations;

void Playground::registerTeam(const Team & team) {
}

