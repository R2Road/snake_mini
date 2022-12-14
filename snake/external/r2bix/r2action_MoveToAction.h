#pragma once

#include "r2base_Action.h"

#include "r2/r2_PointInt.h"
#include "r2/r2_TimerFloat.h"

namespace r2action
{
	class MoveToAction : public r2base::Action
	{
	private:
		MoveToAction();

	public:
		static std::unique_ptr<MoveToAction> Create();

		//
		//
		//
		void Enter() override;
		bool Update( const float delta_time ) override;

		//
		//
		//
		void SetEndPoint( const r2::PointInt end_point )
		{
			mEndPoint = end_point;
		}
		void SetTimeLimit( const float time_limit )
		{
			mTimer.SetLimitTime( time_limit );
		}

	private:
		r2::PointInt mMoveAmount;

		r2::PointInt mStartPoint;
		r2::PointInt mEndPoint;
		r2::TimerFloat mTimer;
	};
}