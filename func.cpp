#include "mylib.h"

void countWords(const string& fileName, map<string, int>& wordCount, map<string, set<int>>& wordLines) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Nepavyko atidaryti failo!" << endl;
        return;
    }

    string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        lineNumber++;
        istringstream stream(line);
        string word;
        while (stream >> word) {
            word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
            if (!word.empty()) {
                wordCount[word]++;
                wordLines[word].insert(lineNumber);
            }
        }
    }
    file.close();
}


void findURLs(const string& fileName, set<string>& urls) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Nepavyko atidaryti failo!" << endl;
        return;
    }

    string line;
    regex urlRegex(R"((https?://[^\s]+|www\.[^\s]+|[a-zA-Z0-9\-]+\.[a-zA-Z]{2,}))");
    smatch match;

    while (getline(file, line)) {
        string::const_iterator searchStart(line.cbegin());
        while (regex_search(searchStart, line.cend(), match, urlRegex)) {
            urls.insert(match[0]);
            searchStart = match.suffix().first;
        }
    }
    file.close();
}
