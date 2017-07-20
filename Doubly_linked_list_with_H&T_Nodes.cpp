#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
  int data;
  Node* next;
  Node* prev;
};

class Xsll
{
   Node* head;
   Node* tail; 
   public:
    Xsll()
    {
      Node* temp = new Node;
      Node* temp1 = new Node;
      temp->next = temp1;
      temp->prev = NULL;
      temp1->next = NULL;
      temp1->prev = temp;
      head = temp;
      tail = temp1;
    }
    
    ~Xsll()
    {
       DeleteList();   
    }
    
    int Nodes()  //Number of Nodes
    {
        if(head->next != tail)
        {
            Node* t = head->next;
            int k = 1;
            while(t->next != tail)
            {
                t = t->next;
                k++;
            }

            return k;
        }

        else
        {
            return 0;
        }
      
    }
  
  
    int NodeValue(int n)  // Value of a particular Node
    {
           
        try
        {
          if(head->next!=tail)
          {
               Node* t = head->next;
                if(n>0 && n<= Nodes())
                {

                    for(int i = 2;i <= n;i++)
                    {
                        t = t->next;
                    }
                }

               else
               {
                  throw 0;
               }
           
           return t->data;
          }
        }
      
         catch(int e)
         {
           cout <<"Invalid position number entered"<<endl; 
         }
        
    }
    void InsertHead(int x)
    {
        Node* t = new Node;
        t->prev = head;
        t->next = head->next;
        head->next->prev = t;
        t->data = x;
        head->next = t;                    
    }
    void AppendNode(int x)
    {
        if(head->next == tail)
        {
          InsertHead(x);
        }
        else
        {           
            Node* t = new Node;
            t->prev = tail->prev;
            t->prev->next = t;
            tail->prev = t;
            t->next = tail;
            t->data = x;       
        }
      
    }

    void RemoveNode(int n)  // 'n' is position of node
    {
      
        if(n<=Nodes() && n>0)
        {

                if(n==1)  
                {                                         
                    Node* temp = head->next;
                    head->next = temp->next;
                    free(temp);
                }

                else
                { 

                      Node* t = head->next;
                      Node* te = head->next;
                      for(int i = 2;i<=(n);i++)
                      {
                        t = t->next;
                        if(i<=(n-1))
                          te = te->next;
                      }

                      if(t->next==tail)
                      {

                          Node* temp = t;
                          te->next = tail;
                          tail->prev = te;
                          free(temp);                                                                
                      }


                      else
                      {                    
                          te->next = t->next;
                          t->next->prev = te;
                          free(t);                 
                      }

                }
        }

        else
        {
           cout << "Invalid position number is entered" << endl; 
        }
             
    }
    
    void DeleteList()
    {
        Node* temp = head->next;
        Node* t;
        while(temp!=tail)
        {
            t = temp->next;
            free(temp);
            temp = t;
        }
        
        head->next = tail;
    }

 
    
};

int main()
{
    Xsll l1,l2;
  for(int i = 0;i<1000;i++)
  {
    l1.InsertHead(rand()%100);
  }
  
  for(int i = 0;i<1000;i++)
  {
      l1.AppendNode(rand()%100);
  }
  
  cout <<l1.Nodes() << endl;
  
    for(int i = 0;i<1000;i++)
    {
      l1.RemoveNode(1);
    } 
  
 cout << l1.Nodes() << endl;
 
  
   for(int i = 0;i<1000;i++)
  {
      l1.AppendNode(rand()%100);
  }
  cout << l1.Nodes() << endl;
  
  cout << l1.NodeValue(45) << endl;
  
  cout << l1.NodeValue(100) << endl;
  
  l1.DeleteList();
  cout << l1.Nodes() << endl; 
    
}
