#include <iostream>
#include "BinaryTree.h"
using namespace std;

void BinaryTree::postOrder(BinaryTreeNode *subTree/*,void (*visit)(BinaryTreeNode *p)*/)//后序访问，用于调试
{
    //if (subTree->content!= Refvalue)
    if (subTree->leftChild != NULL)
    {
        postOrder(subTree->leftChild/*, visit*/);
        postOrder(subTree->rightChild/*, visit*/);
    }
    cout<<subTree->content<<endl;
}

void BinaryTree::Traverse(ofstream& out,BinaryTreeNode *subTree)//后序遍历输出整棵树
{
    if (subTree!=NULL)
    {
        Traverse(out, subTree->leftChild);
        Traverse(out, subTree->rightChild);
        out<<subTree->content<<endl;
    }
}
ofstream& operator<<(ofstream& out,BinaryTree& Tree)//重载<<，方便主函数操作
{
    Tree.Traverse(out, Tree.root);
    return out;
}

void BinaryTree::CreateBinaryTree(ifstream& in, BinaryTreeNode*& subtree)//利用栈，后序建树
{
    Stack a;
    BinaryTreeNode* Tree1 = NULL;
    BinaryTreeNode* Tree2 = NULL;
    BinaryTreeNode* Tree3 = NULL;
    string str="#", cur="#";
    while (in >> str)//输入不为空则循环不停
    {
        cur = str.substr(str.length() - 1, str.length());//取获得的string的最后一个字符
        if (cur == "?")//如果为问号，则出栈两个树节点并与新建立的结点链接，并将新节点入栈
        {
            Tree3 = new BinaryTreeNode(str);
            a.Pop(Tree1);
            a.Pop(Tree2);
            Tree3->leftChild =  Tree2;
            Tree3->rightChild = Tree1;
            a.Push(Tree3);
        }
        else {//否则，创建新节点直接入栈
            Tree1 = new BinaryTreeNode(str);//
            a.Push(Tree1);
        }
    }
    subtree = Tree3;//循环结束，根据后序的规律，让根节点指向最后建立的结点
}

ifstream& operator>>(ifstream& in, BinaryTree& Tree)//重载运算符>>，便于主函数操作
{
     Tree.CreateBinaryTree(in, Tree.root);
     return in;
};


BinaryTree::~BinaryTree()//析构函数
{
    if (!isEmpty())
       makeEmpty(root);
}

void BinaryTree::makeEmpty(BinaryTreeNode *subtree)//后序置空
{
    if (subtree != NULL)
    {
        makeEmpty(subtree->leftChild);
        makeEmpty(subtree->rightChild);
        delete subtree;
    }
}

bool BinaryTree::Guess(BinaryTreeNode*& Newlife, BinaryTreeNode* subTree)
{
    cout << subTree->content << endl;
    Newlife = subTree;
    string answer;
x: cout << "right Y, wrong N" << endl;
    cin >> answer;
    if (answer == "Y" && subTree->leftChild != NULL)
        return Guess(Newlife, subTree->leftChild);
    else if (answer == "N" && subTree->rightChild != NULL)
        return Guess(Newlife, subTree->rightChild);
    else if (answer == "Y" && (subTree->leftChild == NULL))
        return true;
    else if (answer == "N" && (subTree->rightChild == NULL))
        return false;
    else if (answer != "Y" || answer != "N")
    {
        cout << "Y or N" << endl;
        goto x;
    }
    return false;
}
void BinaryTree::Game()
{
    BinaryTreeNode* Newlife;
    if (Guess(Newlife, root)==false)
    {
        cout << "you win,give us the character and thing" << endl;
        string character, Newname, Oldname;
        cin >> character >> Newname;
        Oldname = Newlife->content;
        Newlife->content = character;
        //if (Newlife->rightChild == NULL && Newlife->leftChild == NULL)
        //{
        Newlife->rightChild = new BinaryTreeNode;
        Newlife->leftChild = new BinaryTreeNode;
        //}
        Newlife->leftChild->content = Newname;
        Newlife->rightChild->content = Oldname;
    }
    else
    {
        cout << "you lose" << endl;
    }
}
