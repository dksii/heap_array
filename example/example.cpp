#include <iostream>
#include <heap_array/array.hpp>

int main()
{
	std::cout << "1d\n";
	HeapArray<int, 10> arr1; // int[10]

	for (int i = 0; i < arr1.size<0>(); i++)
	{
		arr1[i] = i;
	}

	for (int i = 0; i < arr1.size<0>(); i++)
	{
		std::cout << "arr1[" << i << "] = " << arr1[i] << '\n';
	}

	std::cout << "\n2d\n";
	HeapArray<int, 3, 4> arr2; // int[3][4]

	for (int i = 0; i < arr2.size<0>(); i++)
	{
		for (int j = 0; j < arr2.size<1>(); j++)
		{
			arr2[i][j] = i + j;
		}
	}

	for (int i = 0; i < arr2.size<0>(); i++)
	{
		for (int j = 0; j < arr2.size<1>(); j++)
		{
			std::cout << "arr2[" << i << "][" << j << "] = " << arr2[i][j] << '\n';
		}
	}

	std::cout << "\n3d\n";
	HeapArray<int, 3, 4, 5> arr3; // int[3][4][5]

	for (int i = 0; i < arr3.size<0>(); i++)
	{
		for (int j = 0; j < arr3.size<1>(); j++)
		{
			for (int k = 0; k < arr3.size<2>(); k++)
			{
				arr3[i][j][k] = i + j + k;
			}
		}
	}

	for (int i = 0; i < arr3.size<0>(); i++)
	{
		for (int j = 0; j < arr3.size<1>(); j++)
		{
			for (int k = 0; k < arr3.size<2>(); k++)
			{
				std::cout << "arr3[" << i << "][" << j << "][" << k << "] = " << arr3[i][j][k] << '\n';
			}
		}
	}

	return 0;
}