#pragma once
#include "IConnectionSearcher.h"

class BasicConnectionSearcher : public IConnectionSearcher
{
public:
	virtual std::vector<Connection> Search(std::vector<Train> trains, std::string from, std::string to, size_t trainsToShowAmount = 4) override
	{
		std::vector<Connection> connections;
		for (size_t i = 0; i < trains.size(); i++)
		{
			if (trains[i].DoesTravelFromTo(from, to))
			{
				Connection connection(trains[i], from, to);
				connections.push_back(connection);				
			}
			if (connections.size() >= trainsToShowAmount)
			{
				return connections;
			}
		}
		
		return connections;
	}
	virtual std::vector<Connection> Search(std::vector<Train> trains, std::string from, Time departureTime, size_t trainsToShowAmount = 4) override
	{
		std::vector<Connection> connections;
		for (size_t i = 0; i < trains.size(); i++)
		{
			if (trains[i].DoesDepartureAfter(from, departureTime))
			{
				Connection connection(trains[i], from, trains[i].GetLastStationName());
				connections.push_back(connection);
			}
			if (connections.size() >= trainsToShowAmount)
			{
				return connections;
			}
		}
		return connections;
	}
};