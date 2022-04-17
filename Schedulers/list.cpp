#include "list.h"

list::list(string name , int s , int e)

{
 chain= new node(name,s,e);
 }


void list::add( string name , int s , int e) 
   
{
node * temp= chain;
if(chain== NULL) chain = new node( name ,  s ,  e);
else
{ for(; temp->next!= NULL; temp=temp->next);
temp->next= new node( name ,  s ,  e);
}
}
