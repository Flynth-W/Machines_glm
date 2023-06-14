#include "undercarriage.hpp"

void DrawUndercarriage::Init(){
    this->guide.setPosition(this->initPosition);
    this->guide.setCamera(this->camera);
    this->guide.setModel(this->modelBody);
    this->guide.setVetices();
    
    this->trackShoes.setPosition(this->initPosition);
    this->trackShoes.setCamera(this->camera);
    this->trackShoes.setModel(&this->guide.model);
    this->trackShoes.Init();

};
void DrawUndercarriage::Update(){
    this->guide.Update();
    this->trackShoes.Update();
};
void DrawUndercarriage::Render(){
    this->guide.Render();
    this->trackShoes.Render();
}

void DrawUndercarriage::setPosition(glm::vec3 initPosition){
    this->initPosition= initPosition;
}
void DrawUndercarriage::setCamera(Camera *camera){
    this->camera = camera ;
}
void DrawUndercarriage::setModel(glm::mat4 *modelBody){
    this->modelBody = modelBody;
}

void DrawUndercarriage::move(double translate){
    this->trackShoes.move(translate);
}
