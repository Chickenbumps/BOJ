#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct node{
    int m_Data;
    struct node* left;
    struct node* right;
}Node;

int CountSubtree(Node *node)
{
    if(!node)
        return 1;
    if(node->left == NULL && node->right == NULL)
        return 1;
    else
        return (CountSubtree(node->right) + CountSubtree(node->left));
}
int main()
{
    ifstream fin;
    fin.open("input.txt");
    int i_Case;
    fin >> i_Case;
    int i_TotalNode;
    for(int i = 0; i < i_Case; i++)
    {
        fin >> i_TotalNode;
        Node nodearr[i_TotalNode +1];
        for (int j = 1; j <= i_TotalNode ; ++j) {
            nodearr[j].m_Data =j;
            nodearr[j].left = NULL;
            nodearr[j].right = NULL;
        }
        for (int k = 1; k <= i_TotalNode ; ++k) {
            int index,data1,data2;
            fin >> index >> data1 >> data2;
            if(data1 != -1)
                nodearr[index].left = &nodearr[data1];
            if(data2 != -1)
                nodearr[index].right = &nodearr[data2];
        }
        int i_Count =0;
        int leftTreeNode,rightTreeNode;
        for (int l = 1; l <= i_TotalNode ; ++l) {
            int leftdata = 0, rightdata =0;
            if(nodearr[l].left) leftdata  = nodearr[l].left->m_Data;
            if(nodearr[l].right) rightdata = nodearr[l].right->m_Data;

            if(leftdata == 0  && rightdata == 0)
                leftTreeNode = rightTreeNode = 0;
            else if(leftdata == 0)
            {
                leftTreeNode = 0;
                rightTreeNode = CountSubtree(&nodearr[rightdata]);
            }
            else if(rightdata == 0)
            {
                leftTreeNode = CountSubtree(&nodearr[leftdata]);
                rightTreeNode= 0;
            }
            else
            {
                leftTreeNode = CountSubtree(&nodearr[leftdata]);
                rightTreeNode = CountSubtree(&nodearr[rightdata]);
            }
            if(leftTreeNode < rightTreeNode) i_Count++;
        }
        cout << i_Count << endl;
    }
}
