#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000; // Define the maximum key value for direct hashing

class DirectHash
{
private:
    vector<int> hashTable; // Hash table to store values

public:
    // Constructor to initialize the hash table with a size of MAX and -1 as default value
    DirectHash()
    {
        hashTable.resize(MAX, -1); // -1 indicates that the index is empty
    }

    // Function to insert a value into the hash table
    void insert(int key, int value)
    {
        if (key >= 0 && key < MAX)
        {
            hashTable[key] = value; // Direct hashing (key itself is the index)
            cout << "Inserted value " << value << " at key " << key << endl;
        }
        else
        {
            cout << "Key " << key << " is out of range!" << endl;
        }
    }

    // Function to search for a value using the key
    int search(int key)
    {
        if (key >= 0 && key < MAX && hashTable[key] != -1)
        {
            return hashTable[key]; // Return the value if key is present
        }
        return -1; // Return -1 if the key is not found or index is empty
    }

    // Function to delete a value at a given key
    void remove(int key)
    {
        if (key >= 0 && key < MAX && hashTable[key] != -1)
        {
            hashTable[key] = -1; // Set the index as empty (-1)
            cout << "Deleted value at key " << key << endl;
        }
        else
        {
            cout << "Key " << key << " not found!" << endl;
        }
    }
};

int main()
{
    DirectHash dh;

    // Insert some key-value pairs
    dh.insert(10, 100);
    dh.insert(200, 500);
    dh.insert(500, 999);

    // Search for keys
    int value = dh.search(200);
    if (value != -1)
        cout << "Value at key 200: " << value << endl;
    else
        cout << "Key 200 not found!" << endl;

    value = dh.search(300);
    if (value != -1)
        cout << "Value at key 300: " << value << endl;
    else
        cout << "Key 300 not found!" << endl;

    // Remove a key
    dh.remove(10);

    // Try to search for the deleted key
    value = dh.search(10);
    if (value != -1)
        cout << "Value at key 10: " << value << endl;
    else
        cout << "Key 10 not found!" << endl;

    return 0;
}
