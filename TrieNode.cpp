#include <iostream>
#include "TrieNode.h"

using namespace std;

TrieNode::TrieNode(){
    for(int i = 0; i < 26; i++){

        children[i] = nullptr;
    }
    leaf = false;
}

void TrieNode::setLetter(char letter){
    this->letter = letter;
}

char TrieNode::getLetter(){
    return this->letter;
}

 bool TrieNode::checkNull(char temp){
    //cout<<"\nIncheckNULL "<<temp<<" "<<(temp - 'a')<<" \n";
    if(children[temp - 'a'] == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void TrieNode::setNode(char temp){
            cout<<"Setting node \n";
            children[temp - 'a'] = new TrieNode();
}

TrieNode* TrieNode::getNode(char temp){
    return children[temp - 'a'];
}

void TrieNode::setLeaf(){
    this->leaf = true;
}

void TrieNode::setWordEnd(){
    this->wordEnd = true;
}

bool TrieNode::isLeaf(){
    return this->leaf;
}

bool TrieNode::isLastNode(){
     for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (this->children[i]) 
            return 0; 
    return 1; 
}

bool TrieNode::isWordEnd(){
    return wordEnd;
}

void TrieNode::insert(TrieNode *root, string str){
    this->insertRecursively(root, str, 0);
    //cout << str << " inserted..." << endl;
}

void TrieNode::insertRecursively(TrieNode* root, string key, int i){
    if(i < key.length()) 
    { 
        int index = key[i] - 'a'; 
        if(root->children[index] == nullptr ) 
        { 
            //Create a new node 
            root->children[index] = new TrieNode(); 
            root->children[index]->setLetter(key[i]);
    
        } 
            // Recursive call for insertion of string 
        insertRecursively(root->children[index], key, i+1); 
    } 
    else
    { 
        // Make the endOfWord true which represents 
        // the end of string 
        root->setWordEnd();
        root->setLeaf(); 
    } 
}

bool TrieNode::search(TrieNode *root, string key){
    return searchRecursively(root, key, 0);
}

bool TrieNode::searchRecursively(TrieNode* root, string key, int i){
    int index = key[i] - 'a'; 
    if(i == key.length() - 1 && root->children[index]->isLeaf()){
        //cout << "letter " << root->children[index]->getLetter() << " found..." << endl;
        cout << key << " found!" << endl;
        return true;
    }
    if(root->children[index] != nullptr && i < key.length()){
        //cout << "letter " << root->children[index]->getLetter() << " found..." << endl;
        return searchRecursively(root->children[index], key, i+1);
    }
    cout << " no match." << endl;
    return false;
}

void TrieNode::prefixSearch(TrieNode* root, string currPrefix, int i, int* num){
    int index = currPrefix[i] - 'a'; 
    int reps;
    char str[26];
    for(int i = 0; i < currPrefix.length(); i++){
        str[i] = currPrefix[i];
    }
    if(i == currPrefix.length() - 1){
        if(!root->children[index]->isLastNode()){
            printAutoSuggestions(root->children[index], currPrefix, str, currPrefix.length(), num);
        }
    }
    if(root->children[index] != nullptr && i < currPrefix.length()){
        return prefixSearch(root->children[index], currPrefix, i+1, num);
    }
    return;
}

void TrieNode::printAutoSuggestions(TrieNode* root, string query, char str[], int level, int* reps) {
    if(*reps < 0){
        return;
    }
    if (root->isLeaf()){
        str[level] = '\0';
        cout << str << endl;
    } 

    for (int i = 0; i < ALPHABET_SIZE; i++)  
    {
        if (root->children[i] != nullptr){
            if(root->children[i]->isLeaf()){
                 *reps = *reps -1;
            }
           
            str[level] = i + 'a';
            printAutoSuggestions(root->children[i], query, str, level+1, reps); 
        }
    }
} 

void TrieNode::prefixSearch(TrieNode* root, string currPrefix, int i){
    int index = currPrefix[i] - 'a'; 
    int reps;
    char str[26];
    for(int i = 0; i < currPrefix.length(); i++){
        str[i] = currPrefix[i];
    }
    if(i == currPrefix.length() - 1){
        if(!root->children[index]->isLastNode()){
            printAutoSuggestions(root->children[index], currPrefix, str, currPrefix.length());
        }
    }
    if(root->children[index] != nullptr && i < currPrefix.length()){
        return prefixSearch(root->children[index], currPrefix, i+1);
    }
    return;
}

void TrieNode::printAutoSuggestions(TrieNode* root, string query, char str[], int level) {
    if (root->isLeaf()){
        str[level] = '\0';
        cout << str << endl;
    } 

    for (int i = 0; i < ALPHABET_SIZE; i++)  
    {
        if (root->children[i] != nullptr){
            str[level] = i + 'a';
            printAutoSuggestions(root->children[i], query, str, level+1); 
        }
    }
} 