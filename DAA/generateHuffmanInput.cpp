#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Define characters and their corresponding frequencies
    vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> frequencies = {5, 9, 12, 13, 16, 45};

    string generatedString;
    
    // Generate the string by repeating each character according to its frequency
    for (size_t i = 0; i < characters.size(); ++i) {
        generatedString += string(frequencies[i], characters[i]);
    }

    cout << "Generated String: " << generatedString << endl;
    return 0;
}
