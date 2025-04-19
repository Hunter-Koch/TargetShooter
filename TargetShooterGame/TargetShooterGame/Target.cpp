#include "Target.hpp"

int Target::getScoreAwarded(void)
{
    return this->mScoreAwarded;
}

void Target::setScoreAwarded(int newScore)
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

void Target::playWarningEffect(void)
{
    sound.setBuffer(this->warningEffect);
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

int Target::getTimeAlive(void)
{
    return this->timeAlive;
}

void Target::setTimeAlive(int newTimeAlive)
{
    this->timeAlive = newTimeAlive;
}

void Target::restartTimer(void)
{
    this->targetTimer.restart();
}

void Target::stopTimer(void)
{
    this->targetTimer.stop();
}

float Target::getTargetTimerInSeconds(void)
{
    return this->targetTimer.getElapsedTime().asSeconds();
}

void Target::destroy(void)
{
    this->stopTimer();
    this->setPosition(sf::Vector2f(0, 1000));
    this->playDestroyEffect();
    this->isDestroyed = true;
}

void Target::appear(void)
{
    this->restartTimer();
    this->setPosition(sf::Vector2f(randRange(0, 1000), randRange(0, 500)));
    this->playAppearEffect();
    this->isDestroyed = false;
}

sf::Texture& Target::getTexture()
{
    return this->texture;
}

void Target::update()
{
    if (timeAlive <= this->getTargetTimerInSeconds())
    {
        this->destroy();
    }
}
