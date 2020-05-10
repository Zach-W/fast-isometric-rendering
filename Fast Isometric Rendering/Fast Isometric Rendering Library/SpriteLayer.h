#pragma once

#include <SFML/Graphics.hpp>


extern class SpriteLayer {
public:
	SpriteLayer();
	~SpriteLayer();

	enum Type {
		staticLayer, // layer that does not change sprites in any way, changes to sprites have a large cpu cost
		movingLayer, // layer that handles many sprites that move every frame, changes to sprites have a low cpu cost
		balancedLayer // layer that is mostly static but may change occasionally, changes have a moderate cost
	};

private:

	int spriteAtlasSize = 1024;
	SpriteLayer::Type layerType;
	sf::VertexArray m_vertices;
	std::vector<std::vector<sf::VertexArray>> vertexChunks;
	sf::Texture m_spriteAtlas;
	//std::vector<textureCoordinates> m_textureCorners;
	std::vector<sf::Texture> m_sprites;

public:

	void DrawLayer(std::shared_ptr<sf::RenderWindow> window);
	void AddSprite(int spriteIndex, int spriteRotation);
};