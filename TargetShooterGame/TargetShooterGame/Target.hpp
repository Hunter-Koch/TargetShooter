#ifndef TARGET
#define TARGET

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


//all objects have to be transformable and drawable to be rendered
class Target : public sf::CircleShape
{
public:
	Target() : sound(destroyEffect), sf::CircleShape(100)
	{
		this->setPosition(sf::Vector2f(0,0));
		this->mScoreAwarded = 5;
		this->destroyEffect.loadFromFile("Assets\\sounds\\destroy.mp3");
		this->appearEffect.loadFromFile("Assets\\sounds\\appear.mp3");
		this->texture.loadFromFile("Assets\\targets\\Basic\\Target 64x64.png");
	}

	Target(sf::Vector2f pos, const sf::Color& color) :
		sf::CircleShape(100), sound(destroyEffect)
	{
		//this->setFillColor(color); //changes color of texture
		this->setPosition(pos);

		this->texture.loadFromFile("Assets\\targets\\Basic\\Target 64x64.png");
		this->setTexture(&texture, true);

		this->destroyEffect.loadFromFile("Assets\\sounds\\destroy.mp3");
		this->appearEffect.loadFromFile("Assets\\sounds\\appear.mp3");

		this->sound.setVolume(50);//ranges from 0-100
		mScoreAwarded = 100;
	}

	int getScoreAwarded(void);
	void setScoreAwarded(int& newScore);
	void playDestroyEffect(void);
	void playAppearEffect(void);

	sf::Texture& getTexture();

private:
	int mScoreAwarded;
	sf::Texture texture;
	sf::SoundBuffer destroyEffect;
	sf::SoundBuffer appearEffect;
	sf::Sound sound;
};


#endif // !TARGET

