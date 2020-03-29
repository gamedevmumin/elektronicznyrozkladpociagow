#pragma once
#include "Train.h"

class ITrainScheduleLoader
{
public:
	virtual std::vector<Train> LoadTrainSchedule() = 0;
	virtual ~ITrainScheduleLoader() {}
};

