#include <iostream>
#include <vector>

#include "include/save.hpp"

using namespace std;

int main()
{
	Save::saveData(vector<int> {1,23,34});
	
	return 0;
}