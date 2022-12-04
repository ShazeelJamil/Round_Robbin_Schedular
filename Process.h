#ifndef PROCESS_H
#define PROCESS_H
#include<iostream>
#include<string.h>
using namespace std;
class Process
{
public:
	int processId;
	string processName;
	int processExecTime;
	Process(int id = 1, string pName = "notepad", int burstTime = 10) :
		processId(id), processName(pName), processExecTime(burstTime)
	{ }
};
#endif // !PROCESS_H
