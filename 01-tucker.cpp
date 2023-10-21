#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Words to be checked
    string words[] = {"bird", "lake", "zoom", "xxyt."};
    int numWords = sizeof(words) / sizeof(words[0]);

    // Loop through the words and check if they exist in the file
    for (int i = 0; i < numWords; ++i) {
        // Open the file in each iteration
        ifstream file("dictionary.txt");

        bool found = false;
        string line;

        // Read the file line by line and check if the word exists
        while (getline(file, line)) {
            if (line.find(words[i]) != string::npos) {
                found = true;
                break;
            }
        }

        // Output whether the word is spelled correctly or not
        if (found) {
            cout << words[i] << " is spelled correctly" << endl;
        } else {
            cout << words[i] << " is not spelled correctly" << endl;
        }

        // Close the file after each iteration
        file.close();
    }

    return 0;
}
