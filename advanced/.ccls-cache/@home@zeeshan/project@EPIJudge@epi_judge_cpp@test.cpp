
#include <iostream>
#include <memory>

struct Node {
    int data;
    std::shared_ptr<Node> next;
    Node(int data) : data{data}, next{nullptr} {}
    ~Node() {
        std::cout << "Destroy node with data: " << data << '\n';
    }
 };
 
int main() {
    /*
     auto n0{std::make_unique<Node>(0)};
 
     auto n1{std::make_unique<Node>(1)};
     n1->next = std::move(n0);
 
     auto n2{std::make_unique<Node>(2)};
     n2->next = std::move(n1);

     n0->next = std::move(n2);
     std::cout << "Done\n";
     */
     auto n0{std::make_shared<Node>(0)};
 
     auto n1{std::make_shared<Node>(1)};
     n1->next = n0;
 
     auto n2{std::make_shared<Node>(2)};
     n2->next = n1;

     n2->next = n0;
     std::cout << "Done\n";
 }
