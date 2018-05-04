//
//  mylist.h
//  miniSTL
//
//  Created by dogrest on 15/9/15.
//  Copyright (c) 2015年 dogrest. All rights reserved.
//

#ifndef miniSTL_mylist_h
#define miniSTL_mylist_h
template<typename T>
class ListNode{
public:
    //ListNode的默认构造函数
    ListNode(){
        data=0;
        next=NULL;
        std::cout<<"#add a ListNode#"<<std::endl;
    }
    //ListNode的析构函数
    ~ListNode(){
        std::cout<<"#kill a ListNode#"<<"$"<<data<<"$"<<std::endl;
    }
    //ListNode的构造函数
    ListNode(int i,ListNode*f):data(i),next(f){
        std::cout<<"#add a ListNode#"<<std::endl;
    }
    T data;
    ListNode<T>*next;
};
template <typename T>
class List{
public:
    T ZERO;
    //List类的默认构造函数
    List(){
        first=NULL;
        length=0;
        std::cout<<"#START A List#"<<std::endl;
    }
    //顺序打印该链表中的节点
    void display() const;
    
    //逆序打印该链表中的节点
    void nixu()const ;
    
    //打印链表的头和尾节点
    void showHeadAndTail();
    T& operator[](int i);
    void addListNodeFromTail(T i);
    void addListNodeFromTail(T data[],T i);
    void addListNodeFromHead(T data[],T i);
    void addListNodeFromHead(T i);
    void deleteListNodeFromHead();
    void deleteListNodeFromTail();
    bool IsEmpty();
    void sort();
    void deletenode(int i);
    ListNode<T>* getfirst();
    size_t getsize();
    ~List(){
        ListNode<T>*temp=first;
        while(temp!=NULL){
            ListNode<T>*newnext=temp->next;
            delete temp;
            temp=newnext;
        }
        std::cout<<"#KILL A LIST#"<<std::endl;
    }
protected:
    size_t length;
    ListNode<T>*first;
    ListNode<T>*tail;
    void show3(ListNode<T>*f) const ;
    void QuickSort(ListNode<T>*start,ListNode<T>*end);
    ListNode<T>*Partition(ListNode<T>*start,ListNode<T>*end);
};
template<typename T>
T& List<T>::operator[](int i){
    if(length==0){
        std::cout<<"链表中没有元素"<<std::endl;
        return ZERO;
    }
    if(i<0){
        std::cout<<"不能输入负数作为下标"<<std::endl;
    }
    if(i>length){
        std::cout<<"链表没有那么长"<<std::endl;
        return ZERO;
    }else{
        ListNode<T>*temp1=first;
        for(int j=1;j<=i;j++){
            temp1=temp1->next;
        }
        return temp1->data;
    }
    
    
}
template<typename T>
ListNode<T> *List<T>::getfirst(){
    return first;
}

template<typename T>
bool List<T>::IsEmpty(){
    if(length==0)return 1;
    else return 0;
}

template<typename T>
size_t List<T>::getsize(){
    return length;
}
template<typename T>
void List<T>::deletenode(int i){
    if(i>length||i<=0){
        std::cout<<"非法输入"<<std::endl;
        return ;
    }
    if(i==1){
        ListNode<T>*temp1=first;
        first=first->next;
        delete temp1;
        length--;
    }
    else{
        ListNode<T>*temp1=first;
        for(int j=1;j<i-1;j++){
            temp1=temp1->next;
        }
        ListNode<T>*temp2=temp1->next;
        temp1->next=temp2->next;
        delete temp2;
        length--;
    }
}
template<typename T>
void List<T>::sort(){
    ListNode<T>*temp1=first;
    ListNode<T>*temp2=tail;
    QuickSort(temp1, temp2);
}
template<typename T>
ListNode<T>*List<T>::Partition(ListNode<T>*start,ListNode<T>*end){
    ListNode<T> c(1,start);
    ListNode<T> *a=&c;
    ListNode<T>*b=start;
    for(;b!=end;b=b->next){
        if((b->data)<(end->data)){
            a=a->next;
            int temp=a->data;
            a->data=b->data;
            b->data=temp;
        }
    }
    a=a->next;
    int temp=a->data;
    a->data=end->data;
    end->data=temp;
    return a;
}
template<typename T>
void List<T>::QuickSort(ListNode<T>*start,ListNode<T>*end){
    ListNode<T>*index=Partition(start, end);
    ListNode<T>*temp1=start;
    if(temp1!=index){
        while (temp1->next!=index) {
            temp1=temp1->next;
        }
        QuickSort(start, temp1);
    }
    if(index!=end){
        QuickSort(index->next, end);
    }
    
}
template<typename T>
void List<T>::showHeadAndTail(){
    if(first==NULL){
        std::cout<<"No head & tail"<<std::endl;
    }else{
        std::cout<<"the tail of this List is:"<<tail->data<<std::endl;
        std::cout<<"the head of this List is:"<<first->data<<std::endl;
    }
}
template<typename T>
void List<T>::addListNodeFromHead(T data[],T i){
    for(int j=0;j<i;j++){
        addListNodeFromHead(data[j]);
    }
}
template<typename T>
void List<T>::addListNodeFromTail(T data[],T i){
    for(int j=0;j<i;j++){
        addListNodeFromTail(data[j]);
    }
}

//从后面加上一个节点
template<typename T>
void List<T>::addListNodeFromTail(T i){
    if(first==NULL){
        first=new ListNode<T>;
        first->data=i;
        tail=first;
    }else{
        ListNode<T>*NewNode=new ListNode<T>;
        NewNode->data=i;
        tail->next=NewNode;
        tail=NewNode;
    }
    length++;
}
template<typename T>
void List<T>::addListNodeFromHead(T i){
    if(first==NULL){
        first=new ListNode<T>;
        first->data=i;
        tail=first;
    }else{
        ListNode<T>*Newnode=new ListNode<T>;
        Newnode->data=i;
        Newnode->next=first;
        first=Newnode;
    }
    length++;
}
template<typename T>
void List<T>::display() const{
    ListNode<T>* temp=first;
    if(temp==NULL){
        std::cout<<"there are nothing in this list"<<std::endl;
    }
    while (temp){
        std::cout<<temp->data<<" "<<std::endl;
        temp=temp->next;
    }
}
template<typename T>
    void List<T>::nixu() const{
    ListNode<T>*temp=first;
    show3(temp);
}
template<typename T>
void List<T>::show3(ListNode<T>*f) const{
    if(f){
        if(f->next){
            show3(f->next);
        }
        std::cout<<"#-"<<f->data<<"-#"<<std::endl;
    }
}
template<typename T>
void List<T>::deleteListNodeFromHead(){
    if(first==NULL) {
        std::cout<<"本链表为空，不能再删除节点"<<std::endl;
    }else if(first==tail){
        delete first;
        first=NULL;
        tail=NULL;
        length--;
    }else{
        ListNode<T>*temp=first->next;
        delete first;
        first=temp;
        length--;
    }
}
template<typename T>
void List<T>::deleteListNodeFromTail(){
    if(tail==NULL){
        std::cout<<"本链表为空，不能删除节点"<<std::endl;
    }
    //head=tail即只有一个节点的情况
    else if(first==tail){
        delete first;
        first=NULL;
        tail=NULL;
    }else{
        //找到倒数第二个节点
        ListNode<T>*temp=first;
        while(temp->next!=tail){
            temp=temp->next;
        }
        //如果只有两个节点
        if(first==temp){
            delete first;
            first=temp;
        }
        //如果有两个以上的节点
        else{
            delete tail;
            temp->next=nullptr;
            tail=temp;
        }
    }
}

#endif
