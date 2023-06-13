#include "tank.hpp"

void DrawTank::Init(glm::vec3 *position){
}
void DrawTank::Update(){
}
void DrawTank::Render(){
}

void DrawTank::setCamera(Camera *camera){
    this->camera=camera;
}
glm::mat4 DrawTank::getModel(){
    return glm::mat4(1.0);
}

void DrawTank::move(float translate){
}
void DrawTank::rotate(double angle){
}
void DrawTank::headRotate(double angle){
}

