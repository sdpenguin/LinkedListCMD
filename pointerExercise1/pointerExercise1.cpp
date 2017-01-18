// pointerExercise1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <windows.h>
using namespace std;

struct linkedList
{
	string data;
	linkedList* next;
};

int main()
{
	int numberOfLLItems;
	cin >> numberOfLLItems;

	linkedList* myLL = NULL;
	//set the pointer to be to the linked list's end element'

	for (int i = 1; i <= numberOfLLItems; i++)
	{
		cout << "Enter your " << i << "th piece of data...";
		string currentData;
		cin >> currentData;

		linkedList* temp = new linkedList;
		//create a new linkedList element

		temp->data = currentData;
		temp->next = myLL;

		myLL = temp;
		//myLL points to the most recently created entry (NULL at first)
	}
	

	cout << endl;
	linkedList* firstElement = myLL; //myLL and temp both point to the first element in the LL
	cout << "The first element in the list is at address " << firstElement << "\n";
	Sleep(2000);

	int elementAccess;
	bool loop = true;

	while (loop == true)
	{
		cout << "Which element would you like to access?\n";
		cin >> elementAccess;
		int i = 1; //i is a counter for the puroposes of accessing the i'th item
		linkedList* temp = firstElement;

		if (0 < elementAccess <= numberOfLLItems)
		{
			while (i <= elementAccess)
			{
				if (i == elementAccess)
				{
					cout << "The value of element " << elementAccess << " is " << temp->data << "\n";
				}
				i++;
				temp = temp->next;
			}
		}
		else
		{
			cout << "That item was never created. Could be that you have input a number too large, or that your input is not a number.\n";
		}

		Choice:
		cout << "Continue (y/n)? ";
			string choice;
		cin >> choice;
		
		if (choice == "y")
		{
			loop = true;
		}
		else if (choice == "n")
		{
			loop = false;
		}
		else
		{
			cout << "\nPlease reenter your choice...\n";
				goto Choice;
		}

		Sleep(2000);
	}
}

