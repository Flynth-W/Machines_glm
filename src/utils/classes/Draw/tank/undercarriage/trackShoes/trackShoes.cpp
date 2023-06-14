#include "trackShoes.hpp"

void DrawTrackShoes::Init(){

    for(int i=0 ; i < 26 ; i++){
        this->trackShoes[i].setVetices();
        this->trackShoes[i].setCamera(this->camera);
        this->trackShoes[i].setModel(this->modelBody);
    }

    this->trackShoes[1].setPosition(Phases::right , 7.76409 , glm::vec3(0.0, 0.139435 , 0.362568));
    this->trackShoes[2].setPosition(Phases::right , 7.17103, glm::vec3(0.0, 0.1086 , 0.438352));
    this->trackShoes[3].setPosition(Phases::right , 6.57538 , glm::vec3(0.0, 0.0403274 , 0.484066));
    this->trackShoes[4].setPosition(Phases::right , 5.92126 , glm::vec3(0.0, -0.0495706 ,0.48093));
    this->trackShoes[5].setPosition(Phases::right , 5.38392 , glm::vec3(0.0, -0.109602 , 0.437106));
    this->trackShoes[6].setPosition(Phases::bottom , 4.71239 , glm::vec3(0.0,-0.139987 ,0.351));
    this->trackShoes[7].setPosition(Phases::bottom , 4.71239 , glm::vec3(0.0,-0.139987 ,0.268));
    this->trackShoes[8].setPosition(Phases::bottom , 4.71239 , glm::vec3(0.0,-0.139987 ,0.176));
    this->trackShoes[9].setPosition(Phases::bottom , 4.71239 , glm::vec3(0.0,-0.139987 ,0.085));
    this->trackShoes[10].setPosition(Phases::bottom , 4.71239 , glm::vec3(0.0,-0.139987 ,0.005));
    this->trackShoes[11].setPosition(Phases::bottom , 4.71239 , glm::vec3(0.0,-0.139987 ,-0.085));
    this->trackShoes[12].setPosition(Phases::bottom , 4.71239 , glm::vec3(0.0,-0.139987 ,-0.170));
    this->trackShoes[13].setPosition(Phases::bottom , 4.71239 , glm::vec3(0.0,-0.139984 ,-0.260));
    this->trackShoes[14].setPosition(Phases::left , 4.72679 , glm::vec3(0.0,-0.139985 , -0.347985));
    this->trackShoes[15].setPosition(Phases::left , 4.07147 , glm::vec3(0.0 ,-0.112217 , -0.43371));
    this->trackShoes[16].setPosition(Phases::left , 3.47687 ,glm::vec3(0.0, -0.046065 , -0.482204));
    this->trackShoes[17].setPosition(Phases::left , 2.82158, glm::vec3(0.0,0.0440415 ,-0.482892));
    this->trackShoes[18].setPosition(Phases::left , 2.16656 ,glm::vec3(0.0,0.11588 ,-0.42856));
    this->trackShoes[19].setPosition(Phases::left , 1.5708 ,glm::vec3(0.0, 0.139936 , -0.354108));
    this->trackShoes[20].setPosition(Phases::top , 7.85398 ,glm::vec3(0.0, 0.139935 , -0.260));
    this->trackShoes[21].setPosition(Phases::top , 7.85398 ,glm::vec3(0.0, 0.139934 , -0.170));
    this->trackShoes[22].setPosition(Phases::top , 7.85398 ,glm::vec3(0.0, 0.139934 , -0.085));
    this->trackShoes[23].setPosition(Phases::top , 7.85398 ,glm::vec3(0.0, 0.139934 , -0.005));
    this->trackShoes[24].setPosition(Phases::top , 7.85398 ,glm::vec3(0.0, 0.139934 , 0.085));
    this->trackShoes[25].setPosition(Phases::top , 7.85398 ,glm::vec3(0.0, 0.139934 , 0.170));
    this->trackShoes[0].setPosition(Phases::top, 7.85398,glm::vec3(0.0,0.139935 ,     0.260) );

    this->time=0;
}

void DrawTrackShoes::Update(){
   
    float distace= 0.09;
    float distaceAngle= 0.65;
    int numLeft=0;

    for( int i=0 ; i< 25 ;i++){
        if(this->trackShoes[i].phase == Phases::top){
            float newZ=this->trackShoes[i].position.z - this->trackShoes[i + 1].position.z;
            this->trackShoes[i + 1].position.z += distace + newZ ;
              
        }
        if(this->trackShoes[i].phase == Phases::bottom){
            float newZ=this->trackShoes[i].position.z - this->trackShoes[i + 1].position.z;
            this->trackShoes[i + 1].position.z -= distace - newZ ;
        }
    }


    for( int i=0 ; i< 26 ;i++){
        this->trackShoes[i].Update();
    }
};
void DrawTrackShoes::Render(){
    for( int i=0 ; i< 26 ;i++){
        this->trackShoes[i].Render();
    }
}
void DrawTrackShoes::move(float translate){
    this->time += translate;

    for(int i =0 ; i < 26 ; i++){
        this->trackShoes[i].move(glm::vec3(0.0,0.0,translate));
    }
}

void DrawTrackShoes::setPosition(glm::vec3 position){
    this->position=position;
}
void DrawTrackShoes::setCamera(Camera *camera){
    this->camera=camera;
}
void DrawTrackShoes::setModel(glm::mat4 *modelBody){
    this->modelBody=modelBody;
}
