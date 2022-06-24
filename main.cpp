#include <iostream>
#include <string>
#include <fstream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree A;
    ifstream fin;
    fin.open("SJJG", ios::in);
    fin >> A;//从文件输入并建树
    A.postOrder();//调试时输出整棵树，观察树是否建对
    int x = 1;
    while (x) {
        A.Game();
        cout << "退出请输入0";
        cout << "继续请输入1";
        cin >> x;
    }
    ofstream fout;
    fout.open("SJJG", ios::out);
    fout << A;//输出到文件
    fout.close();
}

/*int main() {
    BinaryTree A;
    ofstream fout;
    fout.open("animal.data", ios::out);
    fout << "monkey" << endl << "bat" << endl << "fly?" << endl << "snake" << endl << "mammal?" << endl;
    fout.close();
    ifstream fin;
    fin.open("animal.data", ios::in);
    fin >> A;
    A.postOrder();
    int x = 1;
    while (x) {
        A.Game();
        cout << "退出请输入0";
        cout << "继续请输入1"<<endl;
        cin >> x;
    }
    fout.open("animal.data", ios::out);
    fout << A;
    fout.close();
}*/


/*void display(BinaryTreeNode *p)
{
    cout<<p->content<<endl;
}*/

/*int main() {
    BinaryTree A;
    string filename="SJJG";
    ofstream fout(filename.c_str());
    fout<<"monkey"<<endl<<"bat"<<endl<<"fly?"<<endl<<"snake"<<endl<<"mammal?"<<endl;
    fout.close();
    ifstream fin(filename.c_str());
    //char a;
    //while (fin.get(a))
        //cout<<a;
    //ifile.open("animal.data", ios::in);
    fin >> A;
    //BinaryTreeNode *p;
    A.postOrder();
    int x = 1;
    while (x) {
        A.Game();
        cout << "退出请输入0";
        cout << "继续请输入1";
        cin >> x;
    }
    fout.open(filename);
    //ofstream fout(filename.c_str());
    //ofile.open("/Users/apple/Documents/animal", ios::out);
    fout << A;
    //ifile.close();
}*/
/*int main() {
    BinaryTree A;
    string filename = "m_animal";
    ofstream fout(filename.c_str());
    fout<<"monkey"<<endl<<"bat"<<endl<<"fly?"<<endl<<"snake"<<endl<<"mammal?"<<endl;
    fout.close();
    ifstream fin;//(filename.c_str());
    fin.open("m_animal", ios::in);
    fin >> A;
    A.postOrder();
    int x = 1;
    while (x) {
        A.Game();
        cout << "退出请输入0";
        cout << "继续请输入1"<<endl;
        cin >> x;
    }
    fout.open("m_animal", ios::out);
    fout << A;
    fout.close();
}*/


