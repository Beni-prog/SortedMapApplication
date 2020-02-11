#include <iostream>
#include "SortedMap.h"
#include "SMIterator.h"
#include "SMTests.h"

using namespace std;

bool function(TKey k1, TKey k2)
{
	return k1 <= k2;
}

int main() 
{
	testSM();

	SortedMap sm(function);

	sm.add(116, "Pop Ioan");
	sm.add(115, "Boteanu Laura");
	sm.add(113, "Andronic Tudor");
	sm.add(114, "Boca Paul");
	sm.add(156, "Ventuneac Andrei");
	sm.add(111, "Policiuc Robert");
	sm.add(118, "Gurita Stefan");
	sm.add(119, "Penciuc Danut");
	sm.add(112, "Chuck Norris");


	cout << "1. Add a participant." << endl;
	cout << "2. Search for a participant." << endl;
	cout << "3. Remove a participant." << endl;
	cout << "4. Show all the participants." << endl;
	cout << "5. Give me the total number of the participants." << endl;
	cout << "6. Get the density of the tree." << endl;
	cout << "0. Exit." << endl;
	
	while (true)
	{
		int command;
		cout << "Give me a command: ";
		cin >> command;
		if (command == 1)
		{
			int id; std::string name;
			cout << "Give me an ID: ";
			cin >> id;
			cin.ignore();
			cout << "Give me a name: ";
			std::getline(cin, name);
			TValue string = sm.add(id, name);
			if(string!=" ")
			   cout<<"The oldvalue of this ID was: "<<string<<endl;
			
		}
		if (command == 2)
		{
			int id; std::string name;
			cout << "Give me an ID: ";
			cin >> id;
			cin.ignore();

			TValue string = sm.search(id);
			if (string != " ") {
				cout <<"The value of this ID is: "<<string << endl;
			}
			else
				cout << "The participant was not found! Please try another ID!" << endl;

		}
		if (command == 3)
		{
			int id; std::string name;
			cout << "Give me an ID: ";
			cin >> id;
			cin.ignore();

			TValue string = sm.remove(id);
			if (string != "Not found!")
				cout << "The value of the removed element was: " << string<<endl;
			else
				cout << string<<endl;

		}
		if (command == 4)
		{
			SMIterator it = sm.iterator();
			while (it.valid())
			{
				TElem participant = it.getCurrent();
				cout << "The participant has the ID " << participant.first << " and the name: " << participant.second << endl;
				it.next();
			}
		}
		if (command == 5)
		{
			cout<<"The number of all the participants is: "<<sm.sizeSM(sm.getRoot())<<endl;
		}
		if (command == 6)
		{
			cout << "The density is: " << sm.density()<<endl;
		}
		if (command == 0)
			break;
	}
	return 0;
}