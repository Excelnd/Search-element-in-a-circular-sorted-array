// Search element in a circular sorted array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CiruclarArraySearch(int A[], int n, int x)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (x == A[mid]) return mid;

		if (A[mid] <= A[high])
		{
			if (x > A[mid] && x <= A[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
		else
		{
			if (A[low] <= x && x < A[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int A[] = { 12, 15, 18, 22, 3, 6, 7, 9 };
	int x;
	cout << "Enter a number :";
	cin >> x;

	int index = CiruclarArraySearch(A, 8, x);
	if (index == -1)
		cout << x << " not found in the array ";
	else
		cout << x << " was found at index " << index;
    return 0;
}

