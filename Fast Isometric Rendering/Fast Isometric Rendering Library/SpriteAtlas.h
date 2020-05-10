#pragma once

#include <string>
#include "SFML/Graphics.hpp"

struct LoadSpriteInfo {
	std::string filename;
	int width;
	int height;
	std::vector <std::pair<int, int>> offsets;
};

struct SpriteInfo {

	std::pair<int, int> spritePositon;
	std::pair<int, int> spriteDimentions;
	std::pair<int, int> offset;
};

extern class SpriteAtlas {
public:
	SpriteAtlas(std::vector<LoadSpriteInfo> sprites);
	~SpriteAtlas();

	void AddSpriteBatch(std::vector<LoadSpriteInfo> sprite);
	void AddSpriteBatchFromFile(std::string filename);

private:

	std::vector<SpriteInfo> AddTexture(sf::Texture texture, int TWidth, int THeight, std::vector<std::pair<int, int>> offsets);
	SpriteInfo AddSprite(sf::Sprite sprite);

	sf::VertexArray vertices;
	sf::RenderTexture renderTexture;
	sf::Texture atlas;
	std::vector<std::vector<SpriteInfo>> spritesInfo;

	std::pair<int, int> nextSpritePosition;
	int currentColumnMaxWidth;
	int textureSize;

};