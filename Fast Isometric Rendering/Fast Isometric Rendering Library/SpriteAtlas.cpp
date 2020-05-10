#include "SpriteAtlas.h"



SpriteAtlas::SpriteAtlas(std::vector<LoadSpriteInfo> sprites) {

	nextSpritePosition = std::make_pair(0, 0);
	textureSize = sf::Texture::getMaximumSize();
	renderTexture.create(textureSize, textureSize);
	renderTexture.clear(sf::Color::Transparent);
}



SpriteAtlas::~SpriteAtlas() {

}



void SpriteAtlas::AddSpriteBatch(std::vector<LoadSpriteInfo> sprites) {

	// sort from widest to thinest
	std::sort(sprites.begin(), sprites.end(), 
		[&](LoadSpriteInfo A, LoadSpriteInfo B) -> bool {
			return A.width > B.width;
		});

	std::vector<sf::Texture> texturesFromFile;
	texturesFromFile.resize(sprites.size());

	for (int i = 0; i < texturesFromFile.size(); i++) {
		texturesFromFile[i].loadFromFile("bitmaps/" + sprites[i].filename + ".png");
	}

	for (size_t i = 0; i < sprites.size(); i++) {
		spritesInfo.push_back(AddTexture(texturesFromFile[i], sprites[i].width, sprites[i].height, sprites[i].offsets));
	}

}



void SpriteAtlas::AddSpriteBatchFromFile(std::string filename) {

	// todo
}



std::vector<SpriteInfo> SpriteAtlas::AddTexture(sf::Texture texture, int TWidth, int THeight, std::vector<std::pair<int,int>> offsets) {

	int variationsWidth = texture.getSize().x / TWidth;
	int variationsHeight = texture.getSize().y / THeight;
	std::vector<SpriteInfo> variations;

	for (size_t i = 0; i < variationsHeight; i++) {

		for (size_t j = 0; j < variationsWidth; j++) {

			sf::Sprite newSprite;
			newSprite.setTexture(texture);

			sf::IntRect spriteRect(j * TWidth, i * THeight, TWidth, THeight);
			newSprite.setTextureRect(spriteRect);

			auto info = AddSprite(newSprite);
			info.offset = offsets[i * variationsWidth + j];
			variations.push_back(info);
		}
	}

	return variations;
}



SpriteInfo SpriteAtlas::AddSprite(sf::Sprite sprite) {

	int spriteHeight = sprite.getTextureRect().height;
	int spriteWidth = sprite.getTextureRect().width;

	if (spriteHeight > atlas.getSize().y) throw std::invalid_argument("sprite is too tall for this sprite atlas");
	if (spriteWidth > atlas.getSize().x) throw std::invalid_argument("sprite is too wide for this sprite atlas");
	if (nextSpritePosition.first + spriteWidth > atlas.getSize().x) throw std::invalid_argument("there is not enough room on this sprite atlas for more sprites");

	if (nextSpritePosition.second + spriteHeight > atlas.getSize().y) {
		nextSpritePosition.first += currentColumnMaxWidth;
		nextSpritePosition.second = 0;
	}

	if (spriteWidth > currentColumnMaxWidth) {
		currentColumnMaxWidth = spriteWidth;
	}

	sprite.setPosition(nextSpritePosition.first, nextSpritePosition.second);
	renderTexture.draw(sprite);

	SpriteInfo info;
	info.spritePositon = nextSpritePosition;
	info.spriteDimentions = std::make_pair(spriteWidth, spriteHeight);

	nextSpritePosition.second += spriteHeight;

	return info;
}
