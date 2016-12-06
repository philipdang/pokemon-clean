#include "pokemon.h"

std::ostream& operator<< (std::ostream &out, Pokemon &pokemon)
{
    out << "<Pokemon>" << std::endl
    << " <id> " << pokemon.id << " </id>" << std::endl
    << " <name> " << pokemon.name << " </name> " << std::endl
    << " <attack> " << pokemon.attack << " </attack> " << std::endl
    << " <defense> " << pokemon.defense << " </defense> " << std::endl
    << " <entry> " << std::endl
    << "  <number> " << pokemon.userEntry.number << " </number> " << std::endl
    << "  <name> " << pokemon.userEntry.name << " </name> " << std::endl
    << " </entry> " << std::endl
    << "</pokemon> ";
    return out;
}

void Pokemon::write()
{
	std::string fileName = std::to_string(id) + ".dat";
	std::ofstream datFile;

	datFile.open(fileName);

	datFile << *this;

	datFile.close();
}

Fire::Fire(int index) : Pokemon(index){
	maxHP+=1; speed+=2;
	attack+=2; defense-=2;
	specialAttack+=4; specialDefense+=1;
	weaknesses.push_back(element::water);
}

Water::Water(int index) : Pokemon(index){
	maxHP+=2; speed-=1;
	attack-=2; defense+=2;
	specialAttack-=4; specialDefense-=1;
	weaknesses.push_back(element::grass);
}

Grass::Grass(int index) : Pokemon(index){
	maxHP-=3; speed-=2;
	attack-=2; defense+=0;
	specialAttack-=3; specialDefense+=0;
	weaknesses.push_back(element::fire);
}

int Pokemon::take_damage(int damageAmount, std::list<element> damageTypes) {
	int weaknessCount = 0;
	for(auto wIt = weaknesses.begin(); wIt != weaknesses.end(); wIt++)
		for(auto dIt = damageTypes.begin(); dIt != damageTypes.end(); dIt++)
			if(*dIt == *wIt) weaknessCount++;

	damageAmount = damageAmount * (log(5 * weaknessCount + 5) / log(5));
	currentHP -= damageAmount;
	return damageAmount;
};

Pokemon *make_pokemon(element e, std::string n) {

	Pokemon *newPokemon;
	switch(index)
	{
		case 7: newPokemon = new Squirtle;
		case 8: newPokemon = new Wartortle;
		case 9: newPokemon = new Blastoise;
	}
	return newPokemon;
}

Squirtle::Squirtle(std::string nickname): Water(7)
{
	Pokemon.name = nickname;
}

Wartortle::Wartortle(std::string nickname): Water(8)
{
	Pokemon.name = nickname;
}

Blastoise::Blastoise(std::string nickname): Water(9)
{
	Pokemon.name = nickname;
}
