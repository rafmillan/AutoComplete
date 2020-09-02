#include <iostream>
#include <fstream>
#include "TrieNode.h"

using namespace std;

string lowerCase(string str);

int main(int argc, char *argv[]){
    cout << "---AutoComplete---" << endl;
    string line;
    bool running = true;
    bool ask = true;
    TrieNode *root = new TrieNode();

    ifstream file("bank.txt");
    if (file.is_open()){
        while (getline(file,line)){
             root->insert(root, line);
        }
        file.close();
    }

    while(running){
        string word;
        char choice = '\0';
        cout << "Input: ";
        cin >> word;
        if(argc > 1){
            int in = stoi(argv[argc-1]);
            int* reps = &in;
            root->prefixSearch(root, lowerCase(word), 0, reps);
        }
        else{
            root->prefixSearch(root, lowerCase(word), 0);
        }
       
        ask = true;
        
        while(ask){
             cout << "Search Again? [Y/N]: ";
            cin >> choice;
            if(toupper(choice) == 'N'){
                ask = false;
                running = false;
            }
            if(toupper(choice) != 'Y'){
                continue;
            }
            else{
                ask = false;
            }

        }
        
    }

    return 0;
}

string lowerCase(string str){
    string ans = "";
    for(int i = 0; i < str.length(); i++){
        ans += tolower(str[i]);
    }
    return ans;
}