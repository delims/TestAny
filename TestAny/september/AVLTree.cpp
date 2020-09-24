//
//  AVLTree.cpp
//  TestAny
//
//  Created by delims on 2020/9/8.
//  Copyright © 2020 delims. All rights reserved.
//

#include "AVLTree.hpp"

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
        
        void insert(int data){
            //bigger than root insert to right
            if (data > this->data) {
                if (this->right == NULL) {
                    Node *node = new Node(data);
                    this->right = node;
                    node->parent = this;
                    node->depth = this->depth + 1;
                } else {
                    this->right->insert(data);
                }
            } else {
                if (this->left == NULL) {
                    Node *node = new Node(data);
                    this->left = node;
                    node->parent = this;
                    node->depth = this->depth + 1;
                } else {
                    this->left->insert(data);
                }
            }
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
    
    void insert(int data){
        this->root->insert(data);
    }
    
    void print(){
        this->root->print();
    }
    
};


void play_tree(void)
{
    AVLTree rootNote = AVLTree(9);
    
    rootNote.insert(7);
    rootNote.insert(11);
    rootNote.insert(6);
    rootNote.insert(8);
    rootNote.insert(14);
    rootNote.insert(15);
    rootNote.insert(151);
    rootNote.insert(152);
    rootNote.insert(151);
    rootNote.insert(151);
    rootNote.insert(115);

    
    rootNote.print();
    
    
}
