#pragma once
#include <functional> 
#include <list>
#include <iostream>
#include <string>

using namespace std;

// auto is cool.

class HashTable
{
private:
	static const int HashLength = 25;
	list<pair<unsigned int, string>> hashs[HashLength];

public:

	// ADD YOUR FUNCTIONS HERE 
	void print();
	void remove(unsigned int key);
	void insert(unsigned int key, string data);
	void searchTable(unsigned int key);
	bool isEmpty() const;
	int numberOfHashs();
	unsigned int function(unsigned int key);
	//ADDED

};

inline void HashTable::print()
{
	for (int i{}; i < HashLength; i++)//Loops through the list containing the hashes.
	{
		if (hashs[i].size() == 0) { continue; } //If the the hash is empty skip it.

		auto Iterator = hashs[i].begin(); //Initilize an Iterator that is equal to the begining the list.
		for (; Iterator != hashs[i].end(); Iterator++) //Loop through the list.
		{
			cout << "key: " << Iterator->first << " Value: " << Iterator->second << endl; //print out all the keys and values.
		}
		return;
	}
}

inline void HashTable::insert(unsigned int key, string data)
{
	unsigned int value = function(key); //getting the value of the key.
    auto& cell = hashs[value]; // intilizing a pointer hash list to hashes.
 	auto Iterator = begin(cell); // setting the value of the Iterator to the begining of the pointer list.
	bool keyExists = false; //Initilizing a bool to check if they key exits
	for (; Iterator != end(cell); Iterator++) //Iterate through the pointer list.
	{
		if(Iterator->first == key) //Checks if the key of the iterator is equal to the given key.
		{
			keyExists = true; // if so set bool to true.
			Iterator->second = data; // set the Iterators data to the given data.
			cout << "Key already exit, replaced the keys value." << endl; //gives feedback to the user.
			break; //breaks out of the for loop.
		}
	}

	if(!keyExists) // if the key didn't exist.
	{
		cell.emplace_back(key, data); //set the hash's key and value.
		cout << "added Hash" << endl; //Provide feedback to user.
	}
	return;
}

inline void HashTable::remove(unsigned int key)
{
	unsigned int value = function(key); //getting the value of the key.
	auto& cell = hashs[value];// intilizing a pointer hash list to hashes.
	auto Iterator = begin(cell);// setting the value of the Iterator to the begining of the pointer list.
	bool keyExists = false;//Initilizing a bool to check if they key exits
	for (; Iterator != end(cell); Iterator++)//Iterate through the pointer list.
	{
		if (Iterator->first == key)//Checks if the key of the iterator is equal to the given key.
		{
			keyExists = true;// if so set bool to true.
			Iterator = cell.erase(Iterator);// erase the hash.
			cout << "Item removed" << endl;//gives feedback to the user.
			break; //breaks out of the for loop.
		}
	}
	if (!keyExists) // If the key didn't exist.
	{
		cout << "Item not found" << endl;//give feed back.
	}
	return;

}

void HashTable::searchTable(unsigned int key)
{
	unsigned int value = function(key); //getting the value of the key.
	auto& cell = hashs[value];// intilizing a pointer hash list to hashes.
	auto Iterator = begin(cell);// setting the value of the Iterator to the begining of the pointer list.
	bool keyExists = false;//Initilizing a bool to check if they key exits
	for (; Iterator != end(cell); Iterator++)//Iterate through the pointer list.
	{
		if (Iterator->first == key)//Checks if the key of the iterator is equal to the given key.
		{
			keyExists = true;// If so set bool to true.
 			cout << "The value of key " << Iterator->first << " is " << Iterator->second << "." << endl;
		}
	}
	if (!keyExists)// If the key didn't exist.
	{
		cout << "Item not found" << endl; //return feedback.
	}
}

bool HashTable::isEmpty() const 
{
	int total{}; //Initilize an int the number of pairs that are in the list.
	for(int i{}; i < HashLength; i++)
	{
		total += hashs[i].size();
	}
	if (total > 0)
	{
		return true;
	}
	return false;
}

inline int HashTable::numberOfHashs()
{
	int total{}; //Initilize an int the number of pairs that are in the list.
	for (int i{}; i < HashLength; i++)
	{
		total += hashs[i].size();
	}
	return total;
}

inline unsigned int HashTable::function(unsigned int key)
{
	return key % HashLength;
} 

