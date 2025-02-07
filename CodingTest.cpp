#include <iostream>
#include <vector>
#include <algorithm>  // find() 사용을 위해 필요
#include "arrangement01.h"
#include "stack01.h"

using namespace std;

void print2D(vector<vector<int>> vec)
{
    for (const auto& innerVec : vec) {
        copy(innerVec.begin(), innerVec.end(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    cout << endl;
}

void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    cout << ex09(10) << endl;       // 1010
    cout << ex09(27) << endl;       // 11011 
    cout << ex09(12345) << endl;    // 11000000111001 

    return 0;
}



