#include "Game.hpp"

#include "Input\\Keyboard.hpp"
#include "Time.hpp"

namespace NBCG
{
    void CGame::PInitialize()
    {
        FUpper.PX(0.0F).PY(5.0F).PWidth(100.0F).PHeight(1.0F).PColor({0.5F , 0.5F , 0.5F , 1.0F}).PUpdate();
        FLower.PX(0.0F).PY(94.0F).PWidth(100.0F).PHeight(1.0F).PColor({0.5F , 0.5F , 0.5F , 1.0F}).PUpdate();
        for(unsigned int LSeparator{0} ; LSeparator < FSeparators.size() ; LSeparator++)
        {
            FSeparators[LSeparator].PX(49.5F).PY(5.5F + LSeparator * 6.775F).PWidth(1.0F).PHeight(1.0F).PColor({0.5F , 0.5F , 0.5F , 1.0F}).PCorrectToHeight().PUpdate();
        }
        FPlayers[0].PX(5.0F).PY(45.0F).PWidth(1.0F).PHeight(10.0F).PColor({1.0F , 1.0F , 1.0F , 1.0F}).PUpdate();
        FPlayers[1].PX(94.0F).PY(45.0F).PWidth(1.0F).PHeight(10.0F).PColor({1.0F , 1.0F , 1.0F , 1.0F}).PUpdate();
        FBall.PWidth(1.0F).PHeight(1.0F).PColor({1.0F , 1.0F , 1.0F , 1.0F}).PCorrectToWidth().PX(6.0F).PY(50.0F - FBall.PHeight() / 2.0F).PUpdate();
        FDirection = {1.0F , 0.0F};
    }
    
    void CGame::PUpdate()
    {
        FUpper.PRender();
        FLower.PRender();
        for(unsigned int LSeparator{0} ; LSeparator < FSeparators.size() ; LSeparator++)
        {
            FSeparators[LSeparator].PRender();
        }
        if(NInput::GKeyboard.PHeld(SDL_SCANCODE_W) && FPlayers[0].PY() - GTime.PRelative() / 10.0F >= 6.0F)
        {
            FPlayers[0].PY(FPlayers[0].PY() - GTime.PRelative() / 10.0F).PUpdate();
        }
        if(NInput::GKeyboard.PHeld(SDL_SCANCODE_S) && FPlayers[0].PY() + GTime.PRelative() / 10.0F <= 84.0F)
        {
            FPlayers[0].PY(FPlayers[0].PY() + GTime.PRelative() / 10.0F).PUpdate();
        }
        FPlayers[0].PRender();
        if(NInput::GKeyboard.PHeld(SDL_SCANCODE_UP) && FPlayers[1].PY() - GTime.PRelative() / 10.0F >= 6.0F)
        {
            FPlayers[1].PY(FPlayers[1].PY() - GTime.PRelative() / 10.0F).PUpdate();
        }
        if(NInput::GKeyboard.PHeld(SDL_SCANCODE_DOWN) && FPlayers[1].PY() + GTime.PRelative() / 10.0F <= 84.0F)
        {
            FPlayers[1].PY(FPlayers[1].PY() + GTime.PRelative() / 10.0F).PUpdate();
        }
        FPlayers[1].PRender();
        if(SDL_HasIntersectionF
        (
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(FPlayers[0].PX() , FPlayers[0].PY() , FPlayers[0].PWidth() , FPlayers[0].PHeight())}.get() ,
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(FBall.PX() , FBall.PY() , FBall.PWidth() , FBall.PHeight())}.get()
        ))
        {
            FDirection = glm::clamp
            (
                glm::normalize(glm::vec2{1.0F , ((FBall.PY() + FBall.PHeight() / 2.0F + FPlayers[0].PY() + FPlayers[0].PHeight()) / 2.0F - FPlayers[0].PY()) / FPlayers[0].PHeight() - 0.5F}) ,
                glm::normalize(glm::vec2{94.5F - FBall.PX() , 7.0F - FBall.PY()}) ,
                glm::normalize(glm::vec2{94.5F - FBall.PX() , 92.0F - FBall.PY()})
            );
        }
        if(SDL_HasIntersectionF
        (
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(FPlayers[1].PX() , FPlayers[1].PY() , FPlayers[1].PWidth() , FPlayers[1].PHeight())}.get() ,
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(FBall.PX() , FBall.PY() , FBall.PWidth() , FBall.PHeight())}.get()
        ))
        {
            FDirection = glm::clamp
            (
                glm::normalize(glm::vec2{-1.0F , ((FBall.PY() + FBall.PHeight() / 2.0F + FPlayers[1].PY() + FPlayers[1].PHeight()) / 2.0F - FPlayers[1].PY()) / FPlayers[1].PHeight() - 0.5F}) ,
                glm::normalize(glm::vec2{5.5F - FBall.PX() , 7.0F - FBall.PY()}) ,
                glm::normalize(glm::vec2{5.5F - FBall.PX() , 92.0F - FBall.PY()})
            );
        }
        FBall.PX(FBall.PX() + FDirection[0] * GTime.PRelative() / 10.0F).PY(FBall.PY() + FDirection[1] * GTime.PRelative() / 10.0F).PUpdate().PRender();
    }
}