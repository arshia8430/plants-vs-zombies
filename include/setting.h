#ifndef SETTING_H
#define SETTING_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct GameSettings {
    struct ZombieType {
        string type;
        int damage;
        int health;
        int hitRate;
        int speed;
    };

    struct PlantType {
        string type;
        int damage;
        int health;
        int cooldown;
        int hitRate;
        int speed;
        int price;
    };

    struct AttackSettings {
        int totalDuration;
        vector<int> zombieCounts;
    };

    struct SunSettings {
        int verticalSpeed;
        int interval;
    };

    vector<ZombieType> zombieTypes;
    vector<PlantType> plantTypes;
    AttackSettings attackSettings;
    SunSettings sunSettings;
};

void readGameSettings(const string& filename, GameSettings& settings);
void writeGameSettings(const string& filename, const GameSettings& settings);

#endif
