#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <bitset>
#include <string>

using namespace std;

// Convert IP address in string form to a 32-bit unsigned integer
unsigned int ipToUInt(const string &ip)
{
    unsigned int result = 0;
    stringstream ss(ip);
    string segment;
    while (getline(ss, segment, '.'))
    {
        result = (result << 8) + stoi(segment);
    }
    return result;
}

// Mask IP based on prefix length (e.g., /24, /16)
unsigned int maskIP(unsigned int ip, int prefixLength)
{
    unsigned int mask = (0xFFFFFFFF << (32 - prefixLength));
    return ip & mask;
}

// Hash table to store the routing table
unordered_map<unsigned int, string> routingTable;

// Add an IP prefix to the routing table
void addPrefix(const string &ipPrefix, const string &nextHop)
{
    size_t pos = ipPrefix.find('/');
    string ip = ipPrefix.substr(0, pos);
    int prefixLength = stoi(ipPrefix.substr(pos + 1));

    unsigned int ipAsInt = ipToUInt(ip);
    unsigned int maskedIP = maskIP(ipAsInt, prefixLength);

    // Store the prefix and associated next hop in the hash table
    routingTable[maskedIP] = nextHop;
}

// Lookup the longest matching prefix for an IP address
string longestPrefixMatch(const string &ip)
{
    unsigned int ipAsInt = ipToUInt(ip);

    // Start with the full prefix length (32), and check progressively shorter prefixes
    for (int prefixLength = 32; prefixLength >= 0; --prefixLength)
    {
        unsigned int maskedIP = maskIP(ipAsInt, prefixLength);

        // If a match is found in the routing table, return the next hop
        if (routingTable.find(maskedIP) != routingTable.end())
        {
            return routingTable[maskedIP];
        }
    }

    // If no match is found, return a default next hop or "No route found"
    return "No route found";
}

// Driver function
int main()
{
    // Add prefixes to the routing table
    addPrefix("192.168.0.0/16", "Router1");
    addPrefix("192.168.1.0/24", "Router2");
    addPrefix("10.0.0.0/8", "Router3");

    // IP address to lookup
    string ipToLookup = "192.168.1.100";
    string nextHop = longestPrefixMatch(ipToLookup);

    cout << "Next hop for " << ipToLookup << " is: " << nextHop << endl;

    return 0;
}
