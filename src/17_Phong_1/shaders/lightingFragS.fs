#version 330 core

out vec4 FragColor;

//in vec3 ourColor;
//in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;

//uniform sampler2D texture1;  // more: sampler1D, sampler3D
//uniform sampler2D texture2;

void main()
{
    // Ambient lighting
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // Diffuse lighting
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diffuse = max(dot(norm, lightDir), 0.0) * lightColor;

    vec3 color = (ambient + diffuse) * objectColor;
    FragColor = vec4(color, 1.0f);

    //FragColor = vec4(ourColor, 1.0f);
    //FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);
    //FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.5);
    //FragColor = vec4(lightColor * objectColor, 1.0);
}

