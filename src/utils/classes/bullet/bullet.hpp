#pragma once
#include "../Draw/bullet/bullet.hpp"

class Bullet{
    private:
        double * deltaTime;
        DrawBullet square;
        double radius;
        bool run=false;
        Camera *camera;
        glm::vec3 *position;
    public:
        Bullet();
        void Init(glm::mat4 model);
        void Update();
        void Render();
        void setDeltaTime(double *deltaTime);
        void setRadius(unsigned int radius);
        void setCamera(Camera *camera);
        
        glm::vec3 getPosition() ;
        double getRadio() ;
        bool getRun() ;
};
