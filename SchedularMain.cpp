#include"Schedular.h"
int main()
{
	const int SIZE = 3;
	const int TIMEQUANTUM = 5;
	Process arr[SIZE] = { Process(1,"notepad",20),Process(2,"Mp3 Player",5),Process(3,"Chrome",30)};
	Schedular s(arr, SIZE, TIMEQUANTUM);
	s.assignProcessor();
	/*Queue<int> q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);
	q.enQueue(6);
	q.enQueue(7);
	q.enQueue(8);
	cout << q.getNumberOfElements()<<'\n';
	cout << q.deQueue() << "\n";
	cout << q.deQueue() << "\n";
	cout << q.deQueue() << "\n";
	cout << q.deQueue() << "\n";
	cout << q.deQueue() << "\n";
	cout << q.deQueue() << "\n";
	cout << q.deQueue() << "\n";
	cout << q.deQueue() << "\n";*/

	return 0;
}