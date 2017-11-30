#include<iostream>
using namespace std;

enum eDir{STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class CBall{
	private:
		int x, y;//ball's current position
		int OriginalX, OriginalY;//Where the ball spawned.
		eDir direction; //the direction we want the ball to in;
	public:
		CBall(int posX, int posY){
			OriginalX = posX;
			OriginalY = posY;
			x = posX;
			y = posY;
			direction = STOP;
		}

		void Reset(){
			x = OriginalX;
			y = OriginalY;
			direction = STOP;
		}

		void changeDirection("eDir d"){//Get the ball to change direction.
			direction = d;
		}
		void randomDirection(){
			direction = (eDir)((rand()%6)+1);//the first movement is in a random direction.
		}
		inline /* This prevents to compiler from calling the function*/ int getX(){
		return x;
		}
		inline /* This prevents to compiler from calling the function*/ int getY(){
		return y;
		}
		inline /* This prevents to compiler from calling the function*/ int getDirection(){
		return direction;
		}

		void Move(){
			switch (direction)
			{
				case STOP:
					break;
				case LEFT:
					x--;
					break;
				case RIGHT:
					x++;
					break;
				case UPLEFT:
					x--; y--;
					break;
				case DOWNLEFT:
					x--;y++;
					break;
				case UPRIGHT:
					x++; y--;
					break;
				case DOWNRIGHT:
					x++;y++;
					break;
				default:
				break;

			}
		}
		friend ostream & operator <<(ostream & o, CBall c){
			o << "Ball[" <<c.x<<","<<c.y<<"][" << c.direction <<"]";
			return o;
		}
};

int main(){
	CBall c (0,0);
	cou<< c << endl;
	c.randomDirection();
	cout << c << endl;
	c.Move();
	cout << c << endl;
	c.randomDirection();
	c.Move();
	cout << c << endl;
	c.randomDirection();
	c.Move();
	cout << c << endl;


	return 0;
}
