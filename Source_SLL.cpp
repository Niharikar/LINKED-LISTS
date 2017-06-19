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
      head = NULL;
      tail = head;
    }
    
    ~Xsll()
    {
      free(head);
      free(tail);
    }
    void InsertHead(int x)
    {
          try
          {
                if(head==NULL && tail==NULL)
                {
                    
                  Node* t = new Node;
                  t->data = x;
                  t->next = NULL;
                  head = tail = t;
            
                }
            
                else if((head==NULL && tail!=NULL)  ||  (head!=NULL && tail==NULL))
                {
                    throw "Exception: Memory Coruption";
                }

                else
                {
                    Node* t = new Node;
                    t->next = head;
                    t->data = x;
                    head = t;                    
                }
          }
          
          catch(char* msg)
          {
              cout << msg << endl;
          }
    }
    void AppendNode(int x)
    {
        if(head==NULL && tail==NULL)
        {
          InsertHead(x);
        }
        else
        {
            Node* t = new Node;
            t->next = NULL;
            t->data = x;
            tail->next = t;
            tail = t;          
        }
      
    }
    
    void RemoveNode(int n)
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
            
          
        
            else if(n==1)  
            {
              if(head==tail)
                free(head);
              
              else
              {
                Node* temp = head;
                head = temp->next;
                free(temp);
              }
              
            }
          
           
            else
            { 
                  Node* tx  = head;
                  int k = 1;
                  while(tx!=tail)
                  {
                      tx = tx->next;
                      k++;
                  }
                  if(n>k)
                  {
                      cout << " given position does not exist in the list" << endl;
                      return;
                  }
                  
                  if(n<1)
                  {
                      cout << "Enter a valid number" << endl;
                      return;
                  }
                  
                  
                  
                  Node* t = head;
                  Node* te = head;
                  for(int i = 0;i<(n-1);i++)
                  {
                    t = t->next;
                    if(i<(n-2))
                      te = te->next;
                  }


                  if(t->next==NULL)
                  {
                        if(n==2)
                        {
                          Node* temp = t;
                          head->next = NULL;
                          tail = head;
                          free(temp);
                        }

                        else
                        {  
                          Node* temp = tail; 
                          te->next = NULL;
                          tail = te;
                          free(temp);                
                        }                
                  }
              
              
                  else
                  {
                      if(n==2)
                      {                    
                        head->next = t->next;
                        free(t);
                      }

                      else
                      {
                        te->next = t->next;
                        free(t);                   
                      }
                  }
           
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

 
    
};

int main()
{
    Xsll l1,l2;
    l1.InsertHead(34);
    //l1.AppendNode(54);
    //l1.RemoveNode(1);
    

    
}
