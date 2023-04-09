/*
    Asian Language- A coding language for Asians.
    Copyright (C) 2023  Nuaym Syed

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    
    A-Lang  Copyright (C) 2023  Nuaym Syed
    This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
    This is free software, and you are welcome to redistribute it
    under certain conditions; type `show c' for details.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef _MSC_VER
#define and &&
#define or ||
#define not !
#endif

vector<string> file;

void fail(string e = "", int code = 1){
    cerr << "\n\033[31m" << e << "\n" << "FAILURE\033[0m";
    exit(code);
}

int main(int argc, char** argv)
{
    if (argc <= 1) fail();
    ifstream myfile(argv[1]);
    if (!myfile) fail();

    string hello;
    while(getline(myfile,hello)){
        file.push_back(hello);
    }
    myfile.close();
    
    
    int inif = 0;
    /*Inif Values:
    0 = Not in if
    1 = In if, run
    2 = In if, do not run*/
    for(auto line: file){
        vector<string> data;
        if (line.rfind("py:", 0) != 0 or line.rfind("#", 0) != 0){
        string prev = "";
        bool instring = false;
        for(int i = 0; i < line.size(); i++){
            if (instring){
                if (line[i] == '"' && line[i - 1] != '\\'){ instring = false;}
                else prev += line[i];
            }else if (line[i] == '"' && line[i - 1] != '\\'){ 
                instring = true;
            }
            else if(not isspace(line[i])) {
                if (line[i] != '\\')
                    prev += line[i];
                else if (line[i - 1] == '\\') prev += line[i];    
            }

            if (isspace(line[i]) and !instring){
                data.push_back(prev);
                prev = "";
            }
        }
        data.push_back(prev);
        if (instring) fail();
        if (inif != 2){
        // VALUES/ inputs
        for(int i = data.size() - 1; i >=0; i--){
            if(data[i] == "req"){
                cout << data[i + 1];
                string f;
                getline(cin,f);
                data[i] = f;
                data.erase(data.begin() + i + 1);
            }
            else if (data[i] == "read"){
                ifstream z(data[i + 1]);
                string y;
                string Final;
                int i = 0;
                while (getline (z, y)) {
                    Final += y;
                    if(i > 1) Final += "\n";
                    i +=1;
                }
                data[i+ 2] = Final;
                z.close();
                data.erase(data.begin() + i + 3);
            }
        }

        // ALGORITHMS
        for(int i = data.size() - 1; i >=0; i--){
            if(data[i] == "+"){ 
                if (data[i - 2] == "num"){
                    //LATER
                }else{
                    data[i] = data[i - 1] + data[i+1];
                    data.erase(data.begin() + i - 1);
                    data.erase(data.begin() + i);
                }
            }
            if(data[i] == "is"){ 
                int x;
                if( string(data[i-1]) == string(data[i+1])){ 
                    x = 1;
                }else x = 0;
                data[i] = to_string(x);
                data.erase(data.begin() + i - 1);
                data.erase(data.begin() + i);
            }
            if(data[i] == "not"){ 
                int x;
                if( string(data[i-1]) != string(data[i+1])){ 
                    x = 1;
                }else x = 0;
                data[i] = to_string(x);
                data.erase(data.begin() + i - 1);
                data.erase(data.begin() + i);
            }
        }
        // OUTPUTS
        for(int i = 0; i < data.size(); i++){
            string x= data[i];
            transform(x.begin(), x.end(), x.begin(), ::tolower);

            if(x == "say"){
                cout << data[i + 1] << "\n";
                i += 1;
            }
            if (x == "write"){
                ofstream z(data[i+2]);
                z << data[i + 1];
                i += 2;
                z.close();
            }
            if (x == "delete"){
                remove( data[i + 1].c_str() );
            }
            if (x == "if"){
                if (data[i + 1] == "1"){
                    inif = 1;
                }else{
                    inif = 2;
                }
            }
            if (x == "endif"){
                inif = 0;
            }
            if (x == "exec"){
                system(data[i + 1].c_str());
            }
            if (x == "exit"){
                fail("YOUR PROGRAM IS SOO BAD IT DECIDED TO FAIL ITSELF",stoi(data[i+1]));
            }
        } // FOr
        } // Inif
        } // Python manager
        else{
            
            string v;
            stringstream ss;
            int x = 0;
            for(auto z: data){
                if (x != 0) ss << z;
                x += 1;
            }
            v = ss.str();

            replace( v.begin(), v.end(), '"', '\'');
            system(("python -c \"" + v + "\"").c_str());
            
        }
        for(int i = 0; i < data.size(); i++){
            if (data[i] == "endif"){
                inif = 0;
            }
        }
    } // FUll loop


    return 0;
} // Int main