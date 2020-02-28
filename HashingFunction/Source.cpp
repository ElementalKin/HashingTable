#include "HashTable.h"
using namespace std;

int main()
{
	HashTable HT;
	string answer;
	int response = 0;
	while (true)
	{
		std::cout << "Do you want to [1] check whats in the HashTable, [2] add to the HashTable, [3] remove from the HashTable, \n[4] check if its empty" << std::endl;
		std::cin >> response;
		if (response == 1)
		{
			std::cout << "Do you want to [1] see the entire HashTable, [2] find a specific hash or, [3] see how many hashes are in the HashTable." << std::endl;
			std::cin >> response;
			if (response == 1)
			{
				HT.print();
			}
			else if (response == 2)
			{
				std::cout << "please enter a specific key to get the value of." << std::endl;
				std::cin >> response;
				HT.searchTable(response);
			}
			else if (response == 3)
			{
				HT.numberOfHashs();
			}
			else
			{
				std::cout << "please enter 1-2 to respond" << std::endl;
			}
		}
		else if (response == 2)
		{

			std::cout << "please enter a key." << std::endl;
			cin >> response;
			std::cout << "please enter a value." << std::endl;
			cin >> answer;
			HT.insert(response, answer);
		}
		else if (response == 3)
		{
			std::cout << "Enter the key you want deleted." << std::endl;
			std::cin >> response;
			HT.remove(response);
		
		}
		else if (response == 4)
		{
			if(HT.isEmpty())
			{
				std::cout << "it is not empty." << std::endl;
			}
			else 
			{
				std::cout << "it is empty." << std::endl;
			}
		}
		else
		{
			std::cout << "please enter 1-4 to respond" << std::endl;
		}

	}

	return 0;
}