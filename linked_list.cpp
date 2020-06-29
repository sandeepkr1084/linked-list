#include<iostream>
using namespace std;
struct Node{
  int data;
  struct Node* next;
};
struct Node* head;
void InsertAtStart(int x){
  Node* temp = new Node();
  temp->data = x;
  temp->next = head;
  head = temp;
}
void InsertAtLast(int x){
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    Node* temp1 = head;
    if(temp1==NULL){
        head = temp;
    }
    else{
        while(temp1->next!=NULL){
            temp1 = temp1->next;
        }
    }
    temp1->next = temp;
}
void InsertAtPosition(int x,int pos){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(pos<=0){
        cout<<"Not a valid position!\n";
    }
    if(pos==1){
        temp->next = head;
        head = temp;
    }
    else{
        Node* temp1 = head;
        for(int i=0;i<pos-2;i++){
            if(temp1==NULL){
                cout<<"Not a valid position!\n";
                return;
            }
            temp1 = temp1->next;
        }
        if(temp1==NULL){
            cout<<"Not a valid position!\n";
        }
        else{
            temp->next = temp1->next;
            temp1->next = temp;
        }
    }
}

void DeleteAtStart(){
    if(head==NULL){
        cout<<"There is no element\n";
    }
    else{
        head = head->next;
    }
}
void DeleteAtLast(){
    if(head==NULL){
        cout<<"There is no element\n";
    }
    else if(head->next==NULL){
        head = NULL;
    }
    else{
        Node* temp = head;
        while((temp->next)->next!=NULL){
            temp = temp->next;
        }
        temp->next=NULL;
    }

}
void DeleteAtPosition(int pos){
    if(pos<=0){
        cout<<"Not a valid position!\n";
    }
    else if(pos == 1){
        if(head->next==NULL){
            head = NULL;
        }
        else if(head!=NULL){
            head=head->next;
        }
        else{
            cout<<"Not a valid position!\n";
        }
    }
    else{
        Node* temp = head;
        for(int i=0;i<pos-2;i++){
            if(head==NULL || (temp->next)==NULL){
                cout<<"Not a valid position!\n";
                return;
            }
            temp = temp->next;
        }
        if((temp->next)==NULL || head==NULL){
                cout<<"Not a valid position!\n";
                return;
        }
        temp->next = (temp->next)->next;
    }
}

void Print(){
  Node* temp = head;
  cout<<"List is: ";
  while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp = temp->next;
  }
  cout<<"\n";
}
int main(){
  int n,x,pos,opt,choise,flag=1;
  Node* head = NULL;
  while(flag){
  cout<<"What operation you want to perform:\n";
  cout<<"1. insert\n";
  cout<<"2. delete\n";
  cout<<"3. display\n";
  cin>>choise;
  if(choise==1){
     cout<<"How many node you want to create\n";
     cin>>n;
     for(int i=0; i<n;i++){
        cout<<"Enter the number\n";
        cin>>x;
        cout<<"where you want to insert\n";
        cout<<"1. At first position\n";
        cout<<"2. At the last position\n";
        cout<<"3. At a particular position\n";
        cin>>opt;
        if(opt==1){
            InsertAtStart(x);
        }
        else if(opt==2){
           InsertAtLast(x);
        }
        else{
            cout<<"enter the position\n";
            cin>>pos;
            InsertAtPosition(x,pos);
        }
      }
  }
  else if(choise==2){
    cout<<"where you want to insert\n";
    cout<<"1. At first position\n";
    cout<<"2. At the last position\n";
    cout<<"3. At a particular position\n";
    cin>>opt;
    if(opt==1){
        DeleteAtStart();
    }
    else if(opt==2){
        DeleteAtLast();
    }
    else{
        cout<<"Enter the position\n";
        cin>>pos;
        DeleteAtPosition(pos);
    }
  }
  else{
    Print();
  }
  cout<<"Do you want to quit\n1. quit\n2. continue\n";
  cin>>flag;
  if(flag==1){
    flag = 0;
  }
  else{
    flag=2;
  }
  }

  return 0;
}
