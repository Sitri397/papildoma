#include "mylib.h"


int main() {
    cout << "Iveskite failo pavadinima: " << endl;
    string fileName;
    cin >> fileName;
    map<string, int> wordCount;
    map<string, set<int>> wordLines;
    set<string> urls;


    countWords(fileName, wordCount, wordLines);


    findURLs(fileName, urls);


    ofstream outputFile("output.txt");
    outputFile << "Zodziai, pasikartojantys daugiau nei 1 karta:\n";
    for (const auto& [word, count] : wordCount) {
        if (count > 1) {
            outputFile << word << ": " << count << endl;
        }
    }

    outputFile << "\nCross-reference lentele:\n";
    for (const auto& [word, lines] : wordLines) {
        if (wordCount[word] > 1) {
            outputFile << word << ": ";
            for (const auto& line : lines) {
                outputFile << line << " ";
            }
            outputFile << "\n";
        }
    }

    outputFile << "\nSurasti URL:\n";
    for (const auto& url : urls) {
        outputFile << url << "\n";
    }
    outputFile.close();

    cout << "Rezultatai issaugoti faile output.txt\n";
    return 0;
}
