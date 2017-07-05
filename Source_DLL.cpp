#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
  int data;
  Node* next;
  Node* prev;
};

class DLL
{
  Node* head;
  public:

  DLL()
  {
    head = NULL;
  }

  ~DLL()
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
        Node* temp = new Node;
        temp->data = x;
        temp->prev = NULL;
        temp->next = head;
        head = temp;
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
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        temp->prev = t;
        t->next = temp;
      }
   }


   void RemoveNode(int n)
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
                        (t->next)->prev = te;
                        free(t); 
                    }

              }
      }

     else
     {
       cout <<"Invalid position number is entered" << endl;
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
  DLL l1;
  for(int i = 0;i<1000;i++) //INSERTING HEADS 1000 times
  {
    l1.InsertHead(rand()%100);
  }
    cout << l1.Nodes() << endl; // PRINTING no.of nodes

  for(int i = 0;i<1000;i++)  //APPENDING NODES 1000 times
  {
      l1.AppendNode(rand()%100);
  }
  cout << l1.Nodes() << endl; // PRINTING no. of nodes

   for(int i = 0;i<1000;i++) // REMOVING each node
  {
      l1.RemoveNode(1);
  }
 cout << l1.Nodes() << endl; //PRINITNG no. of nodes
  
  cout << l1.NodeValue(34)<< endl;
  cout << l1.NodeValue(1)<< endl;
  cout << l1.NodeValue(100) << endl;
   for(int i = 0;i<1000;i++)
  {
      l1.AppendNode(rand()%100);
  }

  l1.DeleteList();
  cout << l1.Nodes() << endl;

}



