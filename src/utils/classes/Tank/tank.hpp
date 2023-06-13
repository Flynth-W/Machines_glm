#pragma once
#include "../Draw/tank/tank.hpp"
#include "../../../event/events.hpp"
#include "../camera/camera.hpp"

class Tank{
    private:
        std::unordered_map<int,ButtonKey>*keys;
        Camera *camera;
        double *deltaTime;
        double radius;
        DrawTank drawTank;
        glm::vec3 position;
    private:
        void events();
        void view();
    public:
        void Init();
        void Update();
        void Render();
        
        void setKeys(std::unordered_map<int,ButtonKey>*keys) ;
        void setDeltaTime(double *deltaTime);
        void setCamera(Camera *camera);

};
