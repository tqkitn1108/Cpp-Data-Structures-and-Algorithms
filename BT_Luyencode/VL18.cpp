// Code by Ta Quang Kien
//Số đảo ngược
#include <iostream>
#include <string>
using namespace std;
void swap(int a,int b){
    int temp=a;
    a=b;b=temp;
}

int main(){
    string n;
    cin>>n;
    int j=n.length();
    while(n[j-1]=='0'){
        n=n.substr(0,j-1);
        j--;
    }
    if(j%2==0){
        for(int i=0;i<=(j-2)/2;i++){
            swap(n[i],n[j-i-1]);
        }
        cout<<n;
    }else {
        for(int i=0;i<=(j-3)/2;i++){
            swap(n[i],n[j-i-1]);
        }
        cout<<n;
    }


}