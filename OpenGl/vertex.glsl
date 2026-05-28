#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;


out vec4 vertexColor;

uniform float aOffset;

void main()
{
	vec3 Pos = vec3(aPos.x + aOffset, aPos.y, aPos.z);
	// so mirroring along the x axis so that it is upside down 
   gl_Position = vec4(Pos, 1.0);
   vertexColor = vec4(Pos,1.0f);
}
