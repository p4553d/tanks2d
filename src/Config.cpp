/**
 * @file Config.cpp
 * @author user p4553d
 */


#include "Config.h"

Config::Config(char * configFile) {
//Öffnet die Datei
    ifstream file(configFile);

    if(!file.is_open()) {
        throw "Kann die Konfiguration nicht oeffnen!";
    }

    string line;
    string name;
    string value;
    string inSection;
    int posEqual;
//Lese die Zeilen in der Datei ein, bis die Datei zu Ende ist
    while (getline(file,line)) {

        if (! line.length()) continue;

        if (line[0] == '#') continue;
        if (line[0] == ' ') continue;
        //Falls das erste Element in der gelesenen Zeile [ ist, dann extrahiere
        //den String in [], entferne dabei die Leerzeichen
        if (line[0] == '[') {
            inSection=trim(line.substr(1,line.find(']')-1));
            continue;
        }
        //Position von "=" in einer Zeile
        posEqual=line.find('=');
        //Extrahiere den String von Anfang der Zeile bis "=", entferne Leerzeichen
        name  = trim(line.substr(0,posEqual));
        //Extrahiere den String(Wert) hinter "=", entferne Leerzeichen
        value = trim(line.substr(posEqual+1));

        //Der Inhalt ist ein String/String mit Wert value
        mContent[inSection+'/'+name]=value.c_str();
    }

}

string Config::trim(string const& source, char const* delims) {
    string result(source);//Andrej:Wo ist diese Funktion definiert?
    string::size_type index = result.find_last_not_of(delims);
    if(index != string::npos)
        result.erase(++index);

    index = result.find_first_not_of(delims);
    if(index != string::npos)
        result.erase(0, index);
    else
        result.erase();
    return result;
}

//Liefert den Wert von String/String zurück, dieser Wert ist auch string
string Config::getValue(string cName) {
    return mContent[cName];
}

//Überprüft, ob der Wert in String/String gesetzt wurde, bis der String/String
//zu Ende gelesen wurde
bool Config::isValueSet(string cName) {
    map<string,string>::iterator it = mContent.find(cName);
    return it != mContent.end();
}

//Gebe den Inhalt von String/String aus, bis der String/String zu Ende gelesen wurde
void Config::print() {
    map<string,string>::iterator it;
    for ( it=mContent.begin() ; it != mContent.end(); it++ )
        printf("%s = %s\n",(*it).first.c_str(), (*it).second.c_str());

}

//Gebe den String und seinen Wert aus
void Config::print(string cName) {
    printf("%s = %s\n",cName.c_str(), getValue(cName).c_str());
}


