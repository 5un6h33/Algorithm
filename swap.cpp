#include<iostream>
using namespace std;

void swap_call_by_value(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

void swap_call_by_pointer(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main(void)
{
	int x, y;

	cout << "x 입력 : ";
	cin >> x;
	cout << "y 입력 : ";
	cin >> y;

	cout << endl;

	cout << "swap_call_by_value 함수 사용 전"  << endl;
	cout << "x = " << x << ", y = " << y << endl;

	swap_call_by_value(x, y);

	cout << "swap_call_by_value 함수 사용 후"  << endl;
	cout << "x = " << x << ", y = " << y << endl;

	cout << endl;

	cout << "swap_call_by_reference 함수 사용 전"  << endl;
	cout << "x = " << x << ", y = " << y << endl;

	swap_call_by_pointer(&x, &y);

	cout << "swap_call_by_reference 함수 사용 후"  << endl;
	cout << "x = " << x << ", y = " << y << endl;

	return 0;
}