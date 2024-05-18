#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
using std::string;
class TextureManager
{
public:
	static TextureManager* GetInstance() {
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new TextureManager();
	}
	bool Load(string id, string path);
	void Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(string id, int x, int y, int width, int height, 
	int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void Drop(string id);
	void Clean();

private:
	TextureManager();
	static TextureManager* s_Instance;
	std::map<string, SDL_Texture*> m_TextureMap;
};

#endif // !TEXTUREMANAGER_H
