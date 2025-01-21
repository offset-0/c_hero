#include <iostream>

using namespace std;

#define eleType int

struct  SequentialList
{
    eleType *elements;
    int size;
    int capacity;

};


void init(SequentialList* list ,int capacity)
{
    list->elements=new eleType[capacity];
    list->size=0;
    list->capacity=capacity;
}

int size(SequentialList* list)
{
    return list->size;
}

void destory(SequentialList* list)
{
    delete [] list->elements;
}

bool isEmpty(SequentialList* list)
{
    return list->size==0;
}


void insert(SequentialList* list,int index,eleType element)
{
    if(index<0||index>list->size)
    {
        throw std::invalid_argument("invalid_index");
    }
    int newcapacity=list->capacity*2;
    eleType *newelement =new eleType[newcapacity];
    for(int i=0;i<list->size;++i)
    {
        newelement[i]=list->elements[i];
    }
    delete [] list->elements;
    list->elements=newelement;
    list->capacity=newcapacity;
    for(int i=list->size;i>index;--i)
    {
        list->elements[i]=list->elements[i-1];
    }
    list->elements[index]=element;
    list->size++;
}


void deleteElement(SequentialList* list,int index)
{
    if(index<0||index>list->size-1)
    {
        throw std::invalid_argument("invalid_index");
    }
    for(int i=index;i<list->size;++i)
    {
        list->elements[i-1]=list->elements[i];
    }
    list->size--;
}


int findElement(SequentialList* list,eleType element)
{
    for (int i = 0; i < list->size; ++i)
    {
        if(element==list->elements[i])
            return i;
    }
    return -1;
}

eleType getElement(SequentialList* list,int index)
{
    if(index<0||index>list->size-1)
    {
        throw std::invalid_argument("invalid_index");
    }
    return list->elements[index];
}


void updataElement(SequentialList* list,int index,eleType element)
{
    if(index<0||index>list->size-1)
    {
        throw std::invalid_argument("invalid_index");
    }
    list->elements[index]=element;
}

int main()
{

    SequentialList myList;
    init(&myList,10);
    for(int i=0;i<10;++i)
    {
       insert(&myList,i,i);
    }
    cout<<size(&myList) <<endl;
    cout<<"is Empty:"<<isEmpty(&myList) <<endl;
    for(int i=0;i<myList.size;++i)
    {
       cout<<getElement(&myList,i)<<" ";
    }
    cout<<endl;

    deleteElement(&myList,9);
    for(int i=0;i<myList.size;++i)
    {
       cout<<getElement(&myList,i)<<" ";
    }

    updataElement(&myList,1,100);
    cout<<endl;
    for(int i=0;i<myList.size;++i)
    {
       cout<<getElement(&myList,i)<<" ";
    }
    cout<<endl;

    insert(&myList,2,999);
    for(int i=0;i<myList.size;++i)
    {
       cout<<getElement(&myList,i)<<" ";
    }
    cout<<endl;

    cout<<findElement(&myList,999)<<endl;

    destory(&myList);

    return 0;
}
