#version 130

uniform sampler2D texture;

void main()
{
  	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	pixel.g = (pixel.g / 45) * 100;

  	gl_FragColor = pixel;
}
