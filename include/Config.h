/**
 * @file Config.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _CONFIG_H
#define _CONFIG_H

#include <string>
#include <fstream>
#include <map>
using namespace std;

//Klasse Config beschreibt Methoden, um eine Textdatei zu lesen
class Config {
public:
    Config(char * configFile);
    string getValue(string cName);
    void print();
    void print(string cName);
    bool isValueSet(string cName);

private:
    map<string,string> mContent;
    static string trim(const string & source, const char * delims = " \t\r\n");

};
#endif
