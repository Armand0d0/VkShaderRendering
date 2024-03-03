#version 310 es

layout(location = 0) in vec3 in_pos;

/*layout(std140, push_constant) uniform param_block {
	//vec3 light_pos;
	//vec3 light_color;
	//vec2 resolution;
	mat4 model;
	mat4 view_projection;
	float alpha;
} params;

layout(location = 0) out vec3 color;
layout(location = 1) out float alpha;*/

void main()
{
	vec3 world_pos = vec3(in_pos);//vec3(params.model * vec4(in_pos, 1.0));


	gl_Position = vec4(world_pos, 1.0);
	//color = vec3(1.,0.,0.);
	//alpha = params.alpha;
}
