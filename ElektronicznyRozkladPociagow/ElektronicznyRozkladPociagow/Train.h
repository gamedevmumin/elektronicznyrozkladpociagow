#pragma once
#include <vector>
#include <map>
#include "Date.h"
#include "Time.h"
#include "TrainStop.h"

class Train : public IStringable
{
private:
	Date date;
	std::vector<TrainStop> trainStops;
public:
	Train(Date _date, std::vector<TrainStop> _trainStops)
	{
		date = _date;
		trainStops = _trainStops;
	}

	std::string ToString() override
	{
		std::stringstream ss;
		if (trainStops.size() < (size_t)2) return "";
		ss << "From: " << trainStops[0].Name() << std::endl;
		ss << "To: " << trainStops[trainStops.size() - 1].Name() << std::endl;
		ss << "Date: " << date.ToString() << std::endl;
		ss << "Departure: " << trainStops[0].DepartureTime().ToString() << std::endl;
		ss << "Arrival: " << trainStops[trainStops.size() - 1].ArrivalTime().ToString() << std::endl;
		return ss.str();
	}

	bool DoesTravelFromTo(std::string from, std::string to)
	{
		bool travelsFrom = false;
		bool travelsTo = false;
		for (size_t i = 0; i < trainStops.size(); i++)
		{
			if (travelsFrom == false)
			{
				if (trainStops[i].Name() == from) travelsFrom = true;
			}
			else if (travelsTo == false) 
			{
				if (trainStops[i].Name() == to)
				{
					travelsTo = true;
					break;
				}
			}
		}
		return travelsFrom && travelsTo;
	}
	bool DoesDepartureAfter(std::string from, Time time)
	{
		for (size_t i = 0; i < trainStops.size(); i++)
		{
			if (trainStops[i].Name() == from)
			{
				return trainStops[i].DepartureTime() >= time;
			}
		}
		return false;
	}
	std::string GetLastStationName()
	{
		return trainStops[trainStops.size() - 1].Name();
	}
	std::vector<TrainStop> TrainStops() { return trainStops; }
	Date Date() { return date; }
};

