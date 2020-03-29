#pragma once
#include <fstream>
#include <iostream>
#include "ITrainScheduleLoader.h"

class FileTrainScheduleLoader : public ITrainScheduleLoader
{
private:
	std::string fileName;
public:
	FileTrainScheduleLoader(std::string fileName) : fileName(fileName) {}
	virtual std::vector<Train> LoadTrainSchedule() override
	{
		std::ifstream scheduleFile(fileName);
		if (scheduleFile.good() == false)
		{
			std::cout << "Can't find file " << fileName << std::endl;
			return std::vector<Train>();
		}
		std::string tmp;
		std::vector<Train> trains;
		std::string stationName;
		int platform;
		std::stringstream ss;
		while (!scheduleFile.eof())
		{
			scheduleFile >> tmp;
			if (tmp == "---Train---")
			{
				std::vector<TrainStop> trainStops;
				while (!scheduleFile.eof())
				{
					ss.clear();
					//station name
					std::getline(scheduleFile, tmp, ':');
					std::getline(scheduleFile, stationName);
					//platform
					std::getline(scheduleFile, tmp, ':');
					scheduleFile >> platform;
					//arrival time
					std::getline(scheduleFile, tmp, ':');
					int hour, minute;
					std::getline(scheduleFile, tmp, ':');					
					ss << tmp;
					ss >> hour;
					scheduleFile >> minute;
					Time arrivalTime(hour, minute);
					//departure time
					std::getline(scheduleFile, tmp, ':');					
					std::getline(scheduleFile, tmp);
					if (tmp == "last_station")
					{
						Time departureTime(hour, minute);							
						TrainStop trainStop(stationName, departureTime, arrivalTime, platform, true);
						trainStops.push_back(trainStop);						
						break;
					}
					ss << tmp;
					std::getline(ss, tmp, ':');
					hour = stoi(tmp);
					ss >> minute;
					Time departureTime(hour, minute);	
					TrainStop trainStop(stationName, departureTime, arrivalTime, platform, false);
					trainStops.push_back(trainStop);
					scheduleFile >> tmp;
				}
				Date date(10, 10, 10);
				Train train(date, trainStops);
				trains.push_back(train);
			}
		}
		scheduleFile.close();
		return trains;
	}
};
