#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#define str string
using namespace std;

#define and &&
#define or ||
#define not !

vector<str> file;

void fail(str e = "", int code = 1){
    cerr << "\n\033[31m" << e << "\n" << "FAILURE\033[0m";
    exit(code);
}

int main(int argc, char** argv)
{
    if (argc <= 1) fail();
    ifstream myfile(argv[1]);
    if (!myfile) fail();

    str hello;
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
        vector<str> data;
        str prev = "";
        bool instr = false;
        for(int i = 0; i < line.size(); i++){
            if (instr){
                if (line[i] == '"'){ instr = false;}
                else prev += line[i];
            }else if (line[i] == '"'){ 
                instr = true;
            }
            else if(not isspace(line[i])) 
                prev += line[i];    

            if (isspace(line[i]) and !instr){
                data.push_back(prev);
                prev = "";
            }
        }
        data.push_back(prev);
        if (instr) fail();
        if (inif != 2){
        // VALUES/ inputs
        for(int i = data.size() - 1; i >=0; i--){
            if(data[i] == "req"){
                cout << data[i + 1];
                str f;
                getline(cin,f);
                data[i] = f;
                data.erase(data.begin() + i + 1);
            }
            else if (data[i] == "read"){
                ifstream z(data[i + 1]);
                str y;
                str Final;
                int i = 0;
                while (getline (z, y)) {
                    Final += y;
                    if(i > 1) Final += "\n";
                    i +=1;
                }
                data[i] = Final;
                z.close();
                data.erase(data.begin() + i + 1);
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
                if( str(data[i-1]) == str(data[i+1])){ 
                    x = 1;
                }else x = 0;
                data[i] = to_string(x);
                data.erase(data.begin() + i - 1);
                data.erase(data.begin() + i);
            }
            if(data[i] == "not"){ 
                int x;
                if( str(data[i-1]) != str(data[i+1])){ 
                    x = 1;
                }else x = 0;
                data[i] = to_string(x);
                data.erase(data.begin() + i - 1);
                data.erase(data.begin() + i);
            }
        }
        // OUTPUTS
        for(int i = 0; i < data.size(); i++){
            str x= data[i];
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
            if (x == "exit"){
                fail("YOUR PROGRAM IS SOO BAD IT DECIDED TO FAIL ITSELF",stoi(data[i+1]));
            }
        } // FOr
        } // Inif

        for(int i = 0; i < data.size(); i++){
            if (data[i] == "endif"){
                inif = 0;
            }
        }
    } // FUll loop


    return 0;
} // Int main