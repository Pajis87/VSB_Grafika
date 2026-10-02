#include "includer.h"
#include "GameObject.h"


class Scene {
public:
	void addObject(const GameObject& object) {
		objects.push_back(object);
	}
	void draw() {
		for (GameObject object : objects) {
			object.draw();
		}
	}
private:
	std::vector<GameObject> objects = {};
};
