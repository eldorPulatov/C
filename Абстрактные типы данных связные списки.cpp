#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next = NULL;
};

class List{
    Node *Head;
public:
    List();
    void push(const int &value);
    void sortList();
    ~List();
    friend ostream& operator<<(ostream &out, List &list);
};


List::List(){
    Head = NULL;
}


void List::push(const int &value){
    Node *tmp = new Node;
    tmp->data = value;
    if(Head == NULL){
        Head = tmp;
        return;
    }
        
    Node *cur = Head;
    while(cur->next)
        cur = cur->next;
    cur->next = tmp;
}


void List::sortList(){
    Node *cur = Head;
    Node *tmp = Head;
    int q;
    while(tmp){
        while(cur){
            if(cur->data > tmp->data){
                q = tmp->data;
                tmp->data = cur->data;
                cur->data = q;
            }
        cur = cur->next;
        }
        
        cur = Head;
        tmp = tmp->next;
    }
}


List::~List(){
    Node *cur;
    while(Head){
        cur = Head;
        Head = Head->next;
        delete cur;
    }
}


ostream& operator<<(ostream &out, List &list){
    Node *cur = list.Head;
    while(cur){
        out << cur->data << " ";
        cur = cur->next;
    }
    
    return out;
}


int main()
{
    List l;
    
    l.push(5);
    l.push(5);
    l.push(5);
    l.push(5);
    l.push(5);
    l.push(5);
    
    cout << "List 1: ";
    cout << l << endl;
    
    List l1;
    
    l1.push(54);
    l1.push(52);
    l1.push(5);
    l1.push(5325);
    l1.push(5523);
    l1.push(5524);
    
    cout << "List 2: ";
    cout << l1 << endl;
    
    l1.sortList();
    
    cout << "Sort list 2: ";
    cout << l1 << endl;
    
    return 0;
}