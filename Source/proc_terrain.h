#ifndef __PROC_TERRAIN_H__
#define __PROC_TERRAIN_H__

/*void heightmap_to_terrain(ENTITY* _ent, BMAP* _heightmap, float _altitude);
ENTITY* generate_random_terrain(VECTOR* _pos, int _verticesX, int _verticesY, int _vertexSize, float _altitude);
void smooth_to_terrain(ENTITY* _ent);
void bmap_to_colormap(BMAP* _bitmap);*/
BMAP* bmap_to_displacementmap(BMAP* _bitmap);
BMAP* bmap_to_blur(BMAP* _bitmap, int _passes);

// Simple multi texture terrain shader

BMAP* bmapRock    = "test_proc_terrain\\rock.tga";
BMAP* bmapGrass   = "test_proc_terrain\\grass.tga";
BMAP* bmapSand    = "test_proc_terrain\\sand.tga";
BMAP* bmapDetail  = "test_proc_terrain\\detailmap.tga";

void mat_terrain_multi_texture_event()  {	
	bmap_to_mipmap(mtl.skin1);
	bmap_to_mipmap(mtl.skin2);
	bmap_to_mipmap(mtl.skin3);
	bmap_to_mipmap(mtl.skin4);
}

MATERIAL* mat_terrain_multi_texture =
{
	flags=tangent;
	skin1=bmapGrass;
	skin2=bmapRock;
	skin3=bmapSand;
	skin4=bmapDetail;
	event=mat_terrain_multi_texture_event;
	effect="
	
	#include <define>
	#include <transform>
	#include <sun>
	#include <lights>
	#include <fog>
	#include <normal>
	
	float4 vecSkill41;
	float fAmbient;

	texture entSkin1;
	texture entSkin2;
	texture entSkin3;
	texture mtlSkin1;
	texture mtlSkin2;
	texture mtlSkin3;
	texture mtlSkin4;
	sampler2D Texture1 = sampler_state
	{
		Texture = <entSkin1>;
		MinFilter = Linear;
		MagFilter = Linear;
		MipFilter = Linear;
		AddressU = WRAP;
		AddressV = WRAP;
		
	};
	sampler2D RedSampler = sampler_state
	{
		Texture = (mtlSkin2);
		MinFilter = Linear;
		MagFilter = Linear;
		MipFilter = Linear;
		AddressU = WRAP;
		AddressV = WRAP;
		srgbtexture=true;
	};
	sampler2D GreenSampler = sampler_state
	{
		Texture = (mtlSkin1);
		MinFilter = Linear;
		MagFilter = Linear;
		MipFilter = Linear;
		AddressU = WRAP;
		AddressV = WRAP;
		//srgbtexture=true;
	};
	sampler2D BlueSampler = sampler_state
	{
		Texture = (mtlSkin3);
		MinFilter = Linear;
		MagFilter = Linear;
		MipFilter = Linear;
		AddressU = WRAP;
		AddressV = WRAP;
	};
	sampler2D DetailSampler = sampler_state
	{
		Texture = (mtlSkin4);
		MinFilter = Linear;
		MagFilter = Linear;
		MipFilter = Linear;
		AddressU = WRAP;
		AddressV = WRAP;
	};
	//texture terr_color_map_bmap;
	sampler2D ColorMapSampler = sampler_state
	{
		//Texture = (terr_color_map_bmap);
		Texture = <entSkin2>;
		MinFilter = Linear;
		MagFilter = Linear;
		MipFilter = Linear;
		AddressU = WRAP;
		AddressV = WRAP;
	};
	//texture terr_disp_map_bmap;
	sampler2D DispMapSampler = sampler_state
	{
		//Texture = (terr_disp_map_bmap);
		Texture = <entSkin3>;
		MinFilter = Linear;
		MagFilter = Linear;
		MipFilter = Linear;
		AddressU = WRAP;
		AddressV = WRAP;
	};

	float4 PS_multi_texture(float2 Tex0 : TEXCOORD0) : COLOR0
	{
		
		float4 MainTexture = tex2D(Texture1,Tex0);
		float4 RedTexture = tex2D(RedSampler,Tex0*50);
		float4 GreenTexture = tex2D(GreenSampler,Tex0*50);
		float4 BlueTexture = tex2D(BlueSampler,Tex0*50);
		float4 ColorMapTexture = tex2D(ColorMapSampler,Tex0);
		float4 DetailColor = tex2D(DetailSampler,Tex0*50);
		
		MainTexture = 1+reflect(MainTexture,MainTexture);
		MainTexture = MainTexture+DetailColor-0.1;
		
		float4 BaseRed = lerp(MainTexture,RedTexture,ColorMapTexture.r);
		float4 BaseGreen = lerp(BaseRed,GreenTexture,ColorMapTexture.g);
		float4 FinalColor = lerp(BaseGreen,BlueTexture-MainTexture+0.5,ColorMapTexture.b);
		
		float4 Displacement = tex2D(DispMapSampler,Tex0).b+0.3;
		FinalColor*=Displacement;
		
		return FinalColor;

	}
	
	struct out_terraintex3 // Output to the pixelshader fragment
	{
		float4 Pos		: POSITION;
		float4 Color	: COLOR0;
		float  Fog		: FOG;
		float2 MaskCoord: TEXCOORD0;
		float2 BaseCoord: TEXCOORD1;
		float2 RedCoord : TEXCOORD2;
		float2 GreenCoord: TEXCOORD3;
	};
	
	out_terraintex3 vs_terraintex3(
		float4 inPos : POSITION,
		float3 inNormal : NORMAL,
		float2 inTexCoord0 : TEXCOORD0)
	{
		out_terraintex3 Out;
	
		Out.Pos = DoTransform(inPos); // transform to screen coordinates
	
		// rotate and normalize the normal
		float3 N = DoNormal(inNormal);
		float3 P = mul(inPos,matWorld);
	
		Out.Color = fAmbient; // Add ambient and sun light
		for (int i=0; i<8; i++)  // Add 8 dynamic lights
			Out.Color += DoLight(P,N,i);
		Out.Fog = DoFog(inPos); // Add fog
	
		// scale the texture coordinates for the masked textures
		Out.MaskCoord = inTexCoord0.xy;
		Out.BaseCoord = inTexCoord0.xy * vecSkill41.y;
		Out.RedCoord = inTexCoord0.xy * vecSkill41.z;
		Out.GreenCoord = inTexCoord0.xy * vecSkill41.w;
		return Out;
	}	
	
	technique T1
	{
		pass P0
		{
			VertexShader = compile vs_2_0 vs_terraintex3();
			PixelShader = compile ps_2_0 PS_multi_texture();
		}
	}";

}


#include "proc_terrain.c"

#endif