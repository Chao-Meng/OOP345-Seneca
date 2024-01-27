#include <iostream>

using namespace std;

enum action {
	walking, jumping, swimming, running, punching, idle
};


struct Player {
	action currentState;
	string name;
	int directionVelocityX;

	void run(int velocity) {
		directionVelocityX += velocity;
		if (directionVelocityX > 100 || directionVelocityX < -100) {
			currentState = action::running;
		}
		else if (directionVelocityX > 10 || directionVelocityX < -10) {
			currentState = action::walking;
		}
		else {
			directionVelocityX = 0;
			currentState = action::idle;
		}
	}

	void display() {
		cout << name << " is ";
		switch (currentState) {
		case action::idle:
			cout << "idle";
			break;
		case action::swimming:
			cout << "swimming";
			break;
		case action::walking:
			cout << "walking with a speed of " << directionVelocityX;
			break;
		case action::running:
			cout << "running with a speed of " << directionVelocityX;
			break;
		case action::jumping:
			cout << "jumping";
			break;
		case action::punching:
			cout << "punching";
			break;
		}
		cout << endl;
	}

};



int main() {
	Player one = { action::idle, "Mario", 0 };
	one.display();
	one.run(200);
	one.display();



	return 0;
}