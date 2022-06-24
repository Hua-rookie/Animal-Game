#ifndef BinaryTree_h
#define BinaryTree_h
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct BinaryTreeNode
{
    string content;
    BinaryTreeNode *leftChild;
    BinaryTreeNode *rightChild;
    BinaryTreeNode(string con = "#", BinaryTreeNode *lc = NULL, BinaryTreeNode *rc = NULL) : content(con), leftChild(lc), rightChild(rc) {};
};

class BinaryTree
{protected:
    BinaryTreeNode *root;
    string Refvalue;
    void postOrder(BinaryTreeNode *subTree/*,void (*visit)(BinaryTreeNode *p)*/);//后序访问，用于调试
    void CreateBinaryTree(ifstream& in,BinaryTreeNode *&subtree);//树的输入函数
    void Traverse(ofstream& out,BinaryTreeNode *subTree);//后序输出
    bool Guess(BinaryTreeNode *&Newlife,BinaryTreeNode *subTree);//层层判断，直到找到电脑认为的答案
    //int GetHeight(BinaryTreeNode *root);
    void makeEmpty(BinaryTreeNode *subtree);//将树置空
public:
    BinaryTree(string Ref = "#", BinaryTreeNode *r = NULL): Refvalue(Ref), root(r) {};
    ~BinaryTree();
    bool isEmpty() {return (root==NULL)?true:false;}//判断树是否为空
    void postOrder(/*void (*visit)(BinaryTreeNode *p)*/) {postOrder(root/*,visit*/);}//后序访问
    void Game();//
    friend ifstream& operator>>(ifstream& in,BinaryTree& Tree);//调用CreateBinaryTree后序建树
    friend ofstream& operator<<(ofstream& out,BinaryTree& Tree);//调用Traverse后序输出
};

struct Node
{
    BinaryTreeNode* t;
    Node* link;
    Node(Node* ptr = NULL) :link(ptr) {};
    Node(BinaryTreeNode* ch, Node* ptr = NULL) :t(ch), link(ptr) {};
};
class Stack
{
private:
    Node* top;
public:
    Stack() { top = NULL; }
    //~Stack();
    bool IsEmpty() { if (top == NULL) return true; else return false; }
    void Push(BinaryTreeNode*& ch) { top = new Node(ch, top); }
    void Pop(BinaryTreeNode*& subtree) { /*Node* p = top;*/ subtree = top->t; top = top->link; /*delete p;*/ }
};

/*Stack::~Stack()
{
    for (Node* p = top; top != NULL; top = top->link, delete p, p = top);
}*/
#endif /* BinaryTree_h */
