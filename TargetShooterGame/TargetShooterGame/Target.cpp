#include "Target.hpp"

int Target::getScoreAwarded(void)
{
    return this->mScoreAwarded;
}

void Target::setScoreAwarded(int& newScore)
{
    this->mScoreAwarded = newScore;
}

void Target::playDestroyEffect(void)
{
    sound.setBuffer(this->destroyEffect);
    sound.play();
}

void Target::playAppearEffect(void)
{
    sound.setBuffer(this->appearEffect);
    sound.play();
}

bool Target::getIsDestroyed(void)
{
    return this->isDestroyed;
}

void Target::setIsDestryed(bool newbool)
{
    this->isDestroyed = newbool;
}

void Target::destroy(void)
{
    this->setPosition(sf::Vector2f(0, 1000));
    this->playDestroyEffect();
}

void Target::appear(void)
{
    this->setPosition(sf::Vector2f(randRange(0, 1000), randRange(0, 500)));
    this->playAppearEffect();
}

sf::Texture& Target::getTexture()
{
    return this->texture;
}

void Target::update()
{
    //still somewhat confused what we do here
}
