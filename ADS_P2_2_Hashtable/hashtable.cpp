#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size, double threshold, int methode) 
{
	this->collisionCount = 0;
	this->elements = 0;
	this->hashTable = new vector<int>(size, -1);
	this->threshold_rehashing = threshold;
	this->m_sondierMethode = methode;
	this->size = size;
}

HashTable::~HashTable()
{
	delete hashTable;
}

int get_next_prime(int x)
{
	x = x + 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x += 1;
	}
}

int get_last_prime(int x)
{
	x = x - 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x -= 1;
	}
}

// Berechnung des Hashwertes 
int HashTable::hashValue(int item) 
{

	int initialIndex = item % size;
    int index = initialIndex;
    int i = 0;

	/*
	while(((*hashTable)[index] != -1)){
		collisionCount++;
		if(m_sondierMethode == 1) index = (initialIndex + index) % size;
		else if(m_sondierMethode == 2) index = (initialIndex + index * i) % size;
		else if(m_sondierMethode == 3) {
			int R = get_last_prime(size);
            index = (initialIndex + index * (R - (item % R))) % size;
		}
		index++;
	}*/

	switch (m_sondierMethode)
	{
	case (1):
		// Lineares Sondieren
		while((*hashTable)[index] != -1){
			collisionCount++;
			i++;
			index = (initialIndex + i) % size;
		}
		break;
	case (2):
		// Quadr. Sondieren
		while((*hashTable)[index] != -1){
			collisionCount++;
			i++;
			index = (initialIndex + i*i) % size;
		}
		break;
	case (3):
		{
            // Doppeltes Hashing
            int R = get_last_prime(size);
            while ((*hashTable)[index] != -1) {
                collisionCount++;
                i++;
                index = (initialIndex + i * (R - (item % R))) % size;
            }
        }
        break;
	default:
		break;
	}
	return index;
}
	

void HashTable::rehashing()
{
	int oldSize = size;
	vector<int>* oldTable = hashTable;

	size = get_next_prime(2*oldSize);
	hashTable = new vector<int>(size, -1);
	elements = 0;
	collisionCount = 0;

	for(int i = 0; i < oldSize; i++){
		if((*oldTable)[i] != -1 ) insert ((*oldTable)[i]);
		
	}
	delete oldTable;

}

int HashTable::insert(int item) 
{
	if(((double)elements+1) / size >= threshold_rehashing) rehashing();

	int index = hashValue(item);
	
	(*hashTable)[index] = item;
	elements++;
	return index;
}


int HashTable::at(int i) 
{
	return hashTable->at(i);
}

int HashTable::getCollisionCount() 
{
	return this->collisionCount;
}

int HashTable::getSize() 
{
	return this->size;
}

int HashTable::getElements() 
{
	return this->elements;
}



