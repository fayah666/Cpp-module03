# Scale for Project CPP Module 03

**You should evaluate 1 student in this team**

---

## Introduction

Merci de respecter les règles suivantes durant l'évaluation :

- Restez polis, courtois, respectueux et constructifs. Le bien-être de la communauté en dépend.
- Identifiez avec la personne ou le groupe évalué les éventuels dysfonctionnements. Prenez le temps d'en discuter et de débattre des problèmes identifiés.
- Gardez à l'esprit qu'il peut exister de légères différences d'interprétation entre les instructions du projet, son scope et ses fonctionnalités. Faites preuve d'ouverture d'esprit et notez de la manière la plus honnête possible. La pédagogie n'est valide que si la peer-évaluation est prise au sérieux.

## Guidelines

- Ne notez **que** ce qui est contenu dans le dépôt Git cloné de l'étudiant(e) ou du groupe.
- Vérifiez que le dépôt Git appartient bien à l'étudiant(e) ou au groupe, que le projet est celui attendu, et que `git clone` est utilisé dans un dossier vide.
- Vérifiez scrupuleusement qu'aucun alias n'a été utilisé pour vous tromper et assurez-vous que vous évaluez bien le rendu officiel.
- Afin d'éviter toute surprise, vérifiez avec l'étudiant(e) ou le groupe les potentiels scripts utilisés pour faciliter l'évaluation (tests, automatisation, etc.).
- Si vous n'avez pas fait le projet que vous allez évaluer, vous **devez** lire le sujet en entier avant de commencer.
- Utilisez les flags disponibles pour signaler un rendu vide, un programme ne fonctionnant pas, une erreur de Norme, de la triche, etc.

> 📎 **Attachments :** `subject.pdf`

---

## ⚠️ Tests Préliminaires

> 🚨 **Triche :** Si un cas de triche est suspecté, l'évaluation s'arrête immédiatement. Sélectionnez le flag **"Cheat"**. Utilisez ce bouton avec calme, précaution et discernement.

### Prérequis de Compilation

- Le code doit compiler avec `c++` et les flags `-Wall -Wextra -Werror`.
- Ce projet doit suivre le standard **C++98**. Les fonctions C++11 (ou ultérieur) et les containers de la STL ne sont **PAS** attendus.

### 🛑 Critères Éliminatoires (Ne notez pas l'exercice si vous trouvez)

- Une fonction implémentée dans un fichier d'en-tête (sauf pour les fonctions templates).
- Un Makefile compilant sans les flags demandés et/ou avec un autre compilateur que `c++`.

### 🚩 Flag "Forbidden Function"

Sélectionnez ce flag si vous rencontrez :

- L'utilisation d'une fonction "C" (`*alloc`, `*printf`, `free`).
- L'utilisation d'une fonction interdite par les consignes de l'exercice.
- L'utilisation de `using namespace <ns_name>` ou du mot-clé `friend`.
- L'utilisation d'une bibliothèque externe ou de fonctionnalités postérieures à C++98.

---

## Exercise 00: Annnnnnd... ACTION!

> ⚠️ Comme d'habitude, il doit y avoir suffisamment de tests pour prouver que le programme fonctionne comme demandé. **S'il n'y en a pas, ne notez pas cet exercice.**

| Critère | Description | Validation |
| :--- | :--- | :---: |
| **Class & Attributes** | Il existe une classe `ClapTrap` possédant les attributs **privés** suivants :<br>• `name`<br>• `hit points`<br>• `energy points`<br>• `attack damage`<br>*Ces attributs sont-ils initialisés aux valeurs demandées ?* | [ ] Yes<br>[ ] No |
| **Member Functions** | Les fonctions membres suivantes sont présentes et fonctionnent comme spécifié :<br>• `attack()`<br>• `takeDamage()`<br>• `beRepaired()` | [ ] Yes<br>[ ] No |

---

## Exercise 01: Serena, My Love!

> ⚠️ Comme d'habitude, il doit y avoir suffisamment de tests pour prouver que le programme fonctionne comme demandé. **S'il n'y en a pas, ne notez pas cet exercice.**

| Critère | Description | Validation |
| :--- | :--- | :---: |
| **Class & Attributes** | Il existe une classe `ScavTrap` qui hérite **publiquement** de `ClapTrap`.<br>• Elle ne redéclare pas les attributs.<br>• Les attributs de `ClapTrap` sont maintenant **protected** au lieu de private.<br>• Les attributs sont initialisés aux valeurs demandées. | [ ] Yes<br>[ ] No |
| **Member Functions** | Les fonctions membres suivantes sont présentes et fonctionnelles :<br>• `attack()`<br>• `takeDamage()` (héritée)<br>• `beRepaired()` (héritée)<br><br>⚡ Les messages du constructeur, du destructeur et de `attack()` doivent être **différents** de ceux de `ClapTrap`. | [ ] Yes<br>[ ] No |
| **Construction & Destruction** | `ScavTrap` doit avoir un constructeur et un destructeur avec des messages spécifiques.<br>• **Création :** Message du constructeur `ClapTrap` affiché en premier, puis `ScavTrap`.<br>• **Destruction :** Message du destructeur `ScavTrap` affiché en premier, puis `ClapTrap`. | [ ] Yes<br>[ ] No |
| **Special Feature** | • `ScavTrap` possède une fonction `guardGate()` qui affiche un message sur la sortie standard.<br>• `ScavTrap` possède une fonction `attack()` qui affiche un message différent de celui de `ClapTrap`. | [ ] Yes<br>[ ] No |

---

## Exercise 02: Assembly Line Work

> ⚠️ Comme d'habitude, il doit y avoir suffisamment de tests pour prouver que le programme fonctionne comme demandé. **S'il n'y en a pas, ne notez pas cet exercice.**

| Critère | Description | Validation |
| :--- | :--- | :---: |
| **Class & Attributes** | Il existe une classe `FragTrap` qui hérite **publiquement** de `ClapTrap`.<br>• Les attributs ne doivent pas être redéclarés sans raison valable. | [ ] Yes<br>[ ] No |
| **Construction & Destruction** | `FragTrap` doit avoir un constructeur et un destructeur avec des messages spécifiques.<br>• **Création :** Message du constructeur `ClapTrap` affiché en premier, puis `FragTrap`.<br>• **Destruction :** Message du destructeur `FragTrap` affiché en premier, puis `ClapTrap`. | [ ] Yes<br>[ ] No |
| **Special Feature** | `FragTrap` possède une fonction `highFivesGuys()` qui affiche un message sur la sortie standard. | [ ] Yes<br>[ ] No |

---

## Exercise 03: Ok, This Is Getting Weird

> ⚠️ Comme d'habitude, il doit y avoir suffisamment de tests pour prouver que le programme fonctionne comme demandé. **S'il n'y en a pas, ne notez pas cet exercice.**

| Critère | Description | Validation |
| :--- | :--- | :---: |
| **The Ultimate Weirdness of C++** | Il existe une classe `DiamondTrap` qui hérite de **both** `FragTrap` et `ScavTrap`.<br>• Elle définit les attributs aux valeurs demandées.<br>• Elle utilise l'**héritage virtuel** pour éviter les pièges de l'héritage en diamant. | [ ] Yes<br>[ ] No |
| **Choose Wisely...** | • `DiamondTrap` utilise la fonction `attack()` de **ScavTrap**.<br>• Elle possède les fonctions spéciales de ses deux parents.<br>• `DiamondTrap` a un membre privé `std::string name`.<br>• La fonction `whoAmI()` a accès à la fois à `name` (DiamondTrap) et à `ClapTrap::name`. | [ ] Yes<br>[ ] No |
