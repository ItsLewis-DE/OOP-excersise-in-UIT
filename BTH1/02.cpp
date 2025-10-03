#include<iostream>
#include<cmath>
using namespace std;
class fraction {
    private:
        int numerator,denomirator;
    public:
        void input();
        void output();
        fraction operator-(fraction x);
        friend void fraction_higher(fraction a,fraction b);
};
int main () {
    fraction a;
    fraction b;
    a.input();
    b.input();
    fraction_higher(a,b);
}
fraction fraction::operator-(fraction x) {
    fraction res;
    res.numerator = numerator*x.denomirator - x.numerator*denomirator;
    res.denomirator = denomirator*x.denomirator;
    return res;
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
void fraction_higher(fraction a,fraction b) {
    fraction temp = a-b;
    int temp_2 = temp.denomirator*temp.numerator;
    cout<<"Phan so lon hon la: ";
    if(temp_2<0) {
        b.output();
    }
    else if(temp_2>0) {
        a.output();
    }
    else {
        a.output();
    }
}