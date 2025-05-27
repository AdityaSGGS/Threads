#include<iostream>
#include<thread>
#include<algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

typedef long long int ull;

void even(ull start,ull end, ull *even_sum){
    ull sum=0;
    for(ull i=start;i<end;i++){
        if(!(i&1)){
            sum+=i;
        }
    }
    *even_sum=sum;
}

void odd(ull start,ull end, ull *odd_sum){
    ull sum=0;
    for(ull i=start;i<end;i++){
        if(i&1){
            sum+=i;
        }
    }
    *odd_sum=sum;
}


int main(int argc, char const *argv[])
{
    ull start = 0, end = 1900000000;
 
	ull OddSum = 0;
	ull EvenSum = 0;
    auto startTime = high_resolution_clock::now(); 

    thread t1(even,start,end,&EvenSum);
    thread t2(odd,start,end,&OddSum);

    t1.join();
    t2.join();

    auto stopTime = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout<<OddSum<<endl;
    cout<<EvenSum<<endl;

	cout << "Sec: " << duration.count()/1000000 << endl;
    return 0;
}
