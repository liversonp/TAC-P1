#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "GameObject.h"
#include "Vec2.h"

class Camera{
private:
    static GameObject* focus;

public:
    static void Follow (GameObject* newFocus);
    static void Unfollow();
    static void Update(float dt);
    static Vec2 pos;
    static Vec2 speed;
};

#endif