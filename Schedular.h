#ifndef SCHEDULAR_H
#define SCHEDULAR_H
#include"Process.h"
#include"Queue_implementation.cpp"
class Schedular
{
	Process* processArray;
	int processArayLenght;
	int timeQuantum;
public:
	Schedular(Process* p, int lenght, int quantum)
	{
		processArray = p;
		processArayLenght = lenght;
		timeQuantum = quantum;
	}
	void assignProcessor()
	{
		Queue<Process> pQ;
		for (int i = 0; i < processArayLenght; i++)
			pQ.enQueue(processArray[i]);
		while (!pQ.isEmpty())
		{
			Process temp = pQ.deQueue();
			cout << "\nCurrently Running Process->>>\nProcess Name :" << temp.processName
				<< "\nProcess Id : " << temp.processId
				<< "\nProcess Remaining Execution Time : " << temp.processExecTime;
			int count = 0, ctime = temp.processExecTime;
			while (count < timeQuantum && count < ctime)
			{
				temp.processExecTime--;
				count++;
			}
			if (temp.processExecTime > 0)
				pQ.enQueue(temp);
			else
				cout <<'\n' << temp.processName << ", " << temp.processId << " completed successfully.\n";
			cout << "\n--------New Process-------\n";
		}
		cout << "\nAll Process executed Successfully!";
	}
};

#endif // !SCHEDULAR_H
