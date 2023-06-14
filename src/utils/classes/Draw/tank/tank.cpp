#include "tank.hpp"

void DrawTank::Init(glm::vec3 *position){
    this->body.setPosition(position);
    this->body.setCamera(this->camera);
    this->body.setVetices();

    this->undercarriageLeft.setCamera(this->camera);
    this->undercarriageLeft.setPosition(glm::vec3(-0.37,0.0,0.0));
    this->undercarriageLeft.setModel(&this->body.model);
    this->undercarriageLeft.Init();

    this->undercarriageRigth.setCamera(this->camera);
    this->undercarriageRigth.setPosition(glm::vec3(0.37,0.0,0.0));
    this->undercarriageRigth.setModel(&this->body.model);
    this->undercarriageRigth.Init();
}
void DrawTank::Update(){
    this->body.Update();
    this->undercarriageLeft.Update();
    this->undercarriageRigth.Update();
}
void DrawTank::Render(){
    this->body.Render();
    this->undercarriageLeft.Render();
    this->undercarriageRigth.Render();
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
}

