#include <iostream>

namespace Recursion
{
	int get7sCount(int num);


}

int main()
{
	using namespace Recursion;
	std::cout << " get7sCount "<< get7sCount(717) << std::endl;
}

namespace Recursion
{
	int get7sCountHelper(int num, int count)
	{
		if(num == 0)
		{
			return count;
		}
		int mod = num % 10;
		if(mod == 7)
		{
			count += 1;
		}
		num = num/10;
		return get7sCountHelper(num, count);
	}
	int get7sCount(int num)
	{
		return get7sCountHelper(num, 0);
	}
}
