#pragma once
#include "TrainSchedule.h"

class UserInterface
{
public:
	virtual void HandleUser() = 0;
	virtual ~UserInterface() {}
}; 