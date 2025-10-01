#include<iostream>
#include<cmath>
using namespace std;
class phan_so {
    private:
        int tu_so,mau_so;
    public:
        int get_tu_so() {
            return tu_so;
        }
        int get_mau_so() {
            return mau_so;
        }
        void nhap_phan_so();
        void in_phan_so();
        void rut_gon_phan_so();
        int ucln(int a,int b);
};
int main () {
    phan_so a;
    a.nhap_phan_so();
    cout<<"Phan so chua rut gon la: ";
    a.in_phan_so();
    cout<<"\nPhan so da rut gon la:";
    a.rut_gon_phan_so();
    a.in_phan_so();
}
void phan_so::nhap_phan_so() {
    cout<<"Vui long nhap tu so: ";
    cin>>tu_so;
    cout<<"Vui long nhap mau so: ";
    cin>>mau_so;
    while(mau_so==0) {
        cout<<"Vui long nhap lai mau so: ";
        cin>>mau_so;
    }
}
void phan_so::in_phan_so() {
    cout<<tu_so<<"/"<<mau_so;
}
int phan_so::ucln(int a,int b) {
    if(a==0) return b;
    return ucln(b%a,a);
}
void phan_so::rut_gon_phan_so() {
    int so_chia = ucln(tu_so,mau_so);
    tu_so = tu_so/so_chia;
    mau_so = mau_so/so_chia;
}