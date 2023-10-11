#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> readFile(string);
void printVector(vector<vector<string>>);


int main(){

    map<string, string> opcode;
    opcode["LDX"] = "04";
    opcode["LDA"] = "00";
    opcode["TD"] = "E0";
    opcode["JEQ"] = "30";
    opcode["RD"] = "D8";
    opcode["COMP"] = "28";
    opcode["STCH"] = "54";
    opcode["TIX"] = "2C";
    opcode["JLT"] = "38";
    opcode["RSUB"] = "4C";
    opcode["JLT"] = "38";
    opcode["JLT"] = "38";

    string fileName="file.txt";
    vector<vector<string>> vec;
    vec = readFile(fileName);
    // printVector(vec);

    vector<vector<string>> vecOfOpcode;
    vecOfOpcode = vec;

    for (int i = 0; i < vecOfOpcode.size(); i++){
        for(int j = 0; j < vecOfOpcode[i].size(); j++){
            // for ( map<string,string>::iterator itr = opcode.begin(); itr != opcode.end() ; itr++)
            // {
            //     if(itr->first == vecOfOpcode[i][j]){
            //         vecOfOpcode[i][j] = itr->second;
            //     }
            // }

            if(vecOfOpcode[i][j] == opcode.find(vecOfOpcode[i][j]) -> first){
                vecOfOpcode[i][j] = opcode[vecOfOpcode[i][j]];
            }
            
        }
    }

    printVector(vecOfOpcode);

    
    return 0;
}

// printing vector
void printVector(vector<vector<string>> vec){
    // printing the vector
    for (int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[i].size(); j++){
            cout << vec[i][j] + " ";
        }
        cout << endl;
    }
    cout<<endl;
}

// reading file and storing it into vector
vector<vector<string>> readFile(string fileName){

    vector<vector<string>> vec;
    fstream file;
    file.open(fileName, ios::in | ios::out );
    if(file.is_open()){
        cout << "file successfully opened" << endl;
    }else {
        cout << "file is not opened" << endl;
    }

    // whenever getline function executes successfully then consider as it returns true, therefore while loop is executes.
    // at the end of file, file me eof (end of file) aayega which is false where while breaks.
   
    int i=0;
    string line;
    while (getline(file, line))
    {    
        vec.push_back({});

        // stringstream str;
        // str << line;
        stringstream str(line);
        string word;

        while(str >> word){
            vec[i].push_back(word); 
            // cout << word << endl;
        }
        i++;
    }

    file.close();

    return vec;
}