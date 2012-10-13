/**
 * @file TeamMind.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _TEAMMIND_H
#define _TEAMMIND_H

#include "ITeamMind.h"

class TeamMind : public ITeamMind {
public:
    virtual void notify();

};
#endif
