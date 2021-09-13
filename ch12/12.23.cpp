//
// Created by lxx on 2021/8/7.
//
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main(){
    const char *c1 = "Hello ";
    const char *c2 = "world";
    char *ca = new char[strlen(c1) + strlen(c2)];
    strcpy(ca, c1);
    strcat(ca, c2);
    cout << ca << endl;
    return 0;
}

