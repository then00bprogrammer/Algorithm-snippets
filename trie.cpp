#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node *links[26];
    int count=0;
    bool flag;
    
    bool containsKey(char c){
       return (links[c-'a']!=NULL); 
    }   
    
    void putKey(char c,Node* node){
       links[c-'a']=node; 
    } 
    
    Node* get(char c){
      return links[c-'a'];  
    } 

    void markWord(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
    void dfs(Node* root,vector <string> &ans,string word){
        if(root->isEnd())ans.push_back(word);
        for(char c='a';c<='z';c++){
            if(root->containsKey(c)) dfs(root->get(c),ans,word+c);
        }
    }
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){     
            if(!node->containsKey(word[i])){
                node->putKey(word[i],new Node());
            }
            node->get(word[i])->count+=1;
            node=node->get(word[i]);
        }
        node->markWord();
    }
    
    int countPrefix(string word) {
        int count=0;
        Node* node=root;
        for(int i=0;i<word.length();i++){
            count+=node->get(word[i])->count;
            node=node->get(word[i]);
        }
        return count;
    }

    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])) return false;
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])) return false;
            node=node->get(prefix[i]);
        }
        return true;
    }

    vector<string> lexi(){
        Node* node=root;
        vector <string> ans;
        dfs(node,ans,"");
        return ans;
    }
};

int main() {
    Trie trie;
    // Insert some words into the trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    trie.insert("apply");
    trie.insert("test");

    // Check if the trie contains the word "apple"
    if (trie.search("apple")) {
        cout << "Found word: apple" << endl;
    } else {
        cout << "Word not found: apple" << endl;
    }

    // Check if the trie contains the prefix "app"
    if (trie.startsWith("app")) {
        cout << "Found prefix: app" << endl;
    } else {
        cout << "Prefix not found: app" << endl;
    }

    // Count the number of words in the trie that start with the prefix "app"
    int count = trie.countPrefix("app");
    cout << "Number of words with prefix 'app': " << count << endl;

    //Sort the words lexiographically
    vector <string> ans=trie.lexi();
    for(auto word:ans)cout<<word<<" ";
    cout<<endl;

    return 0;
}
