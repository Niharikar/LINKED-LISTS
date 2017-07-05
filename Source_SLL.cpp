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
  
   public:
    Xsll()
    {
      head = NULL;
    }
    
    ~Xsll()
    {
       DeleteList();   
    }
    
    int Nodes()  //Number of Nodes
    {
        if(head)
        {
            Node* t = head;
            int k = 1;
            while(t->next != NULL)
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
        Node* t = head;   
        try
        {
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
        }
      
         catch(int e)
         {
           cout <<"Invalid position number entered"<<endl; 
         }
        return t->data;
    }
    void InsertHead(int x)
    {
        Node* t = new Node;
        t->next = head;
        t->data = x;
        head = t;                    
    }
    void AppendNode(int x)
    {
        if(head==NULL)
        {
          InsertHead(x);
        }
        else
        {
            Node* te = head;
          
            while(te->next != NULL)
            {
                te = te->next;
            }
            Node* t = new Node;
            t->next = NULL;
            t->data = x;
            te->next = t;
        }
      
    }

    void RemoveNode(int n)  // 'n' is position of node
    {
      
        if(n<=Nodes() && n>0)
        {

                if(n==1)  
                {                                         
                    Node* temp = head;
                    head = temp->next;
                    free(temp);
                }

                else
                { 

                      Node* t = head;
                      Node* te = head;
                      for(int i = 2;i<=(n);i++)
                      {
                        t = t->next;
                        if(i<=(n-1))
                          te = te->next;
                      }

                      if(t->next==NULL)
                      {

                          Node* temp = t;
                          te->next = NULL;
                          free(temp);                                                                
                      }


                      else
                      {                    
                          te->next = t->next;
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
        Node* temp = head;
        Node* t;
        while(temp!=NULL)
        {
            t = temp->next;
            free(temp);
            temp = t;
        }
        
        head = NULL;
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
  
  cout << l1.NodeValue(45);
  cout << l1.NodeValue(100);
  l1.DeleteList();
  cout << l1.Nodes() << endl; 
    
}
