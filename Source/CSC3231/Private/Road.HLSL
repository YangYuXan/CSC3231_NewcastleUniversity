#include ""

void Test(
out float3 Color,
float Red = 1.f,
bool Green = false,
Texture2D Texture,
SamplerState TextureSampler,
FMaterialPixelParameters Parameters)
{
	Color.r = Red;
	Color.g = Green ? 1 : 0;
	Color.b = BLUE;

	const float2 UVs = GetSceneTextureUV(Parameters);
	Color = Texture2DSample(Texture, TextureSampler, UVs);
}
