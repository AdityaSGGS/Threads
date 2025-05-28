#include<thread>
#include<iostream>
#include<mutex>
using namespace std;


mutex m;
int count=0;

void increment(){
    for(int i=0;i<100000;i++){
        if(m.try_lock()){
            count++;
            m.unlock();
        }
    }
}


int main(int argc, char const *argv[])
{
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout<<count<<endl;
    return 0;
}
