#version 120

varying vec3     			var_Position;
varying vec2            	var_TexDiffuse;
varying vec2            	var_TexNormal;
varying vec2            	var_TexSpecular;
varying vec4            	var_TexLight;
varying mat3				var_TangentBitangentNormalMatrix;
varying vec4            	var_Color;

uniform sampler2D   		u_normalTexture;
uniform sampler2D   		u_lightFalloffTexture;
uniform sampler2D   		u_lightProjectionTexture;
uniform sampler2D   		u_diffuseTexture;
uniform sampler2D   		u_specularTexture;

uniform vec4 				u_lightOrigin;
uniform vec4 				u_viewOrigin;
uniform vec4 				u_diffuseColor;
uniform vec4 				u_specularColor;

float SchlickFresnel(vec3 H, vec3 V, float power, float k) {
	float w = pow(1.0f - max( dot( H, V ), 0.0f), power);
	return w + ((1.0f - w) * k);
}

// Ward isotropic specular term
float wardiso( vec3 L, vec3 V, vec3 N, vec3 H, float roughness) {
	float ndotv = dot( N, V);
	float ndoth = dot( N, H);
	float ndotl = dot( N, L);
	float tandelta		= tan( acos(ndoth));
	float powtandelta	= pow( tandelta, 2.0f );
	float a				= clamp( ( inversesqrt( ndotl * ndotv ) ), 0.0f, 1.0f );
	float powroughness	= pow( roughness, 2.0f );
	return max(exp( -( powtandelta / powroughness)) * a / (4 * powroughness), 0.0f);
}

// Minnaert diffuse term
float Minnaert( vec3 N, vec3 L, float k) {
	float ndotl = max(dot(N, L), 0.0f);
	return pow(ndotl, k);
}

// lambertian blinn-phong
float Lambertian( vec3 N, vec3 L) {
	return max( dot( N, L ) , 0.0f);
}

// half-lambertian blinn-phong
float HalfLambertian( vec3 N, vec3 L, float k) {
	float ndotl = (max(dot( N, L ), 0.0f) + 0.50f) / ( 1.0f + 0.5f );
	return pow(ndotl, k);
}

const float PI = 3.14159265358979323846264;
const float PI_OVER_4 = (PI / 4.0f);
const float PI_OVER_2 = (PI / 2.0f);
const float max_specular_power = 2000.0f;

vec3 lightingModel( vec3 diffuse_color, vec3 roughness_v, vec3 specular_fresnel, vec3 L, vec3 V, vec3 N, vec3 H ) {
	// WARNING: this is experimental stuff, this is not optimized!
	float n_dot_l = clamp(dot(N, L), 0.0f, 1.0f);
	float n_dot_v = clamp(dot(N, V), 0.0f, 1.0f);
	float n_dot_h = dot(N, H);
	float h_dot_l = dot(H, L);
	float h_dot_v = dot(H, V);

	// fugly hack to give us a 'roughness' from artwork not designed for this ..
	float roughness	= (length(1 - specular_fresnel) / 3.0f);

	// calculate specular power
	float specular_power = pow(max_specular_power, 1.0f - roughness);

	// calculate fresnel term (vector)
	float base = 1.0f - h_dot_l;
	float exponential = pow(base, 5.0f);
	vec3 fresnel_term = specular_fresnel + ((1.0f - specular_fresnel) * exponential);

	// calculate distribution term	(scalar, unbounded)

	// Beckmann
	float m = roughness;
	float m_sqr = m * m;
    float n_dot_h_sqr = n_dot_h * n_dot_h;
    float distribution_term = exp( (n_dot_h_sqr - 1.0f) / (m_sqr * n_dot_h_sqr) ) / (PI * m_sqr * n_dot_h_sqr * n_dot_h_sqr);

	// calculate geometry term (scalar, constrained between 0 and 1)

	// Schlick's approximation to Smith's shadowing function
	float a = roughness * sqrt(2.0f / PI);
	float one_minus_a = 1.0f - a;
	float geometry_term = 1.0f / ( (h_dot_l * one_minus_a + a) * (h_dot_v * one_minus_a + a) );

	// calculate final specular value
	float specular_normalization = max((4.0f * n_dot_l * n_dot_v), 0.15f); // avoid dividing by 0
	vec3 final_specular_color =	 max((clamp(geometry_term, 0.01f, 1.0f) * clamp(distribution_term, 0.0f, 1.0f) * max(fresnel_term, 0.0f)) / specular_normalization, 0.0f);

	// calculate diffuse
	vec3 final_diffuse_color = diffuse_color * max((1.0f - specular_fresnel + (1.0f - specular_fresnel) * pow(1.0f - n_dot_l, 5.0f)), 0.0f);
	vec3 finalColor = (final_diffuse_color + final_specular_color) * n_dot_l;

	return finalColor;
}

void main( void ) {
	vec3 lightDir	= u_lightOrigin.xyz - var_Position;
	vec3 viewDir	= u_viewOrigin.xyz - var_Position;

	// compute normalized light, view and half angle vectors
	vec3 L = normalize( lightDir );
	vec3 V = normalize( viewDir );
	vec3 H = normalize( L + V );

	float attenuation = 1.0f;

	// compute normal from normal map, move from [0, 1] to [-1, 1] range, normalize
	vec3 N = normalize( ( 2.0f * texture2D ( u_normalTexture, var_TexNormal.st ).wyz ) - 1.0f );
	N = var_TangentBitangentNormalMatrix * N;

	// compute the diffuse term
	vec4 diffuse = texture2D( u_diffuseTexture, var_TexDiffuse ) * u_diffuseColor;

	// compute the specular term
	vec3 specular = texture2D( u_specularTexture, var_TexSpecular ).rgb * u_specularColor.rgb;

	// compute light projection and falloff
	vec3 lightFalloff		= texture2D( u_lightFalloffTexture, vec2( var_TexLight.z, 0.5f ) ).rgb;
	vec3 lightProjection	= texture2DProj( u_lightProjectionTexture, var_TexLight.xyw ).rgb;

	// compute lighting model
    vec4 color = vec4(lightingModel(diffuse.rgb, u_specularColor.rgb, specular, L, V, N, H ) * min(attenuation, 1.0f), diffuse.a);
	color.rgb *= lightProjection;
	color.rgb *= lightFalloff;
	color.rgb *= var_Color.rgb;

	// output final color
	gl_FragColor = color;
}