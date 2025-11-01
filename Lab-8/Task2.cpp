#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant {
public:
    string name;
    int id;
    int health;
    int attackPower;

    Combatant() {}
    Combatant(int id, string name, int health, int attackPower) {
        this->id = id;
        this->name = name;
        this->health = health;
        this->attackPower = attackPower;
    }

    void display() const {
        cout << name << " (HP: " << health << ", ATK: " << attackPower << ")";
    }
};

struct Node {
    Combatant data;
    Node* left;
    Node* right;

    Node(Combatant c) : data(c), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, Combatant c) {
        if (node == nullptr)
            return new Node(c);
        if (c.id < node->data.id)
            node->left = insert(node->left, c);
        else if (c.id > node->data.id)
            node->right = insert(node->right, c);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int id) {
        if (node == nullptr) return node;

        if (id < node->data.id)
            node->left = deleteNode(node->left, id);
        else if (id > node->data.id)
            node->right = deleteNode(node->right, id);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data.id);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data.name << " (HP: " << node->data.health << ")  ";
            inorder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(Combatant c) {
        root = insert(root, c);
    }

    void remove(int id) {
        root = deleteNode(root, id);
    }

    bool empty() {
        return root == nullptr;
    }

    Node* getFrontline() {
        return findMin(root);
    }

    void displayTeam() {
        inorder(root);
    }

    Node* getRoot() { return root; }
};

class BattleQuest {
private:
    BST heroes, enemies;
    int round;

    void displayTeams() {
        cout << "\nHeroes: ";
        heroes.displayTeam();
        cout << "\nEnemies: ";
        enemies.displayTeam();
        cout << "\n";
    }

    int calculateDamage(int baseAttack) {
        return baseAttack + rand() % 5;
    }

public:
    BattleQuest() {
        srand(time(0));
        round = 1;
    }

    void setupGame() {
        heroes.insert(Combatant(10, "Usman", 50, 10));
        heroes.insert(Combatant(20, "Abdullah", 45, 12));
        heroes.insert(Combatant(30, "Taaha", 55, 9));
        heroes.insert(Combatant(40, "Jazlan", 40, 11));
        heroes.insert(Combatant(50, "Umair", 60, 8));

        enemies.insert(Combatant(15, "Bilal", 40, 8));
        enemies.insert(Combatant(25, "Ali", 55, 10));
        enemies.insert(Combatant(35, "Absar", 45, 11));
        enemies.insert(Combatant(45, "Sibtain", 60, 9));
        enemies.insert(Combatant(55, "Suhaib", 70, 13));
    }

    void startBattle() {
        while (!heroes.empty() && !enemies.empty()) {
            cout << "\nRound " << round << "\n";
            displayTeams();

            Node* hero = heroes.getFrontline();
            Node* enemy = enemies.getFrontline();

            int damage = calculateDamage(hero->data.attackPower);
            enemy->data.health -= damage;
            cout << hero->data.name << " attacks " << enemy->data.name
                 << " for " << damage << " damage!\n";

            if (enemy->data.health <= 0) {
                cout << enemy->data.name << " has been defeated!\n";
                enemies.remove(enemy->data.id);
                if (enemies.empty()) break;
                enemy = enemies.getFrontline();
            }

            damage = calculateDamage(enemy->data.attackPower);
            hero->data.health -= damage;
            cout << enemy->data.name << " counterattacks " << hero->data.name
                 << " for " << damage << " damage!\n";

            if (hero->data.health <= 0) {
                cout << hero->data.name << " has fallen in battle!\n";
                heroes.remove(hero->data.id);
            }

            round++;
        }

        if (heroes.empty())
            cout << "\nAll heroes have fallen! Enemies win!\n";
        else
            cout << "\nHeroes are victorious! All enemies defeated!\n";
    }
};

int main() {
    BattleQuest game;
    game.setupGame();
    game.startBattle();
    return 0;
}
