#include "sysBullet.hpp"

void SysBullet::Init(){
    this->numBullets=0;
    this->limitBall=false;
}
void SysBullet::AddBullet(glm::mat4 model){
    if(this->limitBall){
        bullets[numBullets]->Init(model); 
    }else{
        bullets[numBullets]= new Bullet();
        bullets[numBullets]->setDeltaTime(this->deltaTime); 
        bullets[numBullets]->setCamera(this->camera); 
        bullets[numBullets]->Init(model); 
        
        keyBullets[bullets[numBullets]]=numBullets;
    }
    numBullets++;
    
    if(numBullets==10){
        numBullets=0;
        this->limitBall=true;
    }
}
void SysBullet::Update(){

  for ( auto item : this->bullets ){
    if( item.second->getRun() ){
      item.second->Update();
    }
  };
}
void SysBullet::Render(){
  for ( auto &item : this->bullets ){
    if( item.second->getRun()){
      item.second->Render();
    }
  };
}


void SysBullet::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void SysBullet::setCamera(Camera *camera){
    this->camera = camera ;
}
