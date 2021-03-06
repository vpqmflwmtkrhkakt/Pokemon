#ifndef DEF_CHARACTER
#define DEF_CHARACTER
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "global2.hh"
#include "picture.hh"
#include "tilemap.hh"


class Character : public Picture{
private:
	sf::IntRect m_intRect; //image selectionnee dans le sprite (le sprite.png)
	std::vector<sf::Vector2<int>> m_ind;
public:
	Character(std::string filename, int x_inTileset, int y_inTileset, int w, 
		int h, int x, int y): Picture(filename, x, y), m_intRect(x_inTileset,y_inTileset,w,h){
			m_sprite.setTextureRect(m_intRect);
			m_sprite.setScale(1.5,1.5); //on agrandit l'image du perso car trop petite
			m_ind = {{0,0},{0,0},{0,0},{0,0}};
	}

	sf::Sprite get_sprite() const{return(m_sprite);}
	sf::IntRect get_intRect() const{return(m_intRect);}
	std::vector<sf::Vector2<int>> get_ind() const{return(m_ind);}
	std::vector<sf::Vector2<int>> get_indEdges(const TileMap& carte, int x, int y);
	bool inObstacleTile(const TileMap& carte, const int* tiles,const int* tiles2, std::vector<sf::Vector2<int>> indEdges, int& intersectX, int& intersectY);
	void update_index(const TileMap& carte);
	void update_spriteTextureRect(){m_sprite.setTextureRect(m_intRect);}
	void set_intRect(int p_left,int p_top){m_intRect.left = p_left;m_intRect.top = p_top;}
	void move_down(bool collision, sf::Clock& clock);
	void move_up(bool collision, sf::Clock& clock);
	void move_right(bool collision, sf::Clock& clock);
	void move_left(bool collision, sf::Clock& clock);
	bool collision(Direction direction, const TileMap& carte, const int* tiles,const int* tiles2);
};



#endif