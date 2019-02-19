//
//  main.cpp
//  #10828
//
//  Created by 조해성 on 18/02/2019.
//  Copyright © 2019 조해성. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int m_iData;
    Node(int data);
    Node();
    ~Node();
};

Node::Node(int data) {
    m_iData = data; // this->data = data;
}
Node::~Node() {
}

class Stack {
public:
    int m_iCapacity;
    int m_iTop;
    Node** m_Nodes;
    
    Stack (int m_iCapacity);
    ~Stack();
    
    void Push(int data);
    int Pop();
    int Top();
    bool IsEmpty();
    int GetSize();
};

Stack::Stack(int capacity)
{
    m_Nodes = new Node*[capacity];
    m_iCapacity = capacity;
    m_iTop = 0;
}

Stack::~Stack() {
    for(int i =0; i < m_iCapacity; i++)
    {
        if(m_Nodes[i])
            delete m_Nodes[i];
    }
    delete [] m_Nodes;
}


void Stack::Push(int data)
{
    m_Nodes[m_iTop] = new Node(data);
    ++m_iTop;
}
int Stack::Pop()
{
    if(IsEmpty())
        return -1;
    m_iTop--;
    int data = m_Nodes[m_iTop]->m_iData;
    return data;
}

int Stack::Top()
{
    if(IsEmpty())
        return -1;
    m_iTop--;
    int data = m_Nodes[m_iTop]->m_iData;
    m_iTop++;
    return data;
}
bool Stack::IsEmpty()
{
    if(m_iTop == 0)
        return 1;
    return 0;
}

int Stack::GetSize()
{
    return m_iTop;
}

int main(int argc, const char * argv[]) {
    int i_N;
    cin >> i_N;
    Stack stack(10001);

    for(int i =0; i< i_N; i++)
    {
        string s_Do;
        cin >> s_Do;
        if(s_Do == "push")
        {
            int i_PushData;
            cin >> i_PushData;
            stack.Push(i_PushData);
        }
        else if(s_Do == "pop")
        {
            int temp1 =0;
            temp1 = stack.Pop();
            cout << temp1 << endl;
        }
        else if(s_Do == "size")
        {
            cout << stack.GetSize() << endl;
        }
        else if(s_Do == "empty")
        {
            cout << stack.IsEmpty() << endl;
        }
        else if(s_Do == "top")
        {
            int temp2 = 0;
            temp2 = stack.Top();
            cout << temp2 << endl;

        }

    }

    return 0;
}
