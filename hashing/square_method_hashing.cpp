#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the number of digits in a number
int numDigits(int number)
{
    return (int)log10(number) + 1;
}

// Function to extract the middle digits of a number
int extractMiddleDigits(int number, int totalDigits, int numDigitsToExtract)
{
    int startPos = (totalDigits - numDigitsToExtract) / 2; // Calculate starting position for middle digits
    int divisor = pow(10, startPos);                       // Move left to middle position
    number = number / divisor;                             // Truncate the left side digits
    return number % (int)pow(10, numDigitsToExtract);      // Extract middle digits
}

// Function to calculate the hash value using Mid-Square Method
int midSquareHash(int key, int tableSize)
{
    int squaredKey = key * key;              // Square the key
    int totalDigits = numDigits(squaredKey); // Get total number of digits in squared key

    // Determine how many middle digits to extract based on table size
    int digitsToExtract = numDigits(tableSize);

    // Extract middle digits from the squared key
    int middleDigits = extractMiddleDigits(squaredKey, totalDigits, digitsToExtract);

    // Use the extracted middle digits as the hash value (mod tableSize to fit within table)
    return middleDigits % tableSize;
}

int main()
{
    int tableSize = 100; // Hash table size (assume we need 2-digit hash values)

    // List of keys to be hashed
    int keys[] = {123, 37, 54, 89, 200, 76, 58};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    // Display hash values
    for (int i = 0; i < numKeys; i++)
    {
        int key = keys[i];
        int hashValue = midSquareHash(key, tableSize);
        cout << "Key: " << key << " --> Hash: " << hashValue << endl;
    }

    return 0;
}
