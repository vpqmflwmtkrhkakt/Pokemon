#ifndef DEF_POKEMON_STEEL

#define DEF_POKEMON_STEEL

#include "pokemon.hh"



class PokemonSteel : public Pokemon{

public:

	PokemonSteel(std::string p_name,int p_hp,int p_attack,int p_specialAttack,int p_defense,

		int p_specialDefense,int p_speed):

		Pokemon(p_name,Steel,p_hp,p_attack,p_specialAttack,p_defense,p_specialDefense,p_speed){}

	virtual void receive_dommage(const Pokemon& p);

};









#endif

