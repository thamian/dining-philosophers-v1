#include "curses/cursesterminal.h"
#include "curses/cursestext.h"
#include "condition.h"
#include "fork.h"
#include "key.h"
#include "keypressedcondition.h"
#include "philosopher.h"
#include "philosopherstatus.h"

#include <iostream>
#include <memory>
#include <thread>
#include <vector>

#include <cstdlib>
#include <cstdio>
#include <ctime>

std::string pathToGraphics = "/home/thamian/C++/dining-philosophers-r/resources/text-graphics/";
std::string txt = ".txt";

CursesText createTableObject()
{
    std::string tablePath = "table";

    File file(pathToGraphics + tablePath + txt);
    CursesText table(file);
    table.moveTo(10, 36);
    return table;
}

std::vector<std::shared_ptr<CursesText>> createPhilosopherObjects()
{
    std::string philosopherPath = "philosopher-";

    std::vector<std::pair<int, int>> objectsCoords = {{10, 26}, {4, 53}, {14, 72}, {27, 58}, {24, 29}};
    std::vector<std::shared_ptr<CursesText>> objects;

    for (int i = 0; i < 5; i++)
    {
        File file(pathToGraphics + philosopherPath + std::to_string(i + 1) + txt);
        objects.push_back(std::make_shared<CursesText>(CursesText(file)));
        objects.at(i)->moveTo(objectsCoords.at(i).first, objectsCoords.at(i).second);
    }
    return objects;
}

std::vector<std::shared_ptr<CursesText>> createForkObjects()
{
    std::string forkPath = "fork-";

    std::vector<std::pair<int, int>> objectsCoords = {{18, 41}, {13, 48}, {14, 59}, {20, 60}, {22, 49}};
    std::vector<std::shared_ptr<CursesText>> objects;

    for (int i = 0; i < 5; i++)
    {
        File file(pathToGraphics + forkPath + std::to_string(i + 1) + txt);
        objects.push_back(std::make_shared<CursesText>(CursesText(file)));
        objects.at(i)->moveTo(objectsCoords.at(i).first, objectsCoords.at(i).second);
    }
    return objects;
}

std::vector<std::shared_ptr<CursesText>> createHudObjects()
{
    std::vector<std::pair<int, int>> objectsCoords = {{10, 7}, {4, 73}, {14, 89}, {27, 76}, {24, 7}};
    std::vector<std::shared_ptr<CursesText>> objects;

    std::vector<std::string> hud;
    hud.push_back("            ");
    hud.push_back("            ");
    hud.push_back("            ");
    hud.push_back("            ");
    hud.push_back("            ");

    for (int i = 0; i < 5; i++)
    {
        objects.push_back(std::make_shared<CursesText>(CursesText(hud)));
        objects.at(i)->moveTo(objectsCoords.at(i).first, objectsCoords.at(i).second);
        objects.at(i)->setColorPair(CursesColorPair::BLACK_WHITE);
    }
    return objects;
}

std::vector<std::shared_ptr<CursesProgressBar>> createProgressBarObjects()
{
    std::vector<std::pair<int, int>> objectsCoords = {{13, 7}, {7, 73}, {17, 89}, {30, 76}, {27, 7}};
    std::vector<std::shared_ptr<CursesProgressBar>> objects;

    for (int i = 0; i < 5; i++)
    {
        objects.push_back(std::make_shared<CursesProgressBar>(CursesProgressBar(objectsCoords.at(i).first, objectsCoords.at(i).second)));
    }
    return objects;
}

int main()
{
    srand(time(NULL));

    auto philosopherObjects = createPhilosopherObjects();
    auto hudObjects = createHudObjects();
    auto progressBarObjects = createProgressBarObjects();
    auto forkObjects = createForkObjects();

    std::vector<std::shared_ptr<CursesObject>> terminalObjects;
    std::vector<std::pair<int, int>> lastPositions;
    terminalObjects.push_back(std::make_shared<CursesText>(createTableObject()));
    lastPositions.push_back(terminalObjects[0]->position());

    std::vector<PhilosopherStatus> philosopherStatuses;
    std::vector<Fork> forks;

    std::vector<std::pair<int, int>> forkCoords = {{18, 41}, {13, 48}, {14, 59}, {20, 60}, {22, 49}};
    std::vector<std::pair<int, int>> philosophersLeftSideCoords = {{9, 37}, {8, 63}, {20, 72}, {28, 54}, {22, 32}};
    std::vector<std::pair<int, int>> philosophersRightSideCoords = {{16, 30}, {7, 49}, {12, 72}, {26, 68}, {27, 40}};

    for (int i = 0; i < 5; i++)
    {
        terminalObjects.push_back(philosopherObjects[i]);
        terminalObjects.push_back(hudObjects[i]);
        terminalObjects.push_back(progressBarObjects[i]);
        terminalObjects.push_back(forkObjects[i]);

        lastPositions.push_back(philosopherObjects[i]->position());
        lastPositions.push_back(hudObjects[i]->position());
        lastPositions.push_back(progressBarObjects[i]->position());
        lastPositions.push_back(forkObjects[i]->position());

        philosopherStatuses.push_back(PhilosopherStatus(*philosopherObjects[i], *hudObjects[i], *progressBarObjects[i]));
        forks.push_back(Fork(*forkObjects[i], forkCoords[i].first, forkCoords[i].second));
    }

    std::unique_ptr<Key> key(new Key());
    std::unique_ptr<Condition> endCondition(new KeyPressedCondition(*key));

    std::thread keyPressDetector(&Key::waitForPress, std::ref(*key));

    std::vector<std::thread> philosophers;
    std::vector<std::string> philosophersNames = {"Confucius", "Plato", "Aristotle", "Socrates", "Pythagoras"};

    for (int i = 0; i < 5; i++)
    {
        int leftForkIndex = (((i + 1) % 5) + 5) % 5;
        philosophers.push_back(std::thread(&Philosopher::work, Philosopher(philosophersNames[i], philosopherStatuses[i], forks[leftForkIndex], forks[i], philosophersLeftSideCoords[i], philosophersRightSideCoords[i]), std::ref(*endCondition)));
    }

    std::thread graphicThread(&CursesTerminal::work, CursesTerminal(terminalObjects, lastPositions), std::ref(*endCondition));

    keyPressDetector.join();
    graphicThread.join();
    for (auto& philosopher : philosophers)
    {
        if (philosopher.joinable())
        {
            philosopher.join();
        }
    }
    return 0;
}
