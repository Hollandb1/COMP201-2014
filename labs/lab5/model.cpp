#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    ended = false;
    width = w;
    height = h;
    Coordinate head;
    Coordinate tail;
    direction = RIGHT;
    head.x = 1;
    head.y = 0;
    tail.x = 0;
    tail.y = 0;
    food.x = rand() %63; //randomize
    food.y = rand() % 47;
    snake.push_front(head);
    snake.push_back(tail);
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return ended || snake.empty() || snake.size() == width * height;
}

// Which way should the snake face?
void Model::go(Direction d) {
    direction = d;
}

// Return true if the front of the snake has the same coordinate as the food
bool Model::eating() {
	return false;
}

void Model::end() {
    ended = true;
}

// Move foward
void Model::crawl() {
    Coordinate front = snake.front();
	int count=0;
	for (std::list<Coordinate>::iterator it=snake.begin(); it!=snake.end(); it++) {
		if (count==0){
				count++;
			}
		else{
			
			if (it->x==front.x && it->y==front.y){
				direction=DEAD;
					while(snake.empty()!= NULL){
						snake.pop_back();
					}
				Model::end();
			}
		}
			
	}
    switch(direction) {
    case UP: front.y--; break;
    case DOWN: front.y++; break;
    case LEFT: front.x--; break;
    case RIGHT: front.x++; break;
    }
	if (front.x>63 || front.y>47){
		direction=DEAD;
		while(snake.empty()!= NULL){
			snake.pop_back();
		}
		Model::end();
		
		
	}
	

	
	
    // TODO: Colliding with the perimeter of the screen should set direction to DEAD
    // When DEAD, the snake slowly shrinks down to nothing
    
    if (direction != DEAD) {
        snake.push_front(front);
    }
    srand(time(0));

    // TODO: Colliding with food grows the snake (so don't pop_back in that case)
    // TODO: Also, colliding with food should cause us to place the food somewhere
    // else, but not anywhere on the snake.
	if( front.x == food.x && front.y == food.y){
		food.x= rand() % 63;
		food.y= rand() % 47;
		return;
	}
	else {
		snake.pop_back();
	}
	}
		
	