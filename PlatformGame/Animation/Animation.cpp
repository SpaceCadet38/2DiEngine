#include "Animation.hpp"
#include "../Graphic/TextureManager.hpp"
void Animation::Update()
{
	m_SpriteFrame = (SDL_GetTicks() / m_AnimationSpeed) % m_FrameCount;
}

void Animation::Draw(float x, float y, int sprite_width, int sprite_height)
{
	TextureManager::GetInstance()->DrawFrame(m_TextureID, x, y, sprite_width,
		sprite_height, m_SpriteRow, m_SpriteFrame, m_Flip);
}

void Animation::SetProp(std::string texture_id, int sprite_row, int frame_count, int animation_speed, SDL_RendererFlip flip)
{
	m_TextureID = texture_id;
	m_SpriteRow = sprite_row;
	m_FrameCount = frame_count;
	m_AnimationSpeed = animation_speed;
	m_Flip = flip;
}
