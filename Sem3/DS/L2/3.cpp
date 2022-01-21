#include <iostream>
#include <iomanip>
using namespace std;
class timer{
    private:
    int hour;
    int min;
    int sec;
    public:

    void read(){
        char ch=':';
        cout<<"Enter the time in the format HH:MM:SS"<<endl;
        cin>>hour>>ch>>min>>ch>>sec;
    }

    void display(){
        cout<<hour<<':'<<min<<':'<<sec<<endl;
    }

    void add(timer t1, timer t2) {
        int s=t1.sec+t2.sec;
        int m=t1.min+t2.min;
        int h=t1.hour+t2.hour;
        sec=s%60;
        min=(m+s/60)%60;
        hour=(h+m/60)%24;
    }

    void difference(timer t1, timer t2){
        sec=t1.sec-t2.sec;
        min=t1.min-t2.min;
        hour=t1.hour-t2.hour;
        if (sec<0){
            min-=1;
            sec+=60;
        }
        if(min<0){
            hour-=1;
            min+=60;
        }
        if(hour<0){
            hour+=24;
        }
    }
};

int main(){
    timer t1,t2;
    t1.read();
    t2.read();
    timer t3, t4;
    t3.add(t1,t2);
    t4.difference(t1,t2);
    cout<<setw(12)<<"ADD  ";
    t3.display();
    cout<<"DIFFERENCE  ";
    t4.display();
}