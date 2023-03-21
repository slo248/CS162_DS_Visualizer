#pragma once

class Node{
    public:
        Node(int _val, Node* _pNext, Node* _pPrev);
    private:
        int val;
        Node *pNext, *pPrev;
};