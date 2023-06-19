#include <bits/stdc++.h> 
struct Node{
    Node* arr[26];
    int cp=0;
    int ew=0;
     
    
    bool contains(char ch){
       return arr[ch-'a']; 
    }
    void put(char ch,Node*node){
        arr[ch-'a']=node;
    }
    Node* get(char ch){
       return arr[ch-'a'];
    }
    void incPre(){
        cp++;
    }
    void incEnd(){
        ew++;
    }
    int getPre(){
        return cp;
    }
    int getEnd(){
        return ew;
    }
   
    void redPre(){    
        cp--;        
    }
    void delEnd(){
        ew--;
    }

};

class Trie{

   private:
    Node*root;
  public:
    
    Trie() {
     root=new Node();
    }
    
    void insert(string &word) {
        Node*node=root;
        for (int i = 0; i < word.length(); i++) {
          if (!node->contains(word[i])){
            node->put(word[i], new Node());          
          
        }
            node=node->get(word[i]);
            node->incPre();
            
        }
        node->incEnd();
    }  

   
    int countWordsEqualTo(string &word){
        // Write your code here.
         Node*node=root;
         
        for(int i=0;i<word.length();i++){
            if(node->contains(word[i]))            
            node=node->get(word[i]);
            else
            return 0;
            
        }
        return node->getEnd();        
       
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
           Node*node=root;
         
        for(int i=0;i<word.length();i++){
            if(node->contains(word[i]))            
            node=node->get(word[i]);
            else
            return 0;
        }
        return node->getPre();  
    }

    void erase(string &word){
        // Write your code here.
           Node*node=root;
       
        for(int i=0;i<word.length();i++){
          if (node->contains(word[i])) {            
            node = node->get(word[i]);
            node->redPre();
          }else
          return ;
        }
       node->delEnd();
    }
};
