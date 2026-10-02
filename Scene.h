#include "includer.h"
#include "GameObject.h"


class Scene {
public:
	void addObject(const GameObject& object) {
		objects.push_back(object);
	}
private:
	std::vector<GameObject> objects;
};
