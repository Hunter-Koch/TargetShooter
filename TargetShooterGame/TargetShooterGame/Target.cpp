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

sf::Texture& Target::getTexture()
{
    return this->texture;
}
