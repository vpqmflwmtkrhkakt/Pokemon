#ifndef DEF_POKEMON_GRASS

#define DEF_POKEMON_GRASS

#include "pokemon.hh"



class PokemonGrass : public Pokemon{

public:

	PokemonGrass(std::string p_name,int p_hp,int p_attack,int p_specialAttack,int p_defense,

		int p_specialDefense,int p_speed):

		Pokemon(p_name,Grass,p_hp,p_attack,p_specialAttack,p_defense,p_specialDefense,p_speed){}

	virtual void receive_dommage(const Pokemon& p);

};









#endif

