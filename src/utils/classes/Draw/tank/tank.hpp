#pragma once
#include "../../shader.hpp"
#include "../../camera/camera.hpp"
#include "./body/body.hpp"
#include "./undercarriage/undercarriage.hpp"


class DrawTank{   
    private:
        Camera *camera;
        DrawBodyOfTank body;
        DrawUndercarriage undercarriageLeft;
        DrawUndercarriage undercarriageRigth;
    public:
        void Init(glm::vec3 *position);
        void Update();
        void Render();
        
        void setCamera(Camera *camera);
        glm::mat4 getModel();

        void move(float translate);
        void rotate(float angle);
        void headRotate(double angle);
};
