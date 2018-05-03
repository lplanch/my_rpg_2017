#version 130

uniform sampler2D texture;
uniform float time = 0;

vec2 step = vec2(1, 1) / textureSize(texture, 0);

float adj(ivec2 v)
{
	return (texture2D(texture, vec2(gl_TexCoord[0].x + float(step.x) * v.x,
		gl_TexCoord[0].y + float(step.y) * v.y)).a);
}

float aura(float n)
{
	float f = adj(ivec2(1, 0));

	for (float x = -n; x < n; x++)
	    for (float y = -n; y < n; y++)

	    	f = max(adj(ivec2(x, y)), f);

 	return (f);
}

void main()
{
  	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	if (pixel.a < 1)
	{
		float f = aura(mod(2.99 * time, 3));
		pixel.r = mod(time, pixel.r) + gl_TexCoord[0].x;
		pixel.g = mod(time, pixel.g) + gl_TexCoord[0].x;
		pixel.b = mod(time, pixel.b) + gl_TexCoord[0].x;
		gl_FragColor = vec4(pixel.rgb, f);
	}
	else
		gl_FragColor = pixel;
}
