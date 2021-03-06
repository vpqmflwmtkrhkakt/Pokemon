#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "global2.hh"
#include "picture.hh"
#include "character.hh"
#include "tilemap.hh"
#include <vector>


//anime et deplace le perso s'il n'y a pas d'obstacleL
void Character::move_down(bool collision, sf::Clock& clock){
	if(clock.getElapsedTime().asSeconds() > 0.10){ //pour ralentir l'animation, sinon elle est trop rapide
		if((m_intRect.left == 67 and m_intRect.top == 33)or(m_intRect.left == 68 and m_intRect.top == 97)){
	    	m_intRect.left = 66;
			m_intRect.top = 64;
		}
		else if(m_intRect.left == 66 and m_intRect.top == 64){
			m_intRect.left = 68;
			m_intRect.top = 97;
		}
		else{ //si le m_sprite dans le mauvais sens, on le remet dans le bon sens : le sens du deplacement
			m_intRect.left = 67;
			m_intRect.top = 33;
		}
	m_sprite.setTextureRect(m_intRect);
	if(!collision){
		m_sprite.move(0,10);
	}
	clock.restart();
	}
}


//anime et deplace le perso s'il n'y a pas d'obstacle
void Character::move_up(bool collision, sf::Clock& clock){
	if(clock.getElapsedTime().asSeconds() > 0.10){ //pour ralentir l'animation, sinon elle est trop rapide
		if((m_intRect.left == 0 and m_intRect.top == 0)or(m_intRect.left == 69 and m_intRect.top == 0)){
	    	m_intRect.left = 36;
			m_intRect.top = 96;
		}
		else if(m_intRect.left == 36 and m_intRect.top == 96){
			m_intRect.left = 69;
			m_intRect.top = 0;
		}
		else{
			m_intRect.left = 0;
			m_intRect.top = 0;
		}
	m_sprite.setTextureRect(m_intRect);
	if(!collision){
		m_sprite.move(0,-10);
	}
	clock.restart();
	}
}


//anime et deplace le perso s'il n'y a pas d'obstacle
void Character::move_right(bool collision, sf::Clock& clock){
	if(clock.getElapsedTime().asSeconds() > 0.10){ //pour ralentir l'animation, sinon elle est trop rapide
		if((m_intRect.left == 35 and m_intRect.top == 0)or(m_intRect.left == 35 and m_intRect.top == 65)){
	    	m_intRect.left = 34;
			m_intRect.top = 33;
		}
		else if(m_intRect.left == 34 and m_intRect.top == 33){
			m_intRect.left = 35;
			m_intRect.top = 65;
		}
		else{
			m_intRect.left = 35;
			m_intRect.top = 0;
		}
	m_sprite.setTextureRect(m_intRect);
	if(!collision){
		m_sprite.move(10,0);
	}
	clock.restart();
	}
}


//anime et deplace le perso s'il n'y a pas d'obstacle
void Character::move_left(bool collision, sf::Clock& clock){
	if(clock.getElapsedTime().asSeconds() > 0.10){ //pour ralentir l'animation, sinon elle est trop rapide
		if((m_intRect.left == 5 and m_intRect.top == 65)or(m_intRect.left == 4 and m_intRect.top == 96)){
	    	m_intRect.left = 4;
			m_intRect.top = 34;
		}
		else if(m_intRect.left == 4 and m_intRect.top == 34){
			m_intRect.left = 4;
			m_intRect.top = 96;
		}
		else{
			m_intRect.left = 5;
			m_intRect.top = 65;
		}
	m_sprite.setTextureRect(m_intRect);
	if(!collision){
		m_sprite.move(-10,0);
	}
	clock.restart();
	}
}


//donne l'indice (iX,iY) de la case ou tile dans laquelle se trouve un point
void Character::update_index(const TileMap& carte){
	m_ind[0].x = m_sprite.getPosition().x/carte.get_tileSize();
	m_ind[0].y = m_sprite.getPosition().y/carte.get_tileSize();
	m_ind[1].x = (m_sprite.getPosition().x + 36)/carte.get_tileSize();
	m_ind[1].y = m_sprite.getPosition().y/carte.get_tileSize();
	m_ind[2].x = (m_sprite.getPosition().x + 36)/carte.get_tileSize();
	m_ind[2].y = (m_sprite.getPosition().y + 36)/carte.get_tileSize();
	m_ind[3].x = m_sprite.getPosition().x/carte.get_tileSize();
	m_ind[3].y = (m_sprite.getPosition().y + 36)/carte.get_tileSize();
}


//donne l'indice des quatre coins de l'image
std::vector<sf::Vector2<int>> Character::get_indEdges(const TileMap& carte, int x, int y){
	std::vector<sf::Vector2<int>> indEdges = {{0,0},{0,0},{0,0},{0,0}};
	indEdges[0].x = x/carte.get_tileSize();
	indEdges[0].y = y/carte.get_tileSize();
	indEdges[1].x = (x + 36)/carte.get_tileSize();
	indEdges[1].y = y/carte.get_tileSize();
	indEdges[2].x = (x + 36)/carte.get_tileSize();
	indEdges[2].y = (y + 36)/carte.get_tileSize();
	indEdges[3].x = x/carte.get_tileSize();
	indEdges[3].y = (y + 36)/carte.get_tileSize();
	return(indEdges);
}


bool Character::inObstacleTile(const TileMap& carte, const int* tiles,const int* tiles2, std::vector<sf::Vector2<int>> indEdges, int& intersectX, int& intersectY){
	bool inObstacle = false;
	if(tiles[indEdges[0].x + indEdges[0].y*carte.get_xTiles()] == 3){intersectX = indEdges[0].x;intersectY = indEdges[0].y;inObstacle = true;}
	else if(tiles[indEdges[1].x + indEdges[1].y*carte.get_xTiles()] == 3){intersectX = indEdges[1].x;intersectY = indEdges[1].y;inObstacle = true;}
	else if(tiles[indEdges[2].x + indEdges[2].y*carte.get_xTiles()] == 3){intersectX = indEdges[2].x;intersectY = indEdges[2].y;inObstacle = true;}
	else if(tiles[indEdges[3].x + indEdges[3].y*carte.get_xTiles()] == 3){intersectX = indEdges[3].x;intersectY = indEdges[3].y;inObstacle = true;}
	else if(tiles2[indEdges[0].x + indEdges[0].y*carte.get_xTiles()] == 23){intersectX = indEdges[0].x;intersectY = indEdges[0].y;inObstacle = true;}
	else if(tiles2[indEdges[1].x + indEdges[1].y*carte.get_xTiles()] == 23){intersectX = indEdges[1].x;intersectY = indEdges[1].y;inObstacle = true;}
	else if(tiles2[indEdges[2].x + indEdges[2].y*carte.get_xTiles()] == 23){intersectX = indEdges[2].x;intersectY = indEdges[2].y;inObstacle = true;}
	else if(tiles2[indEdges[3].x + indEdges[3].y*carte.get_xTiles()] == 23){intersectX = indEdges[3].x;intersectY = indEdges[3].y;inObstacle = true;} 
	else if(tiles2[indEdges[0].x + indEdges[0].y*carte.get_xTiles()] == 4){intersectX = indEdges[0].x;intersectY = indEdges[0].y;inObstacle = true;}
	else if(tiles2[indEdges[1].x + indEdges[1].y*carte.get_xTiles()] == 4){intersectX = indEdges[1].x;intersectY = indEdges[1].y;inObstacle = true;}
	else if(tiles2[indEdges[2].x + indEdges[2].y*carte.get_xTiles()] == 4){intersectX = indEdges[2].x;intersectY = indEdges[2].y;inObstacle = true;}
	else if(tiles2[indEdges[3].x + indEdges[3].y*carte.get_xTiles()] == 4){intersectX = indEdges[3].x;intersectY = indEdges[3].y;inObstacle = true;}
	else if(tiles2[indEdges[0].x + indEdges[0].y*carte.get_xTiles()] == 12){intersectX = indEdges[0].x;intersectY = indEdges[0].y;inObstacle = true;}
	else if(tiles2[indEdges[1].x + indEdges[1].y*carte.get_xTiles()] == 12){intersectX = indEdges[1].x;intersectY = indEdges[1].y;inObstacle = true;}
	else if(tiles2[indEdges[2].x + indEdges[2].y*carte.get_xTiles()] == 12){intersectX = indEdges[2].x;intersectY = indEdges[2].y;inObstacle = true;}
	else if(tiles2[indEdges[3].x + indEdges[3].y*carte.get_xTiles()] == 12){intersectX = indEdges[3].x;intersectY = indEdges[3].y;inObstacle = true;}
	else if(tiles2[indEdges[0].x + indEdges[0].y*carte.get_xTiles()] == 20){intersectX = indEdges[0].x;intersectY = indEdges[0].y;inObstacle = true;}
	else if(tiles2[indEdges[1].x + indEdges[1].y*carte.get_xTiles()] == 20){intersectX = indEdges[1].x;intersectY = indEdges[1].y;inObstacle = true;}
	else if(tiles2[indEdges[2].x + indEdges[2].y*carte.get_xTiles()] == 20){intersectX = indEdges[2].x;intersectY = indEdges[2].y;inObstacle = true;}
	else if(tiles2[indEdges[3].x + indEdges[3].y*carte.get_xTiles()] == 20){intersectX = indEdges[3].x;intersectY = indEdges[3].y;inObstacle = true;}
	return(inObstacle);
}

// detecte une collision entre le perso et le decor
//	- direction : direction du deplacement du perso (varie en fonction de la touche appuyee par le joueur)
//	- carte : carte tracee a l'affichage
//	- tiles : carte avec des numeros qui representent les tiles et leur texture (sol, vide, ciel, carrelage...)
bool Character::collision(Direction direction, const TileMap& carte, const int* tiles,const int* tiles2){
	bool collision = false;
	int posX = m_sprite.getPosition().x;
	int posY = m_sprite.getPosition().y; 
	int newX = posX;
	int newY = posY;
	if(direction == UP){newY -= 10;}
	if(direction == DOWN){newY += 10;}
	if(direction == RIGHT){newX += 10;}
	if(direction == LEFT){newX -= 10;}
 	int obstacleX = 0; 
 	int obstacleY = 0; 
 	int intersectX = 0;
 	int intersectY = 0;	
	std::vector<sf::Vector2<int>> newIndEdges = get_indEdges(carte,newX,newY); //donnes les points au bord de la nouvelle position du perso 
 	if(inObstacleTile(carte, tiles, tiles2, newIndEdges, intersectX, intersectY)){
 		obstacleX = carte.get_vertices()[intersectX][intersectY][0].position.x;
 		obstacleY = carte.get_vertices()[intersectX][intersectY][0].position.y;
 		if(abs(obstacleX - posX) < 40 or abs(obstacleY - posY) < 40){
 			collision = true;
 		}
 	}	
	return(collision);
}


 //dans le sprite du perso (sprite.png) : bas : 67 33 //haut : 0 0 //right : 35 0 //left 5 65
