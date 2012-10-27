/**
 * @file Team.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _TEAM_H
#define _TEAM_H

#include "ITeam.h"


enum TeamID {
    TEAM_RED,
    TEAM_BLUE,
    TEAM_GREY,
    TEAM_NON_COMBAT

};

class TeamMind;

class Team : public ITeam {
protected:
    TeamMind * m_teamMind;

};
#endif
