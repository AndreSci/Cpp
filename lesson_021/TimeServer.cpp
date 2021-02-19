#include <iostream>
#include <exception>
#include <string>

using namespace std;


class TimeServer {
public:
	string GetCurrentTime() {
		try
		{
			string Time;
			Time = AskTimeServer();
			return LastFetchedTime = Time;
		}
		catch (system_error&)
		{
			return LastFetchedTime;
		}
		catch (...) 
		{
			throw;
		}	
	}

private:
	string LastFetchedTime = "00:00:00";
};
