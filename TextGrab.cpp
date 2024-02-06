// Чтение данных из файла

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "TextGrab.h"

using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::cout;

// функция разбора значений из файла по разделительному шаблону
void splitString(const string &fullstr,
                 vector<string> &elements,
                 const string &delimiter) {

    string::size_type lastpos =
        fullstr.find_first_not_of(delimiter, 0);
    string::size_type pos     =
        fullstr.find_first_of(delimiter, lastpos);
    while ( (string::npos != pos) || (string::npos != lastpos) ) {
        elements.push_back(fullstr.substr(lastpos, pos-lastpos));
        lastpos = fullstr.find_first_not_of(delimiter, pos);
        pos = fullstr.find_first_of(delimiter, lastpos);
    }
}
// функция преобразования строки в число
double stringToDouble(const string &str) {
    istringstream stm;
    double val = 0;
    stm.str(str);
    stm >> val;
    return val;
}

void readData(const string &filename,
              const string &csvdelimiter,
              vector< vector<double> > &sarr) {
    ifstream fin(filename.c_str());
    string s;
    vector<string> selements;
    vector<double> delements;
    while ( !fin.eof() ) {
        getline(fin, s);
        if ( !s.empty() ) {
            splitString(s, selements, csvdelimiter);
            for ( size_t i=0; i<selements.size(); i++ ) {
                delements.push_back(stringToDouble(selements[i]));
            }
            sarr.push_back(delements);
            selements.clear();
            delements.clear();
        }    }
    fin.close();
}


