#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
  int data;
  Node* next;
  Node* prev;
}

class DLL
{
  int head;
  public:
  DLL()
  {
    head = NULL;
  }
  ~DULL()
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
                throw 0;
            }
        }
        
        catch(int e)
        {
            cout << "No Nodes in the List" << endl;
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
      if(head != NULL)
      {
        Node* temp = new Node;
        temp->data = x;
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
       }
       else
       {
        Node* temp = new Node;
        temp->data = x;
        temp->prev = NULL;
        temp->next = head;
       }
   }
   
   void AppendNode(int x)
   {
      Node* t = head;
      if(head==NULL)
      {
        InsertHead(x);
      }
      else
      {
        while(t->next!=NULL)
        {
          t = t->next;
        }
        Node* t = head;
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        temp->prev = t;
   }
    
    
   void RemoveNode(int n)
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
              {
                free(head);
                head = NULL;
              }
              
              else
              {
                Node* temp = head;
                head = temp->next;
                head->prev = NULL;
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
                        (t->next)->prev = head;
                        free(t);
                      }

                      else
                      {
                        te->next = t->next;
                        (t->next)->prev = te;
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

  
}



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
  
   for(int i = 0;i<1000;i++)
  {
      l1.RemoveNode(1);
  } 
 cout << l1.Nodes() << endl;
   for(int i = 0;i<1000;i++)
  {
      l1.AppendNode(rand()%100);
  }
  l1.DeleteList();
  cout << l1.Nodes() << endl; 
  
}

