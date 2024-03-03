#version 310 es

precision highp float;

//layout(location = 0) in vec3 color;
//layout(location = 1) in float alpha;

layout(std140,  set = 0, binding = 0) uniform param_block {
	
	vec2 resolution;
	float time;
	vec3 pos;
	mat4 powers;
	mat3x2 coeff;
	//mat4 model;
	

} params;
layout(location = 0) out vec4 fragcolor;

#define time params.time
#define resolution params.resolution
//#define POW params.powers
//#define COEF params.coeff
#define PI 3.141592
#define E 2.7182818
#define zero vec3(0.,0.,0.)
#define one vec3(1.,1.,1.)
#define white vec3(1.,1.,1.)
#define red vec3(1.,0.,0.)
#define green vec3(0.,1.,0.)
#define blue vec3(0.,0.,1.)
#define black vec3(0.,0.,0.)

float POW(int i){
	float res = 0.;
	//if(i>=-1 && i< 16){
		//int row = i%4
	res = params.powers[0][i+1];
	//}	
	return res;
}
float COEF(int i){
	float res = 0.;
	//if(i>=-1 && i< 16){
		//int row = i%4
	res = params.coeff[0][i];
	//}	
	return res;
}
float POS(int i){
	float res = 0.;
	//if(i>=-1 && i< 16){
		//int row = i%4
	res = params.pos[i];
	//}	
	return res;
}
 mat3 rot(vec3 a){
    mat3 mx = mat3(1.,    0.,      0.,
                   0.,cos(a.x),-sin(a.x),
                   0.,sin(a.x),cos(a.x));
   mat3 my = mat3(cos(a.y),0.,sin(a.y),
                   0.,     1.,   0.,
                 -sin(a.y),0.,cos(a.y));
  mat3 mz = mat3(cos(a.z),-sin(a.z),0.,
                 sin(a.z),cos(a.z), 0.,
                   0.,      0.,     1.);
    return  mx*my*mz;

    }
float sin2(float f){
	return sin(f)*sin(f);
}
float cos2(float f){
	return cos(f)*cos(f);
}
float Pow(float x,float y){
	return pow(x*x,y/2.);
}

/////////////////////////////////////////////---------------/////////////////////////////////////////////---------------!
float d =10.,a =1.;
float f(float x){
	return 	(sign(x+a)-sign(x-a))/3.;
}
float g(float x){
	return 	(sign(x+a)-sign(x-a))/3.;
}
float h(float x){
	return 	(sign(x+a)-sign(x-a))/3.;
}
/////////////////////////////////////////////---------------/////////////////////////////////////////////---------------!


float densityF(vec3 pos){
	
	//pos+=vec3(3.*sin(3.),3.*cos(3.),(-5));//translation
	//pos+=vec3(POS(0),POS(0),POS(1));//translation
		pos+=vec3(0.,0.,-5.);//translation

	//pos/=10.;//scale
	pos*=rot(vec3(time,time,-time));//rotation
	float x=pos.x, y=pos.y, z=pos.z;
	float a = 1.;//sin2(time)/2.+0.5;
	float d = 10.;
	float x2 = Pow(x,2.);
	float y2 = Pow(y,2.);
	float z2 = Pow(z,2.);
	float z3 = Pow(z,3.);//*/
	float A=1.,B=1.,C=1.;

	float res = 0.;
	/*for(int i=0;i<3;i++){

		res += -COEF(i)   *   Pow(x,POW(3*i))   *   Pow(y,POW(3*i+1))   *   Pow(z,POW(3*i+2));//////////////////////////
	}//*////////////////////////////////////////////////////////////////////////////////////////////////////////------------------!!!!!!!!!!!!
//
	return  // res + 1.;
	//(	-COEF(0)*Pow(x,POW(0))*Pow(y,POW(1))*Pow(z,POW(2))  +	-COEF(1)*Pow(x,POW(3))*Pow(y,POW(4))*Pow(z,POW(5))  +
	 // -COEF(2)*Pow(x,POW(6))*Pow(y,POW(7))*Pow(z,POW(8)) + -COEF(3)*Pow(x,POW(9))*Pow(y,POW(10))*Pow(z,POW(11)) + 
	 // -COEF(4)*Pow(x,POW(12))*Pow(y,POW(13))*Pow(z,POW(14)) +
	   //1.  )/1.;

		//	max(0.,	-Pow(x,d)  +	-Pow(y,d)  +  -Pow(z,d) + 1.)/10.;
		//max(0.,-Pow(3.,d)*Pow(x,d)  +	-Pow(sin2(time)*3.+1.,d)*Pow(y,d)  +  -Pow(sin2(3.*time+PI/2.)*4.+1.,d)*Pow(z,d) + 1.)/5.;
		 //max(0.,Pow(x2 + 9.*(y2/4.)+z2 - 1. ,3.)  - x2*z3 - (9.*y2*z3)/200. 	)/(time*time*time);
 		//	max(0.,-abs(x)   +	-abs(y)  +  -abs(z) + 1.)/5.;

		//(	(sign(x+a)-sign(x-a))*(sign(y+a)-sign(y-a))*(sign(z+a)-sign(z-a))	)/200.;//

		(1./(1.+pow(E,-d*(x+a)))  + 1./(1.+pow(E,d*(x-a))) - 1. ) *
		(1./(1.+pow(E,-d*(y+a)))  + 1./(1.+pow(E,d*(y-a))) - 1. ) *
		(1./(1.+pow(E,-d*(z+a)))  + 1./(1.+pow(E,d*(z-a))) - 1. )  / 20.;//*/

		//-x*x-y*y-z*z + 1.;
		//max(time,	-Pow(5.*x,-50.)*Pow(5.*z,50.)*Pow(5.*y,50.) /* +	-Pow(y,50.)  +  -Pow(z,50.) */+ 1.)/10.;
			//(sign(x+cos(asin(y)))-sign(x-cos(asin(y))))*(sign(z+cos(asin(y)))-sign(z-cos(asin(y))))/*(sign(z+a)-sign(z-a))*/	/150.;
}
float opacityF(vec3 pos){
	return densityF(pos);
}

float rayOpacityF(vec3 rd,float x){
	return opacityF(vec3(rd.x*x,rd.y*x,rd.z*x));//assuming cam pos =0,0,0
	//x=rd.x*x   y=rd.y*x  z=rd.z*x-5
	//(   (sign(rd.x*x+a)-sign(rd.x*x-a))*(sign(rd.y*x+a)-sign(rd.y*x-a))*(sign(rd.z*x-5+a)-sign(rd.z*x-5-a))	)
}
float h(float X,vec3 rd){
	float a = 1.;
	vec3 p = vec3( rd.x*X, rd.y*X,  rd.z*X);
	//p+=vec3(0,0,-time);//translation
	float x = p.x , y = p.y , z = p.z;
	float s = (   (sign(x+a)-sign(x-a))*(sign(y+a)-sign(y-a))*(sign(z+a)-sign(z-a))	);
	return X * s;//X * (sign(rd.x*X+a)-sign(rd.x*X-a))*(sign(rd.y*X+a)-sign(rd.y*X-a))*(sign(rd.z*X-time+a)-sign(rd.z*X-time-a));//
}
vec3 rayIntegral(float X,vec3 rd){
	float a = 1.;
	float a1 = max((-a)/rd.z,max(-a/rd.x,-a/rd.y));
	float a2 = min((a)/rd.z,min(a/rd.x,a/rd.y));
	float m = (a1+a2)/2.;
	//X+=m;
	float r = h(X,rd) + ((sign(X-a2)+1.))*h(a2,rd);
	return vec3((r));
}
float s(vec3 v){

return 0.;
}

vec3 rayIntegral2( vec3 rd){

	//vec3 p = vec3( rd.x*X, rd.y*X,  rd.z*X);
	//pos+=vec3(0,0,(-5));//translation
	//pos*=rot(vec3(time,time,-time));//rotation
	//float x = p.x , y = p.y , z = p.z;
	float d = 78.;
	float a = 5.;
	//max(0.,-Pow(x,d)   +	-Pow(y,d)  +  -Pow(z,d) + time)/100.
// 			-x^d	-y^d	-z^d + 3
//			-rd.x^d*X^d -rd.y^d*X^d -rd.z^d*X^d + 3							-(rd.x*X+p.x)^d -(rd.y*X+p.y)^d -(rd.x*X+p.z)^d + 3 
//			-(rd.x^d+rd.y^d+rd.z^d)X^d+3									
//			Prim :  -( (rd.x^d+rd.y^d+rd.z^d)X^(d+1) )/(d+1)	+	3X							
//													Prim : ( -(rd.x*X+p.x)^(d+1) -(rd.y*X+p.y)^(d+1) -(rd.x*X+p.z)^(d+1) )/(d+1) + 3X

//			Solve for X : -(rd.x^d+rd.y^d+rd.z^d)X^d+3 = 0 				-(rd.x*X+p.x)^d -(rd.y*X+p.y)^d -(rd.x*X+p.z)^d + 3 =  0
//   <=> 	-(rd.x^d+rd.y^d+rd.z^d)X^d = 3 								-(rd.x*X+p.x)^d -(rd.y*X+p.y)^d -(rd.x*X+p.z)^d     = -3		
//   <=> 	X^d = -3/(rd.x^d+rd.y^d+rd.z^d) 							-(rd.x*X+p.x)^d -(rd.y*X+p.y)^d -(rd.x*X+p.z)^d 
//	<=>	 	X = (+-) ( 3/(rd.x^d+rd.y^d+rd.z^d) )^(1/d)

	//rd += vec3(0.,0.,-time);
	//rd*=3.;//scale
//		float angle = dot(rd,vec3(0,0,-1));
//	a-= angle*a;
	rd*=rot(vec3(time,time,-time));//rotation
	float k = Pow(rd.x,d)+Pow(rd.y,d)+Pow(rd.z,d);
	float s1 = Pow( a/k  , 1./d );
	float s2 = -s1;
	if( s1 > s2 ){ 
		float s = s1;
		s1 = s2;
		s2 = s;
	}
	//vec3 p = vec3(0,0,5);
	//float delta = rd.x*p.x + rd.y*p.y + rd.z*p.z;
	//s1 += -time*time*angle;
	//s2 += -time*time*angle;
	float F1 = -( Pow(	k * s1 , d+1. ) )	/(d+1.)	+	a*s1;
	float F2 = -( Pow(	k * s2 , d+1. ) )	/(d+1.)	+	a*s2;
		float area = F2-F1;
		
		
return vec3(area) / 20.;
}//*/
void main()
{		
	float ratio = resolution.x/resolution.y;
		vec2 uv = (gl_FragCoord.xy/resolution  - vec2(0.5))*vec2(ratio,1.);
		float t = time*3.;

		vec3 rd = normalize(vec3((uv),1.));

		vec3 col = vec3(0);
		
		vec3 objCol = vec3(1.,0.,0.);

		if(false){
			int MAX_ITER = 150;//int(time);
			float MAX_DIST = 8.;
			//vec3 p = vec3(0);
			for(float i=0.;i<MAX_DIST;i+=MAX_DIST/float(MAX_ITER)){
				float c = max(-100.,rayOpacityF(rd,i));
				//if(c>0.)
					col += c;//-vec3(0,0,float(i)/100.);
				
			}
			col = min(col,vec3(1.))*objCol;
			//col = vec3(min(col.x,objCol.x));
		}else{
		col = rayIntegral2(rd);//assuming cam pos =0,0,0
		}
	//	col = vec3(COEF(0));
		fragcolor = vec4(col   , 1.0);

}
//cmake --build . && ./Hologram/Hologram 