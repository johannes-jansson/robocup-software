/*
 * TestPassPlay.hpp
 *
 *  We perform three basic steps to implement a pass:
 *    1.) Generate high-level analytic plan(s)
 *    2.) Optimize high-level plan(s), considering constraints and opponents
 *    3.) Underlying planner - low-level behaviors
 *          Actually executes plan
 *
 *  Currently, this is under development and should not be used.
 *
 *  Current goal: dump solution to screen with a limit of 2 robots
 *
 *
 *  Created on: Nov 29, 2009
 *      Author: Philip Rogers
 *      Author:
 */

#pragma once

#include <iostream>
#include <fstream>
#include "../../Play.hpp"
#include "PassState.hpp"
#include "PassConfig.hpp"
#include <gameplay/behaviors/positions/Fullback.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/foreach.hpp>
#include <vector>

typedef boost::ptr_vector<PassConfig> PassConfigVector;

using namespace std;

#define APPROXBALLVEL 20.0       // m/s
#define APPROXROBOTVELTRANS 1.0  // m/s
#define APPROXROBOTVELROT 4.0    // rad/s

namespace Gameplay{
	namespace Plays{
		class TestPassPlay: public Play{
			public:
				TestPassPlay(GameplayModule *gameplay);

				virtual bool applicable(){return true;}

				virtual void assign(std::set<Robot *> &available);

				virtual bool run();

			protected:
				void initializePlan();

				// passing system state
				enum State{Initializing,Optimizing,Executing,Done};
				State _passState;

				PassConfigVector initialPlans;
		};
	}
}