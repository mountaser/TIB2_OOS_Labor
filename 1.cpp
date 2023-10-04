#include <string>
#include <ctime>
#include <iostream>

using namespace std;

// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object
{
    ROCK,
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge
enum class Result
{
    PLAYER_ONE_WINS,
    PLAYER_TWO_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player
{
    string name;
    Object choice;
};

// Name des Spielers eingeben
string insert_name()
{
    cout << "Name des Spielers: ";
    string name;
    getline(cin, name);
    cin.clear();
    return name;

    // HIER programmieren:
    // Den Namen des Spielers von der Konsole einlesen und zurückgeben
    // Tip: für das Einlesen eines Strings gibt es eine bestimmte Funktion, siehe auch Vorlesung Folie "Eine Zeile als String einlesen"

}

Object determine_choice(string choice)
{
    if (choice.compare("CoderunnerTestValueROCK") == 0)
    {
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestValueSCISSORS") == 0)
    {
        return Object::SCISSORS;
    }
    else if (choice.compare("CoderunnerTestValuePAPER") == 0)
    {
        return Object::PAPER;
    }
    else
    {
        // Den Computer zufällig waehlen lassen.
        // HIER beantworten Sie folgende Fragen:

        // Wie funktioniert die funktion rand?
        // Die Funktion "rand" gibt eine zufällige ganze Zahl zurück, die im Bereich von 0 bis RAND_MAX liegt. RAND_MAX ist eine Konstante, die die größte zufällige Zahl angibt, die von "rand" generiert werden kann.

        // Was bewirkt die funktion srand?
        //Die Funktion "srand" initialisiert den Zufallsgenerator mit einem Startwert, der als Parameter übergeben wird. Durch die Verwendung von "srand" wird sichergestellt, dass bei jeder Ausführung des Programms eine andere Folge von Zufallszahlen generiert wird.


        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        //Die Zeit (time) wird als Eingabe für die Funktion srand verwendet, um sicherzustellen, dass bei jeder Ausführung des Programms eine andere Folge von Zufallszahlen generiert wird, da die aktuelle Zeit bei jeder Ausführung unterschiedlich ist.

        // Warum wird hier modulo 3 verwendet?
        //Das Modulo 3 wird verwendet, um den Zufallswert auf den Bereich von 0 bis 2 zu begrenzen, was den drei möglichen Optionen des Spiels entspricht: Stein, Papier oder Schere.


        srand(static_cast<int>(time(nullptr)));
        int choice = rand() % 3;
        return static_cast<Object>(choice);
    }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object)
{
     switch (object)
    {
        case Object::ROCK:
            return "Stein";
        case Object::SCISSORS:
            return "Schere";
        case Object::PAPER:
            return "Papier";
    }
    return "404";    

    // HIER programmieren:
    // Abhängig vom vorliegenden Object einen entsprechenden String zurückgeben.
    // z.B: Wenn Object dem Wert Object::ROCK entspricht, dann String "Stein" zurückgeben

}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player)
{
    cout << player.name << " hat das Objekt " << get_name(player.choice) << " gewählt \n";
    // HIER programmieren:
    // Auf der Konsole ausgeben, für welches Object sich der Spieler entschieden hat.
    // z.B.: "Computer hat das Object Schere gewählt"
    // TIP: Nutzen sie hierzu die Funktion get_name

}

// Die Wahl des Spielers abfragen
Object chose()
{
    Object choice;
    bool valid;
    
    do{

    cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
    int ch;
    cin >> ch;
    if(ch >= 1 && ch <= 3){
        valid = 1;
        choice = static_cast<Object>(ch -1);
    }
    else valid = 0;
    

    }while(!valid);

    return choice;

    // HIER programmieren:
    // Die Wahl des Spielers von der Konsole einlesen und zurückgeben
    // Stellen sie sicher, dass es sich um eine gültige Wahl handelt!
    // TIP: Nutzen Sie dazu eine geeignete Schleife. Siehe auch Vorlesung Folie "Annehmende Schleifenanweisungen – Do"

}

Result determine_result(Player player_1, Player player_2)
{

    Object choice_1 = player_1.choice;
    Object choice_2 = player_2.choice;

    switch (static_cast<int>(choice_1) - static_cast<int>(choice_2))
    {
        case -1:
        case 2:
            return Result::PLAYER_ONE_WINS;
        case -2:
        case 1:
            return Result::PLAYER_TWO_WINS;
    }
    return Result::DRAW;
    // HIER programmieren:
    // Vergleichen Sie die gewählten Objekte, ermitteln sie das Spielergebnis und geben sie es zurück.
    // TIP: Wenn Sie für den Vergleich mit ganzene Zahlen _rechnen_ wollen, dann nutzen sie den static_cast, siehe auch Vorlesung Folie "Casts in C++: Static_cast"

}

void print_result(Player player_1, Player player_2)
{
    Result result = determine_result(player_1, player_2);

    switch (result)
    {
        case Result::PLAYER_ONE_WINS:
            cout <<"Spieler " <<  player_1.name <<" hat gewonnen." << endl;
            break;
        case Result::PLAYER_TWO_WINS:
            cout <<"Spieler " << player_2.name <<" hat gewonnen." << endl;
            break;
        case Result::DRAW:
            cout << "Unentschieden" << endl;
            break;
    }
    

    // HIER programmieren:
    // Ermitteln Sie zunächst das Spielergebnis. Nutzen sie dazu die Funktion determine_result.
    // Geben Sie anschließend auf der Konsole aus, wer gewonnen hat.
    // z.B: "Spieler Computer hat gewonnen" oder "Unentschieden"

}

int main(int argc, char *argv[])
{
    Player player_1, player_2;
    player_1.name = "Computer";
    player_2.name = insert_name();
    player_1.choice = determine_choice(player_2.name);
    cout << "Der Computer hat seine Wahl getroffen." << endl;
    player_2.choice = chose();
    print_choice(player_1);
    print_choice(player_2);
    print_result(player_1, player_2);

    return 0;
}