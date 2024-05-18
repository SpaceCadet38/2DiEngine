#include "TextureManager.hpp"
#include "../Core/Engine.hpp"

TextureManager* TextureManager::s_Instance = nullptr;

TextureManager::TextureManager()
{
}

bool TextureManager::Load(std::string id, std::string path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == nullptr)
	{
		SDL_Log("Failed to load texture: %s, %s", path.c_str(), SDL_GetError());
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
	if (texture == nullptr)
	{
		SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
		return false;
	}
	m_TextureMap[id] = texture;
	return true;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect src_rect = { 0, 0, width, height };
	SDL_Rect dest_rect = { x, y, width, height };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &src_rect, &dest_rect, 0, nullptr, flip);
}

void TextureManager::DrawFrame(string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
	SDL_Rect src_rect = { width * frame, height * row, width, height };
	SDL_Rect dest_rect = { x, y, width, height };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &src_rect, &dest_rect, 0, nullptr, flip);
}

void TextureManager::Drop(std::string id)
{
	SDL_DestroyTexture(m_TextureMap[id]);
	m_TextureMap.erase(id);
}

void TextureManager::Clean()
{
	std::map<std::string, SDL_Texture*>::iterator i;
	for (i = m_TextureMap.begin(); i != m_TextureMap.end(); i++)
	{
		SDL_DestroyTexture(i->second);
	}
	m_TextureMap.clear();
	SDL_Log("Texture map cleaned!");
}


