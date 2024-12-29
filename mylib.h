#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <regex>

using std::string;
using std::map;
using std::ifstream;
using std::cerr;
using std::endl;
using std::set;
using std::istringstream;
using std::cout;
using std::cin;
using std::regex;
using std::smatch;
using std::ofstream;


void countWords(const std::string& fileName, std::map<std::string, int>& wordCount, std::map<std::string, std::set<int>>& wordLines);
void findURLs(const std::string& fileName, std::set<std::string>& urls);

#endif // MYLIB_H_INCLUDED
