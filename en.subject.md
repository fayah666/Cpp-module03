# C++ - Module 03: Inheritance

**Summary:** This document contains the exercises of Module 03 from the C++ modules.
**Version:** 9.1

---

## Table of Contents
- [I. AI Instructions](#chapter-i-ai-instructions)
- [II. Exercise 00: Aaaaand... OPEN!](#chapter-ii-exercise-00-aaaaand-open)
- [III. Exercise 01: Serena, my love!](#chapter-iii-exercise-01-serena-my-love)
- [IV. Exercise 02: Repetitive work](#chapter-iv-exercise-02-repetitive-work)
- [V. Exercise 03: Now it’s weird!](#chapter-v-exercise-03-now-its-weird)
- [VI. Submission and Peer-Evaluation](#chapter-vi-submission-and-peer-evaluation)

---

## Chapter I: AI Instructions

### Context
This project is designed to help you discover the fundamental building blocks of your 42 training. To properly anchor key knowledge and skills, it’s essential to adopt a thoughtful approach to using AI tools and support. True foundational learning requires genuine intellectual effort — through challenge, repetition, and peer-learning exchanges.

For a more complete overview of our stance on AI — as a learning tool, as part of the 42 training, and as an expectation in the job market — please refer to the dedicated FAQ on the intranet.

### Main message
- ☛ Build strong foundations without shortcuts.
- ☛ Really develop tech & power skills.
- ☛ Experience real peer-learning, start learning how to learn and solve new problems.
- ☛ The learning journey is more important than the result.
- ☛ Learn about the risks associated with AI, and develop effective control practices and countermeasures to avoid common pitfalls.

### Learner rules
- You should apply reasoning to your assigned tasks, especially before turning to AI.
- You should not ask for direct answers to the AI.
- You should learn about 42 global approach on AI.

### Phase outcomes
Within this foundational phase, you will get the following outcomes:
- Get proper tech and coding foundations.
- Know why and how AI can be dangerous during this phase.

### Comments and examples
- Yes, we know AI exists — and yes, it can solve your projects. But you’re here to learn, not to prove that AI has learned. Don’t waste your time (or ours) just to demonstrate that AI can solve the given problem.
- Learning at 42 isn’t about knowing the answer — it’s about developing the ability to find one. AI gives you the answer directly, but that prevents you from building your own reasoning. And reasoning takes time, effort, and involves failure. The path to success is not supposed to be easy.
- Keep in mind that during exams, AI is not available — no internet, no smartphones, etc. You’ll quickly realise if you’ve relied too heavily on AI in your learning process.
- Peer learning exposes you to different ideas and approaches, improving your interpersonal skills and your ability to think divergently. That’s far more valuable than just chatting with a bot. So don’t be shy — talk, ask questions, and learn together!
- Yes, AI will be part of the curriculum — both as a learning tool and as a topic in itself. You’ll even have the chance to build your own AI software. In order to learn more about our crescendo approach you’ll go through in the documentation available on the intranet.

> ✅ **Good practice:**
> I’m stuck on a new concept. I ask someone nearby how they approached it. We talk for 10 minutes — and suddenly it clicks. I get it.
>
> ❌ **Bad practice:**
> I secretly use AI, copy some code that looks right. During peer evaluation, I can’t explain anything. I fail. During the exam — no AI — I’m stuck again. I fail.

---

## Chapter II: Exercise 00: Aaaaand... OPEN!

| | |
|---|---|
| **Exercise:** | 00 |
| **Directory:** | `ex00/` |
| **Files to Submit:** | `Makefile`, `main.cpp`, `ClapTrap.{h, hpp}`, `ClapTrap.cpp` |
| **Forbidden:** | None |

First, you have to implement a class! How original!

It will be called `ClapTrap` and will have the following **private attributes** initialized to the values specified in brackets:
- **Name**, which is passed as a parameter to the constructor
- **Hit points** (10), representing the health of the ClapTrap
- **Energy points** (10)
- **Attack damage** (0)

### Public Member Functions
Add the following public member functions so that the ClapTrap behaves more realistically:
- `void attack(const std::string& target);`
- `void takeDamage(unsigned int amount);`
- `void beRepaired(unsigned int amount);`

### Behavior Rules
- When ClapTrap **attacks**, it causes its target to lose `<attack damage>` hit points.
- When ClapTrap **repairs itself**, it regains `<amount>` hit points.
- Attacking and repairing each cost **1 energy point**.
- ClapTrap **can’t do anything** if it has no hit points or energy points left.
- Since these exercises serve as an introduction, ClapTrap instances should **not interact directly** with one another, and parameters will not refer to another instance of ClapTrap.

### Output Messages
In all member functions, you need to print a message describing what happens. For example:
```text
ClapTrap <name> attacks <target>, causing <damage> points of damage!
```

The **constructors and destructor** must also display a message so your peer-evaluators can easily see that they have been called.

*Implement and turn in your own tests to ensure your code works as expected.*

---

## Chapter III: Exercise 01: Serena, my love!

| | |
|---|---|
| **Exercise:** | 01 |
| **Directory:** | `ex01/` |
| **Files to Submit:** | Files from previous exercise + `ScavTrap.{h, hpp}`, `ScavTrap.cpp` |
| **Forbidden:** | None |

Because you can never have enough ClapTraps, you will now create a derived robot named `ScavTrap`.

### Inheritance & Construction
- `ScavTrap` **inherits** the constructors and destructor from `ClapTrap`.
- Its constructors, destructor, and `attack()` must print **different messages** than ClapTrap.
- **Proper construction/destruction chaining** must be shown in your tests:
  - Creation: ClapTrap constructor → ScavTrap constructor
  - Destruction: ScavTrap destructor → ClapTrap destructor

### Attributes
ScavTrap uses ClapTrap's attributes (update ClapTrap accordingly) initialized to:
- **Name**: passed as parameter
- **Hit points**: 100
- **Energy points**: 50
- **Attack damage**: 20

### Special Ability
```cpp
void guardGate();
```
Displays a message indicating that ScavTrap is now in **Gate keeper mode**.

*Don’t forget to add more tests to your program.*

---

## Chapter IV: Exercise 02: Repetitive work

| | |
|---|---|
| **Exercise:** | 02 |
| **Directory:** | `ex02/` |
| **Files to Submit:** | Files from previous exercises + `FragTrap.{h, hpp}`, `FragTrap.cpp` |
| **Forbidden:** | None |

Making ClapTraps is probably starting to get on your nerves. Now implement `FragTrap`, which inherits from `ClapTrap`.

### Inheritance & Construction
- Similar to ScavTrap but with **different construction/destruction messages**.
- **Proper chaining** must be demonstrated:
  - Creation: ClapTrap constructor → FragTrap constructor
  - Destruction: FragTrap destructor → ClapTrap destructor

### Attributes
Same structure as ClapTrap but with different values:
- **Name**: passed as parameter
- **Hit points**: 100
- **Energy points**: 100
- **Attack damage**: 30

### Special Ability
```cpp
void highFivesGuys(void);
```
Displays a positive high-fives request on the standard output.

*Again, add more tests to your program.*

---

## Chapter V: Exercise 03: Now it’s weird!

| | |
|---|---|
| **Exercise:** | 03 |
| **Directory:** | `ex03/` |
| **Files to Submit:** | Files from previous exercises + `DiamondTrap.{h, hpp}`, `DiamondTrap.cpp` |
| **Forbidden:** | None |

In this exercise, you will create a monster: a ClapTrap that’s half FragTrap, half ScavTrap named `DiamondTrap`. It inherits from **both** FragTrap AND ScavTrap. This is so risky!

### Naming Convention
DiamondTrap has a **private attribute** named `name`. This attribute must have **exactly the same variable name** as in the ClapTrap base class:
- If ClapTrap’s variable is `name` → DiamondTrap’s variable is `name`
- If ClapTrap’s variable is `_name` → DiamondTrap’s variable is `_name`

### Inherited Attributes & Functions
| Attribute/Function | Source | Value/Notes |
|---|---|---|
| Name | Constructor parameter | Passed to constructor |
| ClapTrap::name | Constructor parameter + suffix | `<name>_clap_name` |
| Hit points | FragTrap | Inherited value |
| Energy points | ScavTrap | Inherited value |
| Attack damage | FragTrap | Inherited value |
| `attack()` | ScavTrap | Inherited function |

### Special Ability
```cpp
void whoAmI();
```
Displays **both** its DiamondTrap name and its ClapTrap name.

### Important Notes
- The ClapTrap instance of DiamondTrap will be created **once, and only once**. Yes, there’s a trick.
- Do you know the `-Wshadow` and `-Wno-shadow` compiler flags?
- *You can pass this module without completing exercise 03.*

*Again, add more tests to your program.*

---

## Chapter VI: Submission and Peer-Evaluation

Submit your assignment in your Git repository as usual. Only the work within your repository will be evaluated during the defense. Don’t hesitate to double-check the names of your folders and files to ensure they are correct.

### Live Modifications
During the evaluation, a brief modification of the project may occasionally be requested. This could involve:
- A minor behavior change
- A few lines of code to write or rewrite
- An easy-to-add feature

While this step may not be applicable to every project, you **must be prepared for it** if it is mentioned in the evaluation guidelines.

**Purpose:** Verify your actual understanding of a specific part of the project.

**Execution:** The modification can be performed in any development environment you choose and should be feasible within a few minutes — unless a specific timeframe is defined.

**Examples:**
- Make a small update to a function or script
- Modify a display
- Adjust a data structure to store new information

> *The details (scope, target, etc.) will be specified in the evaluation guidelines and may vary from one evaluation to another for the same project.*
