#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class ListaSimpleEnlazada{
private:
    Node* head;

public:
    ListaSimpleEnlazada(){
        head = nullptr;
    }

    // Push front
    void push_front(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Push back
    void push_back(int val){
        Node* newNode = new Node(val);

        if (!head){
            head = newNode;
            return;
        }

        Node* curr = head;

        while(curr->next){
            curr = curr->next;
        }
        curr->next = newNode;
    }

    // Pop front
    void pop_front(){
        if (!head){
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Pop back
    void pop_back(){
        if (!head){
            return;
        }
        if (!head->next){
            delete head;
            head = nullptr;
            return;
        }
        Node* curr = head;
        while (curr->next->next){
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
    }

    // Imprimir la lista
    void print(){
        Node* curr = head;
        while (curr){
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "nullptr\n";
    }

    // Destructor
    ~ListaSimpleEnlazada(){
        while (head){
            pop_front();
        }
    }
};
/* Funcion main de prueba
int main(){
    ListaSimpleEnlazada lista;
    
    lista.push_back(10);
    lista.push_back(20);
    lista.push_front(5);
    lista.print();
    
    lista.pop_back();
    lista.print(); 
    
    lista.pop_front();
    lista.print();
    
    return 0;
}
*/