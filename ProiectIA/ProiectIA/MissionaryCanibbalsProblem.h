#pragma once
#include <vector>
#include <iostream>

enum EntityTypeAction
{
    MISSIONARY,
    MISSIONARY2,
    CANNIBAL,
    CANNIBAL2,
    
};

struct missionary
{
};

struct cannibal
{
};

struct shore
{
    std::vector<missionary*> misionari;
    std::vector<cannibal*> canibali;
};

struct barca
{
    cannibal* cannibal1 = nullptr;
    cannibal* cannibal2 = nullptr;

    missionary* missionary1 = nullptr;
    missionary* missionary2 = nullptr;

    void load(missionary* m1 = nullptr, missionary* m2 = nullptr, cannibal* c1 = nullptr, cannibal* c2 = nullptr)
    {
        if (m1 != nullptr)
        {
            missionary1 = m1;
        }

        if (m2 != nullptr)
        {
            missionary2 = m2;
        }

        if (c1 != nullptr)
        {
            cannibal1 = c1;
        }

        if (c2 != nullptr)
        {
            cannibal2 = c2;
        }
    }

    /// \brief Allow unloading the item from the boat
    /// \param _shore A reference to the shore where you want to unload the entities
    /// \param entityToMove Tell which entity to move from the boat.
    void unload(shore& _shore, EntityTypeAction entityToMove)
    {
        switch(entityToMove)
        {
        case CANNIBAL:
            if (cannibal1 != nullptr)
            {
                _shore.canibali.push_back(cannibal1);
                cannibal1 = nullptr;
            }
            else
                std::cout << "Nu exista niciun canibal in barca";
            break;
        case CANNIBAL2:
            if (cannibal2 != nullptr)
            {
                _shore.canibali.push_back(cannibal2);
                cannibal2 = nullptr;
            }
            else
                std::cout << "Nu exista al 2-lea canibal in barca";
            break;
    
        case MISSIONARY:
            if (missionary1 != nullptr)
            {
                _shore.misionari.push_back(missionary1);
                missionary1 = nullptr;
            }
            else
                std::cout << "Nu exista misionari in barca";
            break;
        case MISSIONARY2:
            if (missionary2 != nullptr)
            {
                _shore.misionari.push_back(missionary2);
                missionary2 = nullptr;
            }
            else
                std::cout << "Nu exista al 2-lea misionar in barca";
            break;
        }
    }
};

class MissionaryCanibbalsProblem
{
private:
    bool isInit = false;
    bool checkCannibalsNumber();

public:
    ~MissionaryCanibbalsProblem();
    shore* leftShore = new shore;
    shore* rightShore = new shore;

    void initProblem();
};
