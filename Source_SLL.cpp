#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

class Xsll
{
   Node* head;
   Node* tail;
   
   public:
    Xsll()
    {
      head = head->next = tail = tail->next = NULL;
    }
    
    ~Xsll()
    {
      free(head);
      free(tail);
    }
    void push(int x)
    {
      if(head==NULL && tail==NULL)
      {
        Node* t = new Node;
        head = tail = t;
        head->data = tail->data = x; 
      }
      
      else if(head==tail)
      {
          Node* t = new Node;
          head->next = tail = t;
          tail->data = x;
          tail->next = NULL;
      }
      
      else
      {
        Node* t = new Node;
        tail->next = t;
        tail = t;
        tail->data = x;
      }
    }
    
    int pop()
    {
        try
        {
            if(head==NULL && tail==NULL)
            {
              throw "Exception: No Nodes in the linked list";
            }
            
            else if((head!=NULL && tail==NULL ) || (head==NULL && tail!=NULL))
            {
              throw 0;
            }
            
            else
            {
              Node* t = head;
              while(t->next != tail)
              {
                t = t->next;
              }
              
              int val = tail->data;
              Node* temp = tail;
              tail = t;
              tail->next = NULL;
              free(temp);
              return val;
            }
        }

        catch(char* msg)
        {
          cout << msg << endl;
        }
        catch(int e)
        {
            cout <<"Exception: Memory Corruption" << endl;
        }
      
    }
    
    int top()
    {
      try
      {
          if(head==NULL && tail==NULL)
          {
             throw "Exception: No Nodes in the linked list";
          }
          
          else if((head!=NULL && tail==NULL ) || (head==NULL && tail!=NULL))
          {
            
            throw 0;
          }
          else
          {
            return tail->data; 
          }
      }
      
      catch(char* msg)
      {
          cout << msg << endl;
      }
      catch(int e)
      {
          cout << "Exception: Memory corruption" << endl; 
      }
      
    }
};

int main()
{
    Xsll l1,l2;
    l1.push(34);
    l1.push(54);
    l1.pop();
    l1.top();
    l1.pop();
    l1.top();
    
    l2.push(5465);
    l2.pop();
    l2.pop();
    
}

