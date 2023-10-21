#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to perform binary search for a word in the file
bool binarySearch(const string& word) {
    ifstream file("dictionary.txt");
    string line;

    // Read the file line by line and check if the word exists
    while (getline(file, line)) {
        if (line.find(word) != string::npos) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

int main() {
    // Words to be checked
    string words[] = {"bird", "xddd", "zoom", "xxyt."};
    int numWords = sizeof(words) / sizeof(words[0]);

    // Loop through the words and check if they exist in the file
    for (int i = 0; i < numWords; ++i) {
        // Perform binary search for the current word
        bool found = binarySearch(words[i]);

        // Output whether the word is spelled correctly or not
        if (found) {
            cout << words[i] << " is spelled correctly" << endl;
        } else {
            cout << words[i] << " is not spelled correctly" << endl;
        }
    }

    return 0;
}
