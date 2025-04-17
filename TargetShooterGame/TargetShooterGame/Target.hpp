#ifndef TARGET
#define TARGET

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "GameObject.hpp"


//all objects have to be transformable and drawable to be rendered
class Target : public sf::CircleShape, public GameObject
{
public:
	Target() : sound(destroyEffect), sf::CircleShape(100)
	{
		this->setPosition(sf::Vector2f(0,1000));
		this->mScoreAwarded = 100;
		this->destroyEffect.loadFromFile("Assets\\sounds\\destroy.mp3");
		this->appearEffect.loadFromFile("Assets\\sounds\\appear.mp3");
		this->texture.loadFromFile("Assets\\targets\\Basic\\Target 64x64.png");
		this->setTexture(&texture, true);
		this->sound.setVolume(50);//ranges from 0-100
		this->isDestroyed = true;
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
		this->isDestroyed = true;
	}

	int getScoreAwarded(void);
	void setScoreAwarded(int& newScore);
	void playDestroyEffect(void);
	void playAppearEffect(void);
	bool getIsDestroyed(void);
	void setIsDestryed(bool newbool);

	//virutal function that should be overrided in target variants for use in gameDirector.hpp
	virtual void destroy(void);

	//virutal function that should be overrided in target variants for use in gameDirector.hpp
	virtual void appear(void);

	sf::Texture& getTexture();
	void update();

private:
	bool isDestroyed;
	int mScoreAwarded;
	sf::Texture texture;
	sf::SoundBuffer destroyEffect;
	sf::SoundBuffer appearEffect;
	sf::Sound sound;
};


#endif // !TARGET

