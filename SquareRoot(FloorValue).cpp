#include"AllHeader.h"

int getSqrt(int num, int beg, int end)
{
	int mid = beg + (end - beg) / 2;

	if (beg > end) return -1;

	if (mid*mid == num)
		return mid;

	if (mid*mid > num)
	{
		return getSqrt(num, beg, mid - 1);
		// If we would have needed ceil value, we mmust have updatde answer when mid*mid is greater than x, and move closer to sqrt(x)
		// like done below:
		/*int r = getSqrt(num, beg, mid - 1);
		return ((r == -1) ? (mid) : r);*/	//in case we need to return just max
	}
	else
	{
		// Since we needed floor value, we updated answer when mid*mid is  
		// smaller than x, and move closer to sqrt(x) 
		int r = getSqrt(num, mid + 1, end);
		return ((r == -1) ? (mid) : r);	//in case we need to return just max
	}

}

int main()
{
	int n, sqr;
	cout << "Enter No. ";
	cin >> n;

	sqr = getSqrt(n, 0, (n / 2) +1);

	cout << "Sqrt is : " << sqr << endl;

	return 0;
}
