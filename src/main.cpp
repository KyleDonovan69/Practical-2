#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef struct Position
{
	int x;
	int y;
	void
		print()
	{
		cout << "[ x: " << x << " ]" << "[ y: " << y << " ]" << endl;
	}
} Coordinates;

enum WarHead
{
	EXPLOSIVE,
	NUCLEAR
};

struct Player
{
	Coordinates coordinates;
};

typedef struct Enemy
{
	Coordinates coordinates;
} Target;

struct Missile
{
	WarHead payload;
	Coordinates coordinates;
	Target target;

	bool armed;
	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update()
	{
		coordinates.x += 0;
		coordinates.y += 0;
	}
};

WarHead selectWarhead();

WarHead selectWarhead(){
	std::cout << "Select a warhead" << "\n";
	cout << "E = Explosive" << "\n";
	cout << "N = Nuclear" << "\n";
	char input = cin.get();
	WarHead selected = WarHead::EXPLOSIVE;
	if(input == 'n')
	{
		selected = WarHead::NUCLEAR;
		cout << "You have selected nuclear" << endl;
	}
	else{
		cout << "You have selected explosive" << endl;
	}
	return selected;
}

int main()
{
	// Create a new Enemy
	Enemy* e = new Enemy();
	Player* p= new Player();
	cout << "THIS IS A 3x3 GRID" << endl;

	std::cout << "Enter your co-ordinates" << std::endl;
	cout << "X: ";
	cin >> p->coordinates.x;
	while (p->coordinates.x > 3)
	{
		cout << "Outside grid please ReEnter X:";
		cin >> p->coordinates.x;
	}
	cout << "Y: ";
	cin >> p->coordinates.y;
	while (p->coordinates.y > 3)
	{
		cout << "Outside grid please ReEnter Y:";
		cin >> p->coordinates.y;
	}
	p->coordinates.print();

	// Set Enemy Position / Target
	e->coordinates.x = 2;
	e->coordinates.y = 2;

	// Print Enemy Position
	cout << "Print Enemy Position" << endl;
	e->coordinates.print();

	// Create a new Missile
	Missile* m = new Missile();

	// Set Missile Payload
	m->payload = selectWarhead();

	// Set Missile Target by dereferencing Enemy pointer
	m->target = *e;

	srand(time(0));
	int code = rand() % 9999 + 1;
	int inputNo = 0;
	cout << "The arming code is: " << code << endl;
	cout << "Input code to arm missile" << endl;
	cin >> inputNo;

	if(inputNo == code)
	{
		m->armed = true;
	}
	while(inputNo != code){
		cout << "You can read the code.... right?" << endl;
		cin >> inputNo;
	}

	// Set Initial Position
	std::cout << "Where is missile firing?" << std::endl;
	cout << "X: ";
	cin >> m->coordinates.x;
	while(m->coordinates.x > 3)
	{
		cin >> m->coordinates.x;
	}
	cout << "Y: ";
	cin >> m->coordinates.y;

	// Print Position
	//cout << "Print Missile Position" << endl;
	//m->coordinates.print();

	// Update Position
	m->update();

	if (m->coordinates.x == e->coordinates.x && m->coordinates.y == e->coordinates.y)
	{
		if(m->payload == NUCLEAR)
		{
			cout << "You wiped his coordinates off the world map....." << endl;
		}
		else{
		cout << "You absolutely nailed him!" << endl;
		}
	}
	else{
		cout << "How could you miss? He was standing still!" << endl;
	}

	// Print Missile Position
	//cout << "Print Missile Position after an Update" << endl;
	//m->coordinates.print();


	// Print Missile target
	//cout << "Print Missile Target Position" << endl;
	//m->target.coordinates.print();

	cin.get();
}