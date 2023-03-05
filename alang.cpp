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

void fail(str e = ""){
    cerr << "\n" << e << "\n" << "FAILURE";
    exit(1);
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
    
    
    int speek_num = 0;
    int req_num = 0;
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

        for(int i = data.size() - 1; i >=0; i--){
            if(data[i] == "req"){
                if (req_num >= 10) fail("YOU ASK WAY TO MUCH CHILD");
                cout << data[i + 1];
                str f;
                getline(cin,f);
                data[i] = f;
                req_num += 1;
                data.erase(data.begin() + i + 1);
            }
            else if (data[i] == "read"){
                ifstream z(data[i + 1]);
                str y;
                str Final;
                while (getline (z, y)) {
                    Final += y + "\n";
                }
                data[i] = Final;
                z.close();
                data.erase(data.begin() + i + 1);
            }
        }

        for(int i = 0; i < data.size(); i++){
            str x= data[i];
            transform(x.begin(), x.end(), x.begin(), ::tolower);
            
            if(x == "say"){
                if (speek_num >= 10) fail("YOU SPEEK TO MUCH CHILD");
                cout << data[i + 1] << "\n";
                speek_num += 1;
                i += 1;
            }
            if (x == "write"){
                ofstream z(data[i+2]);
                z << data[i + 1];
                i += 2;
                z.close();
            }
        }
    }


    return 0;
}