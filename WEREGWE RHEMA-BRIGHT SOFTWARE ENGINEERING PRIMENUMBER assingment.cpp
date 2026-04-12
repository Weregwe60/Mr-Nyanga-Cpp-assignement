#include <iostream>
using namespace std;

void printPrimes(int n) {
    for(int a=2;a<=n;a++){
        int p=1;
        for(int b=2;b*b<=a;b++){
            if(a%b==0){p=0;break;}
        }
        if(p)cout<<a<<" ";
    }
}

int main() {
    int n;
    cout << "Enter n:";
    cin >> n;
    
    cout<<"All prime numbers in this range are: ";
    
     printPrimes(n);
    
    return 0;
}