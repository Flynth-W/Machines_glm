#pragma once

#include "../bullet/bullet.hpp"
#include <unordered_map>
class SysBullet{
    public:
        Camera  *camera;
        std::unordered_map<int,Bullet *>  bullets;
        std::unordered_map<Bullet *, int> keyBullets;
        int numBullets; 
        bool limitBall;
        double *deltaTime;

    public:
        void Init();
        void Update();
        void Render();

        void AddBullet(glm::mat4 model);
        void setDeltaTime(double *deltaTime);
        void setCamera(Camera *camera);
};
