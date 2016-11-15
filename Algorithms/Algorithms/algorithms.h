#pragma once
#include <iostream>
#include <cstdlib>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

namespace point
{
	using namespace chrono;
	/*double run_time(steady_clock::time_point t1, steady_clock::time_point t2)
	{
		auto t = abs(t1 - t2);
		return duration_cast<duration<double>>(t).count();
	}*/
}