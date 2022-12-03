/*
 * Copyright 2019, All Rights Reserved
 *
 * Project Title:
 * - The Great Etruscan Boar Quest
 *
 * Description: A pseudo RPG which will take the user to the depths of an ancient Etruscan temple on a hunt for the grand Etruscan boar Vessel.
 * Along the way, the user will have to use their wits, memory, intuition and arsenal of items to survive the threats, steal the boar and escape.
 *
 * This program runs a game inspired by the classic zork in which a player will have to navigate and interact with an ancient Etruscan temple on the quest for the
 * golden boar of Etrusca.
 *
 * Developers:
 * - Timothy Holstein
 * - Eric Michalski
 *
 * Help Received:
 * - Teacher: Robert Montjoy
 * - Student: Andrew Dillon
 * - Student: Joshua Sutton
 *
 * Special Instructions: // optional
 * - Nothing special is required to compile or run the program. When you win or lose, to restart, simply exit the program and run it again.
 * - Run the program. In QT, press the green run button.
 *
 * Developer comments:
 * Timothy Holstein:
 * My responsibility was to write the text for the adventure (The descriptions, enviorment, lore, etc), and I programmed the Armory room, the main room, the Boar Vessel room, the victory condition, and the crypt.
 * I learned a great deal about calling variables by reference. Seeing as it was the basis for our inventory system, it was obviously crucial to our success, whereas I rarely used it before.
 * It makes variables so much simpler, now that I see it in practice.
 * Eric Michalski:
 * My responsibilities were to program the start game function, the entrance, the riddle room, the PK room, the coin room, and the hydra room.
 * I also learned a lot about call by reference, as I did not completely understand the concept, but since it was widely used in our code, I now know and understand how it compares to call by value.
 */


#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void StartGame(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory);
void Entrance(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory);
void Armory(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory);
void CryptRoom(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory);
void MainRoom(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory);
void Riddle(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory);
void PKRoom(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory);
void CoinRoom(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory);
void HydraRoom(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory);
void BoarVesselRoom(int& Armor, bool& Spear, bool& victory);
void victoryroom(bool& victory);

/* Function Name: StartGame
 *
 * Function Description:
 * This function is run at the start of the game. It effectivley gives the player to decide if they want to play or not, and begins the game or closes depending on their answer.
 * This function solves the problem of if the player doesn't want to play the game. They can just choose to end it here.
 *
 * Parameters:
 * Note: Virtually all of our functions have the same parameters, which will be described in depth in the following. The majority of them are items which the player may collect, statuses of enemies, whether or not doors are open, and secrets.
 * The Sword parameter is to tell if the player has obtained the sword item, and carries it with them. The sword is required, and can be used in combat, or to explore.
 * The Spear parameter is to tell if the player has obtained the spear item, and carries it with them. The spear is optional, but is a great combat weapon that makes fighting easier. Cannot be used to explore generally.
 * The Shield parameter is to tell if the player has obtained the shield item, and carries it with them. The shield is required, and though it provides little in the way of combat, is useful for exploring.
 * The Torch parameter is to tell if the player has obtained the torch item, and carries it with them. The shield is required. While not a traditional weapon, it will see some limited use in combat, and is useful when exploring.
 * The Armor parameter is basically our health system. Armor is a number starting at 1 that allows the player to absord damage. When the player hits zero armor, then the next hit will be fatal. Additional armor can be found in the temple.
 * The FirstHalf parameter is to tell if the player has picked up the first half of the final coin, which is represented by the Sun Coin in the game. Required for exploration, but nothing else.
 * The SecondHalf parameter is to tell if the player has picked up the second half of the final coin, which is represented by the Moon coin in the game. Required for exploration but nothing else.
 * The Coin paremter is to tell if the player has collected both halves of the coin, and thus completed the seal needed for victory.
 * The Key parameter is to tell if the player has collected a key, which may have some value in exploring the world(hint/spoiler: It won't, a red herring).
 * The Boar parameter is to tell if the player has obtained the golden boar, and with it, soaring victory
 * The Hydra parameter is to tell if the player is aware of the Hydra lurking in the depths of the temple
 * The complete parameter is to tell if the player has sucesfully answered the first of the riddles presented in the riddle room.
 * The complete2 parameter is to tell if the player has sucessfully answered the second of the riddles presented in the riddle room.
 * The VisitPK parameter is to tell if the player has answered the optional riddle and can visit PK in the easteregg room.
 * The boargatecheck parameter is to tell if the player has investigated the boar vessel room's gate, and knows what to look for.
 * The boargateopen parameter is to tell if the player has opened the boar vessel room's gate.
 * The vineopen parameter is to tell if the player has unlocked the vine door
 * The pearlopen parameter is to tell if the player has unlocked the pearl door.
 * The victory parameter is to tell if the player has achieved victory.
 *
 *
 * return value:
 * No return value, this is a void function.
 */

void StartGame(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory){
    char StartGame = 'n';
    cout << "So begins our tale." << endl; //Introduction text
    cout << "Brave adventurer, you alone seek the prize which has been denied to countless others." << endl;
    cout << "The emperor himself has handselected you, bravest in the land to retrieve the ultimate relic of a long long peoples." << endl;
    cout << "The Fabled Etruscan Boar Vessel." << endl;
    cout << "Be warned, the path will be fraught with danger. For Etrusca is not a place of forgiveness or weakness." << endl;
    cout << endl;
    cout << "Your horse stops in front of the decrepit tomb of the old Etruscan king. Inside that massive complex lies the boar vessel, your final goal." << endl;
    cout << "As you have been told before, Etrusca is a place of danger and risk. Inside that temple will be countless traps, puzzles and foes that you must conquer to reach your victory, The Boar Vessel." << endl;
    cout << "How you think on your feet will determine if you live and reach glory, or join the fallen of old Etrusca. Use items, solve puzzles, and navigate the temple until you reach the boar vessel." << endl;
    cout << "Now then, without further delay, the time has come." << endl;
    cout << endl;
    
    cout << "Do you enter the ancient temple, and begin your quest? (y/n): " << endl;      // Asks user if they want to start the game
    cin >> StartGame;
    while (StartGame != 'y' && StartGame != 'n'){
        cout << "It's a yes or no question. There is no time for cowardice or tricks." << endl;
        cout << "You are asked again. Do you enter the ancient temple, and begin your quest? (y/n): " << endl;
        cin >> StartGame;
    }
    if (StartGame == 'y'){                   // Starts the game while user's answer is y (yes)
        cout << "You muster your courage, and march forward. You enter the enormous crumbling stone gateway, the golden boar of Etrusca engraved above the arch." << endl;
        cout << endl;
        string Location = "Entrance";
        Entrance(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);                           // Starts players in Entrance
    }
    else {
        cout << "Fear not, discretion is ultimatley the better part of valor. Perhaps just today isn't your day. Better to go home and prepare than fail now." << endl;
        victory = 1;
        return;
    }
}



/* Function Name: Entrance
 *
 * Function Description:
 * This function is run if the player decides to play the game and enters the entrance room.
 * This function solves where the player wants to go. The player inputs commands here which will guide where the player wants to go. w for up, d for right, and so on.
 *
 *
 * Parameters:
 * Note: Virtually all of our functions have the same parameters, which will be described in depth in the following. The majority of them are items which the player may collect, statuses of enemies, whether or not doors are open, and secrets.
 * The Sword parameter is to tell if the player has obtained the sword item, and carries it with them. The sword is required, and can be used in combat, or to explore.
 * The Spear parameter is to tell if the player has obtained the spear item, and carries it with them. The spear is optional, but is a great combat weapon that makes fighting easier. Cannot be used to explore generally.
 * The Shield parameter is to tell if the player has obtained the shield item, and carries it with them. The shield is required, and though it provides little in the way of combat, is useful for exploring.
 * The Torch parameter is to tell if the player has obtained the torch item, and carries it with them. The shield is required. While not a traditional weapon, it will see some limited use in combat, and is useful when exploring.
 * The Armor parameter is basically our health system. Armor is a number starting at 1 that allows the player to absord damage. When the player hits zero armor, then the next hit will be fatal. Additional armor can be found in the temple.
 * The FirstHalf parameter is to tell if the player has picked up the first half of the final coin, which is represented by the Sun Coin in the game. Required for exploration, but nothing else.
 * The SecondHalf parameter is to tell if the player has picked up the second half of the final coin, which is represented by the Moon coin in the game. Required for exploration but nothing else.
 * The Coin paremter is to tell if the player has collected both halves of the coin, and thus completed the seal needed for victory.
 * The Key parameter is to tell if the player has collected a key, which may have some value in exploring the world(hint/spoiler: It won't, a red herring).
 * The Boar parameter is to tell if the player has obtained the golden boar, and with it, soaring victory
 * The Hydra parameter is to tell if the player is aware of the Hydra lurking in the depths of the temple
 * The complete parameter is to tell if the player has sucesfully answered the first of the riddles presented in the riddle room.
 * The complete2 parameter is to tell if the player has sucessfully answered the second of the riddles presented in the riddle room.
 * The VisitPK parameter is to tell if the player has answered the optional riddle and can visit PK in the easteregg room.
 * The boargatecheck parameter is to tell if the player has investigated the boar vessel room's gate, and knows what to look for.
 * The boargateopen parameter is to tell if the player has opened the boar vessel room's gate.
 * The vineopen parameter is to tell if the player has unlocked the vine door
 * The pearlopen parameter is to tell if the player has unlocked the pearl door.
 * The victory parameter is to tell if the player has achieved victory.
 *
 *
 * return value:
 * only returns once, if the player decides to flee the temple. This return kills the game.
 */
void Entrance(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory){                                                // Main Entrance of Room
    char Move = 'n';
    bool Movement = 0;
    if (Beginning == 0){
        cout << "You march into the opening room, a dimly lit and decrepit passage." << endl;                                                                             //Intro text for first entering the room
        cout << "Now, you quickly asses your surroundings. The walls are dusty and worn. Inscribed on them is countless images and engravings of old Etrusca." << endl;
        cout << "Some depict the glory days of the old civilization, others a time of terror and decline, and others are eerily empty. Yet all have a single constant." << endl;
        cout << "The golden boar." << endl;
        cout << "Immediatly, 3 passage ways catch your eye. You realize that you stand at the northernmost part of the temple." << endl;
        cout << "Directly south, an enormous and dark room, large and open. To the east, or your left, a strangely well lit room, called 'Crpyt' in ancient Etruscan." << endl;
        cout << "To the west, or your right, you see the shining gleam of bronze reflecting around the room." << endl;
        cout << "Which way do you want to go? (w/a/s/d): " << endl;
        cin >> Move;
        Beginning = 1;
    }
    else if (Beginning == 1){
        cout << "Once more you stand in the entrance way. Once more, nothing has changed, and the room is naught but a nexus of other rooms. Which way do you wish to travel? (w/a/s/d): " << endl;
        cin >> Move;
    }
    while (Movement == 0){
        if (Move == 'w'){                                                         // Moves up, off the map
            cout << "Cowardice overtakes you. In your fear, you flee the temple." << endl;
            cout << "As you run out of the northern exit, you turn briefly and adress the temple once more. The golden boar alludes you again." << endl;
            cout << "But that doesn't matter now. What matters is you are alive and breathing. You mount up and scurry home, head hung low." << endl;
            victory = 1;
            return;
        }
        else if (Move == 'a'){
            Movement = 1;
            Armory(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);                                              // Moves left, into the armory
        }
        else if (Move == 'd'){
            Movement = 1;
            CryptRoom(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);                                            // Moves right, into the crypt
        }
        else if (Move == 's'){
            Movement = 1;
            MainRoom(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);                                           // Move down, into the main room
        }
        else{
            cout << "You go nowhere. " << endl;
            cout << "What are you doing? That isnt a direction. W-North, A-West, S-South, D-Eas. Not hard." << endl;                          //slams into a wall.
            Movement = 0;
        }
    }
}

/* Function Name: Armory
 *
 * Function Description:
 * This function is what runs when the player enters the armory room. This will give the player options to get outfitted with different kinds of equitment that will help them in the coming challenges.
 * This is effectivley the "loadout" room.
 *
 * Parameters:
 * Note: Virtually all of our functions have the same parameters, which will be described in depth in the following. The majority of them are items which the player may collect, statuses of enemies, whether or not doors are open, and secrets.
 * The Sword parameter is to tell if the player has obtained the sword item, and carries it with them. The sword is required, and can be used in combat, or to explore.
 * The Spear parameter is to tell if the player has obtained the spear item, and carries it with them. The spear is optional, but is a great combat weapon that makes fighting easier. Cannot be used to explore generally.
 * The Shield parameter is to tell if the player has obtained the shield item, and carries it with them. The shield is required, and though it provides little in the way of combat, is useful for exploring.
 * The Torch parameter is to tell if the player has obtained the torch item, and carries it with them. The shield is required. While not a traditional weapon, it will see some limited use in combat, and is useful when exploring.
 * The Armor parameter is basically our health system. Armor is a number starting at 1 that allows the player to absord damage. When the player hits zero armor, then the next hit will be fatal. Additional armor can be found in the temple.
 * The FirstHalf parameter is to tell if the player has picked up the first half of the final coin, which is represented by the Sun Coin in the game. Required for exploration, but nothing else.
 * The SecondHalf parameter is to tell if the player has picked up the second half of the final coin, which is represented by the Moon coin in the game. Required for exploration but nothing else.
 * The Coin paremter is to tell if the player has collected both halves of the coin, and thus completed the seal needed for victory.
 * The Key parameter is to tell if the player has collected a key, which may have some value in exploring the world(hint/spoiler: It won't, a red herring).
 * The Boar parameter is to tell if the player has obtained the golden boar, and with it, soaring victory
 * The Hydra parameter is to tell if the player is aware of the Hydra lurking in the depths of the temple
 * The complete parameter is to tell if the player has sucesfully answered the first of the riddles presented in the riddle room.
 * The complete2 parameter is to tell if the player has sucessfully answered the second of the riddles presented in the riddle room.
 * The VisitPK parameter is to tell if the player has answered the optional riddle and can visit PK in the easteregg room.
 * The boargatecheck parameter is to tell if the player has investigated the boar vessel room's gate, and knows what to look for.
 * The boargateopen parameter is to tell if the player has opened the boar vessel room's gate.
 * The vineopen parameter is to tell if the player has unlocked the vine door
 * The pearlopen parameter is to tell if the player has unlocked the pearl door.
 * The victory parameter is to tell if the player has achieved victory.
 *
 *
 * return value:
 * No return value, this is a void function, and the player cannot die in this room.
 */
void Armory(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory){
    string weapon;
    string answer;
    int Movement = 0;
    char Move = 'n';
    cout << "You enter the shining gallery, a long and narrow room, remarkably plain in its design. It's design however, isn't why you are here." << endl;

    //This runs if this is the first time the user enters the room, and they have no gear.
    if (Sword == 0 && Spear == 0 && Shield == 0)
            {
        cout << "In rusted racks of ancient armamants and bloodstained gear, you see some functioning equitment. " << endl;
        cout << "Amongst them, you spot a sharpened bronze Sword, a dorian Spear, and a brightly gleaming Shield, more decoration than bulwark." << endl;
        cout << "Would you like to take any of the gear? Aferall, this tomb could be far from empty. Etrusca is a dangerous place. (y/n)" << endl;
        cin >> answer;
        while (answer != "y" && answer != "n") {
            cout << "Come on adventurer, yes or no question here. Not that hard." << endl;
            cout << "I ask again. Do you want to take a weapon?" << endl;
            cin >> answer;
            }
        //Asks the first time if the user wants to take anything.
        if (answer == "y")
            {
            cout << "What item would you like to take? " << endl;;
            cin >> weapon;
            if (weapon == "Sword")
            {
                Sword = 1;
                cout << "You grab the bronze Sword, its blade shining in your hand. The weighty blade is perfect for slashing, and getting up close. " << endl;
            }
            else if (weapon == "Spear")
            {
                Spear = 1;
                cout << "You grab the large dorian Spear. It is pointed and solid. This is a weapon of war, and lets you stab from a distance. " << endl;
            }
            else if (weapon == "Shield")
            {
                Shield = 1;
                cout << "You grab the glossing and radiant Shield. You notice it is brittle, and wont be useful for defense at all. How strange. " << endl;
            }

            else
            {
                cout << "Not a real item, but ok whatever. Say you picked it up in your imagination. Hint: You picked nothing up." << endl;
            }

            cout << "Would you like to take another? (y/n)" << endl;                           //Prompts the user for another one
            cin >> answer;
            while (answer != "y" && answer != "n")
            {
                cout << "Come on adventurer, yes or no question. Isn't that hard." << endl;
                cout << "Once again, do you want another weapon?! " << endl;
                cin >> answer;
            }
            while (answer == "y")
            {
            cout << "What do you want to take?" << endl;;
            cin >> weapon;
            if ((weapon == "Shield" && Shield == 1) || (weapon == "Spear" && Spear == 1) || (weapon == "Sword" && Sword == 1))
            {
                cout << "You already picked this weapon up. What are you doing? Did you addle your head? " << endl;
                cout << "You want to try picking up a weapon again or not? (y/n)" << endl;
                cin >> answer;
                while (answer != "y" && answer != "n"){
                    cout << "Come on adventurer, yes or no question. Isn't that hard." << endl;
                    cout << "Once again, do you want another weapon?! " << endl;
                    cin >> answer;
            }
            }
            else if (weapon == "Sword")
            {
                Sword = 1;
                cout << "You grab the bronze Sword, its blade shining in your hand. The weighty blade is perfect for slashing, and getting up close. " << endl;
                cout << "You want to grab another weapon? You've got the bag space for it. " << endl;
                cin >> answer;
                while (answer != "yes" && answer != "no"){
                    cout << "Come on adventurer, yes or no question. Isn't that hard." << endl;
                    cout << "Once again, do you want another weapon?! " << endl;
                    cin >> answer;
            }
            }
            else if (weapon == "Spear")
            {
                Spear = 1;
                cout << "You grab the large dorian Spear. It is pointed and solid. This is a weapon of war, and lets you stab from a distance. " << endl;
                cout << "You want to grab another weapon? You've got the bag space for it. " << endl;
                cin >> answer;
                while (answer != "yes" && answer != "no"){
                    cout << "Come on adventurer, yes or no question. Isn't that hard." << endl;
                    cout << "Once again, do you want another weapon?! " << endl;
                    cin >> answer;
            }

            }
            else if (weapon == "Shield")
            {
                Shield = 1;
                cout << "You grab the glossing and radiant Shield. You notice it is brittle, and wont be useful for defense at all. How strange. " << endl;
                cout << "You want to grab another weapon? You've got the bag space for it. " << endl;
                cin >> answer;
                while (answer != "yes" && answer != "no"){
                    cout << "Come on adventurer, yes or no question. Isn't that hard." << endl;
                    cout << "Once again, do you want another weapon?! " << endl;
                    cin >> answer;
            }
            }
            else
            {
                cout << "That item is clearly not in the room, whatever you were thinking. " << endl;
                cout << "Want to take another item? " << endl;
                cin >> answer;
            }
            } //While loop ends.


            }
        else if (answer == "n")
            {
             cout <<"You stand in the room and bask in the glory of a load of blood stained and worn bronze armaments. Exciting." << endl;
            }

            }
    //If the user has already taken an item from the Armory.

          else if (Sword == 1 || Shield == 1 || Spear == 1)
            {
        cout << "Once more, you walk into the old Etruscan Armory. The room remains a shining bronze gallery, same as last time." << endl;
        cout << "There may yet be gear still in the Armory. Would you like to inspect it?" << endl;
        cin >> answer;
        while (answer != "y" && answer != "n")
            {
            cout << "Come on adventurer, yes or no question. Isn't that hard." << endl;
            cout << "Once again, do you want another weapon?! " << endl;
            cin >> answer;
            }
        while (answer == "y")
            {
        cout << "What do you want to take?";
        cin >> weapon;
        if ((weapon == "Shield" && Shield == 1) || (weapon == "Spear" && Spear == 1) || (weapon == "Sword" && Sword == 1))
            {
            cout << "You already picked this weapon up. What are you doing? Did you addle your head?" << endl;
            cout << "You want to try picking up a weapon again or not?" << endl;
            cin >> answer;
            }
        else if (weapon == "Sword")
            {
            Sword = 1;
            cout << "You grab the bronze Sword, its blade shining in your hand. The weighty blade is perfect for slashing, and getting up close." << endl;
            cout << "You want to grab another weapon? You've got the bag space for it." << endl;
            cin >> answer;
            }
        else if (weapon == "Spear")
            {
            Spear = 1;
            cout << "You grab the large dorian Spear. It is pointed and solid. This is a weapon of war, and lets you stab from a distance." << endl;
            cout << "You want to grab another weapon? You've got the bag space for it." << endl;
            cin >> answer;

            }
        else if (weapon == "Shield")
            {
            Shield = 1;
            cout << "You grab the glossing and radiant Shield. You notice it is brittle, and wont be useful for defense at all. How strange." << endl;
            cout << "You want to grab another weapon? You've got the bag space for it." << endl;
            cin >> answer;
            }
        else
           {
            cout << "That item is clearly not in the room, whatever you were thinking." << endl;
            cout << "Want to take another item?" << endl;
            cin >> answer;
            }
            } //While loop ends.


            }

    while (Movement == 0){
        cout << "Anyway, you turn back towards the center of the room. Which direction do you want to go (w/a/s/d)?" << endl;                          //Movement command
        cin >> Move;
        if (Move == 'w'){
            cout << "You run into a wall." << endl;
        }
        else if (Move == 'a'){
            cout << "You stare at the old sets of armor." << endl;
        }
        else if (Move == 'd'){
            Movement = 1;
            Entrance(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
        }
        else if (Move == 's'){
            cout << "You inspect the rest of the worn weaponry, nothing else seems to be useful." << endl;
        }
        else {
            cout << "You go nowhere." << endl;
            Movement = 0;
        }
    }
}

/* Function Name: CryptRoom
 *
 * Function Description:
 * This function runs the crypt room portion of the map. Inside this crypt, the player can retrieve a torch needed for later exploration, but must fight a skeleton.
 *
 *
 * Parameters:
 * Note: Virtually all of our functions have the same parameters, which will be described in depth in the following. The majority of them are items which the player may collect, statuses of enemies, whether or not doors are open, and secrets.
 * The Sword parameter is to tell if the player has obtained the sword item, and carries it with them. The sword is required, and can be used in combat, or to explore.
 * The Spear parameter is to tell if the player has obtained the spear item, and carries it with them. The spear is optional, but is a great combat weapon that makes fighting easier. Cannot be used to explore generally.
 * The Shield parameter is to tell if the player has obtained the shield item, and carries it with them. The shield is required, and though it provides little in the way of combat, is useful for exploring.
 * The Torch parameter is to tell if the player has obtained the torch item, and carries it with them. The shield is required. While not a traditional weapon, it will see some limited use in combat, and is useful when exploring.
 * The Armor parameter is basically our health system. Armor is a number starting at 1 that allows the player to absord damage. When the player hits zero armor, then the next hit will be fatal. Additional armor can be found in the temple.
 * The FirstHalf parameter is to tell if the player has picked up the first half of the final coin, which is represented by the Sun Coin in the game. Required for exploration, but nothing else.
 * The SecondHalf parameter is to tell if the player has picked up the second half of the final coin, which is represented by the Moon coin in the game. Required for exploration but nothing else.
 * The Coin paremter is to tell if the player has collected both halves of the coin, and thus completed the seal needed for victory.
 * The Key parameter is to tell if the player has collected a key, which may have some value in exploring the world(hint/spoiler: It won't, a red herring).
 * The Boar parameter is to tell if the player has obtained the golden boar, and with it, soaring victory
 * The Hydra parameter is to tell if the player is aware of the Hydra lurking in the depths of the temple
 * The complete parameter is to tell if the player has sucesfully answered the first of the riddles presented in the riddle room.
 * The complete2 parameter is to tell if the player has sucessfully answered the second of the riddles presented in the riddle room.
 * The VisitPK parameter is to tell if the player has answered the optional riddle and can visit PK in the easteregg room.
 * The boargatecheck parameter is to tell if the player has investigated the boar vessel room's gate, and knows what to look for.
 * The boargateopen parameter is to tell if the player has opened the boar vessel room's gate.
 * The vineopen parameter is to tell if the player has unlocked the vine door
 * The pearlopen parameter is to tell if the player has unlocked the pearl door.
 * The victory parameter is to tell if the player has achieved victory.
 *
 *
 * return value:
 * The return value here is a simple return function used when the skeleton kills the player.
 */
void CryptRoom(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory){
        string Torchyesorno;
        string action;
        int Movement = 0;
        char Move = 'n';

        cout << "You step into the long chamber, the stench of long since decayed corpses and paltry embalming fumes covers your nose. This must be the crypt" << endl;                   //First entry into the crpyt
        if (Torch == 0) //If the Torch hasnt been grabbed yet
               {
            cout << "You notice in the back of the room, a bright Torch shines, a bright orange flame burning deeply within its heart. Just before it lies a singular coffin, half ajar and filled with darkness." << endl;
            cout << "The coffin unnerves you, but that Torch has been the only really solid lightsource youve seen in this place." << endl;
            cout << "Do you dare try to grab it? (y/n)";
            cin >> Torchyesorno;                                                                                                                     // Asks if the user wants to advance on the torch

            while (Torchyesorno != "y" && Torchyesorno != "n")                                                                                  // Ensures there is a yes or no answer
               {
                cout << "Come on adventurer. That isnt a yes or a no. Do you want to take the Torch?" << endl;
                cin >> Torchyesorno;
               } // ends the checking yes or no loop

            if (Torchyesorno == "y")
               {
             cout << "Steeling yourself, you approach the Torch, and by proxy, the coffin in front of it." << endl;
             cout << "As you get near the half open sarcophogus, you are soon suprised and thrown back by the skeletal horror that emerges from it." << endl;
             cout << "An old fallen Etruscan warrior, still weilding his rust covered bronze Sword, emerges from the coffin to bar your path!" << endl;
             cout << "What then do you do? It is clear that this skeleton will not budge, he guards the ornate Torch with unwavering fervor. " << endl;
             cin >> action;
             while ((action != "Sword" && Sword == 0) && (action != "Spear" && Spear == 0) && (action != "run"))
               {
                 Armor -= 1;
                 cout << "That failed, and in the attempt, the skeleton scores a blow upon you." << endl;
                 if (Armor < 0)
               {
                     cout << "With no Armor to protect you any further, the blade finally scores home, and the skeleton cuts you down where you stood." << endl;                                     //Player dies to skeleton
                     cout << "As your life leaves your body, you curse yourself for your inaction. Had you fought back or even ran, you could have the boar vessel!" << endl;
                     cout << "Regardless, you fall in battle as a warrior." << endl;
                     victory = 1;
                     return;
               }
                 else
               {
                     cout << "That was a close one. You are lucky you didnt skimp on youre Armor." << endl;
                     cout << "But as your Armor falls away, you realize now is NOT the time for inaction. You think you should either fight back or run." << endl;
                     cout << "What do you do? What item do you use or action do you take? ";
                     cin >> action;
               }




                }
             if (action == "Sword" && Sword == 1)
               {
              int Swordchance = rand() % 1 + 2;                                                                                                              //1 out of 2 chance using the Sword wounds you
              cout << "You get in close to use the short blade, and get in close to your enemy!" << endl;
              cout << "You score a hit, and succesfully cut down your accursed foe!" << endl;

              if (Swordchance == 1)                                                                                                                          //Roll failed, you get wounded.
              {   Armor -= 1;
                  cout << "The close proximity of the fighting saw you take a blow from the skeleton as well, unfortunatley." << endl;
                  if (Armor < 0)
              {
                      cout << "Though you felled the dread skeleton warrior, you were too brash in your offensive. You fall, bleeding out from your wound." << endl;
                      cout << "You died as a warrior, and there is some honor in that, but the boar vessel eludes your grasp, further buried, its glory hidden everymore." << endl;
                      victory = 1;
                      return;
              }
                  else
              {
                   cout << "That was a close one. You ought to be more careful, you think, as you see another layer of Armor fall off." << endl;
                   cout << "With the skeletal horror dealt with, you march toward the Torch, its ornate scone holding a blaze of incredible power." << endl;
                   cout << "Gently, you reach out and grab the Torch, its handle suprisingly cold considering its warmth." << endl;
                   Torch = 1;
              }
              }
            else if (Swordchance == 2)                                                                                                                       //roll succede. Not wounded
              {
                  cout << "That was close. You were dextrous enough to dodge the fiends strikes, even in close quarters." << endl;
                  cout << "With the skeletal horror dealt with, you march toward the Torch, its ornate scone holding a blaze of incredible power." << endl;
                  cout << "Gently, you reach out and grab the Torch, its handle suprisingly cold considering its warmth." << endl;
                  Torch = 1;
              }

              }

             else if (action == "Spear" && Spear == 1)                                                                                                        //No risk using the spear. The reach keeps you safe
              {
                cout << "Using the superior reach of the Spear, you quite easily impale and destroy your skeletal foe." << endl;
                cout << "No damage comes to you, thanks to the enormous reach of the weapon compared to the pitiful bronze Sword of the skeleton." << endl;
                cout << "With the skeletal horror dealt with, you march toward the Torch, its ornate scone holding a blaze of incredible power." << endl;
                cout << "Gently, you reach out and grab the Torch, its handle suprisingly cold considering its warmth." << endl;
                Torch = 1;                                                                                                                                    //Pick up the torch
             }

             }


        } //Torch hasnt been grabbed loop ends

        else if (Torch == 1)                                                                                                                                 //Already killed the skeleton and grabbed the torch. Useless room now
        {
            cout << "You investigate the room around you, the old crypt where you felled the skeleton warrior and retrieved the Torch." << endl;
            cout << "Now apperant thanks to the amazingly bright light of the Torch, you quickly discern that nothing of interest is in this crypt." << endl;

        }

        while (Movement == 0){                                                                                                                               //Movement command
            cout << "Satisfied, you turn around towards the exit of the crypt. Which way do you want to go next? (w/a/s/d)" << endl;
            cin >> Move;
            if (Move == 'w'){
                cout << "You walk into a wall." << endl;
            }
            else if (Move == 'a'){
                Entrance(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
            }
            else if (Move == 'd'){
                cout << "You stare at some very old graves. Spooky. Yet you feel disrespectful." << endl;
            }
            else if (Move == 's'){
                cout << "You stare at more graves. More spooky. Old Etrusca truly has fallen. Slightly sad sight." << endl;
            }
            else {
                cout << "You go nowhere." << endl;
                cout << "As you have been told, w/a/s/d. Not a hard trip, adventurer.";
                Movement = 0;
            }
        }
}

/* Function Name: MainRoom
 *
 * Function Description:
 * This function runs when the player enters the main room of the temple, in the center of the map. This function serves as a "nexus" of sorts for the temple.
 * It has 3 doorways locked in each direction, and the main goal of the whole temple is behind the central gate. The player must investigate and open all these doors at some point.
 *
 * Parameters:
 * Note: Virtually all of our functions have the same parameters, which will be described in depth in the following. The majority of them are items which the player may collect, statuses of enemies, whether or not doors are open, and secrets.
 * The Sword parameter is to tell if the player has obtained the sword item, and carries it with them. The sword is required, and can be used in combat, or to explore.
 * The Spear parameter is to tell if the player has obtained the spear item, and carries it with them. The spear is optional, but is a great combat weapon that makes fighting easier. Cannot be used to explore generally.
 * The Shield parameter is to tell if the player has obtained the shield item, and carries it with them. The shield is required, and though it provides little in the way of combat, is useful for exploring.
 * The Torch parameter is to tell if the player has obtained the torch item, and carries it with them. The shield is required. While not a traditional weapon, it will see some limited use in combat, and is useful when exploring.
 * The Armor parameter is basically our health system. Armor is a number starting at 1 that allows the player to absord damage. When the player hits zero armor, then the next hit will be fatal. Additional armor can be found in the temple.
 * The FirstHalf parameter is to tell if the player has picked up the first half of the final coin, which is represented by the Sun Coin in the game. Required for exploration, but nothing else.
 * The SecondHalf parameter is to tell if the player has picked up the second half of the final coin, which is represented by the Moon coin in the game. Required for exploration but nothing else.
 * The Coin paremter is to tell if the player has collected both halves of the coin, and thus completed the seal needed for victory.
 * The Key parameter is to tell if the player has collected a key, which may have some value in exploring the world(hint/spoiler: It won't, a red herring).
 * The Boar parameter is to tell if the player has obtained the golden boar, and with it, soaring victory
 * The Hydra parameter is to tell if the player is aware of the Hydra lurking in the depths of the temple
 * The complete parameter is to tell if the player has sucesfully answered the first of the riddles presented in the riddle room.
 * The complete2 parameter is to tell if the player has sucessfully answered the second of the riddles presented in the riddle room.
 * The VisitPK parameter is to tell if the player has answered the optional riddle and can visit PK in the easteregg room.
 * The boargatecheck parameter is to tell if the player has investigated the boar vessel room's gate, and knows what to look for.
 * The boargateopen parameter is to tell if the player has opened the boar vessel room's gate.
 * The vineopen parameter is to tell if the player has unlocked the vine door
 * The pearlopen parameter is to tell if the player has unlocked the pearl door.
 * The victory parameter is to tell if the player has achieved victory.
 *
 *
 * return value:
 * This function does not have a return value, as it is a void function, and the player cannot die in this room.
 */
void MainRoom(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory)
{


    string door;
    string dooryesorno;
    string action;
    string itemyesorno;
    string firstitemyesorno;
    string seconditem;
    string seconditemyesorno;
    string boargateyesorno;

    cout << "At first glance, the enormous main room seems empty. Strangely, there is virtually nothing on the floor of the darkened room." << endl;                                     //Text for entering the room
    cout << "You look around the room and discover that there are 3 large doors, each in the middle of their respective walls." << endl;
    cout << "The door on the western wall is a large door with a gleaming pearl dome in the center of it, and some strange inscription on the wall." << endl;
    cout << "The northern door seems to be a large metal gate that has been slammed shut." << endl;
    cout << "Lastly, an enormous hole covered and criss crossed by vines lays in the center of the eastern wall." << endl;

    cout << "Would you like to investigate any of these passage ways? (y/n). " << endl;                                                                                                 //Asks the user if they want to check out a door
    cin >> dooryesorno;

    //Ensures its a yes or no answer.
    while (dooryesorno != "y" && dooryesorno != "n")
             {
        cout << "Come on adventurer, not that hard. Yes or no question here. " << endl;
        cout << "Once more, would you like to investigate one of the doors? Yes or no. " << endl;
        cin >> dooryesorno;
             }
    while (dooryesorno == "y")
             {

                                                                                                                                                       //Asks the user for the gate.
    cout << "Well, ok then. Perhaps investigate a door. Which door? pearl, gate, or vine. Or exit, if none excite you. " << endl;
    cin >> door;

                                                                                                                                                      //Ensures that the choice is one of the 3 gates.
    while (door != "pearl" && door != "gate" && door != "vine" && door != "exit")
             {
        cout << "That isnt one of the gates. Like I said before, pearl, gate, or vine. Try again. " << endl;
        cin >> door;
             }

    if (door == "pearl")
             {
        cout << "You approach the mighty pearl door. It is guilded and engraved with all manner of Etruscan art." << endl;                                               //Pearl door
        cout << "As you of course noticed first, there is a massive pearl dome, larger than any you'd ever seen before, bulging from the center." << endl;
        cout << "You also note that the inscription states something really strange in Etruscan. A few moments and you translate it." << endl;
        cout << "It says, 'Only the light of apollo's holy Shield may open this barrier. It's gleam is all that will open this way.'" << endl;
        cout << "Cryptic. Weird people those Etruscans." << endl;
        cout << "Well, what do you want to do about this? Want to use an item?(y/n)" << endl;
        cin >> itemyesorno;
        //Makes sure the player enters yes or no
        while (itemyesorno != "y" && itemyesorno != "n")
             {
            cout << "Come on adventurer, not that hard. Yes or no question here. " << endl;
            cout << "Once again, do you want to use an item?" << endl;
            cin >> itemyesorno;
             }
        while (itemyesorno == "y" && pearlopen != 1)
             {
        cout << "What Item do you want to use? " << endl;                                                                           //Choosing an item to use, if any
        cin >> action;
        while (!(action == "Shield" && Shield == 1)) {
            cout << "That seemed to have no effect, or you didn't have the item. Great." << endl;
            cout << "Want to try another item?" << endl;
            cin >> itemyesorno;

             }
        if (action == "Shield" && Shield == 1)
             {
         cout << "Got it! The Shield of apollo! You need to use the Shield. But what other item do you want to use with it? " << endl;
         cin >> seconditem;
         while (!(seconditem == "Torch" && Torch == 1))
             {
             cout << "Nothing happens. Must not have been the right combination." << endl;
             cout << "Want to try another item? " << endl;
             cin >> seconditemyesorno;
             while (seconditemyesorno != "yes" && seconditemyesorno != "no")
             {
                 cout << "Come on adventurer, yes or no question. Do you want to try another item? " << endl;
                 cin >> seconditemyesorno;
             }
             } //Use / have Torch While loop closes

          if (seconditem == "Torch" && Torch == 1)
             {
              cout << "You flash the Torches light onto the glossing Shield. All of a sudden, a huge and strong beam of light pierces through it!" << endl;
              cout << "The light shines into the half pearl, and the gate swings open. The path beyond is now open to you." << endl;

               pearlopen = 1;                                                                                                                                   //Opens the pearl gate. You can travel there now

             } //Success if loop closes.

             } //If action closes


             }

             } //Pearl door nest closes


    if (door == "gate")
             {
        cout << "You approach the grand iron gate. All around it are markings from old Etrusca, about the story of their civlization. " << endl;
        cout << "And just beyond the gate, you see it glittering!" << endl;
        cout << "The golden Etruscan boar vessel! The reason you came to this misbegotten and ruined civilization." << endl;
        cout << "Yet the gate will not budge, not an inch." << endl;
        cout << "Closer inspection reveals a circular slot, roughly the size of a large coin, to the right of the door." << endl;
        boargatecheck = 1;
        cout << "Would you like to use an item? (y/n) " << endl;
        cin >> itemyesorno;
        //Makes sure the player enters yes or no
        while (itemyesorno != "y" && itemyesorno != "n")
             {
            cout << "Come on adventurer, not that hard. Yes or no question here. " << endl;
            cout << "Once again, do you want to use an item?" << endl;
            cin >> itemyesorno;
             }
        while (itemyesorno == "y" && boargateopen != 1)
             {
        cout << "What Item do you want to use? " << endl;                                                                           //Choosing an item to use, if any
        cin >> action;
        while (!(action == "sun_coin" && FirstHalf == 1)) {
            cout << "That seemed to have no effect, or you didn't have the item. Great." << endl;
            cout << "Want to try another item?" << endl;
            cin >> itemyesorno;

             }
        if (action == "sun_coin" && FirstHalf == 1)
             {
         cout << "Eureka! The sun coin slides in fine. " << endl;
         cout << "Try another item, or exit to leave this." << endl;
         cin >> seconditem;
         if (seconditem == "exit")
             {
             cout << "You collect the first coin and step back." << endl;
             break;
             }
         while (!(seconditem == "moon_coin" && SecondHalf == 1))
             {
             cout << "Nothing happens. Must not have been the right combination." << endl;
             cout << "Want to try another item? " << endl;
             cin >> seconditemyesorno;
             while (seconditemyesorno != "yes" && seconditemyesorno != "no")
             {
                 cout << "Come on adventurer, yes or no question. Do you want to try another item? " << endl;
                 cin >> seconditemyesorno;
             }
             } //Use / have Torch While loop closes

          if (seconditem == "moon_coin" && SecondHalf == 1)
             {
              cout << "You fit the moon coin into the other half of the seal, and the gate swings open!" << endl;
              cout << "Scones quickly light up the room ahead of you, and the open passage beckons you!" << endl;
              boargateopen = 1;
              break;
                                                                                                                                                 //Opens the pearl gate. You can travel there now

             } //Success if loop closes.

             } //If action closes


             }

             }
    else if (door == "vine" && vineopen != 1)
            {

                    cout << "The vine vines that coat the passage way are thick and block all movement forward." << endl;                                 //Vine door opening.
                    cout << "Try as you might, you cannot possibly enter through the thick foliage." << endl;
                    cout << "How could you get through that, you wonder." << endl;
                    cout << "Perhaps an item?" << endl;
                    cout << "Would you like to use an item? (y/n). " << endl;;
                    cin >> itemyesorno;
                    while ((itemyesorno != "y" && itemyesorno != "n"))
            {

                    cout << "Adventurer, that wasn't a yes or no. Lets try this again." << endl;
                    cout << "Would you like to use an item?" << endl;
                    cin >> itemyesorno;

             } //Check while loop ends

                    while (itemyesorno == "y" || vineopen == 0)

             {
                        if (vineopen != 1){
                        cout << "What item would you like to try?" << endl;
                        cin >> action;
                        }
                        if (action != "Sword" || Sword != 1)
             {
                            cout << "That item had no effect. Perhaps try another?" << endl;
                            cout << "Would you like to try another item?" << endl;
                            cin >> itemyesorno;
             }
                        else if (action == "Sword" && Sword == 1)
             {
                            cout << "You slash down the vines that bar your way. The passage now lies open, and the darkness beyond it." << endl;
                            vineopen = 1;
                            break;
             }

             }


             }
    else if (door == "vine" && vineopen == 1)                           //If the vinegates and pearl gates are already open
             {

        cout << "The pile of vines, freshly cut by the edge of your bronze blade, lays directly in front of the door." << endl;
        cout << "You accomplish virtually nothing, standing there observing the pile of cut greenery." << endl;
        break;



             }


    else if (door == "pearl" && pearlopen == 1)
            {
        cout << "You stand before the pearl gate, now open and ajar." << endl;
        cout << "Confused as to why you chose to just stare at an open door, you ponder your life briefly." << endl;

            }




    else if (door == "exit")                                                                         //Runs if the player chooses exit
             {
        cout << "You dont choose any gate." << endl;
        break;
             }
             } //The initial check door loop closes here
            cout << "Satisfied, you leave whatever you were doing and turn around." << endl;
            cout << "You head back from where you came. You stand once more in the dead center of the room." << endl;

    int Movement = 0;
    char Move = 'n';
    while (Movement == 0){
        cout << "Which way would you like to travel next? (w/a/s/d): " << endl;
        cin >> Move;
        if (Move == 'w'){
            Movement = 1;               // Move into Entrance Room
            Entrance(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
        }
        else if (Move == 'a' && vineopen == 1){
            Movement = 1;               // Move into Coin Room
            CoinRoom(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
        }
        else if (Move == 'a'){
            cout << "You attempt to peak through the vines to get a glimpse of the other side, but to no avail." << endl;
            cout << "The gate is shut and locked down. Walking into it will yield no results." << endl;
        }
        else if (Move == 'd' && pearlopen == 1){              // Move into Riddle room
            Movement = 1;
            Riddle(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
        }
        else if (Move == 'd'){
            cout << "You stare at the magnificent pearl door. It stands as immovable and peculiar as ever" << endl;
            cout << "You dont know what you hope to accomplish by walking into the thing." << endl;
        }
        else if (Move == 's' && FirstHalf == 1 && SecondHalf == 1 && boargateopen == 1 && boargatecheck == 1){              // Move into Boar room
            BoarVesselRoom(Armor, Spear, victory);
        }
        else{
            cout << "You go nowhere." << endl;
            cout << "Come now adventurer. w/a/s/d. Cardinal directions. Are you addled in the head?" << endl;
            Movement = 0;
        }
    }
}

/* Function Name: Riddle
 *
 * Function Description:
 * This function simulates the riddle room behind the pearl gates to the right of the main room. In this room, the player must answer atleast 2 difficult riddles, and will be rewarded for doing so.
 * The third riddle is optional, but opens up the secret room, which will grant the player a great boon.
 *
 * Parameters:
 * Note: Virtually all of our functions have the same parameters, which will be described in depth in the following. The majority of them are items which the player may collect, statuses of enemies, whether or not doors are open, and secrets.
 * The Sword parameter is to tell if the player has obtained the sword item, and carries it with them. The sword is required, and can be used in combat, or to explore.
 * The Spear parameter is to tell if the player has obtained the spear item, and carries it with them. The spear is optional, but is a great combat weapon that makes fighting easier. Cannot be used to explore generally.
 * The Shield parameter is to tell if the player has obtained the shield item, and carries it with them. The shield is required, and though it provides little in the way of combat, is useful for exploring.
 * The Torch parameter is to tell if the player has obtained the torch item, and carries it with them. The shield is required. While not a traditional weapon, it will see some limited use in combat, and is useful when exploring.
 * The Armor parameter is basically our health system. Armor is a number starting at 1 that allows the player to absord damage. When the player hits zero armor, then the next hit will be fatal. Additional armor can be found in the temple.
 * The FirstHalf parameter is to tell if the player has picked up the first half of the final coin, which is represented by the Sun Coin in the game. Required for exploration, but nothing else.
 * The SecondHalf parameter is to tell if the player has picked up the second half of the final coin, which is represented by the Moon coin in the game. Required for exploration but nothing else.
 * The Coin paremter is to tell if the player has collected both halves of the coin, and thus completed the seal needed for victory.
 * The Key parameter is to tell if the player has collected a key, which may have some value in exploring the world(hint/spoiler: It won't, a red herring).
 * The Boar parameter is to tell if the player has obtained the golden boar, and with it, soaring victory
 * The Hydra parameter is to tell if the player is aware of the Hydra lurking in the depths of the temple
 * The complete parameter is to tell if the player has sucesfully answered the first of the riddles presented in the riddle room.
 * The complete2 parameter is to tell if the player has sucessfully answered the second of the riddles presented in the riddle room.
 * The VisitPK parameter is to tell if the player has answered the optional riddle and can visit PK in the easteregg room.
 * The boargatecheck parameter is to tell if the player has investigated the boar vessel room's gate, and knows what to look for.
 * The boargateopen parameter is to tell if the player has opened the boar vessel room's gate.
 * The vineopen parameter is to tell if the player has unlocked the vine door
 * The pearlopen parameter is to tell if the player has unlocked the pearl door.
 * The victory parameter is to tell if the player has achieved victory.
 *
 *
 * return value:
 * This function does not have a return value, as it is a void function, and the player cannot die in this room.
 */
void Riddle(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory){                               // Room that asks player 3 riddles
    string Riddle1;
    string Riddle2;
    string Riddle3;
    char Answer3 = 'n';
    char Answer0 = 'n';
    char Move;
    bool Movement = 0;
    bool Fail = 0;

    if (Complete2 == 0){
        cout << "You march through the pearled arch, now thrown ajar by the grace of apollo, and come into a smaller side room." << endl;                          //Basically a giant nested loop confirming the player hasnt completed the second riddle yet
        cout << "In the center of this room, stands a peculiar podium. On its surface lies a book, with some Etruscan scribbling on the cover." << endl;
        cout << "The walls around you are absoltuley coated with engravings and stories from Etruscan myth." << endl;
        cout << "You open the Etruscan book, and see in the center of the otherwise blank pages, strange golden letters light up." << endl;
        cout << "A deep and gravely voice lightens up the room, speaking, strangley, in the modern tongue." << endl;
        cout << "'Brave adventurer, to be worthy of the boar, one must not only be strong, but wise.'" << endl;
        cout << "'Would you like to answer our riddles?'" << endl;
        cin >> Answer0;                                                                                                                                     //Asks the user yes or no if they want to answer a riddle, ensures its only yes or no.
        while (Answer0 != 'y' && Answer0 != 'n'){
            cout << "It's a yes or no question..." << endl;
            cout << "Do you want to answer the riddle? (y/n)" << endl;
            cin >> Answer0;
        }
        if (Answer0 == 'y'){
            cout << "The voice continues, 'I see you have decided to accept the challenge. Very well.'" << endl;
            cout << "My first riddle to prove your wisdom, is a classic, from the annals of old Etrusca. State your answer, in one word, adventurer.'" << endl;
            cout << "'Of all the beasts on earth, this one is unqiue. What walks on four legs in the morning, two legs in the afternoon, and three legs in the evening?'" << endl;                                                               // First Riddle
            cin >> Riddle1;
            if (Riddle1 == "Man" || Riddle1 == "man"){
                cout << "You hear the voice say, 'You have answered correctly. Well done, Adventurer. Perhaps you are wise enough to find the boar yet.'" << endl;
                cout << "The voice declares, 'The second riddle is harder than the first. Prepare yourself.'" << endl;
                cout << "'This thing all things devours. Birds beasts, trees, flowers.'" << endl;
                cout << "Gnaws iron, bites steel. Grinds hard stones to meal. Slays Kings, ruins town. And beats mountain down.'" << endl;                                               // Second Riddle
                cin >> Riddle2;
            }
            else if (Riddle1 != "Man" || Riddle1 != "man"){
                cout << "The upset voice shouts at you, 'FALSE! This is not correct, foolish adventurer. You must leave and come back another time if you wish to try again.'" << endl;
                Fail = 1;
            }
                if (Riddle2 == "Time" || Riddle2 == "time"){
                    cout <<"'As ever, you are correct, brave adventurer. Your wisdom is truly awe inspiring. For Time, is the threat none can escape.'" << endl;
                    cout << "'As a reward for your great forsight, accept this gift. A new chestplate, of the finest Etruscan bronze. You will need this, I think.'" << endl;
                    Armor = 1;
                    Complete2 = 1;
                }
                else if ((Riddle2 != "Time" || Riddle2 != "time") && Fail == 0){
                    cout << "'No, foolish adventurer! You were showing promise for a while there. Leave this room, you may only attempt the riddles of fate again once you re-enter.'" << endl;
                    Fail = 1;
                }
        }
        else if (Answer0 == 'n' && Fail == 0 && Complete2 == 0 && Complete == 0){
            cout << "You decide ignore the voice and stand in the room. You dont have time for magic Etruscan freaks." << endl;
        }
    }
                if (Complete == 0 && Complete2 == 1){                                                                                                                                   //Third riddle
                cout << "Once more the voice booms. 'Adventurer, though you may advance on, there is one final riddle. Optional, if you will. Will you attempt it?' (y/n)" << endl;
                cin >> Answer3;
                }
                while ((Answer3 != 'y' && Answer3 != 'n') && Complete == 0){
                    cout << "'It is a yes or no question, whelp. I ask again..." << endl;
                    cout << "Will thou attempt the final riddle? (y/n)" << endl;
                    cin >> Answer3;
                }
                if (Answer3 == 'y'){
                    cout << "The voice yells, the sound echoing throughout the room. 'The final riddle is: " << endl;
                    cout << "This thing tears apart others, ripping itself apart, yet keeping itself together. It crawls throughout its life, " << endl;
                    cout << "yet appears strong to the world. It angers the young, yet the old take pride in it. A freshly laid curse, only the young suffer its cruelty. What is it?'" << endl;                                         // Optional Third Riddle
                    cin >> Riddle3;
                    if (Riddle3 == "ENED" || Riddle3 == "Ened" || Riddle3 == "ened"){
                        cout << "'Congratulations traveller. You have passed the final riddle. Well then, adventurer, come meet me in person.' The voice says, the sound fading out." << endl;
                        cout << "You suddendly hear a loud scraping sound begind you. You turn around and see the wall opening." << endl;
                        cout << "It appears that a secret door to the south has been revealed." << endl;
                        PK = 1;
                        Complete = 1;

                }
                    else if((Riddle3 != "ENED" || Riddle3 != "Ened" || Riddle3 != "ened") && Fail == 0){
                        cout << "The upset voice shouts at you, 'You have failed the riddle! You must leave and come back another time if you wish to try again. Dont be hard on yourself, this IS the ultimate challenge of wisdom.'" << endl;

                }
                }
                else if (Answer3 == 'n' && Complete2 == 1 && Complete == 0){
                    cout << "You decide to ignore the voice and stand there with your new armor. Optional? Yeah, as if you want more work." << endl;

                }
    while (Movement == 0)
                {
        cout << "This appears to be the riddle room. Which way would you like to go next? (w/a/s/d): " << endl;                                                  //Movement command
        cin >> Move;
        if (Move == 'w')
                {
            cout << "You run into a wall. You knew full well what you were doing. Why would you do that? Are you ill?" << endl;
                }
        else if (Move == 'a')
                {
            Movement = 1;
            MainRoom(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
                }
        else if (Move == 'd')
                {
            cout << "You bash your head against a wall. Perhaps you aren't a noble adventurer. That was just stupid." << endl;
                }
        else if (Move == 's')
                {
            if (PK == 1)
                {
                Movement = 1;
                PKRoom(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
                }
            else 
                {
                cout << "You stare at an odd looking wall. Engravings stop abruptly in a square pattern, indicating there must be a door there. But, it is only stone." << endl;
                cout << "Either a secret door lies there, or you are truly losing it." << endl;
                }
                }
        else 
                {
            cout << "You go nowhere." << endl;
            Movement = 0;
        }
    }
}

/* Function Name: PKRoom
 *
 * Function Description:
 * This function solves to simulate the secret room. In this function and by proxy room, the player will simply be granted a gift, notifying them of the existence of a hydra and saving them the damage taken by that encounter.
 *
 * Parameters:
 * Note: Virtually all of our functions have the same parameters, which will be described in depth in the following. The majority of them are items which the player may collect, statuses of enemies, whether or not doors are open, and secrets.
 * The Sword parameter is to tell if the player has obtained the sword item, and carries it with them. The sword is required, and can be used in combat, or to explore.
 * The Spear parameter is to tell if the player has obtained the spear item, and carries it with them. The spear is optional, but is a great combat weapon that makes fighting easier. Cannot be used to explore generally.
 * The Shield parameter is to tell if the player has obtained the shield item, and carries it with them. The shield is required, and though it provides little in the way of combat, is useful for exploring.
 * The Torch parameter is to tell if the player has obtained the torch item, and carries it with them. The shield is required. While not a traditional weapon, it will see some limited use in combat, and is useful when exploring.
 * The Armor parameter is basically our health system. Armor is a number starting at 1 that allows the player to absord damage. When the player hits zero armor, then the next hit will be fatal. Additional armor can be found in the temple.
 * The FirstHalf parameter is to tell if the player has picked up the first half of the final coin, which is represented by the Sun Coin in the game. Required for exploration, but nothing else.
 * The SecondHalf parameter is to tell if the player has picked up the second half of the final coin, which is represented by the Moon coin in the game. Required for exploration but nothing else.
 * The Coin paremter is to tell if the player has collected both halves of the coin, and thus completed the seal needed for victory.
 * The Key parameter is to tell if the player has collected a key, which may have some value in exploring the world(hint/spoiler: It won't, a red herring).
 * The Boar parameter is to tell if the player has obtained the golden boar, and with it, soaring victory
 * The Hydra parameter is to tell if the player is aware of the Hydra lurking in the depths of the temple
 * The complete parameter is to tell if the player has sucesfully answered the first of the riddles presented in the riddle room.
 * The complete2 parameter is to tell if the player has sucessfully answered the second of the riddles presented in the riddle room.
 * The VisitPK parameter is to tell if the player has answered the optional riddle and can visit PK in the easteregg room.
 * The boargatecheck parameter is to tell if the player has investigated the boar vessel room's gate, and knows what to look for.
 * The boargateopen parameter is to tell if the player has opened the boar vessel room's gate.
 * The vineopen parameter is to tell if the player has unlocked the vine door
 * The pearlopen parameter is to tell if the player has unlocked the pearl door.
 * The victory parameter is to tell if the player has achieved victory.
 *
 *
 * return value:
 * This function does not have a return value, as it is a void function, and the player cannot die in this room.
 */
void PKRoom(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory){                                   // Room with PK who informs player of Hydra
    bool Movement = 0;
    char Move;

    if (VisitPK == 0){
        cout << "You enter the secret room and find a man standing in the corner. His hair is white as snow, and his face covered in wrinkles and marks of time and stress." << endl;
        cout << "He is wearing some strange clothing that you have never seen before, anywhere in the whole empire." << endl;
        cout << "He slowly turns around, holding what looks to be some sort of toy, with the words 'MIND STORM' written across it. 'I have an assumption for you.' He says sternly." << endl;
        cout << "'Using my personal problem presentation method, I have concoted a brilliant thesis to help you, brave adventurer." << endl;
        cout << "Given this is a Eutruscan tomb, then there must be several aspects related to...'" << endl;
        cout << "He continues on for about an hour or so until finally he finishes with, '...and that's why there must be a Hydra in one of the rooms.'" << endl;
        cout << "'Yes, that is my gift to you. Approach every room with caution, for one must surley house a Hydra. Afterall, the Etruscan hydra is a proud and rare beast, native only to..." << endl;
        cout << "Before he can finish the statement, a MATLab code appears out of nowhere and quickly runs through thousands of lines of code." << endl;
        cout << "The man disappears, along with the code. His laughter can be heard as the MATLab code swirls away, shuffling him off to some strange foreign land." << endl;
        Hydra = 1;
        VisitPK = 1;
    }
    else {
        cout << "You enter the room that had the strange appearance and disappearance of a man who informed you of the hydra." << endl;
        cout << "Nothing appears to be in this room. It was literally a blank slab of stone where the strange man sat and played with his odd 'MIND STORM' Toy." << endl;
    }

    while (Movement == 0){
        cout << "Which way would you like to go next? (w/a/s/d): " << endl;                                      //Movement command
        cin >> Move;
        if (Move == 'w'){
            Movement = 1;
            Riddle(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
        }
        else if (Move == 'a'){
            cout << "You walk into a wall for some reason. What are you doing?" << endl;
        }
        else if (Move == 'd'){
            cout << "You bash your head against a wall. Why do you persist, even when you know it is pointless?" << endl;
        }
        else if (Move == 's'){
            cout << "You look at the corner that the man was standing in. It seems to be just another corner. Like every other corner in this place. How did YOU pass the wisdom trials?!" << endl;
        }
        else{
            cout << "You go nowhere." << endl;
            Movement = 0;
        }
    }
}

void CoinRoom(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory){                 // Room with first half of seal to boar vessel
    char Answer = 'n';
    bool Movement = 0;
    char Move = 'n';
    cout << "You enter the coin room...giant door to south" << endl;
    if (Gate == 1 && FirstHalf != 1){                                                     // First Half of Seal to Boar Vessel Gate
        cout << "You enter the darkened room beyond the seemingly impassable wall of vines. This sword did the trick alright." << endl;
        cout << "Quite curiously, this room houses a large glass display case, with a singular velvet cushion in its center." << endl;
        cout << "Closer inspection reveals half of a large coin, this one emblazoned with the sun up its face." << endl;
        cout << "It feels noticebly hot to even be near." << endl;
        cout << "You seem to recall something roughly this shape, though twice as large..." << endl;
        cout << "The boar gate, that is it!" << endl;
        cout << "In your excitement, you smash open the glass, and reach your hand over the sun coin." << endl;
        cout << "Do you take up the strange token? (y/n): " << endl;
        cin >> Answer;
        while (Answer != 'y' && Answer != 'n'){
            cout << "It's a yes or no question. Pick it up or not. Come on already..." << endl;
            cout << "Pick it up? (y/n): " << endl;
            cin >> Answer;
        }
        if (Answer == 'y'){
            cout << "The coin's warmth radiates and pulsates in your calloused hands. It is a gentle thing, smooth and calming." << endl;
            cout << "You quickly slip the coin into a side pocket, and step back from the case." << endl;
            FirstHalf = 1;
        }
        else if (Answer == 'n'){
            cout << "A hot, ominous looking broken piece of junk? No thank you. How could this possibly assist you?" << endl;
            cout << "You ignore the broken piece of trash." << endl;
        }
    }
    else{
        cout << "You don't see anything valuable in the room. Only a display case with some piece of garbage in it." << endl;
    }
    while (Movement == 0){
        cout << "Which way would you like to go next? (w/a/s/d): " << endl;
        cin >> Move;
        if (Move == 'w'){
            cout << "You walk into a wall for some reason." << endl;
        }
        else if (Move == 'a'){
            cout << "You bash your head against a wall. Somewhat pathetically, might it be said." << endl;
        }
        else if (Move == 'd'){              // Move into Main room
            Movement = 1;
            MainRoom(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
        }
        else if (Move == 's'){              // Move into Hydra room
            Movement = 1;
            HydraRoom(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
        }
        else{
            cout << "You go nowhere." << endl;
            Movement = 0;
        }
    }
}

/* Function Name: HydraRoom
 *
 * Function Description:
 * This function solves to simulate the Hydra room the player may enter beyond the coin room. In this room, in order to retrieve the other half of the coin, they must fight a hydra.
 * The hydra is a powerful foe, who blocks retreat. It cannot be beaten only by ordinary combat, yet the player must fight it. Killing it yields the moon coin.
 *
 * Parameters:
 * Note: Virtually all of our functions have the same parameters, which will be described in depth in the following. The majority of them are items which the player may collect, statuses of enemies, whether or not doors are open, and secrets.
 * The Sword parameter is to tell if the player has obtained the sword item, and carries it with them. The sword is required, and can be used in combat, or to explore.
 * The Spear parameter is to tell if the player has obtained the spear item, and carries it with them. The spear is optional, but is a great combat weapon that makes fighting easier. Cannot be used to explore generally.
 * The Shield parameter is to tell if the player has obtained the shield item, and carries it with them. The shield is required, and though it provides little in the way of combat, is useful for exploring.
 * The Torch parameter is to tell if the player has obtained the torch item, and carries it with them. The shield is required. While not a traditional weapon, it will see some limited use in combat, and is useful when exploring.
 * The Armor parameter is basically our health system. Armor is a number starting at 1 that allows the player to absord damage. When the player hits zero armor, then the next hit will be fatal. Additional armor can be found in the temple.
 * The FirstHalf parameter is to tell if the player has picked up the first half of the final coin, which is represented by the Sun Coin in the game. Required for exploration, but nothing else.
 * The SecondHalf parameter is to tell if the player has picked up the second half of the final coin, which is represented by the Moon coin in the game. Required for exploration but nothing else.
 * The Coin paremter is to tell if the player has collected both halves of the coin, and thus completed the seal needed for victory.
 * The Key parameter is to tell if the player has collected a key, which may have some value in exploring the world(hint/spoiler: It won't, a red herring).
 * The Boar parameter is to tell if the player has obtained the golden boar, and with it, soaring victory
 * The Hydra parameter is to tell if the player is aware of the Hydra lurking in the depths of the temple
 * The complete parameter is to tell if the player has sucesfully answered the first of the riddles presented in the riddle room.
 * The complete2 parameter is to tell if the player has sucessfully answered the second of the riddles presented in the riddle room.
 * The VisitPK parameter is to tell if the player has answered the optional riddle and can visit PK in the easteregg room.
 * The boargatecheck parameter is to tell if the player has investigated the boar vessel room's gate, and knows what to look for.
 * The boargateopen parameter is to tell if the player has opened the boar vessel room's gate.
 * The vineopen parameter is to tell if the player has unlocked the vine door
 * The pearlopen parameter is to tell if the player has unlocked the pearl door.
 * The victory parameter is to tell if the player has achieved victory.
 *
 *
 * return value:
 * This function has a simple return used if the Hydra kills the player. Otherwise, there is no value to return.
 */
void HydraRoom(bool& Sword, bool& Spear, bool& Shield, bool& Torch, int& Armor, bool& FirstHalf, bool& SecondHalf, bool& Coin, bool& Boar, bool& Key, bool& Hydra, bool& Complete, bool& Gate, bool& Beginning, int& HydraAlive, bool& PK, int& Complete2, bool& VisitPK, bool& boargatecheck, bool& boargateopen, bool& vineopen, bool& pearlopen, bool& victory){
    string Fight;
    string Burn;
    int HydraLife = 1;
    char Answer = 'n';
    int Movement = 0;
    char Move = 'n';

    if (HydraAlive == 1){
        if (Hydra == 0){                                // Player gets attacked if they do not know about Hydra

            cout << "Your journey brings you onward, as you continue your trek into the temple. You head further through an enormous wooden and steel passage way." << endl;
            cout << "Before you can take but a single step, you hear it. A strange hissing sound, sinister and enrapped in venom." << endl;
            cout << "Swiftly as a crack of thunder, an enormous snake head slams at you, fangs barred!" << endl;
            cout << "It encases its fangs around you and bites, before throwing you back." << endl;
            Armor = Armor - 1;
            if (Armor < 0){
                cout << "With no armor to protect you, the fangs sink home, and quickly drain the life from your body." << endl;
                cout << "As you lay dying, you look up to see the enormous, skulking head of the dreaded Etruscan hydra, preparing to gorge itself on its new meal." << endl;
                cout << "So close. The boar vessel was so close!" << endl;
                cout << "And yet, so far. You died a hero's death, in battle, but soon you will become dinner." << endl;
                victory = 1;
                return;
            }
        }
        else if (Hydra == 1){                                   // Player doesn't get attacked if they know about the Hydra
            cout << "Just like the strange man said. You knew the hydra had to be in this room." << endl;
            cout << "You deftly dodge the onrushing serpeant head, and roll a few feet away, until you stand face to face with the beast itself." << endl;

        }
    }
    while (Armor >= 0 && HydraLife == 1 && HydraAlive == 1){
            cout << "Before you stands the mighty beast of legend, the Etruscan hydra!" << endl;
            cout << "Its enormous serpentine heads all come together on a leviathan 4 legged body, ripping with muscled scales and dried blood." << endl;
            cout << "One of its serpent heads immediatly shoots between you and the door, blocking all exit." << endl;
            cout << "It seems you have a fight on your hands, adventurer." << endl;
            cout << "What do you do?" << endl;
        cin >> Fight;
        if ((Sword == 1 || Spear == 1) && (Fight == "Sword" || Fight == "sword" || Fight == "Spear" || Fight == "spear")){                  // Player cuts off head of hydra
            cout << "With a fierce lunge and a hard swing of your weapon, the hydra's head is lopped off!" << endl;
            cout << "You strike a decisive blow, and its stump wavers back and forth, blood gushing from it in torrents." << endl;
            cout << "But this is no time to celebrate. You have seen a wild hydra before. It's head wont stay gone for long." << endl;
            cout << "Already you can see the stump growing back, a new head and skull forming from the scale in a grizzly and ghoulish process." << endl;
            cin >> Burn;
            if ((Torch == 1) && (Burn == "Torch" || Burn == "torch")){                                                        // Player burns the head of hydra and kills it
                cout << "Yet you are a wise one! You know the tried and true method of hydra slaying!" << endl;
                cout << "Before anything can grow back, you quickly grab the ornate torch and thrust it into the bloody stump of the hydra's neck!" << endl;
                cout << "Screams try to echo from it, but with no head to produce noise, it simply staggers back, the fire closing and cauterizing its neck, and killing any regrowth." << endl;
                cout << "After a final bout of flailing and pain, the beast simply goes limp, and drops completely dead upon the floor." << endl;
                HydraLife = HydraLife - 1;
                HydraAlive = 0;
            }
            else if ((Sword == 1 || Spear == 1) && (Burn == "Sword" || Burn == "sword" || Burn == "Spear" || Burn == "spear")){
                cout << "Seeing as the first time it worked so well, you swing at the hydra again." << endl;
                cout << "Though you take a chunk out of its neck, you realize it was largley in vain. The hydra's head has regrown, and it now turns to face you once more." << endl;
            }
            else{
                cout << "You fail to do anything useful. In your ineptitude and inaction, you have wasted your opportunity." << endl;
                cout << "The leviathan regrows it's head, as all hydra's do, and turns to face you again." << endl;
            }
        }
        else {                                      // Player gets attacked and loses 1 Armor
            cout << "You fail to accomplish something useful in the limited time, and the hydra pounces on your foolish inaction." << endl;
            cout << "Its serpentine head lashes out, and strikes at you with unrelenting fury!" << endl;
            Armor = Armor - 1;
        }
    }
    if (Armor < 0){
        cout << "Your armor thrown away and torn asunder, nothing is there to stop the hydra's onslaught. Its fangs hit home, and impale themselves in your chest." << endl;
        cout << "Your life quickly fades, and soon, life leaves your body." << endl;
        cout << "Death has embraced you, all without getting the boar vessel. Though you died with honor, it was truly an ignoble end. You are now hydra food." << endl;
        victory = 1;
        return;
    }
    if ((HydraLife == 0 || HydraAlive == 0) && SecondHalf == 0){
        cout << "Thanks to your bravery and skill of arms, the mighty hydra lays slain, its corpse festering in a pool of its own serpent blood." << endl;
        cout << "Just behind it, something on a pile of otherwise worthless and rusted luxury items catches your eye." << endl;
        cout << "Closer inspection reveals it to be half of a broken coin, much akin to the sun coin you found in the other room." << endl;
        cout << "This coin however, has a moon emblazoned on the front half, and had a chilly aura about it." << endl;
        cout << "Considering the circumstances, being guarded by a hydra and all, you have a distinct feeling this coin could be useful." << endl;
        cout << "Well then. Do you pick it up? (y/n)" << endl;           // Second half of boar gate seal
        cin >> Answer;
    }
    while (Answer != 'y' && Answer != 'n'){
        cout << "It's a yes or no question. You either pick the damn coin up or you dont. Come on!" << endl;
        cout << "Once again, because for some reason this needs to be asked twice, do you pick it up? (y/n)" << endl;
        cin >> Answer;
    }
    if (Answer == 'y'){
        cout << "You reach out and grab the moon coin." << endl;
        cout << "This coin seemed to have a chilling effect, and felt cold in your hand despite being in this damp and hot hydra lair." << endl;
        cout << "Regardless, you pocket the coin, and turn around." << endl;
        SecondHalf = 1;
    }
    else if ((Answer == 'n') && SecondHalf == 0){
        cout << "You don't pick it up and just stand there. The thing might have hydra posion on it, or some such. No thank you." << endl;
    }
    if (SecondHalf == 1){
        cout << "You are the room with the decapitated Hydra. Not exactly a pleasant sight. Nothing else of value seems to be here." << endl;
    }

    while (Movement == 0){                                                                  // Player movement from Hydra Room
        cout << "Which way would you like to go next? (w/a/s/d): " << endl;
        cin >> Move;
        if (Move == 'w'){
            Movement = 1;
            CoinRoom(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
        }
        else if (Move == 'a'){
            cout << "You bash your head against a wall. Seriously?" << endl;
        }
        else if (Move == 'd'){
            cout << "You walk into a wall for some reason. At this point, its getting painful." << endl;
        }
        else if (Move == 's'){
            cout << "You stare at the dead hydra and start to feel bad for it. It was locked up in here, starving to death." << endl;
            cout << "Everyone knows wild Etruscan hydra's need plenty of affection and free space to roam." << endl;
            cout << "Well, it's dead now regardless." << endl;
        }
        else{
            cout << "You go nowhere." << endl;
            Movement = 0;
        }
    }
}
/* Function Name: victoryroom
 *
 * Function Description:
 * This function serves to simulate the victory room. It only runs when the player grabs the boar vessel and claims victory. It also ends the game.
 * Parameters:
 * Note: Virtually all of our functions have the same parameters, which will be described in depth in the following. The majority of them are items which the player may collect, statuses of enemies, whether or not doors are open, and secrets.
 * The Sword parameter is to tell if the player has obtained the sword item, and carries it with them. The sword is required, and can be used in combat, or to explore.
 * The Spear parameter is to tell if the player has obtained the spear item, and carries it with them. The spear is optional, but is a great combat weapon that makes fighting easier. Cannot be used to explore generally.
 * The Shield parameter is to tell if the player has obtained the shield item, and carries it with them. The shield is required, and though it provides little in the way of combat, is useful for exploring.
 * The Torch parameter is to tell if the player has obtained the torch item, and carries it with them. The shield is required. While not a traditional weapon, it will see some limited use in combat, and is useful when exploring.
 * The Armor parameter is basically our health system. Armor is a number starting at 1 that allows the player to absord damage. When the player hits zero armor, then the next hit will be fatal. Additional armor can be found in the temple.
 * The FirstHalf parameter is to tell if the player has picked up the first half of the final coin, which is represented by the Sun Coin in the game. Required for exploration, but nothing else.
 * The SecondHalf parameter is to tell if the player has picked up the second half of the final coin, which is represented by the Moon coin in the game. Required for exploration but nothing else.
 * The Coin paremter is to tell if the player has collected both halves of the coin, and thus completed the seal needed for victory.
 * The Key parameter is to tell if the player has collected a key, which may have some value in exploring the world(hint/spoiler: It won't, a red herring).
 * The Boar parameter is to tell if the player has obtained the golden boar, and with it, soaring victory
 * The Hydra parameter is to tell if the player is aware of the Hydra lurking in the depths of the temple
 * The complete parameter is to tell if the player has sucesfully answered the first of the riddles presented in the riddle room.
 * The complete2 parameter is to tell if the player has sucessfully answered the second of the riddles presented in the riddle room.
 * The VisitPK parameter is to tell if the player has answered the optional riddle and can visit PK in the easteregg room.
 * The boargatecheck parameter is to tell if the player has investigated the boar vessel room's gate, and knows what to look for.
 * The boargateopen parameter is to tell if the player has opened the boar vessel room's gate.
 * The vineopen parameter is to tell if the player has unlocked the vine door
 * The pearlopen parameter is to tell if the player has unlocked the pearl door.
 * The victory parameter is to tell if the player has achieved victory.
 *
 *
 * return value:
 * This function does not have a return value, it merely ends the game, in a resounding victory for the player.
 */
void victoryroom(bool& victory) {

              cout << "Youve done it! The emperor will surely reward you well!" << endl;
              cout << "Outstanding brave adventurer. Outstanding." << endl;
              cout << "Despite a trail packed with mistakes and idiocy, dangers and threats, you came out on the other side victorious" << endl;
              cout << "Bask in the sun, and enjoy your days on a sunny Villa of an early retirement!" << endl;
              victory = 1;
              return;
        }
/* Function Name: BoarVesselRoom
 *
 * Function Description:
 * This function simulates the room that contains the final goal of the temple game, the Etruscan boar vessel. In certain circumstances, it also serves to simulate combat with the fabled Guardian, an enemy.
 * If the player either takes the vessel the first time around or matches the guardian in combat, then they win the game. Otherwise, the guardian will cut the player down.
 *
 * Parameters:
 * Note: Virtually all of our functions have the same parameters, which will be described in depth in the following. The majority of them are items which the player may collect, statuses of enemies, whether or not doors are open, and secrets.
 * The Sword parameter is to tell if the player has obtained the sword item, and carries it with them. The sword is required, and can be used in combat, or to explore.
 * The Spear parameter is to tell if the player has obtained the spear item, and carries it with them. The spear is optional, but is a great combat weapon that makes fighting easier. Cannot be used to explore generally.
 * The Shield parameter is to tell if the player has obtained the shield item, and carries it with them. The shield is required, and though it provides little in the way of combat, is useful for exploring.
 * The Torch parameter is to tell if the player has obtained the torch item, and carries it with them. The shield is required. While not a traditional weapon, it will see some limited use in combat, and is useful when exploring.
 * The Armor parameter is basically our health system. Armor is a number starting at 1 that allows the player to absord damage. When the player hits zero armor, then the next hit will be fatal. Additional armor can be found in the temple.
 * The FirstHalf parameter is to tell if the player has picked up the first half of the final coin, which is represented by the Sun Coin in the game. Required for exploration, but nothing else.
 * The SecondHalf parameter is to tell if the player has picked up the second half of the final coin, which is represented by the Moon coin in the game. Required for exploration but nothing else.
 * The Coin paremter is to tell if the player has collected both halves of the coin, and thus completed the seal needed for victory.
 * The Key parameter is to tell if the player has collected a key, which may have some value in exploring the world(hint/spoiler: It won't, a red herring).
 * The Boar parameter is to tell if the player has obtained the golden boar, and with it, soaring victory
 * The Hydra parameter is to tell if the player is aware of the Hydra lurking in the depths of the temple
 * The complete parameter is to tell if the player has sucesfully answered the first of the riddles presented in the riddle room.
 * The complete2 parameter is to tell if the player has sucessfully answered the second of the riddles presented in the riddle room.
 * The VisitPK parameter is to tell if the player has answered the optional riddle and can visit PK in the easteregg room.
 * The boargatecheck parameter is to tell if the player has investigated the boar vessel room's gate, and knows what to look for.
 * The boargateopen parameter is to tell if the player has opened the boar vessel room's gate.
 * The vineopen parameter is to tell if the player has unlocked the vine door
 * The pearlopen parameter is to tell if the player has unlocked the pearl door.
 * The victory parameter is to tell if the player has achieved victory.
 *
 *
 * return value:
 * This function has a simple return value if the player dies. Otherwise, the player wins.
 */
void BoarVesselRoom(int& Armor, bool& Spear, bool& victory){
    string boarchoice;
    string attordef;

    cout << "Success, so clearly in view. The moment of glory is at hand." << endl;
    cout << "As you walk into the richly decorated room, you observe all around you the hall marks and splendor of a once great people." << endl;
    cout << "The walls are lined with endless amounts of gold and shining silver, tapestries resplendent with pictures, carvings and engravings." << endl;
    cout << "Each tells a story of old Etrusca, once mighty and rich beyond all measure, now, a backwater ruin." << endl;
    cout << "But enough of that. What sits in the middle of the room sits an enormouly ornate platform. On it, stands the fabled object of your search." << endl;
    cout << endl;
    cout << "The Etruscan boar vessel." << endl;
    cout << "An overwhelming sense of dread enraptures you as you appraoch the platform." << endl;
    cout << "Dare you take it? Dare you risk it all for the glory which will follow?" << endl;
    cout << "Brave adventurer, do you want to take the golden boar?!?! (y/n)" << endl;;
    cin >> boarchoice;
    while (boarchoice != "y" && boarchoice != "n")
        {
        cout << "ADVENTURER! This is no time to screw around! Victory is at hand. Do you want to take it?!? (y/n)" << endl;
        cin >> boarchoice;
        }
    if (boarchoice == "y")
        {
        cout << "Gently and slowly, as though expecting the obvious trap, you grab the boar vessel from the table." << endl;
        cout << "You scoop it up ever so gently and slowly, waiting for the oncoming whistle of a trap door or something of the nature." << endl;
        cout << "Alas.....nothing comes of it! You are amazed as you cower in cover for a second. There is no trap..." << endl;
        cout << "Of course there is no trap! The Etruscans were not some kind of nutty paranoid race of super engineers. The trials you endured thus far were enough, no?!" << endl;
        cout << "You simply grab the vessel and.....walk out the alter room." << endl;
        cout << "Once more, nothing happens. Joy rushes into you, excitement filling your every step. You did it!" << endl;
        cout << "You actually did it! The Etruscan boar vessel of myth is yours!" << endl;
        cout << "You quickly and gently secure the vessel into your bag, and book it out the door!" << endl;
        cout << "As you stand outside, the cool northern air rushes into your lungs, and you let out one last victorious battle cry as you mount your steed." << endl;
        cout << "You rush down the road and start your journey home, safe in the knowledge that your quest is a success. You will have a tale to tell back home, that is for sure!" << endl;
        cout << "Rest well warrior, you've earned it!" << endl;
        victory = 1;

        return;

        }

    else if (boarchoice == "n")
        {
        cout << "For reasons known only to you, perhaps cowardice, perhaps fear of retribution or perhaps blatant stupidity, you do not grab the boar vessel." << endl;
        cout << "Instead, you step back, positive there must be some kind of catch." << endl;
        cout << "As you step back, you feel your foot sink, even if only a little, as a stone slightly falls underfoot." << endl;
        cout << "What the hells is going on?" << endl;
        cout << "Before you can react any further, you hear a laugh consume the room." << endl;
        cout << "'Coward! Of course you are not worthy of the might of the boar vessel. Who sees glory in hand, and does not take it?!'" << endl;
        cout << "Before you can possibly react, a Spear is thrust at you with the force of a tidal wave." << endl;
        Armor -= 1;
        if (Armor < 0)
        {
        cout << "With no more Armor for protection, your old defenses long since stripped away, the Spear passes straight into your chest." << endl;
        cout << "The sharp, intense sting soon covers and burns over your whole body, as you see your own blood stream out of the wound." << endl;
        cout << "You collapse, and look up to see a ghoulish sight. A man dressed in old Etruscan Armor stands over you, gloating and cackling more." << endl;
        cout << "The skeletal king moves over your body that is quickly losing conciousness." << endl;
        cout << "'The vessel is the heart of Etrusca, it will never fall into your hands, foolish adventurer. Better luck next time!'" << endl;
        cout << "The cackling of the old Etruscan king can be heard as you fade into blackness." << endl;
        cout << endl;
        cout << "Soon, you wake to find yourself outside the old temple, laying on the cool grass as the sun rises on the northern italian countryside." << endl;
        cout << "Immediatly behind you, the temple's enormous stone doors have been long since slammed shut and sealed, preventing all further entry." << endl;
        cout << "So close. So close yet so far. It the end it didn't even matter." << endl;
        cout << "Defeated, you mount your horse and ride home in shame, knowing full well that you will have to carry the burden of getting so close, yet failing, forever." << endl;
        cout << "The boar vessel has alluded you." << endl;
        return;
        }
        else if(Armor > 0)
        {
        cout << "Your Armor catches the blow, but you are sent staggering back as your Armor breaks and falls off you from the force of the blow." << endl;
        cout << "You turn to see a ghoulish skeleton figure standing before you, like the one you cut down earlier, but this one decked in ornate golden Armor." << endl;
        cout << "You hear a snarling voice coming from his decayed remnants of a mouth." << endl;
        cout << "'Intruder. You werre lucky. You think to claim my boar vessel? I think not. This is a treasure for only the king of Etrusca!'" << endl;
        cout << "'Etrusca has fallen, fiend.' You shout back at him. 'Just give me the boar vessel!'" << endl;
        cout << endl;
        cout << "'It will take more than that, you pathetic interloper. Face the wrath of the vessel guardian!'" << endl;
        cout << "The monster stands in front of you in a combat pose." << endl;
        cout << "He blocks your path. It looks to be fight or die now." << endl;
        cout << "What do you do now?";
        cin >> attordef;
        while (attordef != "Sword" && attordef != "Spear" && attordef != "Shield" && attordef != "Torch")
        {
        cout << "That accomplished virtually nothing but angering the guardian." << endl;
        cout << "Annoyed, he lashes forward in fury with his nasty Spear." << endl;
        Armor -= 1;
        if (Armor < 0)
        {
        cout << "With no more Armor for protection, your old defenses long since stripped away, the Spear passes straight into your chest." << endl;
        cout << "The sharp, intense sting soon covers and burns over your whole body, as you see your own blood stream out of the wound." << endl;
        cout << "You collapse, and look up to see a ghoulish sight. A man dressed in old Etruscan Armor stands over you, gloating and cackling more." << endl;
        cout << "The skeletal king moves over your body that is quickly losing conciousness." << endl;
        cout << "'The vessel is the heart of Etrusca, it will never fall into your hands, foolish adventurer. Better luck next time!'" << endl;
        cout << "The cackling of the old Etruscan king can be heard as you fade into blackness." << endl;
        cout << endl;
        cout << "Soon, you wake to find yourself outside the old temple, laying on the cool grass as the sun rises on the northern italian countryside." << endl;
        cout << "Immediatly behind you, the temple's enormous stone doors have been long since slammed shut and sealed, preventing all further entry." << endl;
        cout << "So close. So close yet so far. It the end it didn't even matter." << endl;
        cout << "Defeated, you mount your horse and ride home in shame, knowing full well that you will have to carry the burden of getting so close, yet failing, forever." << endl;
        cout << "The boar vessel has alluded you." << endl;
        return;
        }
        else
        {

        cout << "You have a feeling you wont be able to try that again." << endl;
        cout << "Its now or never. You think you ought to use a weapon here." << endl;
        cout << "What do you use? ";
        cin >> attordef;

        }

        if (attordef == "Spear" && Spear == 1)
        {
            cout << "You draw the dorian Spear across your back, lower it in a combat posture and advance." << endl;
            cout << "The foolish monster charges you, just as you expected he would." << endl;
            cout << "Quick as a flash, you deflect his blow with your Spear, and then sweep the guardians legs." << endl;
            cout << "The guardian collapses backwards, its footing lost, and his gnarled treasure Spear flies from his hands out into the darkness." << endl;
            cout << "Before he can get a word in endwise, you quickly jab the Spear into his skull, and with a loud crunch of bones, the Spear finds its mark and punches through." << endl;
            cout << "The guardian immediatly drops lifelessly, and soon the bones turn to dust and blow off into the temple." << endl;

        }

        else if (attordef == "Sword") {
            cout << "You draw your bronze Sword, that trusted weapon, and begin to advance on the guardian." << endl;
            cout << "He jabs with his Spear, but you quickly deflect the blow, and chop downward, splitting the Spear in half" << endl;
            cout << "Quick as lightining, you slash forward across the skeletal creature." << endl;
            cout << "The force of cold and sharp bronze quickly cracks the bone in its path, and the guardian is cut down." << endl;
            cout << "Before it can respond, life leaves its haunted remains, and its bones turn to dust and fly off into the temple." << endl;
        }

        else if (attordef == "Shield")
        {
            cout << "'The Shield!' You think as you reach for the Shield of apollo in your bag, and present it before you to face down the guardian." << endl;
            cout << "The reflection from the Shield shines brightly with the fury of a thousand scorching suns. The boar vessel begins glowing, as if responding to the Shields prescence!" << endl;
            cout << "The bright light from the boar vessel shines into the Shield, and the piercing light fires forward onto the skeletal guardian!" << endl;
            cout << "The skeleton screams and claws at its face, but it is all in vain. It's bones catch fire and combust, as the power of the sun shines onto it with a fury!" << endl;
            cout << "The creature is scattered, its remains destroyed and flung across the room." << endl;
            cout << "Soon, the light from the vessel stops, and the Shield returns to its shining silverly glow." << endl;

        }

        cout << "The room now cleared of threats, you turn back towards the boar vessel." << endl;
        cout << "You may have made the mistake once of not grabbing it, be it cowardice or fear, but you do not repeat this mistake." << endl;
        cout << "You gently grab the boar vessel, throw it into your pack, and flee the temple with the haste of the wind!" << endl;
        cout << "You quickly and gently secure the vessel into your bag, and book it out the door!" << endl;
        cout << "As you stand outside, the cool northern air rushes into your lungs, and you let out one last victorious battle cry as you mount your steed." << endl;
        cout << "You rush down the road and start your journey home, safe in the knowledge that your quest is a success. You will have a tale to tell back home, that is for sure!" << endl;
        cout << "Rest well warrior, you've earned it!" << endl;
        victory = 1;
        victoryroom(victory);

        }




        }
        }


        }




int main(){

    //Inventory
    int Armor = 1;
    bool Sword = 0;
    bool Spear = 0;
    bool Shield = 0;
    bool Torch = 0;
    bool FirstHalf = 1;
    bool SecondHalf = 1;
    bool Coin = 0;
    bool Boar = 0;
    bool Key = 0;

    //Player status
    bool boargatecheck = 0;
    bool victory = 0;
    bool Complete = 0;
    int Complete2 = 0;
    bool VisitPK = 0;
    int HydraAlive = 1;
    bool Beginning = 0;
    bool Hydra = 0;

    //Doors
    bool pearlopen = 0;
    bool boargateopen = 0;
    bool vineopen = 0;
    bool Gate = 0;
    bool PK = 0;

    while (victory == 0) {
    StartGame(Sword, Spear, Shield, Torch, Armor, FirstHalf, SecondHalf, Coin, Boar, Key, Hydra, Complete, Gate, Beginning, HydraAlive, PK, Complete2, VisitPK, boargatecheck, boargateopen, vineopen, pearlopen, victory);
}
    if (victory == 1) {
        cout << "So our tale ends, one way or another." << endl;
    }
    return 0;
}
