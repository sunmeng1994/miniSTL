//
//  myvector.h
//  miniSTL
//
//  Created by dogrest on 15/9/15.
//  Copyright (c) 2015年 dogrest. All rights reserved.
//

#ifndef miniSTL_myvector_h
#define miniSTL_myvector_h

template <typename T>
class myVector{
private:
    int Vsize;
    T*p;
    int length;
    T*tail;
    T*head;
public:
    //默认构造函数
    myVector():Vsize(256),p(new T[Vsize]),length(0),
    tail(p),head(p){}
    //拷贝构造函数
    myVector (const myVector<T>& a){
        Vsize=a.Vsize;
        length=a.length;
        p=new T[Vsize];
        T*temp=a.p;
        for(int i=0;i<length;i++){
            p[i]=temp[i];
        }
        head=a.head;
        tail=a.tail;
    }
    //拷贝复制运算符
    myVector<T> & operator=(myVector<T>&a){
        delete []p;
        Vsize=a.Vsize;
        length=a.length;
        p=new T[Vsize];
        T*temp=a.p;
        for(int i=0;i<length;i++){
            p[i]=temp[i];
        }
        head=a.head;
        tail=a.tail;
        return*this;
    }
    //析构函数
    ~myVector(){
        delete []p;
    }
    //重载[]运算符，返回i所在的下标
    T& operator[](size_t i){
        if(i>=length){
            return p[length-1];
        }
        return p[i];
    }
        void push_back(T i);
        void pop_back();
        const int size();
    //获得头指针
    //作用相当于迭代器
        const T* begin();
    //获得尾后指针
        const T*end();
};

//从尾部添加元素
template <typename T>
void myVector<T>::push_back(T i){
    length++;
    //如果length到达了Vsize-1,虽然最后还可以存一个元素
    //但是尾后指针就会变成未定义的，会引起程序的崩溃
    if(length==Vsize){
        Vsize*=2;
        int *q=new int[Vsize];
        for(int i=0;i<(Vsize/2);i++){
            q[i]=p[i];
        }
        delete []p;
        p=q;
        head=p;
        tail=p+(Vsize/2)-1;
        *tail=i;
        tail=tail+1;
    }
    else{
        p[length-1]=i;//为什么*tail不行
        tail=tail+1;
    }
}

template <typename T>
void myVector<T>::pop_back(){
    if(tail==head){
        std:: cout<<"no elements in the vector"<<std::endl;
    }else{
        tail=tail-1;
        length--;
    }
}

template <typename T>
const int myVector<T>::size(){
    return length;
}

template <typename T>
const T* myVector<T>::begin(){
    return head;
}

template <typename T>
const T* myVector<T>::end(){
    return tail;
}


#endif
