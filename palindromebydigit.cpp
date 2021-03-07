#include<bits/stdc++.h>
using namespace std;
string minlen(int n){
    string s="1";
    n-=1;
    while(n--){
        s+="0";
    }
    return s;
}
long long maxlen(int n){
    long long s=0;
    while(n--)
        s=10*s+9;
    return s;
}
long long stolong(string s){
    long long number=0;
    for(int i=0; i<s.length(); i++){
        number=number*10+s[i]-'0';
    }
    return number;
}
string longtos(long long n){
    string s="";
    int x[20]={0};
    int i=0;
    while(n){
        x[i]=n%10;
        i++;
        n/=10;
    }
    for(int j=i-1; j>=0; j--){
        s+=(x[j]+'0');
    }
    return s;
}
string rev(string s){
    string a="";

    for(int i=s.length()-1; i>=0; i--){
        a+=s[i];
    }
    return a;
}
string nextn(string s){
    long long n=stolong(s);
    n++;
    return longtos(n);
}


int main(){
    int length=1;
    cin>>length;
    string s="1";
    int n;
    vector<string> vec;

    for(int j=1; j<=length; j++){
        if(j%2==1){
            s=minlen((j+1)/2);
            for(int i=maxlen(((j+1)/2-1)); i<maxlen((j+1)/2); i++){

                string xy=s,pu="";
                if(j>1){
                    pu=xy.substr(0,s.length()-1);
                    pu=rev(pu);
                    xy+=pu;
                    vec.push_back(xy);
                }
                else
                    vec.push_back(xy);
                cout<<xy<<endl;
                s=nextn(s);
            }
        }
        else{
            s=minlen(j/2);
            for(int i=maxlen(j/2-1);i<maxlen(j/2); i++){
                string xy=s;
                xy+=rev(xy);
                vec.push_back(xy);
                cout<<xy<<endl;

                s=nextn(s);
            }
        }
    }
}
