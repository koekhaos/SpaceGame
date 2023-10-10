#include <Projectiles.hpp>

Projectiles::Projectiles()
: projectilesVec()
{

}

void Projectiles::add(std::string tTexture, sf::Vector2f tPosition, float tVelocity, float tAngle, sf::Time tTimeToLiveLimit, sf::Color tColor)
{
    projectilesVec.push_back(new Projectile(tTexture, tPosition, tVelocity, tAngle, tTimeToLiveLimit, tColor));
}

//void Projectiles::remove(Projectile tProjectile)
//{
    //
//}

void Projectiles::update(sf::Time elapsedTime)
{
    for(size_t i=0;i<projectilesVec.size();i++)
    {
        auto *temp = projectilesVec[i];

        if(temp->getTimeToLive() >= temp->getTimeToLiveLimit())
        {
            projectilesVec.erase(projectilesVec.begin() + i);
            delete temp;
        }
        else
        {
            projectilesVec[i]->update(elapsedTime);
        }
    }
}

void Projectiles::draw(sf::RenderWindow *tWindow)
{
    for(size_t i=0;i<projectilesVec.size();i++)
    {
        projectilesVec[i]->draw(tWindow);
    }
}
