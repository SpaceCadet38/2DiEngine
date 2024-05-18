#ifndef ANIMATION_H
#define ANIMATION_H
#include <string>
#include <SDL.h>
class Animation
{
public:
	Animation() {};
	void Update();
	void Draw(float x, float y, int sprite_width, int sprite_height);
	void SetProp(std::string texture_id, int sprite_row, int frame_count, int animation_speed, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
	int m_SpriteRow = 0; 
	int m_SpriteFrame = 0;
	int m_AnimationSpeed = 0;
	int m_FrameCount = 0;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip = SDL_FLIP_NONE;
};

#endif // !ANIMATION_H
