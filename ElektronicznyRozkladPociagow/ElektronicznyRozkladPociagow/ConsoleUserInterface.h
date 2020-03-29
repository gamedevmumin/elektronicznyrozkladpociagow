#pragma once
#include <iostream>
#include "UserInterface.h"
#include "IConnectionSearcher.h"

class ConsoleUserInterface : public UserInterface
{
	bool isRunning;
	TrainSchedule* trainSchedule;
	IConnectionSearcher* connectionSearcher;
public:
	ConsoleUserInterface(TrainSchedule* _trainSchedule, IConnectionSearcher* _connectionSearcher) : isRunning(true)
	{
		trainSchedule = _trainSchedule;
		connectionSearcher = _connectionSearcher;
	}
	~ConsoleUserInterface()
	{
		delete trainSchedule;
		trainSchedule = nullptr;
		delete connectionSearcher;
		connectionSearcher = nullptr;
	}
	virtual void HandleUser() override
	{
		std::string from, to;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Welcome to Electronic Train Schedule" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		while (isRunning)
		{
			std::cout << "Please, fill the form" << std::endl;
			std::cout << "From: ";
			getline(std::cin, from);
			std::cout << "To: ";
			getline(std::cin, to);
			std::vector<Connection> connections = connectionSearcher->Search(trainSchedule->Trains(), from, to);
			std::string s_time;
			std::cout << "Departure Time (hh:mm): ";
			std::cin >> s_time;
			Time time(s_time);
			std::vector<Train> trains;
			for (size_t i = 0; i < connections.size(); i++)
			{
				trains.push_back(connections[i].Train());
			}
			connections = connectionSearcher->Search(trains, from, time);
			std::cout << std::endl;
			for (size_t i = 0; i < connections.size(); i++)
			{
				std::cout<< connections[i].ToString();
				std::cout << std::endl;
			}
			if (connections.size() == 0) std::cout << "No results..." << std::endl << std::endl;
			std::cout << "Do you want to finish here? y/n" << std::endl;
			char decision;
			std::cin >> decision;
			getchar();
			if (decision == 'y') isRunning = false;
			std::cin.clear();
		}
	}
};