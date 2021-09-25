// ConsoleApplication17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void func(int& x) {

    cout << x << "; ";
}
class MyFunc {
    int& sum;
    int& count;
public:
    MyFunc(int& sum, int& count) : sum(sum), count(count) {

    }
    void operator()(int& x) {
        ++count;
        sum += x;
    }
};

class MyF {
    int sum = 0;
    int count = 0;
public:
 
    void operator()(int& x) {
        ++count;
        sum += x;
    }
    int getSum() {
        return sum;
    }
    int getCount() {
        return count;
    }
    double getAvg() {
        return sum / (double)count;
    }
};



class SomeClass {

};

ostream& operator<<(ostream& s, const SomeClass&) {

    s << "SomeClass";
    return s;
}


int main(){

    vector<SomeClass> vsc(10);
    ostream_iterator<SomeClass> oscit(cout, "; ");
    copy(vsc.begin(), vsc.end(), oscit);

    vector<int> v({ 1,2,3,4,5,6,7,8,9,10,11 });    

    ostream_iterator<int> oit(cout, "; ");
    copy(v.begin(), v.end(), oit);


    int sum = 0, count = 0;
    MyFunc f(sum, count);
    MyF f0;
    
    //for_each(v.begin(), v.end(), func);
    //f0 = for_each(v.begin(), v.end(), f0);
    //for_each(v.begin(), v.end(), f);

    auto l = [&sum, &count](int& x) {
        ++count;
        sum += x;
    };
  
    for_each(v.begin(), v.end(), l);

    sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
    for_each(v.begin(), v.end(), func);

    cout << sum << count << sum / (double) count;

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
