#include "tank.hpp"

void DrawTank::Init(glm::vec3 *position){
    this->body.setPosition(position);
    this->body.setCamera(this->camera);
    this->body.setVetices();
    
    this->head.setCamera(this->camera);
    this->head.setVetices();
    this->head.setModel(&this->body.model);
    this->head.setPosition(glm::vec3(0.0,0.23,0));
    this->head.Init();
    this->undercarriageLeft.setCamera(this->camera);
    this->undercarriageLeft.setPosition(glm::vec3(-0.37,0.0,0.0));
    this->undercarriageLeft.setModel(&this->body.model);
    this->undercarriageLeft.Init();

    this->undercarriageRigth.setCamera(this->camera);
    this->undercarriageRigth.setPosition(glm::vec3(0.37,0.0,0.0));
    this->undercarriageRigth.setModel(&this->body.model);
    this->undercarriageRigth.Init();
    
    bullets.setDeltaTime(this->deltaTime);
    bullets.setCamera(this->camera);
    bullets.Init();
}
void DrawTank::Update(){
    this->body.Update();
    this->head.Update();
    this->undercarriageLeft.Update();
    this->undercarriageRigth.Update();
    bullets.Update();
}
void DrawTank::Render(){
    this->body.Render();
    this->head.Render();
    this->undercarriageLeft.Render();
    this->undercarriageRigth.Render();
    bullets.Render();
}

void DrawTank::setCamera(Camera *camera){
    this->camera=camera;
}
glm::mat4 DrawTank::getModel(){
    return this->body.model;
}

void DrawTank::move(float translate){
    this->body.move(glm::vec3(0.0,0.0,translate));
    this->undercarriageLeft.move(translate);
    this->undercarriageRigth.move(translate);
}
void DrawTank::rotate(float angle){
    //this->body.move(this->undercarriageRigth.initPosition);
    this->body.rotate(angle);
    //this->body.move(-this->undercarriageRigth.initPosition);
    if(angle > 0){
        this->undercarriageRigth.move(angle );
        //this->undercarriageLeft.move(angle * 0.05 );
    }else{
        this->undercarriageLeft.move(-angle  );
    }
}
void DrawTank::headRotate(double angle){
    this->head.rotate(angle);
}
void DrawTank::gunRotate(double angle){
    this->head.gun.rotate(angle);
}
void DrawTank::shootGun(){
    //shot
    //this->head.gun.model;
    this->bullets.AddBullet(*this->head.gun.model);
}
void DrawTank::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
};

