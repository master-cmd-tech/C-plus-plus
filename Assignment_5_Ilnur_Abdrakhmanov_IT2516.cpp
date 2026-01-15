#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

// Task 1
void task1() {
    unsigned long long a,b;cin>>a>>b;
    unsigned long long *p1=&a,*p2=&b,temp=*p1;*p1=*p2;*p2=temp;
    cout<<a<<" "<<b;
}

// Task 2
void task2() {
    int n;cin>>n;int a[100],b[100],*p=a,*q=b;for(int i=0;i<n;i++)cin>>*(p+i);
    int j=0;for(int i=0;i<n;i+=2)* (q+j++)=*(p+i);
    for(int i=1;i<n;i+=2)* (q+j++)=*(p+i);
    for(int i=0;i<n;i++)cout<<*(q+i)<<" ";
}

// Task 3
void task3() {
    int n;cin>>n;int a[100],*p=a;for(int i=0;i<n;i++)cin>>*(p+i);
    int *mn=min_element(a,a+n),*mx=max_element(a,a+n),c=0;
    if(mn>mx)swap(mn,mx);
    for(int *i=mn+1;i<mx;i++)if(*i%2==0)c++;
    cout<<c;
}

// Task 4
void task4() {
    char s[20];cin>>s;char *p=strtok(s,".");int c=0;
    while(p){int v=atoi(p);if(v<0||v>255){cout<<0;return;}c++;p=strtok(NULL,".");}
    cout<<(c==4);
}

// Task 5
void task5() {
    string d;int x=0,y=0,n;
    while(cin>>d>>n){
        if(d=="North")y+=n;
        else if(d=="South")y-=n;
        else if(d=="East")x+=n;
        else if(d=="West")x-=n;
    }
    cout<<x<<" "<<y;
}

// Task 6
void task6() {
    long long m,n;cin>>m>>n;int c=0;
    for(long long i=m;i<=n;i++){
        string s=to_string(i);
        int a=0,b=0;
        for(int j=0;j<4;j++)a+=s[j]-'0';
        for(int j=4;j<8;j++)b+=s[j]-'0';
        if(a==b)c++;
    }
    cout<<c;
}

// Task 7
void task7() {
    string s;getline(cin,s);if(s.empty())getline(cin,s);
    for(auto &x:s)x=toupper(x);
    cout<<(s.find("AITU")!=string::npos?"Yes":"No");
}

// Task 8
void replaceChar(char *source,char *dest){
    while(*source){*dest=(*source=='!')?'.':*source;source++;dest++;}
    *dest=0;
}
void task8(){
    char a[1001],b[1001];cin.getline(a,1001);
    if(strlen(a)==0)cin.getline(a,1001);
    replaceChar(a,b);cout<<b;
}

// Task 9
void task9() {
    char s[101];cin>>s;int n=strlen(s),c=0;string r="";
    for(int i=n-1;i>=0;i++){r+=s[i];c++;if(c%3==0&&i!=0)r+=' ';}
    reverse(r.begin(),r.end());
    cout<<r;
}

// Task 10
void task10() {
    char s[1001];cin.getline(s,1001);
    if(strlen(s)==0)cin.getline(s,1001);
    char *p=s;string cur="",best="";
    while(*p){
        if(isdigit(*p))cur+=*p;
        else{if(cur.size()>best.size())best=cur;cur="";}
        p++;
    }
    if(cur.size()>best.size())best=cur;
    for(int i=0;i<best.size();i++){cout<<best[i];if((i+1)%2==0&&i+1!=best.size())cout<<" ";}
}

// Task 11
void addVeryLongIntegers(char *a,char *b,char *c){
    int i=strlen(a)-1,j=strlen(b)-1,k=0,carry=0;char r[100005];
    while(i>=0||j>=0||carry){
        int x=(i>=0?a[i--]-'0':0)+(j>=0?b[j--]-'0':0)+carry;
        r[k++]=x%10+'0';carry=x/10;
    }
    r[k]=0;for(int l=0;l<k/2;l++)swap(r[l],r[k-1-l]);
    strcpy(c,r);
}
void task11(){
    char a[100005],b[100005],c[100010];
    cin>>a>>b;addVeryLongIntegers(a,b,c);cout<<c;
}

// Task 12
void task12(){
    char s[10001];cin>>s;int c=0;
    for(int i=0;i+4<strlen(s);i++)
        if(strncmp(s+i,">>-->",5)==0||strncmp(s+i,"<--<<",5)==0)c++;
    cout<<c;
}

// Task 13
void task13(){
    char s[1001];cin.getline(s,1001);
    if(strlen(s)==0)cin.getline(s,1001);
    int letters=0,words=0,len=0;
    for(int i=0;s[i];i++){
        if(isalpha(s[i]))len++;
        else if(len>0){letters+=len;words++;len=0;}
        if(s[i]=='#')break;
    }
    if(len>0){letters+=len;words++;}
    cout<<fixed<<setprecision(9)<<(words?(double)letters/words:0.0);
}

// MAIN
int main(){
    int n;cin>>n;
    switch(n){
        case 1: task1();break;
        case 2: task2();break;
        case 3: task3();break;
        case 4: task4();break;
        case 5: task5();break;
        case 6: task6();break;
        case 7: task7();break;
        case 8: task8();break;
        case 9: task9();break;
        case 10: task10();break;
        case 11: task11();break;
        case 12: task12();break;
        case 13: task13();break;
        default: cout<<"Invalid task number!";break;
    }
    return 0;
}
