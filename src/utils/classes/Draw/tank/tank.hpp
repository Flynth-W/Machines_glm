#pragma once
#include "../../shader.hpp"
#include "../../camera/camera.hpp"
#include "./body/body.hpp"
#include "./undercarriage/undercarriage.hpp"
#include "./head/head.hpp"
#include "../../sysBullets/sysBullet.hpp"
class DrawTank{   
    private:
        Camera *camera;
        DrawBodyOfTank body;
        DrawUndercarriage undercarriageLeft;
        DrawUndercarriage undercarriageRigth;
        DrawHeadOfTurtle head;
        SysBullet bullets;
        double *deltaTime;
    public:
        void Init(glm::vec3 *position);
        void Update();
        void Render();
        
        void setCamera(Camera *camera);
        void setDeltaTime(double *deltaTime);
        glm::mat4 getModel();

        void move(float translate);
        void rotate(float angle);
        void headRotate(double angle);
        void gunRotate(double angle);
        void shootGun();
};
