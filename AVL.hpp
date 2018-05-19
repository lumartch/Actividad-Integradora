#ifndef AVL_hpp
#define AVL_hpp

#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class NodeException : public exception {
private:
    string msg;

public:
    explicit NodeException(const char* message) : msg(message) { }
    explicit NodeException(const string& message) : msg(message) { }
    virtual ~NodeException() throw () { }
    virtual const char* what() const throw() {
        return msg.c_str();
    }
};

template <class T>
class Node {
private:
    Node<T>* left;
    Node<T>* right;
    T* dataPtr;
public:
    int cantB;
    Node();
    Node(const T&);
    ~Node();


    T* getDataPtr();
    T& getData();

    Node<T>*& getRight();
    Node<T>*& getLeft();

    void setDataPtr(T*);
    void setData(const T&);
    void setRight(Node<T>*&);
    void setLeft(Node<T>*&);

};

template <class T>
Node<T>::Node() : left(nullptr), right(nullptr), dataPtr(nullptr), cantB(0) { }

template <class T>
Node<T>::Node(const T&e) : left(nullptr), right(nullptr) {
    if((dataPtr = new T(e)) == nullptr) {
        throw NodeException("Posicion invalida, tratando de insertar.");
    }

}

template <class T>
Node<T>::~Node() { delete dataPtr; }

template <class T>
T* Node<T>::getDataPtr() {
    return dataPtr;
}

template <class T>
T& Node<T>::getData() {
    if(dataPtr == nullptr) {
        throw NodeException("Dato inexistente, getData de nodo.");
    }

    return *dataPtr;
}

template <class T>
Node<T>*& Node<T>::getRight() {
    return right;
}

template <class T>
Node<T>*& Node<T>::getLeft() {
    return left;
}

template <class T>
void Node<T>::setDataPtr(T* p) {
    dataPtr = p;
}

template <class T>
void Node<T>::setData(const T&e) {
    if(dataPtr == nullptr) {
        if((dataPtr = new T(e)) == nullptr) {
            throw NodeException("Memoria no disponible, creando data, setData de node.");
        }
    }
    else { *dataPtr = e; }
}

template <class T>
void Node<T>::setRight(Node<T>*& p) {
    right = p;
}

template <class T>
void Node<T>::setLeft(Node<T>*& p) {
    left = p;
}

//Arbol binario

class BTreeException : public exception {
private:
    string msg;

public:
    explicit BTreeException(const char* message) : msg(message) { }
    explicit BTreeException(const string& message) : msg(message) { }
    virtual ~BTreeException() throw () { }
    virtual const char* what() const throw() {
        return msg.c_str();
    }
};

template <class T>
class BTree {
private:
    Node<T>* root;
    void insertData(Node<T>*&, const T&);
    void deleteData(Node<T>*&, Node<T>*&);
    unsigned int getHeight(Node<T>*&);
    Node<T>*& getLowest(Node<T>*&);
    Node<T>*& getBiggest(Node<T>*&);
    Node<T>*& findData(Node<T>*&, const T&);

    void preOrder(Node<T>*&);
    void inOrder(Node<T>*&);
    void postOrder(Node<T>*&);

    void deleteAll(Node<T>*&);

    int getBalanceFactor(Node<T>*&);

    void doBalancing(Node<T>*&);

    void simpleRotationToTheLeft(Node<T>*&);
    void simpleRotationToTheRight(Node<T>*&);

    void doubleRotationToTheLeft(Node<T>*&);
    void doubleRotationToTheRight(Node<T>*&);

    void findMinSearch(Node<T>*&r);
    void vecPEliminar(Node<T>*&r);
    void findEliminar(Node<T>*&r,const T&);

public:
    int menorCantB;
    Node<T>* menorDataB;
    Node<T>*& menorParaEliminar();
    void insertarEliminar(const T&e);
    vector<pair<T, int>>vec;
    void Eliminar(const T&);


    BTree();
    ~BTree();

    bool isEmpty();

    void insertData(const T&);
    void deleteData(Node<T>*&);

    T& retrieveData(Node<T>*&);
    Node<T>*& findData(const T&);

    unsigned int getHeight();

    Node<T>*& getLowest();
    Node<T>*& getBiggest();

    bool isLeaf(Node<T>*&);

    void preOrder();
    void inOrder();
    void postOrder();

    void deleteAll();

};
template<class T>
void BTree<T>::insertData(Node<T>*&r, const T&e) {
    if(r == nullptr) {
        try {
            r = new Node<T>(e);
            r->cantB=0;
            if(r == nullptr) {

                throw BTreeException("Memoria no disponible.");
            }
        }
        catch(NodeException ex) {
            BTreeException("error");
        }
    }
    else {
        if(e < r->getData()) {
            insertData(r->getLeft(), e);
        }
        else {
            insertData(r->getRight(), e);
        }

        doBalancing(r);
    }
}

template<class T>
void BTree<T>::deleteData(Node<T>*&, Node<T>*&) {

}

template<class T>
unsigned int BTree<T>::getHeight(Node<T>*&r) {
    if(r == nullptr) {
        return 0;
    }

    unsigned lH(getHeight(r->getLeft()));
    unsigned rH(getHeight(r->getRight()));

    return 1 + (lH > rH ? lH : rH);
}

template<class T>
void BTree<T>::preOrder(Node<T>*&r) {
    if(r == nullptr) {
        return;
    }

    std::cout << r->getData() << ", ";
    preOrder(r->getLeft());
    preOrder(r->getRight());
}


template<class T>
void BTree<T>::findMinSearch(Node<T>*&r) {
    if(r == nullptr) {
        return;
    }

    findMinSearch(r->getLeft());
    if(r->cantB < menorCantB){
        menorCantB = r->cantB;
        menorDataB = r;
    }
    findMinSearch(r->getRight());
}
template<class T>
Node<T>*& BTree<T>::menorParaEliminar(){
    menorCantB=INT_MAX;
    menorDataB=nullptr;
    findMinSearch(root);
    return menorDataB;
}


template<class T>
void BTree<T>::vecPEliminar(Node<T>*&r) {
    if(r == nullptr) {
        return;
    }
    vecPEliminar(r->getLeft());
    //cout<<r->getData()<<endl;
    if(!(r->getData() == menorDataB->getData())){
        pair<T, int>par;
        par.first=r->getData();
        par.second=r->cantB;
        vec.push_back(par);
    }
    vecPEliminar(r->getRight());
}
template<class T>
void BTree<T>::insertarEliminar(const T&e){
    //insertData(root, e);
    vec.clear();
    menorParaEliminar();
    vecPEliminar(root);
    root = nullptr;
    for (unsigned int i=0; i<vec.size(); i++) {
        insertData(root,vec[i].first);
        findData(vec[i].first)->cantB=vec[i].second;
    }
    insertData(root,e);
    findData(e)->cantB=1;
}


template<class T>
void BTree<T>::findEliminar(Node<T>*&r,const T&e) {
    if(r == nullptr) {
        return;
    }
    findEliminar(r->getLeft(),e);
    if(!(r->getData() == e)){
        pair<T, int>par;
        par.first=r->getData();
        par.second=r->cantB;
        vec.push_back(par);
    }
    findEliminar(r->getRight(),e);
}

template<class T>
void BTree<T>::Eliminar(const T&e){
    vec.clear();
    findEliminar(root,e);
    root = nullptr;
    for (unsigned int i=0; i<vec.size(); i++) {
        insertData(root,vec[i].first);
        findData(vec[i].first)->cantB=vec[i].second;
    }
    ifstream file(string(DIR) + string(ARCH_USR));
    if(!file.good()){
        return;
    }
    while(!file.eof()){
        Usuario usr;
        file.read((char*)&usr, sizeof(Usuario));
        if(file.eof()){break;}
        if(findData(usr)==nullptr){
            insertData(root, usr);
            break;
        }
        //arbol.insertData(usr);
    }
    file.close();
}


template<class T>
void BTree<T>::inOrder(Node<T>*&r) {
    if(r == nullptr) {
        return;
    }

    inOrder(r->getLeft());
    std::cout << r->getData() <<r->cantB<< ", ";
    inOrder(r->getRight());
}

template<class T>
void BTree<T>::postOrder(Node<T>*&r) {
    if(r == nullptr) {
        return;
    }

    postOrder(r->getLeft());
    postOrder(r->getRight());
    std::cout << r->getData() << ", ";
}

template<class T>
Node<T>*& BTree<T>::getLowest(Node<T>*&r) {
    if(r == nullptr or r->getLeft() == nullptr) {
        return r;
    }

    return getLowest(r->getLeft());
}

template<class T>
Node<T>*& BTree<T>::getBiggest(Node<T>*&r) {
    if(r == nullptr or r->getRight() == nullptr) {
        return r;
    }

    return getBiggest(r->getRight());
}

template<class T>
Node<T>*& BTree<T>::findData(Node<T>*&r, const T&e) {
    if(r == nullptr or e == r->getData()) {
        return r;
    }
    if(e < r->getData()) {
        return findData(r->getLeft(),e);
    }
    else {
        return findData(r->getRight(),e);
    }
}

template<class T>
void BTree<T>::deleteAll(Node<T>*&) {

}

template<class T>
int BTree<T>::getBalanceFactor(Node<T>*& r) {
    return getHeight(r->getRight()) - getHeight(r->getLeft());
}

template<class T>
void BTree<T>::doBalancing(Node<T>*& r) {
    switch(getBalanceFactor(r)){
        case 2: ///Esta desbalanceado a la derecha
            if(getBalanceFactor(r->getRight()) == 1){///Coincide signo
                //cout << "RSI [" << r->getData() << "]" << std::endl;
                simpleRotationToTheLeft(r);
            }
            else{
                //cout << "RDI [" << r->getData() << "]" << std::endl;
                doubleRotationToTheLeft(r);
            }

            break;

        case -2: ///Esta desbalanceado a la izquierda
            if(getBalanceFactor(r->getLeft()) == -1){///coincide signo
                //cout << "RSD [" << r->getData() << "]" << std::endl;
                simpleRotationToTheRight(r);
            }
            else{
                //cout << "RDD [" << r->getData() << "]" << std::endl;
                doubleRotationToTheRight(r);
            }
            break;
    }
}

template<class T>
void BTree<T>::simpleRotationToTheLeft(Node<T>*& r) {
    Node<T>* aux1(r->getRight());
    Node<T>* aux2(aux1->getLeft());

    r->setRight(aux2);
    aux1->setLeft(r);
    r = aux1;
}

template<class T>
void BTree<T>::simpleRotationToTheRight(Node<T>*& r) {
    Node<T>* aux1(r->getLeft());
    Node<T>* aux2(aux1->getRight());

    r->setLeft(aux2);
    aux1->setRight(r);
    r = aux1;
}

template<class T>
void BTree<T>::doubleRotationToTheLeft(Node<T>*& r) {
    simpleRotationToTheRight(r->getRight());
    simpleRotationToTheLeft(r);
}

template<class T>
void BTree<T>::doubleRotationToTheRight(Node<T>*& r) {
    simpleRotationToTheLeft(r->getLeft());
    simpleRotationToTheRight(r);
}



template<class T>
BTree<T>::BTree() : root(nullptr) {
}

template<class T>
BTree<T>::~BTree() {
    deleteAll();
}

template<class T>
bool BTree<T>::isEmpty() {
    return root == nullptr;
}

template<class T>
void BTree<T>::insertData(const T&e) {
    insertData(root, e);
}

template<class T>
void BTree<T>::deleteData(Node<T>*&r) {
    if(r == nullptr) {
        return;
    }

    deleteAll(r->getLeft());
    deleteAll(r->getRight());
    delete r;
}

template<class T>
T& BTree<T>::retrieveData(Node<T>*&r) {
    return r->getData();
}

template<class T>
Node<T>*& BTree<T>::findData(const T&e) {
    return findData(root, e);
}

template<class T>
unsigned int BTree<T>::getHeight() {
    return getHeight(root);
}

template<class T>
Node<T>*& BTree<T>::getLowest() {
    return getLowest(root);
}

template<class T>
Node<T>*& BTree<T>::getBiggest() {
    return getBiggest(root);
}

template<class T>
bool BTree<T>::isLeaf(Node<T>*&r) {
    return r != nullptr and (r->getLeft() == r->getRight());
}

template<class T>
void BTree<T>::preOrder() {
    preOrder(root);
}

template<class T>
void BTree<T>::inOrder() {
    inOrder(root);
}

template<class T>
void BTree<T>::postOrder() {
    postOrder(root);
}

template<class T>
void BTree<T>::deleteAll() {
    deleteAll(root);

    root = nullptr;
}

#endif /* AVL_hpp */
