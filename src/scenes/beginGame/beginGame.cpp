#include "beginGame.hpp"

void BeginGame::Init(){
    this->camera= new Camera(1000,1000);
    this->stage=Stages::beginGame;
    this->stateGame=StateGame::RunToPoint;
    this->time=0.0;

    this->floor.Init(this->camera);
    this->floor.setBackgroundColor(glm::vec3(1.0,1.0,1.0));

    this->tank.setDeltaTime(this->deltaTime);
    this->tank.setKeys(this->keys);
    this->tank.setCamera(this->camera);
    this->tank.Init();
};
void BeginGame::Update(){
    
    this->tank.Update();
};
void BeginGame::Render(){

    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.003f, 0.03f,1.0f);
    this->floor.Render();
    this->tank.Render();
};

void BeginGame::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void BeginGame::setMouse(Mouse *mouse){
    this->mouse=mouse;
};
void BeginGame::setKeys(std::unordered_map<int,ButtonKey>*Keys){
    this->keys=Keys;
};
void BeginGame::setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys){
    this->mouseKeys=mouseKeys;
};

Stages BeginGame::getStage(){
    return this->stage ;
}
