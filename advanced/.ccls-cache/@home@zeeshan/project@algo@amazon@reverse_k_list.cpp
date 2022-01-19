

#include  <iostream>

struct node
{
    int   value;
    node* next;
};


int main()
{
    node * head = nullptr;

    auto temp = new node{1, nullptr};
    head = temp;
    auto curr = new node{2, nullptr};
    temp->next = curr;
    temp = curr;

    curr = new node{4, nullptr};
    temp->next = curr;
    temp = curr;

    curr = new node{5, nullptr};
    temp->next = curr;
    temp = curr;

    curr = new node{6, nullptr};
    temp->next = curr;
    temp = curr;

    curr = new node{7, nullptr};
    temp->next = curr;
    temp = curr;

    curr = new node{8, nullptr};
    temp->next = curr;
    temp = curr;

    curr = new node{9, nullptr};
    temp->next = curr;
    temp = curr;

    curr = new node{10, nullptr};
    temp->next = curr;
    temp = curr;

    node * h_prev = nullptr;
    auto * h = head;
    int count = 1;
    int k = 3;

    while(h)
    {

    }
}
