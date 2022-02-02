#include <iostream>
#include <cmath>
#include <string>
#include <conio.h>
using namespace std;

class SnatchingRoots
{
public:
	virtual void GetRoots() = 0;
};
class LinearEquation : public SnatchingRoots
{
	float a;
	float b;
public:
	LinearEquation(float a, float b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void GetRoots()
	{
		cout << "x = " << b / a << "\n";
	}
};
class SqrtEquation :public SnatchingRoots
{
	float a;
	float b;
	float c;
public:
	SqrtEquation(float a, float b, float c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	virtual void GetRoots()
	{
		cout << "x1 = " << (-b + sqrt(b*b - 4*a*c))/2*a << "\n";
		cout << "x2 = " << (-b - sqrt(b * b - 4 * a * c)) / 2 * a << "\n";
	}
};

class Living
{
public:
	int countf = 0;
	int countr = 0;
	int counth = 0;
};
class Fox : public Living
{
	int age;
	const int deadage = 4;
	bool dead = 0;
public:
	Fox(int age)
	{
		this->age = age;
		countf++;
	}
	int& GetAge()
	{
		return age;
	}
	int& GetCountFox()
	{
		return countf;
	}
	bool& IsDead()
	{
		return dead;
	}
	int GetDeadAge()
	{
		return deadage;
	}
};
class Rabbit :public Living
{
	int age;
	const int deadage = 9;
	bool dead = 0;
public:
	Rabbit(int age)
	{
		this->age = age;
		countr++;
	}
	int& GetAge()
	{
		return age;
	}
	int& GetCountRabbit()
	{
		return countr;
	}
	bool& IsDead()
	{
		return dead;
	}
	int GetDeadAge()
	{
		return deadage;
	}
};
class Herb :public Living
{
public:
	Herb()
	{
		counth+=rand()%20;
	}
	int& GetCountHerb()
	{
		return counth;
	}
};
class Unliving : public Living
{
public:
	void DeleteAll()
	{
		countf = 0;
		countr = 0;
		counth = 0;
	}
};

int main()
{
	//LinearEquation lin(2, 4);
	//lin.GetRoots();
	//SqrtEquation sqr(1,-8,7);
	//sqr.GetRoots();
	srand(time(NULL));
	Fox foxs[5] = {0,2,4,3,1};
	Rabbit rabbits[8] = {0,2,4,6,8,7,5,3};
	Herb herbs;
	while (foxs[0].GetCountFox() != 0)
	{
		int year = 0;
		cout << "Year number: " << year << "\n";
		cout << "Herbs in area: " << herbs.GetCountHerb() << "\n";
		if (herbs.GetCountHerb() < rabbits->GetCountRabbit())
		{
			int deadr = rabbits->GetCountRabbit() - herbs.GetCountHerb();
			for (int i = 0; i < deadr; i++)
				rabbits[rand() % 8].IsDead() = 1;
			rabbits->GetCountRabbit() = herbs.GetCountHerb();
		}
		else
			herbs.GetCountHerb() -= rabbits->GetCountRabbit();
		int deadrab = foxs->GetCountFox();
		if (deadrab > 0)
		{
			if (deadrab > rabbits->GetCountRabbit())
			{
				rabbits->GetCountRabbit() = 0;
				for (int i = 0; i < 8; i++)
					rabbits[i].IsDead() = 1;
			}
			else
			{
				for (int i = 0; i < deadrab; i++)
					if (!rabbits[rand() % 8].IsDead())
						rabbits[rand() % 8].IsDead() = 1;
					else
						i--;
				rabbits->GetCountRabbit() -= foxs->GetCountFox();
			}
		}
		else
		{
			int deadf = rabbits->GetCountRabbit() - foxs->GetCountFox();
			for (int i = 0; i < deadf; i++)
				if (!foxs[rand() % 5].IsDead())
					foxs[rand() % 5].IsDead() = 1;
				else
					i--;
			foxs->GetCountFox() = rabbits->GetCountRabbit();
			rabbits->GetCountRabbit() = 0;
			for(int i = 0 ; i < 8;i++)
				rabbits[i].IsDead() = 1;
		}
		cout << "Count of fox in area: " << foxs->GetCountFox() << "\nAges of foxes in area: ";
		for (int i = 0; i < 5; i++)
		{
			foxs[i].GetAge()++;
			if (foxs[i].GetAge() < foxs[i].GetDeadAge())
				foxs[i].IsDead() = 1;
			if (!foxs[i].IsDead())
				cout << foxs[i].GetAge() << " ";
		}
		cout << "\n"<< "Count of rabbits in area: " << rabbits->GetCountRabbit() << "\nAges of rabbits in area: ";
		for (int i = 0; i < 8; i++)
		{
			rabbits[i].GetAge()++;
			if (rabbits[i].GetAge() < rabbits[i].GetDeadAge())
				rabbits[i].IsDead() = 1;
			if (!rabbits[i].IsDead())
				cout << rabbits[i].GetAge() << " ";
		}
		cout << "\n";
		for(int i = 0; i < 8;i++)
			if (rabbits[i].IsDead())
			{
				rabbits[i].IsDead() = 0;
				rabbits[i].GetAge() = 0;
				rabbits[i].GetCountRabbit()++;
			}
		if(year%2==0)
			for (int i = 0; i < 5; i++)
				if (foxs[i].IsDead())
				{
					foxs[i].IsDead() = 0;
					foxs[i].GetAge() = 0;
					foxs[i].GetCountFox()++;
				}
		herbs.GetCountHerb() = rand() % 20;
		_getch();
	}
	return 0;
}