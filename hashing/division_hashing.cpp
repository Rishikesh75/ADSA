// table-size 10
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the hash value using division method
int divisionHash(int key, int tableSize)
{
    return key % tableSize;
}

int main()
{
    int tableSize = 10;                   // Size of the hash table
    vector<int> hashTable(tableSize, -1); // Initialize hash table with -1 (empty slots)

    // List of keys to be inserted into the hash table
    int keys[] = {23, 43, 13, 27, 89, 34, 56, 78, 11};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    // Inserting keys into the hash table
    for (int i = 0; i < numKeys; i++)
    {
        int key = keys[i];
        int hashIndex = divisionHash(key, tableSize);

        // Handle collision using linear probing (basic handling)
        while (hashTable[hashIndex] != -1)
        {
            hashIndex = (hashIndex + 1) % tableSize; // Linear probing
        }

        // Insert the key into the calculated hash index
        hashTable[hashIndex] = key;
    }

    // Display the hash table
    cout << "Hash Table:" << endl;
    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i] != -1)
            cout << i << " --> " << hashTable[i] << endl;
        else
            cout << i << " --> " << "Empty" << endl;
    }

    return 0;
}
