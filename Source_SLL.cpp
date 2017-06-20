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
      free(head);
     
    }
    
    int Nodes()  //Number of Nodes
    {
        try
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
                throw "No nodes in the list";
            }
        }
        
        catch(char* msg)
        {
            cout << msg << endl;
        }
    }
    int NodeValue(int n)  // Value of a particular Node
    {
        
        Node* t = head;
        for(int i = 2;i <= n;i++)
        {
            t = t->next;
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
        try
        {
            if(head==NULL)
            {
              throw "Exception: No Nodes in the linked list";
            }
            
        
            else if(n==1)  
            {
              if(head->next==NULL)
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
                  while(tx->next!=NULL)
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
                  for(int i = 2;i<=(n);i++)
                  {
                    t = t->next;
                    if(i<=(n-1))
                      te = te->next;
                  }


                  if(t->next==NULL)
                  {
                        if(n==2)
                        {
                          Node* temp = t;
                          head->next = NULL;
                          free(temp);
                        }

                        else
                        {  
                          Node* temp = t; 
                          te->next = NULL;
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
    l1.InsertHead(34);
    l1.InsertHead(455);
    l1.AppendNode(54);
    l1.RemoveNode(2);

    cout << l1.NodeValue(2) << endl;
    l1.DeleteList();
    cout << l1.Nodes() << endl;
    
    //l1.RemoveNode(1);
    

    
}
