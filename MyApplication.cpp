#ifndef MY_APPLICATION_H
#define MY_APPLICATION_H

#include <map>

#include "Engine/EasyGL.h"
#include "Engine/Scene.h"
#include "Assets/GameObjects/Triangle.h"

class MyApplication {
public:
	void init() {
		engine = EasyGL();
		engine.init(800, 800, "ZPG");
	}

	void setupScenes() {
		scenes.insert({ "triangle", new Scene() });

		engine.setActiveScene(scenes["triangle"]);
	}

	void setupGameObjects() {
		scenes["triangle"]->addObject(new Triangle());
	}

	void run() {
		while (engine.running()) {
			engine.startFrame();
			engine.endFrame();
		}
	}
private:
	EasyGL engine;
	std::map<const char*, Scene*> scenes;
};

#endif