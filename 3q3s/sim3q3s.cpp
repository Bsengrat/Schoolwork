//****************************************************************************************************
//
//		File:					sim3q3s.cpp
//		
//		Student:				Bently Sengrath
//
//		Assignment:	 			Program  # 13
//
//		Course Name:			Data Structures   I 
//
//		Course Number:			COSC 3050 - 01
//
//		Due:					Dec 16, 2019
//
//
//		This program create a simluation with three queues and three servers.
//		 
//		
//****************************************************************************************************

#include<iostream>
#include<fstream>
using namespace std;
#include "Queue.h"
#include "customer.h"
#include "Server.h"


int fillCustomerArray(Customer a[100]);
int findMinQ(Queue <Customer> q[3], Server s[3]);
void processCustomers(Customer a[100], Queue<Customer> q[3], Server s[3], const int & totalCust, 
									int & currCust, int time, ofstream & trace);
void processServers(Queue<Customer> q[3], const int & time, Server serv[3], ofstream & fout);
bool isAllDone(Queue <Customer>  q[3], Server serv[3], const int & time, const int & totalCust);

//****************************************************************************************************

int main()
{
	int time = -1,
		totalCust = 0,
		currCust = 0;
	Customer  cust[100];
	Server serv[3];
	Queue <Customer> q[3];

	ofstream trace("trace.txt");

	totalCust = fillCustomerArray(cust);

	while (!isAllDone(q, serv, currCust, totalCust))
	{
		time++;
		processCustomers(cust, q, serv, totalCust, currCust, time, trace);
		processServers(q, time, serv, trace);
	}

	trace.close();
	cout << "All customers procesed in " << time << " minutes" << endl;

	return 0;
}

//****************************************************************************************************

int fillCustomerArray(Customer cust[100])
{
	int count = 0,
		temp;
	fstream fin;

	fin.open("customerList.txt");

	if (!fin.fail())
	{
		while (fin >> temp)
		{
			cust[count].id = temp;
			fin >> temp;
			cust[count].arrivalTime = temp;
			fin >> temp;
			cust[count].serviceTime = temp;
			count++;
		}

	}

	fin.close();

	return count;
}

//****************************************************************************************************

int findMinQ(Queue <Customer> q[3], Server s[3])
{
	const int size = 3;
	int minQ = 0;
	int qsize[size];

	for (int i = 0; i < size; i++)
	{
		qsize[i] = q[i].getNumValues();

		if (s[i].busy)
		{
			qsize[i]++;
		}
	}

	if (qsize[minQ] > qsize[1])
	{
		minQ = 1;
	}

	if (qsize[minQ] > qsize[2])
	{
		minQ = 2;
	}

	return minQ;
}

//****************************************************************************************************

void processCustomers(Customer cust[100], Queue <Customer> q[3], Server s[3],  const int & totalCust, 
			int & currCust, int time, ofstream & trace)
{
	int minQ;

	trace << "t = " << time << endl;

	while ((currCust <= totalCust) && (cust[currCust].arrivalTime == time))
	{

		minQ = findMinQ(q, s);
		q[minQ].enqueue(cust[currCust]);
		trace << "cust-id #" << cust[currCust].id << "added to Q" << endl;
		currCust++;
	}

}

//****************************************************************************************************

void processServers(Queue<Customer> q[3], const int & time, Server serv[3], ofstream & trace)
{
	Customer temp;

	for (int i = 0; i < 3; i++)
	{
		if ((serv[i].busy == false) || serv[i].endTime == time)
		{

			if (q[i].dequeue(temp))
			{

				serv[i].custid = temp.id;
				serv[i].endTime = (time + temp.serviceTime);
				serv[i].busy = true;

				trace << 'S' << i << " start serving cust-id #" << temp.id << ","
					<< " service length = " << temp.serviceTime << ","
					<< " service ends at t = " << serv[i].endTime << endl;

			}
			else
			{
				serv[i].busy = false;
				trace << "S" << i << " is not busy" << endl;
			}
		}
		else
		{
			trace << "S" << i << " serving cust-id until t = " << serv[i].endTime << endl;
		}
	}
	trace << endl;

}

//****************************************************************************************************

bool isAllDone(Queue <Customer> q[3], Server serv[3], const int & currCust, const int & totalCust)
{
	return ((totalCust == currCust) && (q[0].isEmpty()) && (q[1].isEmpty()) && (q[2].isEmpty()) 
				&& !(serv[0].busy) && !(serv[1].busy) && !(serv[2].busy));
}

//****************************************************************************************************

/*
All customers procesed in 85 minutes

C:\C++\Assignement13\Debug\Assignement13.exe (process 16852) exited with code 0.
Press any key to close this window . . .

*/