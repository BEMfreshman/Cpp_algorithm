//
// Created by 杨文露 on 2019-03-09.
//

#ifndef CPP_ALGORITHM_BTREE_H
#define CPP_ALGORITHM_BTREE_H

#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class Stack:public stack<T>
{
public:
    T pop()
    {
        T tmp = stack<T>::top();
        stack<T>::pop();

        return tmp;
    }
};

template<typename T>
class Queue:public queue<T>
{
public:
    T dequeue()
    {
        T tmp = queue<T>::front();
        queue<T>::pop();
        return tmp;
    }

    void enqueue(const T& el)
    {
        push(el);
    }
};

template<typename T>
class BSTNode
{
public:
    BSTNode()
    {
        left = right = nullptr;
    }

    explicit BSTNode(const T& e,BSTNode<T> *l= nullptr,BSTNode<T> *r = nullptr)
    {
        el = e;
        left = l;
        right = r;
    }

    const T getel() const
    {
        return el;
    }

    const BSTNode<T>* getLeft() const
    {
        return left;
    }

    const BSTNode<T>* getRight() const
    {
        return right;
    }

    BSTNode<T>* getLeft()
    {
        return left;
    }

    BSTNode<T>* getRight()
    {
        return right;
    }

private:
    T el;
    BSTNode<T> *left,*right;

};

template <typename T>
class BST
{
public:
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {

    }

    void clear()
    {
        clear(root);
        root = nullptr;
    }

    bool isempty() const
    {
        return root == nullptr;
    }

    void breadthFirst();

    void preorder();
    void inorder();

    T* search(const T* el) const;     //查找



protected:
    BSTNode<T>* root;          //根节点


protected:
    void clear(BSTNode<T>*);
    T* search(BSTNode<T>*,const T&) const;
    void preorder(BSTNode<T>*);
    void inorder(BSTNode<T>*);
    void postorder(BSTNode<T>*);


    void iterativeinorder();
    void iterativepreorder();
    void iterativepostorder();

    virtual void visit(BSTNode<T>* p)
    {
        cout << p->getel() << endl;
    }
};


template <typename T>
T* BST<T>::search(BSTNode<T>* p,const T& el) const
{
    while(p != nullptr)
    {
        if(p->getel() == el)
        {
            return &(p->getel());
        }
        else if(p->getel() < el)
        {
            p = p->getRight();
        }
        else if(p->getel() > el)
        {
            p = p->getLeft();
        }
    }

    return nullptr;

}

template <typename T>
void BST<T>::breadthFirst()
{
    Queue<BSTNode<T>*> queue;

    BSTNode<T> *p = root;
    if(p != nullptr)
    {
        queue.enqueue(p);
        while(!queue.empty())
        {
            p = queue.dequeue();
            visit(p);

            if(p->getLeft() != nullptr)
            {
                queue.enqueue(p->getLeft());
            }

            if(p->getRight() != nullptr)
            {
                queue.enqueue(p->getRight());
            }
        }
    }
}

template <typename T>
void BST<T>::inorder(BSTNode<T>* p)
{
    if(p != nullptr)
    {
        inorder(p->getLeft());
        visit(p);
        inorder(p->getRight());
    }
}

template<typename T>
void BST<T>::postorder(BSTNode<T> *p)
{
    if(p != nullptr)
    {
        postorder(p->getLeft());
        postorder(p->getRight());
        visit(p);
    }
}

template <typename T>
void BST<T>::preorder(BSTNode<T> *p)
{
    if( p!= nullptr)
    {
        visit(p);
        preorder(p->getLeft());
        preorder(p->getRight());
    }
}

template <typename T>
void BST<T>::iterativepreorder()
{
    Stack<BSTNode<T>*> tmpStack;
    BSTNode<T>* p = root;
    if(p != nullptr)
    {
        tmpStack.push(p);
        while(!tmpStack.empty())
        {
            p = tmpStack.pop();
            visit(p);

            if(p->getRight() != nullptr)
            {
                tmpStack.push(p->getRight());
            }

            if(p->getLeft() != nullptr)
            {
                tmpStack.push(p->getLeft());
            }
        }
    }
}



template <typename T>
void BST<T>::iterativepostorder()
{
    Stack<BSTNode<T>*> tmpStack;
    BSTNode<T> *p = root, *q = root;

    while( p != nullptr)
    {
        for(; p->getLeft() != nullptr; p = p->getLeft())
        {
            tmpStack.push(p);
        }

        while(p->getRight() == nullptr || p->getRight() == q)
        {
            visit(p);
            q = p;
            if(tmpStack.empty())
            {
                return;
            }
            p = tmpStack.pop();
        }

        tmpStack.push(p);
        p = p->getRight();
    }
}

template <typename T>
void BST<T>::iterativeinorder()
{

}





#endif //CPP_ALGORITHM_BTREE_H
