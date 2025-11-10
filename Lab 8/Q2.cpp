#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant {
public:
    string name;
    int hp;
    int attackPower;
    int id;
    Combatant() {}
    Combatant(string n, int h, int a, int i) {
        name = n;
        hp = h;
        attackPower = a;
        id = i;
    }
};

class Node {
public:
    Combatant data;
    Node* left;
    Node* right;
    Node(Combatant c) {
        data = c;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, Combatant c) {
        if (!node) return new Node(c);
        if (c.id < node->data.id)
            node->left = insert(node->left, c);
        else
            node->right = insert(node->right, c);
        return node;
    }

    void insert(Combatant c) {
        root = insert(root, c);
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* node, int id) {
        if (!node) return node;
        if (id < node->data.id)
            node->left = deleteNode(node->left, id);
        else if (id > node->data.id)
            node->right = deleteNode(node->right, id);
        else {
            if (!node->left) return node->right;
            else if (!node->right) return node->left;
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data.id);
        }
        return node;
    }

    void deleteById(int id) {
        root = deleteNode(root, id);
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data.name << "(" << node->data.hp << "HP) ";
            inorder(node->right);
        }
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    bool empty() {
        return root == nullptr;
    }

    Node* getFrontline() {
        return minValueNode(root);
    }
};

int randomDamage(int baseAttack) {
    return baseAttack + (rand() % 5);
}

void displayRoundInfo(int round, BST& heroes, BST& villains) {
    cout << "\n=== Round " << round << " ===\n";
    cout << "Heroes: ";
    heroes.display();
    cout << "Villains: ";
    villains.display();
}

int main() {
    srand(time(0));
    BST heroes, villains;

    Combatant heroList[4] = {
        {"Superman", 45, 10, 10},
        {"Spiderman", 35, 8, 20},
        {"Batman", 30, 7, 30},
        {"Flash", 28, 9, 40}
    };

    Combatant villainList[4] = {
        {"Joker", 30, 6, 15},
        {"Thor", 40, 9, 25},
        {"Thanos", 50, 10, 35},
        {"Venom", 38, 8, 45}
    };

    for (int i = 0; i < 4; i++) heroes.insert(heroList[i]);
    for (int i = 0; i < 4; i++) villains.insert(villainList[i]);

    int round = 1;
    while (!heroes.empty() && !villains.empty()) {
        displayRoundInfo(round, heroes, villains);

        Node* hero = heroes.getFrontline();
        Node* villain = villains.getFrontline();

        if (!hero || !villain) break;

        cout << "\n" << hero->data.name << " attacks " << villain->data.name << endl;
        int damage = randomDamage(hero->data.attackPower);
        villain->data.hp -= damage;
        cout << "Damage: " << damage << " | " << villain->data.name << " HP now " << villain->data.hp << endl;

        if (villain->data.hp <= 0) {
            cout << villain->data.name << " has been defeated!\n";
            villains.deleteById(villain->data.id);
            if (villains.empty()) break;
        }

        if (!villains.empty()) {
            villain = villains.getFrontline();
            cout << villain->data.name << " attacks " << hero->data.name << endl;
            damage = randomDamage(villain->data.attackPower);
            hero->data.hp -= damage;
            cout << "Damage: " << damage << " | " << hero->data.name << " HP now " << hero->data.hp << endl;

            if (hero->data.hp <= 0) {
                cout << hero->data.name << " has been defeated!\n";
                heroes.deleteById(hero->data.id);
            }
        }

        round++;
    }

    cout << "\n=== Battle Over ===\n";
    if (heroes.empty() && villains.empty()) cout << "It's a draw!\n";
    else if (villains.empty()) cout << "Victory! Heroes win!\n";
    else cout << "Defeat! Villains win!\n";

    return 0;
}
