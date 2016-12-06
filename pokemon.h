#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <list>

using namespace std;

enum class element {
    fire = 0, water = 1, grass = 2, normal = 3, dragon = 4
};

struct PokeEntry
{
	int number;
	char name[20];
	char type[10];
	char description;
	PokeEntry() {};
	PokeEntry(int n)
   	 {
		std::ifstream entryFile(std::to_string(n) + ".txt");
		entryFile >> number;
		entryFile >> name;
		entryFile >> type;
		entryFile.seekg(1, std::ios::cur);
		entryFile.getline(description, 199);
		entryFile.close();
	}
};

class Pokemon {
private:
	int id;
	std::string name;
	int level = 1;
protected:
	int maxHP = 20;
	int currentHP = maxHP;
	int speed = 10;
	int attack = 10;
	int defense = 10;
	int specialAttack = 10;
	int specialDefense = 10;
	std::list<element> weaknesses;

public:
	PokeEntry *userEntry;

	Pokemon(int i) {}
	Pokemon(int i)
	{
		userEntry = new PokeEntry(i);
	}
	~Pokemon() {}
	std::string get_name() {
		return name;
	}
	int get_level() {
		return level;
	}
	int get_maxHP() {
		return maxHP;
	}
	int get_currentHP() {
		return currentHP;
	}

	int take_damage(int damageAmount, std::list<element> damageTypes);

	friend Pokemon* make_pokemon(element type, std::string name);

	friend std::ostream& operator<< (std::ostream &out, Pokemon &pokemon);

	void write();

};

class Fire: public Pokemon {
public:
	Fire(int index);
};

class Water: public Pokemon {
public:
	Water(int index);

	virtual int attack1(Pokemon *pokemon)
   	{
        	list<element> temp = {element::water};
        	cout << this->get_name() << " used Bubble. " << pokemon->get_name() << " took " << take_damage(2, temp) << " damage.";
        	return int();
    	}
};

// Specific Water Pokemon

class Squirtle: public Water
{
	Squirtle(string nickname = "Squirtle");

	virtual int attack2(Pokemon *pokemon)
    	{
        	list<element> temp = {element::normal};
        	cout << this->get_name() << " used Tackle. " << pokemon->get_name() << " took " << take_damage(2, temp) << " damage.";
        	return int();
    	}
};

class Wartortle: public Water
{
	Wartortle(string nickname = "Wartortle");

	virtual int attack2(Pokemon *pokemon)
    	{
        	list<element> temp = {element::water};
        	cout << this->get_name() << " used Surf. " << pokemon->get_name() << " took " << take_damage(3, temp) << " damage.";
        	return int();
    	}
};

class Blastoise: public Water
{
	Blastoise(string nickname = "Blastoise");

	virtual int attack1(Pokemon *pokemon)
    	{
        	list<element> temp = {element::water, element::dragon};
        	cout << this->get_name() << " used Water Pledge. " << pokemon->get_name() << " took " << take_damage(8, temp) << " damage.";
        	return int();
    	}
    
    	virtual int attack2(Pokemon *pokemon)
    	{
        	list<element> temp = {element::water};
        	cout << this->get_name() << "used Hydro Cannon. " << pokemon->get_name() << " took " << take_damage(6, temp) << " damage.";
        	return int();
    	}
};

//-----------------------

class Grass: public Pokemon {
public:
	Grass(int index);
};

#endif // POKEMON_H
