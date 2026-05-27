# The Hero Excercise
This is a simple proyect for OOP class, created in c++ 14, that models object relationship such as inheritance, composition, aggregation, and dependency, so we can learn what happens when creating or destroying different types of objects.

## Class Relationships
| Class | Relationship | Description |
|---|---|---|
| 'Hero' | Inherits from 'GameObject | Hero is treated as a generic game object |
| 'Stats' | Composition inside 'Hero' | Dies when Hero dies |
| 'SoulMark' | Composition inside 'Hero' | Dies when hero dies |
| 'Guild' | Aggregation from 'Hero' | Survives when Hero dies | 
| 'Weapon' | Aggregation from 'Hero' | Survives when 'Hero' dies |
| 'Potion' | Dependency of 'Hero' | Passed, used, and gone |
| 'Sword' | Inherits from 'Weapon' | Overrides attack() with sharpness |

## How to Compile and Run
Make sure you have g++ installed. Then navigate to the poject folder in your terminal. 
Then compile the file:

```bash
g++ -std=c++14 TheHeroClass_A01715095.cpp -o HeroGame
```
and, run the program:

```bash
./HeroGame
```
or, if you are in Windows:
```bash
HeroGame
```
Then you'll find a mini-game loop where the guild, hero, and all of the other objects are created, it also equip the sword, use a potion, attack, and safely delete the hero while proving the Guild survives, and how the other objects are eliminated depending on what type of objects are.
