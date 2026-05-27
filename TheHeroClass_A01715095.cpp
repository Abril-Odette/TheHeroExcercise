// Abril Odette Jiménez Sánchez | A01715095

#include <iostream>
#include <string>
using namespace std;

class GameObject {
protected:
    int id;
    string tag;

public:
    GameObject(int id, const string& tag): id(id), tag(tag) {}

    int getId() const { return id; }
    string getTag() const { return tag; }

    virtual ~GameObject() {
        cout << "[GameObject destroyed] id: " << id << "\n";
    }
};

class Stats {
public:
    int health;
    int mana;

    Stats(int h = 100, int m = 50): health(h), mana(m) {}
    ~Stats() {
        cout << "[Stats destroyed - no health or mana remaining]\n";
    }
};

class SoulMark {
public:
    string mark;

    SoulMark(const string& m = "Tattoo"): mark(m) {}
    ~SoulMark() {
        cout << "[SoulMark destroyed - the tattoo has faded]\n";
    }
};

class Guild{
    string name;

public:
    Guild(const string& n) : name(n) {}
    string getName() const { return name; }
    ~Guild() {
        cout << "[Guild '" << name << "' is still standing]\n";
    }
};

class Weapon {
protected:
    string name;
    int baseDamage;

public:
    Weapon(const string& n, int d): name(n), baseDamage(d) {}

    string getName() const { return name; }

    virtual void attack() {
        cout<< "Attack with " << name << " dealing " 
        << baseDamage << "n damage\n";
    }

    virtual ~Weapon() {
        cout << "[Weapon '" << name << "' destroyed]\n";
    }
};

class Sword : public Weapon {
public:
    int sharpness;

    Sword(const string& n, int d, int s): Weapon(n,d), sharpness(s) {}

    void attack() override {
        cout << "Slash with " << name
             << " dealing " << baseDamage + sharpness << " damage"
             << " (sharpness: " << sharpness << ")\n";
    }

    ~Sword() {
        cout << "[Sword '" << name << "' destroyed]\n";
    }
};

class Potion{
public:
    string name;
    int healAmount;

    Potion(const string& n, int h) : name(n), healAmount(h) {}

    void use(int& health) {
        health += healAmount;
        cout << "Used " << name << " and recovered " 
        << healAmount << " health\n";
    }

    ~Potion() {
        cout << "[Potion '" << name << "' consumed]\n";
    }
};

class Hero : public GameObject {
    Stats stats;
    SoulMark soulMark;
    Guild* guild;
    Weapon* weapon;

public: 
    Hero(int id, const string& tag, int health = 100, int mana = 50, 
        const string& mark = "Tattoo")
        : GameObject(id, tag), 
        stats(health, mana), 
        soulMark(mark), 
        guild(nullptr), 
        weapon(nullptr) {
            cout << "Hero '" << tag << "´created:"
            << " Health: " << stats.health
            << " Mana: " << stats.mana
            << " Soul Mark: " << soulMark.mark << "\n";
        }
    
    void joinGuild(Guild* g) {
        guild = g;
        cout << "Equipped: " << guild->getName() << "\n";
    }

    void equipWeapon(Weapon* w) {
        weapon = w;
        cout << "Equiped: " << weapon->getName() << "\n";
    }

    void attack(){
        if (weapon)
            weapon->attack();
        else
            cout << "No weapon equipped\n";
    }

    void usePotion(Potion* p) {
        p->use(stats.health);
        cout << "Current health: " << stats.health << "\n";
    }

    ~Hero() {
        cout << "[Hero '" << tag << "' has fallen]\n";
    }
};

int main(){
    Guild guild1("Diamod Guild");
    Sword sword1("Strawberry Sword", 25, 10);
    Hero* hero = new Hero(1, "Odette", 100, 60, "Spider Mark");

    hero->joinGuild(&guild1);
    hero->equipWeapon(&sword1);
    hero->attack();

    {
        Potion potion1("Lemon Potion", 40);
        hero->usePotion(&potion1);
    }

    cout << "\n--- The hero dies, so the soul mark and the stats do---\n\n";
    
    delete hero;

    cout << "\nGuild is still alive: " << guild1.getName() << "\n";
    cout << "Sword is still alive: " << sword1.getName() << "\n";

    return 0;
}