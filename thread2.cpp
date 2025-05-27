#include<iostream>
#include<thread>
#include<algorithm>
#include <chrono>
using namespace std;


void run(int n){
    while(n){
        cout<<"Hi"<<endl;
        n--;
    }
    std::this_thread::sleep_for(chrono::seconds(5));
}

int main(int argc, char const *argv[])
{
    thread t1(run,10);
    cout<<"Main"<<endl;
    t1.detach();
    cout<<"End"<<endl;
    return 0;
}
