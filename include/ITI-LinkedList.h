class LinkedList
{

struct Node
{
    int Data;
    Node *Next,*Prev;
    Node(int Data)
    {
        this->Data = Data;
        Next=Prev=NULL;
    }
};


    Node *Head, *Tail;

public :
    int length;
    LinkedList()
    {
        Head=Tail=NULL;
        length=0;
    }

    ~LinkedList() {
    Node* current = Head;
    while (current != NULL) {
        Node* next = current->Next;
        delete current;
        current = next;
    }
}

    void insert(int Data)
    {
        Node *node = new Node(Data);
        ++length;
        if(Head==NULL)
        {
            Head=Tail=node;
        }
        else
        {
            Tail->Next = node;
            node->Prev = Tail;
            Tail=node;
        }
    }

    void remove(int Data)
    {

        Node *node = GetNodeByData(Data);

        if(node==NULL)return;
        --length;

        if(node==Head)
        {

            if(node==Tail)  
            {
                Head=Tail=NULL;
            }
            else
            {
                Head=Head->Next;
                Head->Prev=NULL;
            }
        }
        else if(node==Tail)
        {
            Tail= Tail->Prev;
            Tail->Next=NULL;
        }
        else
        {
            node->Prev->Next = node->Next;
            node->Next->Prev = node->Prev;
        }

        delete node;
    }

    int GetDataByIndex(int index) {
    Node* node = GetNodeByIndex(index);
    return node ? node->Data : -1; 
   }

    void insertAtIndex(int Data,int index){

      if(index<0 or index>length)return;

        Node* node = new Node(Data);

      if(index==0){ 

        if(Head==NULL){ 
            Head=Tail=node;
        }
        else{
        node->Next=Head;
        Head->Prev=node;
        Head=node;
        }

      }
      else if(index==length){
        node->Prev = Tail;
        Tail->Next= node;
        Tail=node;
      }
      else{

        Node *f = GetNodeByIndex(index-1);
        Node *s = GetNodeByIndex(index);

        f->Next=node;
        node->Prev = f;

        node->Next=s;
        s->Prev=node;
      }

      ++length;
    }

    void Display()
    {
        Node * cursor = Head;
        while(cursor!=NULL)
        {
            cout<< cursor->Data<<" ";
            cursor = cursor->Next;
        }
        cout<<"\n";
    }

     void removeHead() {
        if (Head == NULL) return;
        Node* temp = Head;
        Head = Head->Next;
        if (Head != NULL) Head->Prev = NULL;
        else Tail = NULL; 
        delete temp;
        --length;
    }

    bool IsEmpty(){
     return length==0;
    }


protected:

private:

    Node* GetNodeByData(int data)
    {
        Node * cursor = Head;
        while(cursor!=NULL)
        {
            if(data==cursor->Data)return cursor;
            cursor=cursor->Next;
        }
        return NULL;
    }

     Node* GetNodeByIndex(int indx){

     if(indx<0 or Head==NULL)return NULL;

     Node*cursor=Head;
     int i=0;
     while(cursor!=NULL){
        if(i==indx)return cursor;
        cursor=cursor->Next;
        ++i;
     }
     return NULL;
    }

};