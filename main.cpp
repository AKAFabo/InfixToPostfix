#include <iostream>
#include <string>
#include <iomanip>
#include "evaluate.cpp"

using namespace std;

int main(int argc, char const *argv[])
{

    //cout << buildPostfix("1+5*7^9") << endl;
    double result = evalPostfix(buildPostfix("7+(6*7)+7-(3*7)")); 
    cout << "Result: " << fixed << setprecision(2) << result << endl;

    return 0;
}
//TODO FIX POW PORQUE NO FUNCIONAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA