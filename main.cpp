#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Custom compare function (from the previous task)
int customCompare(const char* s, size_t pos, size_t len, const string& str) {
    for (size_t i = 0; i < len && i < str.size(); ++i) {
        if (s[pos + i] != str[i]) {
            return s[pos + i] - str[i];
        }
    }
    if (len == str.size()) {
        return 0;
    } else if (len < str.size()) {
        return -1;
    } else {
        return 1;
    }
}

// Function to convert all uppercase Latin letters to lowercase
void convertToLowercase(string& s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}

// Function to check if a string contains any uppercase Latin letters
bool containsUppercase(const string& s) {
    return any_of(s.begin(), s.end(), ::isupper);
}

int main() {
    // Input string from console
    char cstr[100];
    string str;

    cout << "Enter a string: ";
    cin.getline(cstr, 100);
    str = cstr;

    // Parameters for comparison
    size_t pos = 0;
    size_t len = str.size() / 2; // Example length for comparison
    string compareStr = "example"; // Example string to compare with

    // Using std::string::compare
    int resultStd = str.compare(pos, len, compareStr);

    // Using custom compare function
    int resultCustom = customCompare(cstr, pos, len, compareStr);

    // Output results
    cout << "Result using std::string::compare: " << resultStd << endl;
    cout << "Result using customCompare: " << resultCustom << endl;

    // Create an input file with at least 10 different lines
    ofstream outFile("input.txt");
    outFile << "Hallo der Welt\n";
    outFile << "Ich liebe dich\n";
    outFile << "Das Wetter heute ist so schlecht\n";
    outFile << "Gestern habe ich meine Hausaufgabe gemacht\n";
    outFile << "Am Morgen gehe ich in die Schule\n";
    outFile << "Jetzt Studiere ich in ein Universität\n";
    outFile << "Ich mag Capri-Sun\n";
    outFile << "Der Zug ist spät für C.A. 20 Minuten\n";
    outFile << "Heute Abend\n";
    outFile << "Am Morgen früch\n";
    outFile.close();

    // Open the input file for reading and an output file for writing
    ifstream inFile("input.txt");
    ofstream resultFile("output.txt");

    if (!inFile || !resultFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        // Check if the line contains any uppercase letters
        if (containsUppercase(line)) {
            // Convert the line to lowercase
            convertToLowercase(line);
        }
        // Write the processed line to the output file
        resultFile << line << endl;
    }

    inFile.close();
    resultFile.close();

    cout << "Processing complete. Check 'output.txt' for results." << endl;

    return 0;
}
