#pragma once
#include "Train.h"
#include "ITrainScheduleLoader.h"


class TrainSchedule : public IStringable
{
	std::vector<Train> trains;
	ITrainScheduleLoader* trainScheduleLoader;
public:
	TrainSchedule(ITrainScheduleLoader* _trainScheduleLoader) 
	{
		trainScheduleLoader = _trainScheduleLoader;
		trains = trainScheduleLoader->LoadTrainSchedule();
	}
	~TrainSchedule()
	{
		delete trainScheduleLoader;
		trainScheduleLoader = nullptr;
	}

	std::vector<Train> Trains()
	{
		return trains;
	}

	virtual std::string ToString() override
	{
		std::stringstream schedule;
		for (size_t i = 0; i < trains.size(); i++)
		{
			schedule << trains[i].ToString();
			schedule << std::endl;
		}
		return schedule.str();
	}

};