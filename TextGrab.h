#ifndef _TextGrab_H
#define _TextGrab_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::cout;

void readData(const string &filename,
              const string &csvdelimiter,
              vector< vector<double> > &sarr);


#endif
