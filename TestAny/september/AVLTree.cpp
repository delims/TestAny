//
//  AVLTree.cpp
//  TestAny
//
//  Created by delims on 2020/9/8.
//  Copyright © 2020 delims. All rights reserved.
//

#include "AVLTree.hpp"
#include <stdlib.h>

class AVLTree
{
    
public:
    class Node {
        int data;
    public:
        Node *parent;
        Node *left;
        Node *right;
        int depth;

        Node(int data){
            this->data = data;
            this->right = nullptr;
            this->left = nullptr;
            this->parent = nullptr;
            this->depth = 0;
        }
        
        int getData()
        {
            return this->data;
        }
        
        Node *insert(int data){
            //bigger than root insert to right
            if (data > this->data) {
                if (this->right == NULL) {
                    Node *node = new Node(data);
                    this->right = node;
                    node->parent = this;
                    node->depth = this->depth + 1;
                    return node;
                } else {
                    this->right->insert(data);
                }
            } else {
                if (this->left == NULL) {
                    Node *node = new Node(data);
                    this->left = node;
                    node->parent = this;
                    node->depth = this->depth + 1;
                    return node;
                } else {
                    this->left->insert(data);
                }
            }
            return nullptr;
        }
        
        //以this为根节点右旋
        void r_rotate()
        {
            //右旋就是左孩子替代父节点，先拿到左孩子。
            Node *left = this->left;
            
            //让父节点指向this的左孩子。
            if (this->parent->left == this) {
                this->parent->left = left;
            } else {
                this->parent->right = left;
            }
            
            //左孩子的右孩子成为this的左孩子。
            this->left = left->right;
            //this 成为 左孩子的右孩子。
            left->right = this;
        }
        
        void l_rotate()
        {
            Node *right = this->right;
            
            if (this->parent->left == this) {
                this->parent->left = right;
            } else {
                this->parent->right = right;
            }
            
            this->right = right->left;
            
            right->left = this;
            
        }
//        前序遍历
        void print(){
            
            printf("%d  depth = %d  \n ",this->getData(),this->depth);
            
            if (this->left != NULL) {
                this->left->print();
            }
            
            if (this->right != NULL) {
                this->right->print();
            }
        }
    };
    
private:
    Node *root;
    
public:
    AVLTree(int data){
        Node *node = new Node(data);
        node->depth = 1;
        this->root = node;
    }
    
    Node *insert(int data){
        return this->root->insert(data);
        
    }
    
    void print(){
        this->root->print();
    }
    
};

class TestNew {
    int a;
    int b;
public:
    void *operator new(size_t size) {
        printf("alloc size : %zu \n",size);
        void *p = malloc(1000);
        printf("==%p \n",p);
        return p;
    }
    
};


void play_tree(void)
{
//    AVLTree rootNote = AVLTree(9);
//
//    AVLTree::Node *node = rootNote.insert(7);
//    rootNote.insert(11);
//    rootNote.insert(6);
//    rootNote.insert(8);
//    rootNote.insert(14);
//    rootNote.insert(15);
//    rootNote.insert(151);
//    rootNote.insert(152);
//    rootNote.insert(151);
//    rootNote.insert(151);
//    rootNote.insert(115);

//    node->r_rotate();
    
//    rootNote.print();
    
    
    void *p = new TestNew;
    
    
    
    printf("== %p \n",p);
    
}
