#include <iostream>
struct Zambie
{
	int health;
	bool alive;
	int spirit;
	char name[255];
};
struct Ninja
{
	int health;
	bool alive;
	int chi;
	char name[255];
};
bool CanZambieAttack(Zambie &z, Ninja &n)
{
	if (n.health <= 0)
		return false;
	if (z.spirit <= 0)
		return false;

}
bool CanNinjaAttack(Ninja &n, Zambie &z)
{
	if (z.health <= 0)
		return false;
	if (n.chi <= 0)
		return false;
}

void zombieInfo(Zambie z)
{
	std::cout << "chris's health and spirit are -> " << z.health << " & " << z.spirit << std::endl;



}
void ninjaInfo(Ninja n)
{
	std::cout << "regi's health and chi are -> " << n.health << " & " << n.chi << std::endl;

}
// a Zambie can't attack when the target has 0 health or when the zambie has 0 spirit
// make multiple attack types 
void ZamFight(Zambie &z, Ninja &n)
{
	bool CanAttack = CanZambieAttack(z, n);
	if (CanAttack == false)
	{
		std::cout << "CAN'T ATTACK!" << std::endl;

		return;
	}
	std::cout << "zambie is attacking ninja" << std::endl;
	n.health -= 10;
	std::cout << "the ninja took 10 damage his health is now -> " << n.health << std::endl;
	z.spirit -= 1;
	std::cout << "the zambie attacked so his spirit is now -> " << z.spirit << std::endl;
	if (z.spirit <= 0)
		std::cout << "the zambie does not have enough spirit energy to attack again" << std::endl;
	//fighting is when a zambie "does damage" to a ninja
	//fighting is when a ninja "does damage" to a zambie
	//"damage" is when we decrement the health variable of a ninja or zambie
	//in order to do "damage" you must "attack"
	//"attack" is able to be performed if you have positive chi if you are a ninja or positive spirit if you a zambie
	// you can not "attack" if you have negative chi as a ninja or negative spirit as zambie
}
//need to make it so that a Ninja can't attack when the target has 0 Health or when the Ninja has 0 chi
//make multiple attack types
void NinFight(Ninja &n, Zambie &z)
{
	bool CanAttack = CanNinjaAttack(n, z);
	if (CanAttack == false)
	{
		std::cout << "CAN'T ATTACK!!" << std::endl;
		return;
	}
	std::cout << "ninja is attacking zambie" << std::endl;
	z.health -= 10;
	std::cout << "the zambie took 10 damage his health is now -> " << z.health << std::endl;
	n.chi -= 1;
	std::cout << "the ninja attacked so his chi is now -> " << n.chi << std::endl;

	if (n.chi <= 0)
		std::cout << "the ninja has exhausted all of his chi, he cannot attack again" << std::endl;
}
int main()
{
	Zambie chris = { 90, true, 10,"big chris" };
	Zambie matthew = { 110, true, 15, "matthew" };
	Ninja regi = { 150, true, 15, "reggggggiiii" };
	Ninja wilson = { 100, true, 20, "wilsontheball" };
	char input = '0';

	printf("WELCOME TO THE ZAMBIE VERSUS NINJA BATTLE SIMULATOR!\n");
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("Controls\n");
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("Press Z to select a Zambie to attack with\n");
	printf("Press N to select a Ninja to attack with\n");
	printf("Press s to see the status of all characters\n");
	printf("Press r to see which characters have died and to end the game\n");
	while (input != 'q')
	{
		std::cin >> input;
		if (input == 'Z')
		{
			std::cout << "Now choose which Zambie will attack which Ninja\n" << std::endl;
			std::cout << "A = chris -> regi\n" << std::endl;
			std::cout << "B = matthew -> regi\n" << std::endl;
			std::cout << "C = chris -> wilson\n" << std::endl;
			std::cout << "D = matthew -> wilson\n" << std::endl;
			std::cin >> input;
			if (input == 'A')
			{
				std::cout << "CHRIS FIGHT REGI" << std::endl;
				ZamFight(chris, regi);
			}
			if (input == 'B')
			{
				std::cout << "MATTHEW FIGHT REGI" << std::endl;
				ZamFight(matthew, regi);
			}
			if (input == 'C')
			{
				std::cout << "CHRIS FIGHT WILSON" << std::endl;
				ZamFight(chris, wilson);
			}
			if (input == 'D')
			{
				std::cout << "MATTHEW FIGHT WILSON" << std::endl;
				ZamFight(matthew, wilson);
			}
		}
		if (input == 'N')
		{
			std::cout << "Now choose which Ninja will attack which Zambie\n" << std::endl;
			std::cout << "a= regi -> chris\n" << std::endl;
			std::cout << "b = wilson -> chris\n" << std::endl;
			std::cout << "c = regi -> matthew\n" << std::endl;
			std::cout << "d = wilson -> matthew\n" << std::endl;
			std::cin >> input;
			if (input == 'a')
			{
				std::cout << "REGI FIGHT CHRIS" << std::endl;
				NinFight(regi, chris);
			}
			if (input == 'b')
			{
				std::cout << "WILSON FIGHT CHRIS" << std::endl;
				NinFight(wilson, chris);
			}
			if (input == 'c')
			{
				std::cout << "REGI FIGHT MATTHEW" << std::endl;
				NinFight(regi, matthew);
			}
			if (input == 'd')
			{
				std::cout << "WILSON FIGHT MATHEW" << std::endl;
				NinFight(wilson, matthew);
			}
		}
		if (input == 's')
		{
			zombieInfo(chris);
			zombieInfo(matthew);
			ninjaInfo(regi);
			ninjaInfo(wilson);

		}
		if (input == 'r')
		{
			if (regi.health <= 0)
			{
				printf("Git Guhd Regi\n \a");

			}
			if (wilson.health <= 0)
			{
				printf("Rest in Pepperoni Wilson\n \a");

			}
			if (chris.health <= 0)
			{
				printf("Chris Got Rekt\n \a");
			}
			if (matthew.health <= 0)
			{
				printf("Goodbye Matthew");
			}
			printf("GAME OVER");
			break;
		}
		printf("new frame \n");

	}



	system("pause");
	//how i fight??
	return 0;
}