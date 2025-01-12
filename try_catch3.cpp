#include<iostream>
#include<exception>
using namespace std;
class bank {
    double bal;
    public:
    void set(double bal){
        this->bal = bal;
        cout<<"Current balance is : "<<bal<<endl;
    }
    void deposit(){
        double a;
        cout<<"Enter amount which you want to deposit"<<endl;
        cin>>a;
        if(a<=0){
            throw invalid_argument("Unable to deposit amount\n");
        }
        bal += a;
        cout<<"Remaining balance is : "<<bal<<endl;
    }
    void withdrawn(){
        double a;
        cout<<"Enter amount which you want to withdrawn"<<endl;
        cin>>a;
        if(a>bal){
            throw invalid_argument("Insufficient balance\n");
        }
        bal -= a;
        cout<<"Remaining balance is : "<<bal<<endl;
    }
};
int main(){
    bank b;
    b.set(4000);
    int x;
    do
    {
        try
        {
            cout<<"Enter 1 to deposit\nEnter 2 to withdrawn\nEnter 0 to terminate\n";
        cin>>x;
        switch (x)
        {
        case 1:
        b.deposit();
        break;
        case 2:
        b.withdrawn();
        break;
        }
        }
        catch(exception& e)
        {
            cerr << e.what() << '\n';
        }
        
    } while (x>0);
}