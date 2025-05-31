#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;

int amount=0;

timed_mutex m;

void increment(int i){
    if(m.try_lock_for(std::chrono::seconds(1))){
        ++amount;
        this_thread::sleep_for(std::chrono::seconds(2));
        cout<<"Thread "<<i<<" Entered "<<endl;
        m.unlock();
    }else{
        cout<<"Thread "<<i<<" could not enter"<<endl;
    }
}


int main(int argc, char const *argv[])
{
    thread t1(increment,1);
    thread t2(increment,2);

    t1.join();
    t2.join();
    cout<<amount<<endl;
    return 0;
}
