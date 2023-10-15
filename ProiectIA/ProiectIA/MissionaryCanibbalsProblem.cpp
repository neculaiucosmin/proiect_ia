#include "MissionaryCanibbalsProblem.h"


/// \brief
/// Initializeaza malul stang cu 3 canibali, respectiv 3 misionari
void MissionaryCanibbalsProblem::initProblem()
{
    if (!isInit)
    {
        
        leftShore->canibali.push_back(new cannibal);
        leftShore->canibali.push_back(new cannibal);
        leftShore->canibali.push_back(new cannibal);

        leftShore->misionari.push_back(new missionary);
        leftShore->misionari.push_back(new missionary);
        leftShore->misionari.push_back(new missionary);

        isInit = true;
    }
    else
    {
        std::cout << "Programul este deja initializat" << std::endl;
    }
}

/// \brief Verifica numarul entitatilor de pe fiecare mal
/// \return true daca numaralul misionarilor este mai mare sau egal decat numarul canibalilor
/// \return false daca numarul canibalilor este mai mare
bool MissionaryCanibbalsProblem::checkCannibalsNumber()
{
    auto nrCanibaliStanga = leftShore->canibali.size();
    auto nrMisionariStanga = leftShore->misionari.size();

    auto nrCanibaliDreapta = rightShore->canibali.size();
    auto nrMisionariDreapta = rightShore->misionari.size();

    if (nrCanibaliStanga > nrMisionariStanga)
    {
        return false;
    }

    if (nrCanibaliDreapta > nrMisionariDreapta)
    {
        return false;
    }


    return true;
}

MissionaryCanibbalsProblem::~MissionaryCanibbalsProblem()
{
    delete leftShore;
    delete rightShore;
}
