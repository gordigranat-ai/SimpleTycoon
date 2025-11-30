#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class MishasGame {
private:
    int knowledge;  // IT knowledge
    int charisma;   // Negotiation skills
    int energy;     // Energy level
    int day;        // Career day
    bool hasStartup;// Has a startup
    string companyName; // Company name

public:
    MishasGame() : knowledge(5), charisma(5), energy(100), day(1), hasStartup(false) {}

    void startGame() {
        cout << "=== Misha Rybakov: Path of an IT Entrepreneur ===\n\n";
        cout << "Welcome to the game where you become Misha Rybakov!\n";
        cout << "Your goal is to build a successful IT business and become a famous entrepreneur.\n\n";

        cout << "Come up with a name for your future company: ";
        getline(cin, companyName);

        cout << "\nGreat! Your company will be called '" << companyName << "'\n";
        cout << "Let your entrepreneurial adventure begin!\n";

        while (energy > 0 && day <= 30) {
            startDay();
        }

        if (day > 30) {
            cout << "\n\n=== Congratulations! ===" << endl;
            cout << "You've completed 30 days of entrepreneurial journey!" << endl;
            if (hasStartup) {
                cout << "Your company '" << companyName << "' has achieved success!" << endl;
            }
            cout << "Your final stats:" << endl;
            showStats();
        }
        else {
            cout << "\n\n=== Game Over ===" << endl;
            cout << "Misha Rybakov burned out and couldn't continue his journey." << endl;
        }
    }

private:
    void startDay() {
        cout << "\n=== Day " << day << " ===" << endl;
        showStats();

        cout << "\nChoose an action:" << endl;
        cout << "1. Study programming" << endl;
        cout << "2. Attend IT event" << endl;
        cout << "3. Rest" << endl;

        if (knowledge >= 10 && !hasStartup) {
            cout << "4. Found startup '" << companyName << "'" << endl;
        }

        if (hasStartup) {
            cout << "5. Work on company development" << endl;
            cout << "6. Look for investors" << endl;
        }

        int choice;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            studyProgramming();
            break;
        case 2:
            attendEvent();
            break;
        case 3:
            rest();
            break;
        case 4:
            if (knowledge >= 10 && !hasStartup) {
                foundStartup();
            }
            else {
                cout << "Wrong choice!" << endl;
            }
            break;
        case 5:
            if (hasStartup) {
                workOnStartup();
            }
            else {
                cout << "Wrong choice!" << endl;
            }
            break;
        case 6:
            if (hasStartup) {
                findInvestors();
            }
            else {
                cout << "Wrong choice!" << endl;
            }
            break;
        default:
            cout << "Wrong choice!" << endl;
        }

        energy -= 15 + rand() % 10;
        day++;

        if (rand() % 5 == 0) {
            randomEvent();
        }
    }

    void showStats() {
        cout << "Knowledge: " << knowledge << " | Charisma: " << charisma << " | Energy: " << energy << endl;
        if (hasStartup) {
            cout << "Status: Founder of '" << companyName << "'" << endl;
        }
        else {
            cout << "Status: Aspiring entrepreneur" << endl;
        }
    }

    void studyProgramming() {
        int gained = 2 + rand() % 3;
        knowledge += gained;
        cout << "You spent the day studying programming and gained +" << gained << " knowledge!" << endl;
    }

    void attendEvent() {
        int gained = 1 + rand() % 2;
        charisma += gained;
        cout << "You attended an IT event, met new people and gained +" << gained << " charisma!" << endl;

        if (rand() % 3 == 0) {
            int extra = 1 + rand() % 2;
            knowledge += extra;
            cout << "You also learned something new and gained additional +" << extra << " knowledge!" << endl;
        }
    }

    void rest() {
        int gained = 20 + rand() % 30;
        energy += gained;
        if (energy > 100) energy = 100;
        cout << "You had a good rest and recovered " << gained << " energy!" << endl;
    }

    void foundStartup() {
        hasStartup = true;
        cout << "Congratulations! You've founded '" << companyName << "'!" << endl;
        cout << "Now you can work on its development and look for investors." << endl;
    }

    void workOnStartup() {
        int gainedKnowledge = 1 + rand() % 2;
        int gainedCharisma = 1 + rand() % 2;

        knowledge += gainedKnowledge;
        charisma += gainedCharisma;

        cout << "You worked hard on developing '" << companyName << "'!" << endl;
        cout << "Gained +" << gainedKnowledge << " knowledge and +" << gainedCharisma << " charisma!" << endl;

        if (rand() % 4 == 0) {
            cout << "Your company earned its first revenue! This motivates you to continue!" << endl;
            energy += 10;
        }
    }

    void findInvestors() {
        if (charisma < 10) {
            cout << "Your charisma isn't high enough to interest investors." << endl;
            return;
        }

        int chance = 30 + (charisma * 5);
        if (rand() % 100 < chance) {
            int investment = 50000 + rand() % 100000;
            cout << "Congratulations! You found an investor who put $" << investment << " into your startup!" << endl;
            cout << "Now you have more opportunities for development!" << endl;
            knowledge += 3;
            charisma += 2;
        }
        else {
            cout << "Unfortunately, investors weren't interested in your project. Try again!" << endl;
        }
    }

    void randomEvent() {
        cout << "\n=== Random Event! ===" << endl;
        int event = rand() % 4;

        switch (event) {
        case 0:
            cout << "You came across an interesting business article and learned something new!" << endl;
            knowledge += 2;
            break;
        case 1:
            cout << "Your friend invited you to speak at a conference. It was a valuable experience!" << endl;
            charisma += 3;
            break;
        case 2:
            cout << "You caught a cold and lost a day recovering." << endl;
            energy -= 20;
            break;
        case 3:
            cout << "You met an old acquaintance who gave you valuable advice." << endl;
            if (rand() % 2 == 0) {
                knowledge += 1;
                cout << "+1 to knowledge!" << endl;
            }
            else {
                charisma += 1;
                cout << "+1 to charisma!" << endl;
            }
            break;
        }
    }
};

int main() {
    srand(time(0));
    MishasGame game;
    game.startGame();
    return 0;
}