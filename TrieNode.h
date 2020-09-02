#ifndef TRIENODE_H
#define TRIENODE_H
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode{
  public:
    TrieNode();
    TrieNode* children[ALPHABET_SIZE];

    void setNode(char temp);
    void setLetter(char letter);
    void setLeaf();
    void setWordEnd();

    char getLetter();
    TrieNode* getNode(char temp);

    bool isLeaf();
    bool isLastNode();
    bool isWordEnd();
    bool checkNull(char temp);
    
    void insert(TrieNode* root, string key);
    void insertRecursively(TrieNode* root, string key, int i);

    //search trie for exact match for key
    bool search(TrieNode* root, string key);
    bool searchRecursively(TrieNode* root, string key, int i);

    //finds first num words beginign w prefix key
    void prefixSearch(TrieNode* root, string key, int i, int* num);
    void printAutoSuggestions(TrieNode* root, string query, char str[], int level, int* reps);

    //finds all words begining  w prefix key
    void prefixSearch(TrieNode* root, string key, int i);
    void printAutoSuggestions(TrieNode* root, string query, char str[], int level);

    
    
    private:
      char letter;
      bool leaf;
      bool wordEnd;
      

};

#endif //TRIENODE_H