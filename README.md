# Text RPG

A simple **text based RPG game** written in C++    
This project demonstrates **OOP concepts**, a basic **battle system**, and a simple **game loop**

---

## Project Structure

```
text_rpg/
├── include/
│   ├── player.h
│   ├── enemy.h
│   ├── item.h
│   └── game.h
├── src/
│   ├── player.cpp
│   ├── enemy.cpp
│   ├── item.cpp
│   └── game.cpp
├── main.cpp
├── Makefile
├── rpg-game (compiled executable)
└── README.md
```

---

##  Features
- **Player System:** name, health, attack power, inventory
- **Enemy System:** randomly generated enemies with health/attack
- **Battle System:** turn based combat with random damage variation
- **Inventory:** use healing items during battle
- **Replayability:** fight multiple enemies until you quit or die

---

##  Concepts Covered
- **Object-Oriented Programming (OOP):** classes, encapsulation
- **Inheritance:** player & enemy as separate classes
- **Data Structures:** std::vector for inventory
- **Randomness:** rand() for damage variation
- **Game Loop:** while-player-alive cycle
- **Makefile Usage:** automating compilation
