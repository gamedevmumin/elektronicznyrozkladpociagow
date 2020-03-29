#pragma once
#include "Train.h"
#include "Connection.h"

class IConnectionSearcher
{
public:
	virtual std::vector<Connection> Search(std::vector<Train> trains, std::string from, std::string to, size_t trainsToShowAmount = 4) = 0;
	virtual std::vector<Connection> Search(std::vector<Train> trains, std::string from, Time departureTime, size_t trainsToShowAmount = 4) = 0;
	virtual ~IConnectionSearcher() {};
};