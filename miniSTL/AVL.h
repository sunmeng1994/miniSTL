//
//  AVL.h
//  miniSTL
//
//  Created by dogrest on 15/9/15.
//  Copyright (c) 2015年 dogrest. All rights reserved.
//

#ifndef miniSTL_AVL_h
#define miniSTL_AVL_h
#include <iostream>
template<typename T,typename G>
class TreeNode{
public:
    T data;//键
    G val;//值
    TreeNode<T,G>*parent;
    TreeNode<T,G>*left;
    TreeNode<T,G>*right;
    TreeNode(T m_data=T(),G m_val=G(),
             TreeNode<T,G>*m_parent=NULL,
             TreeNode<T,G>*m_left=NULL,
             TreeNode<T,G>*m_right=NULL
             ):data(m_data),val(m_val),
    parent(m_parent),left(m_left),right(m_right)
    {
        std::cout<<"#start a treenode#"<<std::endl;}
    ~TreeNode(){std::cout<<"#kill a TreeNode#"<<data<<std::endl;}
};

template<typename T,typename G>
class Tree{
protected:
    TreeNode<T,G>*root;
public:
    Tree(TreeNode<T,G>*m_root=NULL);
    ~Tree();
private:
    TreeNode<T,G>*Find(const T&data,TreeNode<T,G>*p)const;
    TreeNode<T,G>*FindMin(TreeNode<T,G>*p)const;
    TreeNode<T,G>*FindMax(TreeNode<T,G>*p)const;
    void DestroyNode(TreeNode<T,G>*p);
    
    void PreOrderTraverse(
                          const TreeNode<T,G>*p)const ;
    
    void InOrderTraverse(const TreeNode<T,G>*p) ;
    
    void PostOrderTraverse(
                           const TreeNode<T,G>*p,
                           void(*Visit)(TreeNode<T,G>*j))const;
public:
    
    TreeNode<T,G>*Find(const T&data)const;
    TreeNode<T,G>*FindMin()const;
    TreeNode<T,G>*FindMax()const;
    TreeNode<T,G>* GetRoot() ;
public:
    TreeNode<T, G> * operator[](const T&  t);
    int IsEmpty()const;
    void Destroy();
    void PreOrderTraverse(void(*Visit)(TreeNode<T,G>*j))const;
    void InOrderTraverse();
    void PostOrderTraverse(void(*Visit)(TreeNode<T,G>*j))const;
    int GetDepth()const;
    int GetDepth(const TreeNode<T,G>*p)const;
private:
    TreeNode<T,G>*AVLInsert(const T&data,TreeNode<T,G>*p);
public:
    TreeNode<T,G>*AVLInsert(const T&data);
    TreeNode<T,G>*LeftLeftRotate(TreeNode<T,G>*p);
    TreeNode<T,G>*RightLeftRotate(TreeNode<T,G>*p);
    TreeNode<T,G>*RightRightRotate(TreeNode<T,G>*p);
    TreeNode<T,G>*LeftRightRotate(TreeNode<T,G>*p);
};
//自带平衡的插入
template<typename T,typename G>
TreeNode<T,G>* Tree<T,G>::AVLInsert(const T&data,
                                    TreeNode<T,G>*p){
    if(p==NULL)
    {
        p=new TreeNode<T,G>;
        p->data=data;
        p->left=NULL;
        p->right=NULL;
        if(root==NULL)
        {
            root=p;
            root->parent=NULL;
        }
    }
    else if(data<p->data)
    {
        p->left=AVLInsert(data, p->left);
        if(p->left)
            p->left->parent=p;
        if((GetDepth(p->left)-GetDepth(p->right))==2)
        {
            if(data<p->left->data)
                p=LeftLeftRotate(p);
            else if(data>p->left->data)
                p=RightLeftRotate(p);
        }
    }
    else if (data>p->data)
    {
        p->right=AVLInsert(data, p->right);
        if(p->right)
            p->right->parent=p;
        if((GetDepth(p->right)-GetDepth(p->left))==2)
        {
            if(data>p->right->data)
                p=RightRightRotate(p);
            else if (data<p->right->data)
                p=LeftRightRotate(p);
        }
    }
    return p;
    
}

//重载[]运算符
template<typename T,typename G>
TreeNode<T, G> *Tree<T,G>::operator[](const T& t){
    TreeNode<T,G>*c=Find(t);
    
    if(c==NULL) {
        c= AVLInsert(t);
    }
    return c;
}
//自带平衡的插入
template<typename T,typename G>
TreeNode<T,G>* Tree<T,G>::AVLInsert(const T&data){
    return  AVLInsert(data, root);
}

template<typename T,typename G>
TreeNode<T,G>* Tree<T,G>::LeftLeftRotate(TreeNode<T,G>*p){
    TreeNode<T,G>*temp=p->left;
    p->left=temp->right;
    temp->right=p;
    p->parent=temp;
    if(p->left){
        p->left->parent=p;
    }
    if(root==p)root=temp;
    std::cout<<"左旋一次"<<std::endl;
    return temp;
}
template<typename T,typename G>
TreeNode<T,G>* Tree<T,G>::RightRightRotate(TreeNode<T,G>*p){
    TreeNode<T,G>*temp=p->right;
    p->right=temp->left;
    temp->left=p;
    temp->parent=p->parent;
    p->parent=temp;
    if(p->right){
        p->right->parent=p;
    }
    if(root==p){
        root=temp;
    }
    std::cout<<"右旋一次"<<std::endl;
    return temp;
}
template<typename T,typename G>
TreeNode<T,G>* Tree<T,G>::LeftRightRotate(TreeNode<T,G>*p){
    std::cout<<"左右旋一次"<<std::endl;
    p->right=LeftLeftRotate(p->right);
    return RightRightRotate(p);
}

template<typename T,typename G>
TreeNode<T,G>*Tree<T,G>::RightLeftRotate(TreeNode<T,G>*p){
    std::cout<<"右左旋一次"<<std::endl;
    p->left=RightRightRotate(p->left);
    return LeftLeftRotate(p);
}


//构造函数
template<typename T,typename G>
inline Tree<T,G>::Tree(TreeNode<T,G>*m_root):root(m_root)
{
    std::cout<<"#START A TREE#"<<std::endl;
}

//析构函数
template<typename T,typename G>
inline Tree<T,G>::~Tree(){
    std::cout<<"#KILL A TREE#"<<std::endl;
    Destroy();
}
template<typename T,typename G>
inline void Tree<T,G>::DestroyNode(TreeNode<T,G>*p){
    if(p){
        if(p->left)
            DestroyNode(p->left);
        if(p->right)
            DestroyNode(p->right);
        delete p;
    }
}
template<typename T,typename G>
inline void Tree<T,G>::Destroy(){
    DestroyNode(root);
    root=NULL;
}
/*
 template<typename T,typename G>
 inline void Tree<T,G>::PreOrderTraverse(
 void(*Visit)(const T&data))const {
 PreOrderTraverse(root,Visit);
 }
 
 
 template<typename T,typename G>
 inline void Tree<T,G>::PreOrderTraverse(
 const TreeNode<T,G>*p,void(*Visit)(const T&data))const {
 if(p!=NULL){
 Visit(p->data);
 PreOrderTraverse(p->left,Visit);
 PreOrderTraverse(p->right,Visit);
 }
 }
 */

//中序遍历
template<typename T,typename G>
inline void Tree<T,G>::InOrderTraverse()
{
    InOrderTraverse(root);
}
template<typename T,typename G>
inline void Tree<T,G>::InOrderTraverse(const TreeNode<T,G>*p)
{
    if(p!=NULL){
        InOrderTraverse(p->left);
        std::cout<<p->data<<":"<<p->val<<std::endl;
        InOrderTraverse(p->right);
    }
    
}

//后续遍历
/*
 template<typename T,typename G>
 inline void Tree<T,G>::PostOrderTraverse(
 void(*Visit)(const T&data))const {
 PostOrderTraverse(root,Visit);
 }
 template<typename T,typename G>
 inline void Tree<T,G>::PostOrderTraverse(
 const TreeNode<T,G>*p,void(*Visit)(const T&data))const {
 if(p!=NULL){
 PostOrderTraverse(p->left,Visit);
 PostOrderTraverse(p->right,Visit);
 Visit(p->data);
 }
 }
 */

//获得树的高度，即根节点的高度
template<typename T,typename G>
inline int Tree<T,G>::GetDepth()const{
    return GetDepth(root);
}
//获得当前节点的高度
template<typename T,typename G>
inline int Tree<T,G>::GetDepth(const TreeNode<T,G>*p)const
{
    int leftDepth,rightDepth;
    if(p){
        leftDepth=GetDepth(p->left);
        rightDepth=GetDepth(p->right);
        int tempdepth=(leftDepth>rightDepth?leftDepth:rightDepth);
        return 1+tempdepth;
    }else{
        return 0;
    }
}
//从根节点开始查找值为data的节点，返回指向其的指针
//如果没有则返回NULL
template<typename T,typename G>
inline TreeNode<T,G>* Tree<T,G>::Find(const T&data)const{
    return Find(data, root);
}
template<typename T,typename G>
inline TreeNode<T,G>*Tree<T,G>::Find(const T&data,TreeNode<T,G>*p)const
{
    if(p==NULL)return NULL;
    if(data<p->data)
        return Find(data, p->left);
    else if(data>p->data)
        return Find(data,p->right);
    else return p;
}
//找到值最小的节点
template<typename T,typename G>
TreeNode<T,G>*Tree<T,G>::FindMin()const{
    return FindMin(root);
}
template<typename T,typename G>
TreeNode<T,G>*Tree<T,G>::FindMin(TreeNode<T,G>*p)const{
    if(p==NULL)return NULL;
    else if (p->left==NULL)return p;
    else return FindMin(p->left);
}
template<typename T,typename G>
TreeNode<T,G>*Tree<T,G>::FindMax()const{
    return FindMax(root);
}
template<typename T,typename G>
TreeNode<T,G>*Tree<T,G>::FindMax(TreeNode<T,G>*p)const{
    if(p==NULL)return NULL;
    else if(p->right==NULL)return p;
    else return FindMax(p->right);
}
#endif
