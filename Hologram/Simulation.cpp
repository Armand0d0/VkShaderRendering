/*
 * Copyright (C) 2016 Google, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cassert>
#include <cmath>
#include <array>
#include <glm/gtc/matrix_transform.hpp>
#include "Simulation.h"







Simulation::Simulation(int object_count) : random_dev_() {
   

    objects_.reserve(object_count);
    for (int i = 0; i < object_count; i++) {

        
        objects_.emplace_back(Object{
        Meshes::MESH_RECTANGLE,
        });

        auto &obj = objects_[i];
        float pos[3] = {     0.0f, 0.0f, -15.0f};//     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f};
       float pows[16] = { .00,     2.0f,0.0f, 0.0f,     0.0f, 2.0f, 0.0f,     0.0f, 0.0f, 2.0f,    00.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f,     };
        float coef[6] = {           1.,                2.0,                      3.0f,                   0.0,                     0.0                  ,00. };
        
         Func3D speed = {
        {0.0,      0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//addX
        {0.0,      2.0f, 2.0f, 2.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//powersX
        {0.0,      -1.0f, -10.0f, -1.0f,     1.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//coeffX

        {0.0,      0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//addY
        {0.0,      2.0f, 2.0f, 2.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//powersY
        {0.0,      -1.0f, -10.0f, -1.0f,     0.0f, 1.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//coeffY

        {0.0,      0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//addZ
        {0.0,      5.0f, 5.0f, 5.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//powersZ
        {0.0,      -1.0f, -10.0f, -1.0f,     0.0f, 0.0f, 1.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f}//coeffZ
        };
        
        for(int j = 0;j<16;j++){
            obj.Density.pos[j/4] = pos[j/4];
            obj.Density.powers[j] = pows[j];
            obj.Density.coeff[j] = coef[j];

            //obj.Speed = speed;
            obj.Speed.addX[j] = speed.addX[j];
            obj.Speed.powersX[j] = speed.powersX[j];
            obj.Speed.coeffX[j] = speed.coeffX[j];

            obj.Speed.addY[j] = speed.addY[j];
            obj.Speed.powersY[j] = speed.powersY[j];
            obj.Speed.coeffY[j] = speed.coeffY[j];

            obj.Speed.addZ[j] = speed.addZ[j];
            obj.Speed.powersZ[j] = speed.powersZ[j];
            obj.Speed.coeffZ[j] = speed.coeffZ[j];
            
        }
    }
}

void Simulation::set_frame_data_size(uint32_t size) {
    uint32_t offset = 0;
    for (auto &obj : objects_) {
        obj.frame_data_offset = offset;
        offset += size;
    }
}
//*/
/*float pow(float a, float b){
    return pow((double)a,(double)b);
}*/
void Simulation::update(float timeDelta, int begin, int end) {
    time_ += timeDelta;
    for (int i = begin; i < end; i++) {
        auto &obj = objects_[i];
        glm::vec3 Pos =  glm::vec3(0.0f);
        glm::vec3 axis = glm::normalize( glm::vec3(0.0f,0.0f,1.0f));

        glm::mat4 trans = glm::rotate(glm::mat4(1.0f),0.0f,axis);
        obj.model = glm::scale(glm::translate(glm::mat4(1.0f), Pos) * trans,glm::vec3(0.5f));
        obj.alpha = 1.0f;
        //glm::vec3 v0 = glm::vec3(0.0f,0.0f,0.0f);
        //glm::vec3 v1 = glm::vec3(1.0f,1.0f,1.0f);
        //const int n = 16;
        float pos[3] = {   0.0f, 0.0f, -5.0f};
        float pows[16] = {      10.0f, 0.0f, 0.0f,     0.0f, 10.0f, 0.0f,     0.0f, 0.0f, 10.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f,     0.5};
        float coef[6] = {    1./pow(2.,pows[1]),      1.0f,                  1.0f,                   0.,                     0.                ,0.5};

        //Acc Divergence :
        //AD = f(Density)

        //Acceleration : 
        //vec3 acc :        x = dAD/dx     y = dAD/dy      z = dAD/dz
        //AD = 	-COEF(0)*Pow(x+ADD(0),POW(0))  +	-COEF(1)*Pow(y+ADD(1),POW(1))  +  -COEF(2)*Pow(z+ADD(2),POW(2)) + ... + 1.  
        //acc.x  =  	-COEF(0)*POW(0)*Pow(x+ADD(0),POW(0)-1)  +	     0        +                  0       + ... + 0.
        //acc.y  =  	  0          +	    -COEF(1)*POW(1)*Pow(y+ADD(1),POW(1)-1)  +                  0       + ... + 0.
        //acc.z  =  	   0          +	     0        +     -COEF(2)*POW(2)*Pow(z+ADD(2),POW(2)-1)      + ... + 0.
        #define a obj.Density.add
        #define p obj.Density.powers
        #define c obj.Density.coeff 
 
        Func3D acc = {
        {0.5,      0.0f, 0.0f, -5.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//addX
        {0.5,      0.0f, 0.0f, -5.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//powersX
        {0.5,      0.0f, 0.0f, -5.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//coeffX

        {0.5,      0.0f, 0.0f, -5.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//addY
        {0.5,      0.0f, 0.0f, -5.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//powersY
        {0.5,      0.0f, 0.0f, -5.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//coeffY

        {0.5,      0.0f, 0.0f, -5.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//addZ
        {0.5,      0.0f, 0.0f, -5.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f},//powersZ
        {0.5,      0.0f, 0.0f, -5.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f}//coeffZ
        };
        #define ax obj.Speed.addX
        #define px obj.Speed.powersX
        #define cx obj.Speed.coeffX
        #define ay obj.Speed.addY
        #define py obj.Speed.powersY
        #define cy obj.Speed.coeffY
        #define az obj.Speed.addZ
        #define pz obj.Speed.powersZ
        #define cz obj.Speed.coeffZ

        // vec3 Speed :  sx sy sz
        // Div = dsx/dx + dsy/dy + dsz/dz
        //     = dsx.x/dx + 0..+0   + dsy.y/dy + 0..+0   + dsz.z/dz + 0..+0 
        //     = COEF(0)*POW(0)*Pow(x+ADD(0),POW(0)-1)   +	COEF(1)*POW(1)*Pow(y+ADD(1),POW(1)-1)  +  COEF(2)*POW(2)Pow(z+ADD(2),POW(2)-1) 
       /* Func SpeedDiv = {
            {0.5,  ax[1],ay[2],az[3],   ax[4],ay[5],az[6],  ax[7],ay[8],az[9],  ax[10],ay[11],az[12],  ax[13],ay[14],az[15]},//add
            {0.5,  px[1]-1.,py[2]-1.,pz[3]-1.,   px[4]-1.,py[5]-1.,pz[6]-1.,  px[7]-1.,py[8]-1.,pz[9]-1.,  px[10]-1.,py[11]-1.,pz[12]-1.,  px[13]-1.,py[14]-1.,pz[15]-1.},//powers
            {0.5,  cx[1]*px[1],cy[2]*py[2],cz[3]*pz[3],   cx[4]*px[4],cy[5]*py[5],cz[6]*pz[6],  cx[7]*px[7],cy[8]*py[8],cz[9]*pz[9],  cx[10]*px[10],cy[11]*py[11],cz[12]*pz[12],  cx[13]*px[13],cy[14]*py[14],cz[15]*pz[15]}//coeff
        };*/
       // obj.Density = mul(obj.Density, SpeedDiv);
        /*for(int j = 0;j<16;j++){
            a[j] = add[j];
            p[j] = pows[j];
            c[j] *= coef[j];
            
        }//*/

    }

}
Simulation::Func mul(Simulation::Func f1, Simulation::Func f2){
        float add[16];
        float pows[16];
        float coeff[16];
        
}
