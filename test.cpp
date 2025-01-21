#include <bits/stdc++.h>
using namespace std;

void reverseLinesInFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file: " << inputFileName << endl;
        return;
    }

    // Open the output file for writing
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open output file: " << outputFileName << endl;
        inputFile.close();
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        reverse(line.begin(), line.end());
        outputFile << line << '\n';
    }

    inputFile.close();
    outputFile.close();

    cout << "Reversed lines have been written to " << outputFileName << endl;
}

int main() {
    const string inputFileName = "input.txt";
    const string outputFileName = "output.txt";

    // Process the file
    reverseLinesInFile(inputFileName, outputFileName);

    return 0;
}
