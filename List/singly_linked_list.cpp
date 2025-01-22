#include<iostream>
#include<stdexcept>

using namespace std;


#define eleType int
struct ListNode
{
    eleType data;
    ListNode *next;
    ListNode(eleType x):data(x),next(NULL){}
};

class LinkedList
{
    private:
        ListNode* head;
        int size;

    public:
        LinkedList():head(NULL),size(0){};
        ~LinkedList();
        void insert(int i,eleType value);
        void remove(int i);
        
        ListNode* find(eleType value);
        ListNode* get(int i);

        void updata(int i,eleType value);
        void print();
};


LinkedList::~LinkedList()
{
    ListNode *curr=head;
    while(curr!=NULL)
    {
        ListNode *temp=curr;
        curr=curr->next;
        delete temp;
    }
}

void LinkedList::insert(int i, eleType value)
{
    if(i>size||i<size)
    {
        throw std::out_of_range("Invalid position");
    }
    ListNode *newNode =new ListNode(value);
    if(i==0)
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        ListNode *curr=head;
        for(int j=0;j<i-1;++j)
        {
            curr=curr->next;
        }
        newNode->next=curr->next;
        curr->next=newNode;
    }
    size++;
}

void LinkedList::remove(int i)
{
    if(i>size||i<0)
    {
        throw std::out_of_range("Invalid position");
    }
    if(i==0)
    {
        ListNode *temp=head;
        head=head->next;
        delete temp;
    }
    else
    {
        ListNode *curr=head;
        for(int j=0;j<i-1;++j)
        {
            curr=curr->next;
        }
        ListNode *temp=curr->next;
        curr->next=temp->next;
        delete temp;
    } 
    size--;
}

ListNode *LinkedList::get(int i)
{
    if(i>size||i<0)
    {
        throw std::out_of_range("Invalid position");
    }
    ListNode *curr=head;
    for(int j=0;j<i;++j)
    {
        curr=curr->next;
    }
    return curr;
}

void LinkedList::updata(int i, eleType value)
{
    get(i)->data=value;
}


ListNode *LinkedList::find(eleType value)
{
    ListNode *curr=head;
    while(curr!=NULL&&curr->data!=value)
    {
        curr=curr->next;
    }
    return curr;
}


void LinkedList::print()
{
    ListNode *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}





int main(int argc, const char** argv) {
    LinkedList list;
    list.insert(0,0);
    list.insert(1,1);
    list.insert(2,2);
    list.insert(3,3);
    list.print();
    list.remove(0);
    list.print();
    list.updata(2,100);
    list.print();
    ListNode*temp=list.find(100);
    cout<<temp<<endl;
    cout<<temp->data<<endl;
    cout<<list.get(2)->data<<endl;
    
    return 0;
}

