#pragma once
#include "Date.h"
#include "Time.h"

class TrainStop
{
private:
	std::string name;
	Time arrivalTime;
	Time departureTime;
	int platform;
	bool isLastStation;
public:
	TrainStop(std::string _name, Time _departureTime, Time _arrivalTime, int _platform, bool _isLastStation)
	{
		name = _name;
		arrivalTime = _arrivalTime;
		departureTime = _departureTime;
		platform = _platform;
		isLastStation = _isLastStation;
	}
	TrainStop(const TrainStop& trainStop)
	{
		name = trainStop.name;
		arrivalTime = trainStop.arrivalTime;
		departureTime = trainStop.departureTime;
		platform = trainStop.platform;
	}
	Time DepartureTime() { return departureTime; }
	Time ArrivalTime() { return arrivalTime; }
	std::string Name() { return name;  }
	int Platform() { return platform; }
	bool IsLastStation() { return isLastStation; }
};
