#pragma once

#include <gameplay/behaviors/Idle.hpp>
#include <QTime>

namespace Gameplay
{
	class PreventDoubleTouch
	{
	    public:
		PreventDoubleTouch(GameplayModule *gameplay, Behavior *kicker = 0);
		
		void assign(std::set<Robot *> &available);
		void run();
		
		bool keepRunning() const
		{
		    return _keepRunning;
		}
		
		bool kicked() const
		{
			return _kicked;
		}

	    protected:
		GameplayModule *_gameplay;
		Behavior *_kicker;
		Behaviors::Idle _backoff;
		bool _keepRunning;
		bool _kicked;
		bool _wasReady;
		QTime _ruleTime;
	};
}