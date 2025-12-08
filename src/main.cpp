#include <iostream>
#include "State.h"
#include <ctime>
using namespace std;

// Run utilizing make and then ./sim in terminal!!!!!!!!!!
int main(){
    srand(static_cast<unsigned>(time(nullptr))); //Make sure randint is always random
    State state(32, -10, 10); 
    state.run();
    return 0;
}  