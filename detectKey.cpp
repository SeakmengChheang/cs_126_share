#include <iostream>
#include <conio.h>

using std::cout;

int main()
{
	char key = getch();

	if (key == 72) //up arrow
	{
		cout << "Up Arrow";
	}
	else if (key == 75) //left arrow
	{
		cout << "Left Arrow";
		key = 'l';
	}
	else if (key == 77) //right
	{
		key = 'r';
	}
	else if (key == 80) //down
	{
		key = 'd';
	}

	std::cout << key;

	return 0;
}