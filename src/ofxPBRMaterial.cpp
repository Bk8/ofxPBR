#include "ofxPBRMaterial.h"

void ofxPBRMaterial::begin(ofxPBR* pbr){
    begin(pbr->getShader());
}

void ofxPBRMaterial::begin(ofShader* shader){
    this -> shader = shader;
    shader -> setUniform2f("textureRepeatTimes", textureRepeat);
    shader -> setUniform2f("detailTextureRepeatTimes", detailTextureRepeat);
    // baseColor
    if(enableGlobalColor){
        shader -> setUniform1i("enableGlobalColor", 1);
    } else {
        shader -> setUniform1i("enableGlobalColor", 0);
        shader -> setUniform4f("baseColorUniform", baseColor);
    }
    if(enableBaseColorMap && baseColorMap != nullptr && baseColorMap->isAllocated()){
        shader -> setUniform1i("enableBaseColorMap", 1);
        shader -> setUniformTexture("baseColorMap", *baseColorMap, 3);
    } else {
        shader -> setUniform1i("enableBaseColorMap", 0);
    }
    
    // roughnessMap
    if(enableRoughnessMap && roughnessMap != nullptr && roughnessMap->isAllocated()){
        shader -> setUniform1i("enableRoughnessMap", 1);
        shader -> setUniformTexture("roughnessMap", *roughnessMap, 4);
    } else {
        shader -> setUniform1i("enableRoughnessMap", 0);
        shader -> setUniform1f("roughnessUniform", roughness);
    }
    
    // metallicMap
    if(enableMetallicMap && metallicMap != nullptr && metallicMap->isAllocated()){
        shader -> setUniform1i("enableMetallicMap", 1);
        shader -> setUniformTexture("metallicMap", *metallicMap, 5);
    } else {
        shader -> setUniform1i("enableMetallicMap", 0);
        shader -> setUniform1f("metallicUniform", metallic);
    }
    
    // normalMap
    if(enableNormalMap && normalMap != nullptr && normalMap->isAllocated()){
        shader -> setUniform1i("enableNormalMap", 1);
        shader -> setUniformTexture ("normalMap", *normalMap, 6);
        shader -> setUniform1f ("normalValUniform", normalVal);
    } else {
        shader -> setUniform1i("enableNormalMap", 0);
    }
    
    // occlusionMap
    if(enableOcclusionMap && occlusionMap != nullptr && occlusionMap->isAllocated()){
        shader -> setUniform1i("enableOcclusionMap", 1);
        shader -> setUniformTexture("occlusionMap", *occlusionMap, 7);
    } else {
        shader -> setUniform1i("enableOcclusionMap", 0);
    }
    
    // emissionMap
    if(enableEmissionMap && emissionMap != nullptr && emissionMap->isAllocated()){
        shader -> setUniform1i("enableEmissionMap", 1);
        shader -> setUniformTexture("emissionMap", *emissionMap, 8);
    } else {
        shader -> setUniform1i("enableEmissionMap", 0);
    }
    
    // detailBaseColor
    if(enableDetailBaseColorMap && detailBaseColorMap != nullptr && detailBaseColorMap->isAllocated()){
        shader -> setUniform1i("enableDetailBaseColorMap", 1);
        shader -> setUniformTexture("detailBaseColorMap", *detailBaseColorMap, 9);
    } else {
        shader -> setUniform1i("enableDetailBaseColorMap", 0);
    }
    
    // detailNormalMap
    if(enableDetailNormalMap && detailNormalMap != nullptr && detailNormalMap->isAllocated()){
        shader -> setUniform1i("enableDetailNormalMap", 1);
        shader -> setUniformTexture ("detailNormalMap", *detailNormalMap, 10);
    } else {
        shader -> setUniform1i("enableDetailNormalMap", 0);
    }
}

void ofxPBRMaterial::end(){
    shader -> setUniform1i("enableBaseColorMap", 0);
    shader -> setUniform1i("enableRoughnessMap", 0);
    shader -> setUniform1i("enableMetallicMap", 0);
    shader -> setUniform1i("enableNormalMap", 0);
    shader -> setUniform1i("enableOcclusionMap", 0);
    shader -> setUniform1i("enableEmissionMap", 0);
    shader -> setUniform1i("enableDetailBaseColorMap", 0);
    shader -> setUniform1i("enableDetailNormalMap", 0);
    shader -> setUniform1i("enableGlobalColor", 0);
    shader -> setUniform2f("textureRepeatTimes", ofVec2f(1.0, 1.0));
    shader -> setUniform2f("detailTextureRepeatTimes", ofVec2f(1.0, 1.0));
}