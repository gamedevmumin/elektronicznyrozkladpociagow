#pragma once
#include "Train.h"

class Connection : public IStringable
{
private:
	Train train;
	std::string from;
	std::string to;
	int startingStationIndex;
	int lastStationIndex;
public:
	Connection(Train train, std::string from, std::string to) : train(train), from(from), to(to)
	{
		std::vector<TrainStop> trainStops = train.TrainStops();
		for (size_t i = 0; i < trainStops.size(); i++)
		{
			if (train.TrainStops()[i].Name() == from) startingStationIndex = i;
			if (train.TrainStops()[i].Name() == to) lastStationIndex = i;
		}
	}
	std::vector<TrainStop> GetTrainStopsFromStartingStation()
	{
		return std::vector<TrainStop>(train.TrainStops().begin() + startingStationIndex, train.TrainStops().end() + lastStationIndex);
	}
	Train Train() { return train; }
	std::string ToString() override
	{
		std::stringstream ss;
		std::vector<TrainStop> trainStops = train.TrainStops();
		if (trainStops.size() < (size_t)2) return "";
		ss << "From: " << trainStops[startingStationIndex].Name() << std::endl;
		ss << "To: " << trainStops[lastStationIndex].Name() << std::endl;
		ss << "Date: " << train.Date().ToString() << std::endl;
		ss << "Departure: " << trainStops[startingStationIndex].DepartureTime().ToString() << std::endl;
		ss << "Arrival: " << trainStops[lastStationIndex].ArrivalTime().ToString() << std::endl;
		return ss.str();
	}
};