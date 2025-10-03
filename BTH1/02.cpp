#include<iostream>
#include<cmath>
using namespace std;
class fraction {
    private:
        int numerator,denomirator;
    public:
        void reduceFraction();
        void input();
        void output();
        friend void fraction_higher(fraction a,fraction b);
};
int gcd(int a,int b);
int lcm(int a,int b);
int main () {
    fraction a;
    fraction b;
    a.input();
    b.input();
    fraction_higher(a,b);
}
void fraction::input() {
    cout<<"Moi nhap tu so: ";
    cin>>numerator;
    cout<<"Moi nhap phan so: ";
    cin>>denomirator;
    while(denomirator==0) {
        cout<<"Mau so khong xac dinh! Xin moi nhap lai mau so: ";
        cin>>denomirator;
    }
    if(denomirator<0) {
        numerator = -numerator;
        denomirator = -denomirator;
    }
}
void fraction::output() {
    if(denomirator==1) cout<<numerator;
    else
    cout<<numerator<<"/"<<denomirator;
}
int gcd(int a, int b) {
    a= abs(a);
    b= abs(b);
    if (a == 0) return b;
    return gcd(b % a, a);
}
int lcm(int a,int b) {
    return a/gcd(a,b)*b;
}
void fraction::reduceFraction() {
    int divisor = gcd(numerator, denomirator);
    numerator = numerator / divisor;
    denomirator = denomirator / divisor;
}

void fraction_higher(fraction a,fraction b) {
    a.reduceFraction();
    b.reduceFraction();
    if(a.denomirator==b.denomirator) {
        if(a.numerator>=b.numerator) {
            cout<<"Phan so lon hon la: ";
            a.output();
        }
        else {
            cout<<"Phan so lon hon la: ";
            b.output();
        }
    }
    else {
        int x = lcm(a.denomirator,b.denomirator);
        cout<<"Phan so lon hon la: ";
        if(a.numerator*(x/a.denomirator)<(b.numerator*(x/b.denomirator))) b.output();
        else a.output();
    }
}