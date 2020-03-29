#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "Date.h"
#include "Time.h"
#include "Train.h"
#include "TrainSchedule.h"
#include "MockTrainScheduleLoader.h"
#include "FileTrainScheduleLoader.h"
#include "BasicConnectionSearcher.h"
#include "ConsoleUserInterface.h"



int main()
{	{
		TrainSchedule* trainSchedule = new TrainSchedule(new FileTrainScheduleLoader("schedule.txt"));
		UserInterface* userInterface = new ConsoleUserInterface(trainSchedule, new BasicConnectionSearcher());
		userInterface->HandleUser();
		delete userInterface;
	}
	
	_CrtDumpMemoryLeaks();
	return 0;
}
