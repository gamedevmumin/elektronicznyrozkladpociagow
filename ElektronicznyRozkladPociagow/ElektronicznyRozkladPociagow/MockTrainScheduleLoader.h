#pragma once
#include "ITrainScheduleLoader.h"

class MockTrainScheduleLoader : public ITrainScheduleLoader
{
public:
	virtual std::vector<Train> LoadTrainSchedule() override
	{
		std::vector<Train> trains;
		std::string stacjeKoncowe[] = { "Katowice", "Gdansk", "Warszawa", "Krakow", "Opole Glowne" };
		for (int i = 0; i < 5; i++)
		{
			Time arrivalTime(12+i, 37+i*2);
			Time departureTime(12+i, 41+i*2);
			Date date(29, 12, 2019);
			std::vector<TrainStop> trainStops;
			TrainStop ts("Strzelce Opolskie", departureTime, arrivalTime, 2, false);
			trainStops.push_back(ts);
			Time arrivalTime1(13+i, 15);
			Time departureTime1(13+i, 20);
			TrainStop ts2(stacjeKoncowe[i], departureTime1, arrivalTime1, 2, true);
			trainStops.push_back(ts2);
			Train train(date, trainStops);
			trains.push_back(train);
		}
		return trains;
	}
};