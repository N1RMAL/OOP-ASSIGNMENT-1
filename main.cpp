#include <iostream>
#include<string.h>
using namespace std;

struct library
{
    char name[100];
    char author[100];
    double price;
    int copies;
};

int main()
{
    struct library l[100];
    char authorname[50],bookname[50];
    int i=0,j=0,count=0,flag1=0,flag2=0;
    
    while(j!=6)
    {
        cout << "WELCOME TO THE ONLINE LIBRARY, PLEASE SELECT ONE OF THE OPTIONS \n";
        cout << "1. Enter your book into the system \n";
        cout << "2. Display list of all the books in the library \n";
        cout << "3. Search a book name in the library \n";
        cout << "4. Search books by author's name \n";
        cout << "5. Sort all the books \n";
        cout << "Press any other button to exit\n";
        cin >> j;
        
        switch(j)
        {
            case 1:
              cout << "Enter the name of the book: \n";
              cin.ignore();
              cin.getline(l[count].name,100);
            
              cout << "Enter the name of the author: \n";
              cin.getline(l[count].author,100);
              
              cout << "Enter the price of the book: \n";
              cin >> l[count].price;
              
              cout << "Enter the number of copies of books you are adding: \n";
              cin >> l[count].copies;
              
              count++;
              break;
              
            case 2:
              for(i=0; i<count; i++)
              {
                  cout << "BOOK NAME: " << l[i].name << "  ";
                  cout << "AUTHOR NAME: " << l[i].author << "  ";
                  cout << "PRICE: " << l[i].price << "  ";
                  cout << "NUMBER OF COPIES: " << l[i].copies << "\n";
              }
              break;
              
            case 3:
               cout << "Enter the name of the book to be searched:";
               cin.ignore();
               cin.getline(bookname,100);
               for(i=0;i<count;i++)
               {
                   if (strcmp(bookname, l[i].name) == 0)
                   {
                       cout << "There are " << l[i].copies << " copies left \n";
                       flag1=1;
                   }

               }
               if(flag1==0)
               cout << "Sorry, no such book is entered into our system \n";
               break;
               
            case 4:
              cout << "Enter the name of the author to be searched:";
              cin.ignore();
              cin.getline(authorname,100);
              for(i=0;i<count;i++)
              {
                  if (strcmp(authorname, l[i].author) == 0)
                  {
                      cout << "There are " << l[i].copies << " copies of " << l[i].name << "\n";
                      flag2=1;
                  }

              }
              if(flag2==0)
              cout << "Sorry, there are no books by this author in the system currently \n";
              break;
              
            case 5:
              char ch[100];        
              for(int i=0;i<count;++i)
              {
                  for(j=0;j<(count-1);++j)
                  {
                      if(strcmp(l[j].name, l[j+1].name)>0)
                      {
                          strcpy(ch, l[j].name);
                          strcpy(l[j].name, l[j+1].name);
                          strcpy(l[j+1].name, ch);
                      }
                  }
              }
              cout << "The books in sorted order are: \n";
              for(int i=0;i<count;i++)
              {
                  cout << " " << l[i].name <<"\n";
              }
              break;
              
            default :
              exit(0);
              
        }
    }
}










