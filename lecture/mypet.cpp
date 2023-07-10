/* new, delete - My pet */

#include <iostream>

typedef struct Animal
{
	char	name[30];
	int		age;
	int		health;
	int		food;
	int		clean;
};

void	play(Animal*& animal, char *name, int age, int health, int food, int clean)
{
	animal->age = age;
	animal->health = health;
	animal->food = food;
	animal->clean = clean;
}

void	show_stat(Animal*& animal)
{
	std::cout << "<< " << animal->name << "'s Status >>" << std::endl;
	std::cout << "Age : " << animal->age << "" << std::endl;
	std::cout << "Health : " << animal->health << "" << std::endl;
	std::cout << "Food : " << animal->food << "" << std::endl;
	std::cout << "Clean : " << animal->clean << "" << std::endl;
}

int main()
{
	struct Animal* list[30];

	while (1)
	{
		
	}

	return 0;
}