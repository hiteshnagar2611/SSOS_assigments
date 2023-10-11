#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    
    fstream file;
    
    file.open("file.txt", ios::in);
    if(file.is_open()){
        cout << "file successfully opened" << endl;
    }else {
        cout << "file is not opened" << endl;
    }

    // 2d vector
    vector<vector<string>> vec;
    
    // read file line by line
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
    
    // print 2d vector
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[i].size(); j++){
            cout << vec[i][j] + " ";
            count++;
        }
        cout << endl;
    }
    cout << endl;
    cout << "Number of words in file : " << count;
    

    file.close();
    return 0;
}