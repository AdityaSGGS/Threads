#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m;

int amount=0;

void increment1(){
    m.lock();
    amount+=2;
    m.unlock();
}

void increment2(){
    m.lock();
    amount+=3;
    m.unlock();
}


int main(int argc, char const *argv[])
{
    thread t1(increment1);
    thread t2(increment2);
    t1.join();
    t2.join();

    cout<<amount<<endl;
    return 0;
}
