#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string Convert2Binary(int n){
    string result = "";
    while(n !=1){

        if(n%2==1) result+="1";
        else result +="0";
        n = n/2;
    }
    reverse(result.begin(),result.end());
    return result;
}

int main(){
    cout<<Convert2Binary(7);
}