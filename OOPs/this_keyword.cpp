#include<iostream>
using namespace std;
class Hero {
    private:
        int health;
    public:
        Hero (int health) {
            this -> health = health;
        }
        int getHealth() {
            return health;
        }

};
int main() {
    Hero ramesh(10);//input yahi dena hai parameter ka
    int h = ramesh.getHealth();
    cout << h;
    return 0;
}
