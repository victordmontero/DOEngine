#pragma once


template<class T>
class LinkList{

  struct Node{
     T data;
     Node *next;
     Node(T d, Node *n):data{d},next{n}{}
  };


  Node *head={nullptr};
  int   _len;
  public:
   
   LinkList(){
       head=nullptr;
       _len =0;
   }
   void insert(T d){
       Node* ne = new Node(d,nullptr);
       if(!head)head=ne;
       else{
           Node* curr = head;
           while(curr->next!=nullptr)
                curr=curr->next;
           curr->next = ne;
       }
       _len++;
   }


};