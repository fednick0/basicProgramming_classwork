#include <iostream>

using namespace std;

int main(){

    int a = 47;
    int *ipa = &a;
    *ipa = 100;

    cout<<"a = " <<a;
    cout<<"\n*ipa = " <<*ipa;
    cout<<endl;
}
