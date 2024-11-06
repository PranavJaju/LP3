//Write a program to implement Huffman Encoding using a greedy strategy. 
#include<bits/stdc++.h>
using namespace std;
class Node{
    char data;
    public:
    int freq;
    Node *left;
    Node *right;
    Node(char data,int freq){
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
    friend void printHuffmanCode(Node * root,string str);
};
struct compare{
    bool operator()(Node * l,Node * r){
        return l->freq > r->freq;
    }
};
Node * GenerateHuffmanCode(map<char,int> & freq){
    priority_queue<Node*,vector<Node*>,compare> pq;
    for(auto it = freq.begin();it!=freq.end();it++){
        pq.push(new Node(it->first,it->second));
    }
    Node * left,*right,*temp;
    while(pq.size()!=1){
        left = pq.top();
        pq.pop();
        right = pq.top();
        pq.pop();
        temp = new Node('#',left->freq+right->freq);
        temp->left = left;
        temp->right = right;
        pq.push(temp);
    }
    return pq.top();
}
void printHuffmanCode(Node * root,string str){
        if(root==NULL){
            return;
        }
        if(root->data!='#'){
            cout<<root->data<<"\t"<<str<<endl;
        }
        printHuffmanCode(root->left,str+"0");
        printHuffmanCode(root->right,str+"1");
    
}
void findFrequency(string input,map<char,int> &freq){
    for(int i = 0;i<input.length();i++){
        freq[input[i]]++;
    }
    cout<<"-----------------------------"<<endl;
    cout<<"Character\tFrequency"<<endl;
   
    for(auto it = freq.begin();it!=freq.end();it++){
        cout<<it->first<<"\t\t"<<it->second<<endl;
    }
}
int main(){
    string input;
    cout<<"Enter the string: ";
    cin>>input;
    map<char,int> freq;
    findFrequency(input,freq);

    Node * root = GenerateHuffmanCode(freq);
    cout<<"-------------------Output--------------------"<<endl;
    printHuffmanCode(root,"");
    return 0;
}