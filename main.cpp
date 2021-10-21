#include <iostream>

using namespace std;

template<typename T>
class node {
    T num;
    node *next;
    node *prev;
public:
    node(){
        num=0;
        next= NULL;
        prev= NULL;
    }
    void set_value(T set_num) {
        num = set_num;
    }

    void append(node *another) {
        next = another;
    }

    node *get_prev() {
        return prev;
    }

    node *get_next() {
        return next;
    }

    T get_value() {
        return num;
    }
    void insert(node * to_be){
        if(this->prev){
            this->prev->next=to_be;
            to_be->prev= this->prev;
            to_be->next= this;
            this->prev=to_be;
        }else{
            to_be->next= this;
            this->prev=to_be;
        }

    }
};

#include <iostream>

using namespace std;

void test1() {

    node<int> *ptr;

    node<int> node1, node2, node3;

    node1.set_value(1);

    node2.set_value(2);

    node3.set_value(3);

    node3.insert(&node2);

    node2.insert(&node1);

    for (ptr = &node1;; ptr = ptr->get_next()) {

        cout << ptr->get_value() << " ";

        if (ptr->get_next() == NULL) {
            break;
        }

    }

}

void test2() {

    node<float> *ptr;

    node<float> node1, node2, node3;

    node1.set_value(1.1);

    node2.set_value(2.2);

    node3.set_value(3.3);

    node3.insert(&node2);

    node2.insert(&node1);

    for (ptr = &node1;; ptr = ptr->get_next()) {

        cout << ptr->get_value() << " ";

        if (ptr->get_next() == NULL) {
            break;
        }

    }

}

void test3() {

    node<char> *ptr;

    node<char> node1, node2, node3;

    node1.set_value('a');

    node2.set_value('b');

    node3.set_value('c');

    node3.insert(&node2);

    node2.insert(&node1);

    for (ptr = &node1;; ptr = ptr->get_next()) {

        cout << ptr->get_value() << " ";

        if (ptr->get_next() == NULL) {
            break;
        }

    }

}

int main() {

    int type;

    cin >> type;


    switch (type) {

        case 1:

            test1();

            break;


        case 2:

            test2();

            break;

        case 3:

            test3();

            break;

    }

    return 0;

}


