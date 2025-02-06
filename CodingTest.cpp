#include <iostream>
#include <vector>
#include <algorithm>  // find() 사용을 위해 필요
#include "arrangement01.h"

using namespace std;

int main()
{
	vector<int> v = { 1, 2, 5, 6,4 };
	auto arr = ex03_commentary(v);
	for (int ar : arr)
	{
		cout << ar << " ";
	}
	

}