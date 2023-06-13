#pragma once
#include "../../shader.hpp"
#include "../../camera/camera.hpp"

class DrawTank{   
    private:
        Camera *camera;
    public:
        void Init(glm::vec3 *position);
        void Update();
        void Render();
        
        void setCamera(Camera *camera);
        glm::mat4 getModel();

        void move(float translate);
        void rotate(double angle);
        void headRotate(double angle);
};
