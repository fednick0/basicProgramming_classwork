#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

int main(){
   char pass[50];
   char ch[2];

   memset(pass, '\0', 50);
   memset(ch, '\0', 2);

   cout << "Enter pass:\n";
   ch[0] = getch();

   while(ch[0] != 13){ //13 = Enter
      strcat(pass, ch);
      cout << '*';
      ch[0] = getch();
   }

   cout<<"\n\nPass: " <<pass <<endl;

   for(int x = 0; x < strlen(pass); x++)
        pass[x]+=x;

    cout<<"\n\nPass cifrado: " <<pass <<endl;
}
