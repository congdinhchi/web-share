#include<bits/stdc++.h>
#include <fstream>
using namespace std;

long long n;
long long a[1000000], check;

int main(){
    ifstream input("C:/Users/ADMIN/Desktop/my_document.txt");

    if (input.fail())
    {
        std::cout << "Failed to open this file!" << std::endl;
        return -1;
    }
    input>>n;
    input>>a[0];
    for(long long i=1;i<n;i++){
        input>>a[i];
        getchar();
        if (a[i]-a[i-1]<=0) check++;
    }
    input.close();
    cout<<check + 1;
}
