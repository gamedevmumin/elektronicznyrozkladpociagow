#pragma once
#include <sstream>
#include "IStringable.h"

class Time : public IStringable
{
private:
	int hour;
	int minute;
public:
	Time() : hour(0), minute(0) {}
	Time(int _hour, int _minute)
	{
		hour = _hour;
		minute = _minute;
		if (hour < 0 || hour > 23) hour = 0;
		if (minute < 0 || minute > 59) minute = 0;
	}
	Time(std::string time)
	{
		std::string tmp;
		std::stringstream ss;
		ss << time;
		std::getline(ss, tmp, ':');
		hour = stoi(tmp);
		ss >> minute;
		if (hour < 0 || hour > 23) hour = 0;
		if (minute < 0 || minute > 59) minute = 0;
	}
	std::string ToString() override
	{
		std::stringstream time;
		if (hour < 10) time << "0";
		time << hour << ":";
		if (minute < 10) time << "0";
		time << minute;
		return time.str();

	}

	bool operator== (const Time& other) const
	{
		return (other.hour == hour) && (other.minute == minute);
	}

	bool operator!= (const Time& other) const
	{
		return (other.hour != hour) || (other.minute != minute);
	}

	bool operator>= (const Time& other) const
	{
		if (hour > other.hour) return true;
		if (hour == other.hour)
		{
			return minute >= other.minute;
		}
		else return false;
	}

	bool operator<= (const Time& other) const
	{
		if (hour < other.hour) return true;
		if (hour == other.hour)
		{
			return minute <= other.minute;
		}
		else return false;
	}

	bool operator< (const Time& other) const
	{
		if (hour < other.hour) return true;
		if (hour == other.hour)
		{
			return minute < other.minute;
		}
		else return false;
	}

	bool operator> (const Time& other) const
	{
		if (hour > other.hour) return true;
		if (hour == other.hour)
		{
			return minute > other.minute;
		}
		else return false;
	}
};